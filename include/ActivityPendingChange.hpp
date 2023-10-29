#pragma once

#include <unordered_map>
#include <any>
#include <string>
#include <memory>
#include <Extra.hpp>
#include <ActivityStack.hpp>

class PendingChange
{
friend class PendingChangeBuilder;

public:
    PendingChange();
    ~PendingChange();

public:
    ActivityStack::Action getAction() const;
    ActivityID getActivityID() const;
    int getRequestCode() const;
    int getResultCode() const;
    std::unique_ptr<Extra> getExtra() const;

private:
    std::unordered_map<std::string, std::any> m_params;
};

class PendingChangeBuilder
{
public:
    PendingChangeBuilder();
    ~PendingChangeBuilder();

public:
    PendingChangeBuilder& setAction(ActivityStack::Action action);
    PendingChangeBuilder& setActivityID(ActivityID activityID);
    PendingChangeBuilder& setRequestCode(int requestCode);
    PendingChangeBuilder& setResultCode(int resultCode);
    PendingChangeBuilder& setExtra(std::unique_ptr<Extra>  extra);

    PendingChange build();

private:
    std::unique_ptr<PendingChange> m_pendingChange;
};