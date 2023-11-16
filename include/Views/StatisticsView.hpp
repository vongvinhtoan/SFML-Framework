#pragma once

#include <ViewNode.hpp>

class StatisticsView : public ViewNode
{
public:
    StatisticsView();
    StatisticsView(sf::Font& font);
    virtual ~StatisticsView() final;

public:
    void setFont(sf::Font& font);

private:
    virtual void update(sf::Time dt) final override;
    virtual void handleEvent(sf::Event& event) final override;
    virtual void handleRealtimeInput() final override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

private:
    const sf::Time  TimePerUpdate = sf::seconds(1.f);
    sf::Time        m_StatisticsUpdateTime = sf::Time::Zero;
    std::size_t     m_StatisticsNumFrames = 0;
    sf::Text        m_StatisticsText;
    sf::Font*       m_font = nullptr;
};