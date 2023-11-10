#pragma once

#include <unordered_map>
#include <any>
#include <string>
#include <memory>
#include <Extra.hpp>
#include <ActivityStack.hpp>

class PendingChange
{
public:
    PendingChange();

public:
    PendingChange& setAction(ActivityStack::Action action);
    PendingChange& setActivityID(ActivityID activityID);
    PendingChange& setRequestCode(int requestCode);
    PendingChange& setResultCode(int resultCode);
    PendingChange& setExtra(Extra* extra);

public:
    ActivityStack::Action getAction() const;
    ActivityID getActivityID() const;
    int getRequestCode() const;
    int getResultCode() const;
    Extra* getExtra() const;

private:
    ActivityStack::Action m_action;
    ActivityID m_activityID;
    int m_requestCode;
    int m_resultCode;
    Extra* m_extra;
};