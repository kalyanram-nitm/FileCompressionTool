 #include <iostream>
#include <string>

#include "FileManager.h"
#include "FrequencyCounter.h"

int main()
{
    std::cout << "=====================================\n";
    std::cout << " Smart File Compression Tool\n";
    std::cout << " Version 1.0\n";
    std::cout << "=====================================\n\n";

    FileManager fileManager;
    FrequencyCounter frequencyCounter;

    std::string fileName;

    std::cout << "Enter file name: ";
    std::getline(std::cin, fileName);

    if (fileManager.readFile("input/" + fileName))
    {
        std::cout << "\nFile loaded successfully!\n\n";

        std::cout << "File Contents\n";
        std::cout << "-----------------------------\n";

        std::cout << fileManager.getFileData();

        frequencyCounter.countFrequency(fileManager.getFileData());

        std::cout << "\n\nFrequency Table\n";
        std::cout << "=========================\n";

        frequencyCounter.displayFrequency();

        std::cout << "\n";
    }
    else
    {
        std::cout << "\nFailed to load file.\n";
    }

    return 0;
}