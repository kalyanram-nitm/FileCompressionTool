 #ifndef FREQUENCYCOUNTER_H
#define FREQUENCYCOUNTER_H

#include <string>
#include <unordered_map>

class FrequencyCounter
{
private:
    std::unordered_map<char, int> frequencyMap;

public:
    FrequencyCounter();

    void countFrequency(const std::string& text);

    void displayFrequency() const;

    const std::unordered_map<char, int>& getFrequencyMap() const;
};

#endif