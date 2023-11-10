#pragma once

#include <ViewNode.hpp>

class MovingSquare : public ViewNode
{
public:
    MovingSquare(sf::FloatRect bounds);
    virtual ~MovingSquare() final;

private:
    virtual void update(sf::Time dt) final;
    virtual void handleEvent(sf::Event& event) final;
    virtual void handleRealtimeInput() final;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

public:
    virtual bool contains(sf::Vector2f point) const final;

private:
    std::unique_ptr<sf::RectangleShape> m_square;
    sf::Vector2f m_velocity = { 100.f, 100.f };
    sf::FloatRect m_bounds;
};