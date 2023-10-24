#pragma once

#include <ViewNode.hpp>

class EmptyView : public ViewNode
{
public:
    EmptyView();
    virtual ~EmptyView() final;

private:
    virtual void update(sf::Time dt) final;
    virtual void handleEvent(sf::Event& event) final;
    virtual void handleRealtimeInput() final;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
};