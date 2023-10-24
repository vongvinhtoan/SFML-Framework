#pragma once

#include <SFML/Graphics.hpp>
#include <Activity.hpp>
#include <memory>
#include <vector>

class ActivityStack
{
public:
    ActivityStack();
    ~ActivityStack();

public:
    bool isEmpty() const;
    void handleEvent(sf::Event& event);
    void handleRealtimeInput();
    void update(sf::Time dt);
    void draw();

private:
    std::vector<std::unique_ptr<Activity>> m_stack;
};