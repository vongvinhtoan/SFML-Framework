#include <ActivityStack.hpp>

ActivityStack::ActivityStack()
{
}

ActivityStack::~ActivityStack()
{
}

bool ActivityStack::isEmpty() const
{
    return m_stack.empty();
}

void ActivityStack::handleEvent(sf::Event& event)
{
    for(auto it = m_stack.rbegin(); it != m_stack.rend(); ++it)
    {
        if(!(*it)->handleEvent(event)) break;
    }
}

void ActivityStack::handleRealtimeInput()
{
    for(auto it = m_stack.rbegin(); it != m_stack.rend(); ++it)
    {
        if(!(*it)->handleRealtimeInput()) break;
    }
}

void ActivityStack::update(sf::Time dt)
{
    for(auto it = m_stack.rbegin(); it != m_stack.rend(); ++it)
    {
        if(!(*it)->update(dt)) break;
    }
}

void ActivityStack::draw()
{
    for(auto it = m_stack.rbegin(); it != m_stack.rend(); ++it)
    {
        if(!(*it)->draw()) break;
    }
}