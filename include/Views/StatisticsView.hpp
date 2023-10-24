#pragma once

#include <ViewNode.hpp>

class StatisticsView : public ViewNode
{
public:
    StatisticsView();
    virtual ~StatisticsView() final;

private:
    virtual void update(sf::Time dt) final;
    virtual void handleEvent(sf::Event& event) final;
    virtual void handleRealtimeInput() final;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
};