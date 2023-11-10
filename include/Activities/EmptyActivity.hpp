#pragma once

#include <Activity.hpp>

class EmptyActivity : public Activity
{
public:
    EmptyActivity(ActivityStack& stack, int requestCode, Extra& intent);
    virtual ~EmptyActivity() final;
    virtual bool handleEvent(sf::Event& event) final;
    virtual bool handleRealtimeInput() final;
    virtual bool update(sf::Time dt) final;
    virtual bool draw() final;
};