#include <Application.hpp>
#include <iostream>

Application::Application()
: m_backend(&Backend::getInstance())
, m_fontHolder(std::make_unique<FontHolder>())
{
    loadData();
    m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(640, 480), "SFML Application");
    m_activityStack = std::make_unique<ActivityStack>(); 
    m_viewTree = std::make_unique<ViewTree>(std::make_unique<StatisticsView>(m_fontHolder->get(FontID::Main)));
    m_statisticsView = dynamic_cast<StatisticsView*>(m_viewTree->getRoot());
    m_statisticsView->attachChild(std::make_unique<MovingSquare>(sf::FloatRect(0.f, 0.f, 640.f, 480.f)));

    m_window->setFramerateLimit(60);
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
    loadFonts();
}

void Application::loadFonts()
{
    m_backend->loadFonts(*m_fontHolder);
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
                if(event.key.code == sf::Keyboard::F5) m_statisticsView->toggle();
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