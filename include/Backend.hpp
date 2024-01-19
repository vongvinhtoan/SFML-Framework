#pragma once

#include <ResourceHolder.hpp>
#include <json.h>

class Backend
{
public:
    void loadTextures(TextureHolder& textures);
    void loadFonts(FontHolder& fonts);
    void loadConfigs(Json::Value& configs);

    void saveConfig(Json::Value& configs);

public:
    static Backend& getInstance();
    ~Backend();

private:
    Backend();
    Backend(const Backend&) = delete;
    Backend& operator=(const Backend&) = delete;
};