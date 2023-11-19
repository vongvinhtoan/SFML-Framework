#include <Activities/MainActivity.hpp>

MainActivity::MainActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	ViewNode* layer = getLayer(0);
	auto window_size = getContext()->getWindow()->getSize();
	layer->attachChild(std::make_unique<MovingSquare>(sf::FloatRect(0, 0, window_size.x, window_size.y)));
}

MainActivity::~MainActivity()
{
}

bool MainActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool MainActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool MainActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool MainActivity::draw()
{
	return Activity::draw();
}
