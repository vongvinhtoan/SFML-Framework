#pragma once

#include <Activity.hpp>

class EmptyActivity : public Activity
{
public:
    EmptyActivity(ActivityStack& stack, int requestCode, Extra& intent);
    virtual ~EmptyActivity() final override;
    virtual bool handleEvent(sf::Event& event) final override;
    virtual bool handleRealtimeInput() final override;
    virtual bool update(sf::Time dt) final override;
    virtual bool draw() final override;
};