#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class ViewNode :
    public sf::Drawable,
    public sf::Transformable,
    private sf::NonCopyable
{

friend class ViewTree;

public:
    ViewNode();
    virtual ~ViewNode();

public:
    void attachChild(std::unique_ptr<ViewNode> child);
    std::unique_ptr<ViewNode> detachChild(const ViewNode& node);

protected:
    virtual void update(sf::Time dt) = 0;
    virtual void handleEvent(sf::Event& event) = 0;
    virtual void handleRealtimeInput() = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

private:
    void drawIfEnabled(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    void toggle();
    void enable();
    void disable();

private:
    ViewNode*                               m_parent = nullptr;
    bool                                    m_enabled = true;
    std::vector<std::unique_ptr<ViewNode>>  m_children;
};