#include "FrequencyCounter.h"

#include <iostream>

FrequencyCounter::FrequencyCounter()
{
    frequencyMap.clear();
}

void FrequencyCounter::countFrequency(const std::string& text)
{
    frequencyMap.clear();

    for (char character : text)
    {
        frequencyMap[character]++;
    }
}

void FrequencyCounter::displayFrequency() const
{
    std::cout << "\nCharacter\tFrequency\n";
    std::cout << "-------------------------\n";

    for (const auto& pair : frequencyMap)
    {
        if (pair.first == ' ')
        {
            std::cout << "SPACE\t\t";
        }
        else if (pair.first == '\n')
        {
            std::cout << "\\n\t\t";
        }
        else
        {
            std::cout << pair.first << "\t\t";
        }

        std::cout << pair.second << "\n";
    }
}

const std::unordered_map<char, int>&
FrequencyCounter::getFrequencyMap() const
{
    return frequencyMap;
}