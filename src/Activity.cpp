#include <Activity.hpp>

Activity::Activity(ActivityStack& stack)
    : m_stack(&stack)
{
}

Activity::~Activity()
{
}