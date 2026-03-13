#include "file_updator.h"
#include <fstream>
#include <string>
#include <filesystem>

std::string updateFile(std::string fileToUpdate, std::string newContent)
{
    if (!std::filesystem::exists(fileToUpdate)) {
        return "Error: File '" + fileToUpdate + "' does not exist.";
    }

    std::ofstream outFile(fileToUpdate, std::ios::trunc); // open file and truncate existing content
    if (!outFile) {
        return "Error: Could not open file '" + fileToUpdate + "' for updating.";
    }

    outFile << newContent; // write new content
    outFile.close();

    return "File '" + fileToUpdate + "' updated successfully.";
}