/*@Author: Rachel Luginbill
@Date: March 12, 2026
@Description: This MS users will be able to upload files and request to view them. 
Also, you will be able to use CRUD op on all avalible files.*/

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "content/file_contents.h"
#include "create/create_files.h"
#include "delete/delete_file.h"
#include "update/file_updator.h"
#include "display/display_files.h"


std::string handleRequest(int option, std::string filename, std::string content)
{
    std::string folder = "files";
    std::filesystem::create_directories(folder);

    if(option == 1)
        return createFile(folder + "/" + filename, content);

    else if(option == 2)
        return updateFile(folder + "/" + filename, content);

    else if(option == 3)
        return deleteFile(folder + "/" + filename);

    else if(option == 4)
        return displayFiles(folder);

    else
        return "Invalid option";
}

int main()
{
    int option = 4; // example from JSON { "option": 4 }

    std::string response = handleRequest(option, "", "");

    std::cout << response;

    return 0;
}