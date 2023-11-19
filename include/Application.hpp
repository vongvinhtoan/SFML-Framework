#pragma once

#include <SFML/Graphics.hpp>
#include <ActivityStack.hpp>
#include <Backend.hpp>
#include <ViewList.hpp>
#include <ActivityIdentifiers.hpp>
#include <ViewTree.hpp>
#include <ResourceHolder.hpp>
#include <Context.hpp>
#include <memory>

class Application
{
public:
    static Application& getInstance();
    ~Application();

private:
    Application();
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

public:
    void run();

private:
    void registerActivities();
    void loadData();
    void loadFonts();
    void loadConfig();

private:
    bool processInput();
    void update(sf::Time dt);
    void draw();

private:
    std::unique_ptr<sf::RenderWindow>   m_window;
    std::unique_ptr<ActivityStack>      m_activityStack;
    std::unique_ptr<Backend>            m_backend;
    std::unique_ptr<ViewTree>           m_viewTree;
    std::unique_ptr<FontHolder>         m_fontHolder;
    std::unique_ptr<TextureHolder>      m_textureHolder;
    std::unique_ptr<Context>            m_context;
    Json::Value                         m_configs;
    StatisticsView*                     m_statisticsView = nullptr;
    bool                                m_isPaused = false;

private:
    sf::Time TimePerFrame = sf::Time::Zero;
};