#include <Backend.hpp>

Backend::Backend()
{
}

Backend::~Backend()
{
}

Backend& Backend::getInstance()
{
    static Backend instance;
    return instance;
}

void Backend::save()
{
}

void Backend::loadFonts(FontHolder& fonts)
{
    fonts.load(FontID::Main, "res/fonts/Sansation.ttf");
}