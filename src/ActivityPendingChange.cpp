#include <ActivityPendingChange.hpp>

PendingChange::PendingChange()
: m_action(ActivityStack::Action::Null)
, m_activityID(ActivityID::Null)
, m_requestCode(0)
, m_resultCode(0)
, m_extra(nullptr)
{
}

PendingChange& PendingChange::setAction(ActivityStack::Action action)
{
    m_action = action;
    return *this;
}

PendingChange& PendingChange::setActivityID(ActivityID activityID)
{
    m_activityID = activityID;
    return *this;
}

PendingChange& PendingChange::setRequestCode(int requestCode)
{
    m_requestCode = requestCode;
    return *this;
}   

PendingChange& PendingChange::setResultCode(int resultCode)
{
    m_resultCode = resultCode;
    return *this;
}

PendingChange& PendingChange::setExtra(Extra* extra)
{
    m_extra = extra;
    return *this;
}

ActivityStack::Action PendingChange::getAction() const
{
    return m_action;
}

ActivityID PendingChange::getActivityID() const
{
    return m_activityID;
}

int PendingChange::getRequestCode() const
{
    return m_requestCode;
}

int PendingChange::getResultCode() const
{
    return m_resultCode;
}

Extra* PendingChange::getExtra() const
{
    return m_extra;
}