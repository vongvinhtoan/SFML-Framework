#include <ResultTextProcessor.hpp>
#include <Randomizer.hpp>
#include <Context.hpp>

ResultTextProcessor::ResultTextProcessor()
    : m_resultText("")
    , m_result(-1)
    , m_reviewedLength(0)
    , m_wonCount(Context::getInstance().getWonList()->size())
    , m_randomSeed(123)
{
    
}

void ResultTextProcessor::step()
{
    m_resultText = convertToString(m_result);
    for(int i = m_reviewedLength; i < m_resultText.length(); i++) {
        m_resultText[i] = '0' + ((m_resultText[i] + m_randomSeed) % 10 + 10) % 10;
        m_randomSeed *= m_resultText[i];
        m_randomSeed %= 1000000007;
        m_randomSeed += 123;
    }
}

void ResultTextProcessor::process()
{
    std::map<int, int>& wonList = *Context::getInstance().getWonList();
    if(m_result == -1) {
        std::pair<int, int> range;
        range.first = (*Context::getInstance().getConfigs())["random_range"]["min"].asInt();
        range.second = (*Context::getInstance().getConfigs())["random_range"]["max"].asInt();

        m_result = Randomizer::getInstance().getRandomInt(range.first, range.second);
        while(wonList.find(m_result) != wonList.end())
            m_result = Randomizer::getInstance().getRandomInt(range.first, range.second);

        m_reviewedLength = 1;
    }
    else {
        m_reviewedLength++;
        if(m_reviewedLength > m_resultText.length())
            m_reviewedLength = m_resultText.length();
        int size = std::to_string((*Context::getInstance().getConfigs())["random_range"]["max"].asInt()).size();
        if(m_reviewedLength == size)
            wonList[m_result] = ++m_wonCount;
    }
}

void ResultTextProcessor::reset()
{
    m_result = -1;
    m_reviewedLength = 0;
}

std::string ResultTextProcessor::convertToString(int number)
{
    std::string result = "";
    int temp = m_result;
    if(temp <= 0) 
        temp = 0;
    int size = std::to_string((*Context::getInstance().getConfigs())["random_range"]["max"].asInt()).size();

    for(int i=0; i<size; i++, temp/=10) {
        result += (char)('0' + temp%10);
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string ResultTextProcessor::getString()
{
    return m_resultText;
}