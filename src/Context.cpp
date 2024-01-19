#include <Context.hpp>

Context::Context()
    : window(nullptr)
    , textures(nullptr)
    , fonts(nullptr)
    , backend(nullptr)
{
}

Context& Context::getInstance()
{
    static Context instance;
    return instance;
}

Context::~Context()
{
}

sf::RenderWindow* Context::getWindow()
{
    return window;
}

TextureHolder* Context::getTextures()
{
    return textures;
}

FontHolder* Context::getFonts()
{
    return fonts;
}

Backend* Context::getBackend()
{
    return backend;
}

Json::Value* Context::getConfigs()
{
    return configs;
}

void Context::setWindow(sf::RenderWindow* window)
{
    this->window = window;
}

void Context::setTextures(TextureHolder* textures)
{
    this->textures = textures;
}

void Context::setFonts(FontHolder* fonts)
{
    this->fonts = fonts;
}

void Context::setBackend(Backend* backend)
{
    this->backend = backend;
}

void Context::setConfigs(Json::Value* configs)
{
    this->configs = configs;
}

std::map<int, int>* Context::getWonList()
{
    return &wonList;
}