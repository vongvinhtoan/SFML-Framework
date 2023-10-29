#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <ViewTree.hpp>
#include <Context.hpp>
#include <Extra.hpp>
#include <ActivityList.hpp>

class ActivityStack;

class Activity
{
friend class ActivityStack;

public:
    Activity(ActivityStack& stack, int requestCode, Extra& intent);
    virtual ~Activity();

private:
    virtual bool handleEvent(sf::Event& event) = 0;
    virtual bool handleRealtimeInput() = 0;
    virtual bool update(sf::Time dt) = 0;
    virtual bool draw();

protected:
    void requestActivity(ActivityID activityID);
    void requestActivity(ActivityID activityID, int requestCode, std::unique_ptr<Extra> extra);
    void finishActivity();
    void finishActivity(int resultCode, std::unique_ptr<Extra> extra);
    virtual void onActivityResult(int resultCode, std::unique_ptr<Extra> extra) = 0;

protected:
    ViewNode* getLayer(int layer);

private:
    ActivityStack*              m_stack;
    std::unique_ptr<ViewTree>   m_viewTree;
    Context*                    m_context;
    std::vector<ViewNode*>      m_layers;
};