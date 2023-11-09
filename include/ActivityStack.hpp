#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Activity.hpp>
#include <ActivityFactory.hpp> 
#include <ActivityIdentifiers.hpp>
#include <Extra.hpp>
#include <memory>
#include <vector>

class PendingChange;
class PendingChangeBuilder;

class ActivityStack
{
private:
    friend class PendingChange;
    friend class PendingChangeBuilder;

    enum class Action;

public:
    ActivityStack();
    ~ActivityStack();

public:
    template <typename ActivityChild, typename... Args>
    void registerActivity(ActivityID activityID);

public:
    bool isEmpty() const;
    void handleEvent(sf::Event& event);
    void handleRealtimeInput();
    void update(sf::Time dt);
    void draw();

public:
    void pushActivity(ActivityID activityID);
    void pushActivity(ActivityID activityID, int requestCode, std::unique_ptr<Extra> extra);
    void backActivity();
    void backActivity(int resultCode, std::unique_ptr<Extra> extra);
    void clearActivities();

private:
    template <class Child, typename... Args>
    std::unique_ptr<Activity> createClass(Args... args);

private:
    void applyPendingChanges();

private:
    std::vector<std::unique_ptr<Activity>>  m_stack;
    std::vector<PendingChange>              m_pendingList;
    ActivityFactory<int, Activity>          m_factory;
};

enum class ActivityStack::Action
{
    Push,
    Pop,
    Clear,
    Back
};

#include <ActivityStack.inl>