#include <Randomizer.hpp>
#include <Context.hpp>

Randomizer::Randomizer()
    : std::mt19937((*Context::getInstance().getConfigs())["random_seed"].asInt())
{
}

Randomizer& Randomizer::getInstance()
{
    static Randomizer instance;
    return instance;
}

int Randomizer::getRandomInt(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(*this);
}