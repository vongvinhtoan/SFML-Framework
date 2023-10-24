#pragma once
#include <SFML/Graphics.hpp>
#include <ActivityStack.hpp>
#include <Backend.hpp>
#include <ViewList.hpp>
#include <ViewTree.hpp>
#include <memory>

class Application
{
public:
    static Application& getInstance();
    ~Application();

public:
    void run();

private:
    Application();
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

private:
    void loadData();
    void processInput();
    void update(sf::Time dt);
    void draw();

private:
    std::unique_ptr<sf::RenderWindow>   m_window;
    std::unique_ptr<ActivityStack>      m_activityStack;
    std::unique_ptr<Backend>            m_backend;
    std::unique_ptr<ViewTree>           m_viewTree;
    StatisticsView*                     m_statisticsView = nullptr;
    bool                                m_isPaused = false;

private:
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};