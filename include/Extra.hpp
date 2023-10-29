#pragma once

#include <unordered_map>
#include <string>
#include <any>

class Extra
{
public:
    template<typename T>
    void putExtra(const std::string& key, const T& value);

    template<typename T>
    T getExtra(const std::string& key);

    bool hasExtra(const std::string& key);

private:
    std::unordered_map<std::string, std::any> m_extra;
};

#include <Extra.inl>