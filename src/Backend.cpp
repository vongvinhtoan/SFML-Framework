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
    textures.load(TextureID::Background, "res/textures/Background.png");
    textures.load(TextureID::Background2, "res/textures/Background2.png");
}

void Backend::loadFonts(FontHolder &fonts)
{
    fonts.load(FontID::Main, "res/fonts/Sansation.ttf");
    fonts.load(FontID::chison2, "res/fonts/chison2.ttf");
}

void Backend::loadConfigs(Json::Value &configs)
{
    std::ifstream file("res/configs/configs.json");
    file >> configs;
    file.close();
}

void Backend::loadWonList(std::map<int, int> &wonList)
{
    std::ifstream file("res/won.txt");
    int rank, number;
    while(file >> rank >> number) {
        wonList[number] = rank;
    }
    file.close();
}

void Backend::saveConfig(Json::Value &configs)
{
    std::ofstream file("res/configs/configs.json");
    file << configs;
    file.close();
}

void Backend::saveWonList(std::map<int, int> &wonList)
{
    std::ofstream file("res/won.txt");
    std::vector<std::pair<int, int>> wonListVector;
    for(auto &pair : wonList) {
        wonListVector.push_back(std::make_pair(pair.second, pair.first));
    }
    std::sort(wonListVector.begin(), wonListVector.end());
    for(auto &pair : wonListVector) {
        file << pair.first << " " << pair.second << std::endl;
    }
    file.close();
}