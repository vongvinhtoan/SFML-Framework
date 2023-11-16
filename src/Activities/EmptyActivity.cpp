#include <Activities/EmptyActivity.hpp>

EmptyActivity::EmptyActivity(ActivityStack& stack, int requestCode, Extra& intent)
: Activity(stack, requestCode, intent)
{
    ViewNode* layer = getLayer(0);
    auto window = getContext()->getWindow();
    layer->attachChild(std::make_unique<MovingSquare>(sf::FloatRect(0.f, 0.f, window->getSize().x, window->getSize().y)));
}

EmptyActivity::~EmptyActivity()
{
}

bool EmptyActivity::handleEvent(sf::Event& event)
{
    return Activity::handleEvent(event);
}

bool EmptyActivity::handleRealtimeInput()
{
    return Activity::handleRealtimeInput();
}

bool EmptyActivity::update(sf::Time dt)
{
    return Activity::update(dt);
}

bool EmptyActivity::draw()
{
    return Activity::draw();
}