#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <ViewTree.hpp>
#include <Context.hpp>
#include <Extra.hpp>
#include <ActivityIdentifiers.hpp>

class ActivityStack;

class Activity
{
friend class ActivityStack;

public:
    Activity(ActivityStack& stack, int requestCode, Extra& intent);
    virtual ~Activity();

protected:
    virtual bool handleEvent(sf::Event& event) = 0;
    virtual bool handleRealtimeInput() = 0;
    virtual bool update(sf::Time dt) = 0;
    virtual bool draw() = 0;

protected:
    void requestActivity(ActivityID activityID);
    void requestActivity(ActivityID activityID, int requestCode, std::unique_ptr<Extra> extra);
    void finishActivity();
    void finishActivity(int resultCode, std::unique_ptr<Extra> extra);
    virtual void onActivityResult(int resultCode, std::unique_ptr<Extra> extra);

protected:
    ViewNode* getLayer(int layer);
    Context* getContext() const;

private:
    ActivityStack*              m_stack;
    std::unique_ptr<ViewTree>   m_viewTree;
    Context*                    m_context;
    std::vector<ViewNode*>      m_layers;
};

