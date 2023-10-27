#include <Backend.hpp>
#include <fstream>

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

void Backend::loadConfigs(Json::Value& configs)
{
    std::ifstream file("res/configs/configs.json"); 
    file >> configs;
    file.close();
}