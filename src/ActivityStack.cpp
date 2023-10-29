#include <ActivityStack.hpp>
#include <ActivityPendingChange.hpp>

ActivityStack::ActivityStack()
{
}

ActivityStack::~ActivityStack()
{
}

bool ActivityStack::isEmpty() const
{
    return m_stack.empty();
}

void ActivityStack::handleEvent(sf::Event& event)
{
    for(auto it = m_stack.rbegin(); it != m_stack.rend(); ++it)
    {
        if(!(*it)->handleEvent(event)) break;
    }

    applyPendingChanges();
}

void ActivityStack::handleRealtimeInput()
{
    for(auto it = m_stack.rbegin(); it != m_stack.rend(); ++it)
    {
        if(!(*it)->handleRealtimeInput()) break;
    }

    applyPendingChanges();
}

void ActivityStack::update(sf::Time dt)
{
    for(auto it = m_stack.rbegin(); it != m_stack.rend(); ++it)
    {
        if(!(*it)->update(dt)) break;
    }

    applyPendingChanges();
}

void ActivityStack::draw()
{
    for(auto it = m_stack.rbegin(); it != m_stack.rend(); ++it)
    {
        if(!(*it)->draw()) break;
    }

    applyPendingChanges();
}

void ActivityStack::pushActivity(ActivityID activityID)
{
    PendingChangeBuilder builder;
    builder.setAction(Action::Push);
    builder.setActivityID(activityID);
    m_pendingList.push_back(builder.build());
}

void ActivityStack::pushActivity(ActivityID activityID, int requestCode, std::unique_ptr<Extra> extra)
{
    PendingChangeBuilder builder;
    builder.setAction(Action::Push);
    builder.setActivityID(activityID);
    builder.setRequestCode(requestCode);
    builder.setExtra(std::move(extra));
    m_pendingList.push_back(builder.build());
}

void ActivityStack::backActivity()
{
    PendingChangeBuilder builder;
    builder.setAction(Action::Pop);
    m_pendingList.push_back(builder.build());
}

void ActivityStack::backActivity(int resultCode, std::unique_ptr<Extra> extra)
{
    PendingChangeBuilder builder;
    builder.setAction(Action::Pop);
    builder.setResultCode(resultCode);
    builder.setExtra(std::move(extra));
    m_pendingList.push_back(builder.build());
}

void ActivityStack::clearActivities()
{
    PendingChangeBuilder builder;
    builder.setAction(Action::Clear);
    m_pendingList.push_back(builder.build());
}

void ActivityStack::applyPendingChanges()
{
    for(auto& change : m_pendingList)
    {
        switch(change.getAction())
        {
            case Action::Push:
            {
                ActivityID activityID = change.getActivityID();
                std::unique_ptr<Activity> activity = m_factory.create(activityID, *this, change.getRequestCode(), *change.getExtra());
                m_stack.push_back(std::move(activity));
                break;
            }
            case Action::Pop:
            {
                if(m_stack.empty())
                    throw std::runtime_error("ActivityStack::applyPendingChanges() : stack is empty, cannot pop");
                m_stack.pop_back();
                break;
            }
            case Action::Clear:
            {
                m_stack.clear();
                break;
            }
            case Action::Back:
            {
                if(m_stack.empty())
                    throw std::runtime_error("ActivityStack::applyPendingChanges() : stack is empty, cannot pop");
                m_stack.pop_back();

                if(m_stack.empty())
                    throw std::runtime_error("ActivityStack::applyPendingChanges() : stack is empty, cannot back");
                m_stack.back()->onActivityResult(change.getResultCode(), std::move(change.getExtra()));
                break;
            }
        }
    }
    m_pendingList.clear();
}