template <class Key, class Object>
ActivityFactory<Key, Object>::ActivityFactory()
{
}

template <class Key, class Object>
ActivityFactory<Key, Object>::ActivityFactory(std::initializer_list<std::pair<Key, Object*>> list)
{
    for (auto& pair : list)
    {
        m_factory[pair.first] = pair.second;
    }
}

template <class Key, class Object>
template <typename Function>
void ActivityFactory<Key, Object>::add(Key key, Function createFunction)
{
    m_factory[key] = std::any(createFunction);
}

template <class Key, class Object>
template <typename... Args>
std::unique_ptr<Object> ActivityFactory<Key, Object>::create(Key key, Args&&... args)
{
    auto it = m_factory.find(key);
    if (it != m_factory.end())
    {
        auto& any = it->second;
        auto function = std::any_cast<std::function<std::unique_ptr<Object>(Args...)>>(any);
        return std::move(function(args...));
    }
    return nullptr;
}