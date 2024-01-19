#include <Views/PreviewTextView.hpp>
#include <Views/TextView.hpp>
#include <Context.hpp>
#include <iostream>

PreviewTextView::PreviewTextView()
{
	auto& config = (*Context::getInstance().getConfigs())["text_preview"];
	auto& font = Context::getInstance().getFonts()->get(FontID::Main);

	for(int i=0; i<3; i++) {
		m_texts[i] = new TextView();
		attachChild(std::unique_ptr<TextView>(m_texts[i]));
	}

	for(int i=0; i<3; i++) {
		auto& text = *m_texts[i];
		text.get().setFont(font);
		text.get().setCharacterSize(config["character_size"].asInt());
		text.get().setFillColor(sf::Color::White);
		text.get().setPosition(config["offset_x"].asFloat() + i * config["spacing_x"].asFloat(), config["offset_y"].asFloat());
		text.get().setStyle(sf::Text::Bold);
	}
}

PreviewTextView::~PreviewTextView()
{
}

void PreviewTextView::update(sf::Time dt)
{
}

void PreviewTextView::handleEvent(sf::Event& event)
{
}

void PreviewTextView::handleRealtimeInput()
{
}

void PreviewTextView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(int i=0; i<3; i++) {
		target.draw(*m_texts[i], states);
	}
}

bool PreviewTextView::contains(sf::Vector2f point) const
{
	return false;
}

void PreviewTextView::setString(const std::string& string)
{
	for(int i=0; i<3; i++) {
		m_texts[i]->get().setString(string[i]);
		auto bound = m_texts[i]->get().getLocalBounds();
		m_texts[i]->get().setOrigin(bound.left + bound.width / 2.f, bound.top + bound.height / 2.f);
	}
}
