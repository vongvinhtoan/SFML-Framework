#include <Views/StatisticsView.hpp>
#include <stdexcept>

StatisticsView::StatisticsView()
{
}

StatisticsView::StatisticsView(sf::Font& font)
: m_font(&font)
{
}

StatisticsView::~StatisticsView()
{
}

void StatisticsView::setFont(sf::Font& font)
{
    m_font = &font;
}

#include <iostream>

void StatisticsView::update(sf::Time dt)
{
    m_StatisticsUpdateTime += dt;
    m_StatisticsNumFrames += 1;
    
    if(m_font == nullptr) 
        throw std::runtime_error("StatisticsView::update() - m_font is nullptr");
    m_StatisticsText.setFont(*m_font);
    m_StatisticsText.setCharacterSize(10); 

    if(m_StatisticsUpdateTime >= TimePerUpdate)
    {
        m_StatisticsText.setString(
            "Frames / Second = " + std::to_string(m_StatisticsNumFrames) + "\n" +
            "Time / Update = " + std::to_string(m_StatisticsUpdateTime.asMicroseconds() / m_StatisticsNumFrames) + "us"
        );

        m_StatisticsUpdateTime -= TimePerUpdate;
        m_StatisticsNumFrames = 0;
    }
}

void StatisticsView::handleEvent(sf::Event& event)
{
}

void StatisticsView::handleRealtimeInput()
{
}

void StatisticsView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(m_font == nullptr) 
        throw std::runtime_error("StatisticsView::draw() - m_font is nullptr");

    target.draw(m_StatisticsText, states);
}