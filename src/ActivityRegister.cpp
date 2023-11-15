#include <Application.hpp>

void Application::registerActivities()
{
    m_activityStack->registerActivity<EmptyActivity>(ActivityID::Empty);
}
