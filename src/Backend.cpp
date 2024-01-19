#include <Backend.hpp>
#include <fstream>
#include <iostream>

Backend::Backend() {}

Backend::~Backend() {}

Backend &Backend::getInstance()
{
    static Backend instance;
    return instance;
}

void Backend::loadTextures(TextureHolder &textures)
{
    // textures.load(TextureID::LoadingScreen, "res/textures/LoadingScreen.png");
}

void Backend::loadFonts(FontHolder &fonts)
{
    fonts.load(FontID::Main, "res/fonts/Sansation.ttf");
}

void Backend::loadConfigs(Json::Value &configs)
{
    std::ifstream file("res/configs/configs.json");
    file >> configs;
    file.close();
}

void Backend::saveConfig(Json::Value &configs)
{
    std::ofstream file("res/configs/configs.json");
    file << configs;
    file.close();
}