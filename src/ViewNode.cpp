#include <ViewNode.hpp>
#include <cassert>

ViewNode::ViewNode()
{
}

ViewNode::~ViewNode()
{
}

void ViewNode::toggle() { m_enabled = !m_enabled; }
void ViewNode::enable() { m_enabled = true; }
void ViewNode::disable() { m_enabled = false; }

void ViewNode::attachChild(std::unique_ptr<ViewNode> child)
{
    child->m_parent = this;
    m_children.push_back(std::move(child));
}

std::unique_ptr<ViewNode> ViewNode::detachChild(const ViewNode& node)
{
    auto found = std::find_if(m_children.begin(), m_children.end(),
        [&node](std::unique_ptr<ViewNode>& p) -> bool { return p.get() == &node; });

    assert(found != m_children.end());

    std::unique_ptr<ViewNode> result = std::move(*found);
    result->m_parent = nullptr;
    m_children.erase(found);
    return result;
}

void ViewNode::drawIfEnabled(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(this->m_enabled)
        draw(target, states);
}