#pragma once

#include <ViewNode.hpp>

class TextView;

class PreviewTextView : public ViewNode
{
public:
	PreviewTextView();
	virtual ~PreviewTextView() final;

private:
	virtual void update(sf::Time dt) final override;
	virtual void handleEvent(sf::Event& event) final override;
	virtual void handleRealtimeInput() final override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
	virtual bool contains(sf::Vector2f point) const final override;
	void setString(const std::string& string);

public:
	// Getters

private:
	TextView* m_texts[3];
};
