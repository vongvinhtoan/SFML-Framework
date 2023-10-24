#include <Application.hpp>
#include <iostream>

Application::Application()
{
    loadData();
    m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(640, 480), "SFML Application");
    m_activityStack = std::make_unique<ActivityStack>();
    m_viewTree = std::make_unique<ViewTree>(std::unique_ptr<StatisticsView>(new StatisticsView));
    m_statisticsView = dynamic_cast<StatisticsView*>(m_viewTree->getRoot());
    std::cout << m_statisticsView << std::endl;
}

Application& Application::getInstance()
{
    static Application instance;
    return instance;
}

Application::~Application()
{
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (m_window->isOpen())
    {
        // if(m_activityStack->isEmpty()) m_window->close();

        processInput();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            processInput();
            if(!m_isPaused) update(TimePerFrame);
        }
        draw();
    }
}

void Application::loadData()
{

}

void Application::processInput()
{
    sf::Event event;
    while(m_window->pollEvent(event))
    {
        if(!m_isPaused) m_activityStack->handleEvent(event);
        switch (event.type)
        {
            case sf::Event::Closed:
                m_backend->save();
                m_window->close();
                break;
            case sf::Event::GainedFocus:
                m_isPaused = false;
                break;
            case sf::Event::LostFocus:
                m_isPaused = true;
                break;
            case sf::Event::KeyPressed:
                m_statisticsView->toggle();
                break;
        }
    }
    if(!m_isPaused) m_activityStack->handleRealtimeInput();
}

void Application::update(sf::Time dt)
{
    m_activityStack->update(dt);
    m_viewTree->update(dt);
}

void Application::draw()
{
    m_window->clear();
    m_activityStack->draw();
    m_window->draw(*m_viewTree);
    m_window->display();
}