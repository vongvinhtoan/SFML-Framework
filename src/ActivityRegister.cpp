#include <Application.hpp>
#include <ActivityList.hpp>

void Application::registerActivities()
{
	m_activityStack->registerActivity<MainActivity>(ActivityID::Main);
}
