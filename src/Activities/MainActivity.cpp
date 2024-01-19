#include <Activities/MainActivity.hpp>
#include <Utils.hpp>

MainActivity::MainActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	auto* layer = getLayer(0);
	auto background = std::make_unique<RectangleView>(sf::Vector2f(1500, 750));
	background->get().setTexture(&getContext()->getTextures()->get(TextureID::Background));

	layer->attachChild(std::move(background));

	auto* layer2 = getLayer(1);
	auto previewText = std::make_unique<PreviewTextView>();
	
	m_previewText = previewText.get();
	layer2->attachChild(std::move(previewText));
}

MainActivity::~MainActivity()
{
}

bool MainActivity::handleEvent(sf::Event& event)
{
	Activity::handleEvent(event);
	if(event.type == sf::Event::KeyPressed) {
		if(event.key.code == sf::Keyboard::Space) {
			m_resultTextProcessor.process();
		}
		else if(event.key.code == sf::Keyboard::R) {
			m_resultTextProcessor.reset();
		}
	}
	
	return 0;
}

bool MainActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool MainActivity::update(sf::Time dt)
{
	m_resultTextProcessor.step();
	m_previewText->setString(m_resultTextProcessor.getString());
	return 0;
}

bool MainActivity::draw()
{
	Activity::draw();
	return 0;
}

void MainActivity::onActivityResult(int resultCode, Extra* extra)
{
}