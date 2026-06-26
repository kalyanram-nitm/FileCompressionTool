#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager
{
private:
    std::string fileName;
    std::string fileData;

public:
    FileManager();

    bool readFile(const std::string& fileName);

    bool writeFile(const std::string& fileName,
                   const std::string& data);

    std::string getFileData() const;
};

#endif