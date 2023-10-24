#pragma once

class Backend
{
public:
    static Backend& getInstance();
    ~Backend();

private:
    Backend();
    Backend(const Backend&) = delete;
    Backend& operator=(const Backend&) = delete;

public:
    void save();
    void load();
};