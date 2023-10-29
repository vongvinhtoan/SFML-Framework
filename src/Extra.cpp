#include <Extra.hpp>

bool Extra::hasExtra(const std::string& key)
{
    return m_extra.find(key) != m_extra.end();
}