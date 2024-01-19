#pragma once

#include <string>
#include <map>

class ResultTextProcessor
{
private:
    std::string m_resultText;
    int m_result;
    int m_reviewedLength;
    int m_wonCount;
    int m_randomSeed;

public:
    ResultTextProcessor();
    void step();
    void process();
    void reset();
    std::string convertToString(int number);
    std::string getString();
};