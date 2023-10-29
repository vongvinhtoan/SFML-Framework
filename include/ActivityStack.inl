template <typename ActivityChild, typename... Args>
void ActivityStack::registerActivity(ActivityID activityID) 
{
    m_factory.add(activityID, createClass<ActivityChild, Args...>);
}


template <class Child, typename... Args>
std::unique_ptr<Activity> ActivityStack::createClass(Args... args)
{
    return std::make_unique<Child>(args...);
}