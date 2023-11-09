#pragma once

#include <Activity.hpp>

class EmptyActivity : public Activity
{
public:
    EmptyActivity(ActivityStack& stack, int requestCode, Extra& intent);
    virtual ~EmptyActivity();
    virtual bool handleEvent(sf::Event& event);
    virtual bool handleRealtimeInput();
    virtual bool update(sf::Time dt);
    virtual bool draw();
};