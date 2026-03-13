//delete given file
#include "delete_file.h"
#include <filesystem>
#include <string>

std::string deleteFile(std::string fileToDelete)
{
    try {
        if (std::filesystem::exists(fileToDelete)) {
            std::filesystem::remove(fileToDelete);
            return "File '" + fileToDelete + "' deleted successfully.";
        } else {
            return "Error: File '" + fileToDelete + "' does not exist.";
        }
    } catch (const std::filesystem::filesystem_error& e) {
        return std::string("Error deleting file: ") + e.what();
    }
}