#include "display_files.h"
#include <filesystem>
#include <string>

std::string displayFiles(std::string folderPath)
{
    std::string result;

    try {
        if (!std::filesystem::exists(folderPath) || !std::filesystem::is_directory(folderPath)) {
            return "Error: Folder does not exist or is not a directory.";
        }

        for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
            if (entry.is_regular_file()) {                   // Only list files, not subfolders
                result += entry.path().filename().string() + "\n ";
            }
        }

        if (result.empty()) {
            return "No files found in the folder.";
        }

        return result;
    } catch (const std::filesystem::filesystem_error& e) {
        return std::string("Error accessing folder: ") + e.what();
    }
}