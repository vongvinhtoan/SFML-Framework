#pragma once

#include <random>
#include <chrono>

class Randomizer : public std::mt19937
{
private:
    Randomizer();
    Randomizer(const Randomizer&) = delete;
    Randomizer& operator=(const Randomizer&) = delete;

public:
    static Randomizer& getInstance();
    int getRandomInt(int min, int max);
};