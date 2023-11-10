#include <ViewTree.hpp>

ViewTree::ViewTree()
: m_root(std::make_unique<EmptyView>())
{
}

ViewTree::ViewTree(std::unique_ptr<ViewNode> root)
: m_root(std::move(root))
{
}

ViewTree::~ViewTree()
{
}

void ViewTree::setRoot(std::unique_ptr<ViewNode> root)
{
    m_root = std::move(root);
}

ViewNode* ViewTree::getRoot() const
{
    return m_root.get();
}

void ViewTree::update(sf::Time dt)
{
    if (m_root)
        update(dt, *m_root);
}

void ViewTree::handleEvent(sf::Event& event)
{
    if (m_root)
        handleEvent(event, *m_root);
}

void ViewTree::handleRealtimeInput()
{
    if (m_root)
        handleRealtimeInput(*m_root);
}

void ViewTree::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (m_root)
        draw(target, states, *m_root);
}

void ViewTree::update(sf::Time dt, ViewNode& node)
{
    for (auto& child : node.m_children)
        update(dt, *child);
    
    node.update(dt);
}

void ViewTree::handleEvent(sf::Event& event, ViewNode& node)
{
    for (auto& child : node.m_children)
        handleEvent(event, *child);
    
    node.handleEvent(event);
}

void ViewTree::handleRealtimeInput(ViewNode& node)
{
    for (auto& child : node.m_children)
        handleRealtimeInput(*child);
    
    node.handleRealtimeInput();
}

void ViewTree::draw(sf::RenderTarget& target, sf::RenderStates states, const ViewNode& node) const
{
    states.transform *= node.getTransform();
    
    for (auto& child : node.m_children)
        draw(target, states, *child);

    node.drawIfEnabled(target, states);
}