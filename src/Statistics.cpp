#include "Statistics.h"

#include <iostream>
#include <iomanip>

Statistics::Statistics()
{
    originalBits = 0;
    compressedBits = 0;

    compressionRatio = 0.0;
    spaceSaved = 0.0;
}

void Statistics::calculate(
    int originalCharacters,
    int compressedBitLength)
{
    originalBits = originalCharacters * 8;
    compressedBits = compressedBitLength;

    if (originalBits == 0)
    {
        compressionRatio = 0.0;
        spaceSaved = 0.0;
        return;
    }

    compressionRatio =
        (static_cast<double>(compressedBits) /
         originalBits) * 100.0;

    spaceSaved = 100.0 - compressionRatio;
}

void Statistics::displayStatistics() const
{
    std::cout << "\nCompression Statistics\n";
    std::cout << "===============================\n";

    std::cout << "Original Size      : "
              << originalBits
              << " bits\n";

    std::cout << "Compressed Size    : "
              << compressedBits
              << " bits\n";

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Compression Ratio  : "
              << compressionRatio
              << "%\n";

    std::cout << "Space Saved        : "
              << spaceSaved
              << "%\n";
}