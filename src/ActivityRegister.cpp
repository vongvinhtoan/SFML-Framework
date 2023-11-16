#include <Application.hpp>
#include <ActivityList.hpp>

void Application::registerActivities()
{
    m_activityStack->registerActivity<EmptyActivity>(ActivityID::Empty);
}
