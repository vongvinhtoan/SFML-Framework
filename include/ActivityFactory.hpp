#pragma once

#include <memory>
#include <map>
#include <any>
#include <functional>

template <class Key, class Object>
class ActivityFactory
{
public:
    ActivityFactory();
    ActivityFactory(std::initializer_list<std::pair<Key, Object*>> list);

public:

    /**
     * @brief Add a new object to the factory.
     * @param key The key to associate with the object.
     * @param createFunction A function that returns a pointer to the object.
    */
    template <typename Function>
    void add(Key key, Function createFunction);

    /**
     * @brief Create a new object from the factory.
     * @param key The key associated with the object.
     * @param args The arguments to pass to the object's constructor.
     * @return A pointer to the object.
    */
    template <typename... Args>
    std::unique_ptr<Object> create(Key key, Args&&... args);

private:
    std::map<Key, std::any> m_factory;
};

#include <ActivityFactory.inl>