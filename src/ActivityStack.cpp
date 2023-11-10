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
    PendingChange change;
    change.setAction(Action::Push)
            .setActivityID(activityID)
            .setRequestCode(0)
            .setExtra(new Extra());
    m_pendingList.push_back(change);
}

void ActivityStack::pushActivity(ActivityID activityID, int requestCode, Extra* extra)
{
    PendingChange change;
    change.setAction(Action::Push)
            .setActivityID(activityID)
            .setRequestCode(requestCode)
            .setExtra(extra);
    m_pendingList.push_back(change);
}

void ActivityStack::backActivity()
{
    PendingChange change;
    change.setAction(Action::Back);
    m_pendingList.push_back(change);
}

void ActivityStack::backActivity(int resultCode, Extra* extra)
{
    PendingChange change;
    change.setAction(Action::Back)
            .setResultCode(resultCode)
            .setExtra(extra);
    m_pendingList.push_back(change);
}

void ActivityStack::clearActivities()
{
    PendingChange change;
    change.setAction(Action::Clear);
    m_pendingList.push_back(change);
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
                int requestCode = change.getRequestCode();
                Extra* extra = change.getExtra();

                if (m_factory.find(activityID) == m_factory.end())
                    throw std::runtime_error("ActivityStack::applyPendingChanges() : activity not registered");

                std::unique_ptr<Activity> activity = m_factory[activityID](*this, requestCode, *extra);

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
                m_stack.back()->onActivityResult(change.getResultCode(), change.getExtra());
                break;
            }
        }
    }
    m_pendingList.clear();
}