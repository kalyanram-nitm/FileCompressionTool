#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics
{
private:
    int originalBits;
    int compressedBits;

    double compressionRatio;
    double spaceSaved;

public:
    Statistics();

    void calculate(
        int originalCharacters,
        int compressedBitLength
    );

    void displayStatistics() const;
};

#endif