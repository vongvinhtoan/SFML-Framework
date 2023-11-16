#pragma once

#include <ViewNode.hpp>

class EmptyView : public ViewNode
{
public:
    EmptyView();
    virtual ~EmptyView() final;

private:
    virtual void update(sf::Time dt) final override;
    virtual void handleEvent(sf::Event& event) final override;
    virtual void handleRealtimeInput() final override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;
};