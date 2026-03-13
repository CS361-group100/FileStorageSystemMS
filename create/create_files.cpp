#include "create_files.h"
#include <fstream>
#include <string>

std::string createFile(std::string fileName, std::string fileContents)
{
    std::ofstream outFile(fileName); // open file for writing
    if (!outFile) {
        return "Error: Could not create file " + fileName;
    }

    outFile << fileContents; // write contents to the file
    outFile.close();

    return "File '" + fileName + "' created successfully.";
}