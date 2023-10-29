#include <ActivityPendingChange.hpp>

PendingChange::PendingChange()
{
}

PendingChange::~PendingChange()
{
}

ActivityStack::Action PendingChange::getAction() const
{
    if (m_params.find("action") != m_params.end())
        return std::any_cast<ActivityStack::Action>(m_params.at("action"));
    else
        throw std::runtime_error("PendingChange::getAction() : action not found");
}

ActivityID PendingChange::getActivityID() const
{
    if (m_params.find("activityID") != m_params.end())
        return std::any_cast<ActivityID>(m_params.at("activityID"));
    else
        throw std::runtime_error("PendingChange::getActivityID() : activityID not found");
}

int PendingChange::getRequestCode() const
{
    if (m_params.find("requestCode") != m_params.end())
        return std::any_cast<int>(m_params.at("requestCode"));
    else
        throw std::runtime_error("PendingChange::getRequestCode() : requestCode not found");
}

int PendingChange::getResultCode() const
{
    if (m_params.find("resultCode") != m_params.end())
        return std::any_cast<int>(m_params.at("resultCode"));
    else
        throw std::runtime_error("PendingChange::getResultCode() : resultCode not found");
}

std::unique_ptr<Extra> PendingChange::getExtra() const
{
    if (m_params.find("extra") != m_params.end())
        return std::unique_ptr<Extra>(std::any_cast<Extra*>(m_params.at("extra")));
    else
        throw std::runtime_error("PendingChange::getExtra() : extra not found");
}

PendingChangeBuilder::PendingChangeBuilder()
    : m_pendingChange(std::make_unique<PendingChange>())
{
}

PendingChangeBuilder::~PendingChangeBuilder()
{
}

PendingChangeBuilder& PendingChangeBuilder::setAction(ActivityStack::Action action)
{
    m_pendingChange->m_params["action"] = action;
    return *this;
}

PendingChangeBuilder& PendingChangeBuilder::setActivityID(ActivityID activityID)
{
    m_pendingChange->m_params["activityID"] = activityID;
    return *this;
}

PendingChangeBuilder& PendingChangeBuilder::setRequestCode(int requestCode)
{
    m_pendingChange->m_params["requestCode"] = requestCode;
    return *this;
}

PendingChangeBuilder& PendingChangeBuilder::setResultCode(int resultCode)
{
    m_pendingChange->m_params["resultCode"] = resultCode;
    return *this;
}

PendingChangeBuilder& PendingChangeBuilder::setExtra(std::unique_ptr<Extra> extra)
{
    m_pendingChange->m_params["extra"] = extra.get();
    return *this;
}

PendingChange PendingChangeBuilder::build()
{
    return std::move(*m_pendingChange);
}