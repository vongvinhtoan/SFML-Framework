#pragma once

#include <ResourceHolder.hpp>

class Backend
{
public:
    void save();
    void loadFonts(FontHolder& fonts);

public:
    static Backend& getInstance();
    ~Backend();

private:
    Backend();
    Backend(const Backend&) = delete;
    Backend& operator=(const Backend&) = delete;
};