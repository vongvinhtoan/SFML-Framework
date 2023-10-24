#pragma once

#include <SFML/Graphics.hpp>

class ActivityStack;

class Activity
{
public:
    Activity(ActivityStack& stack);
    virtual ~Activity();

public:
    virtual bool handleEvent(sf::Event& event) = 0;
    virtual bool handleRealtimeInput() = 0;
    virtual bool update(sf::Time dt) = 0;
    virtual bool draw() = 0;

private:
    ActivityStack* m_stack;
};