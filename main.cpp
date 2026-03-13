/*@Author: Rachel Luginbill
@Date: March 12, 2026
@Description: This MS users will be able to upload files and request to view them. 
Also, you will be able to use CRUD op on all avalible files.*/

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "json.hpp"
#include "httplib.h"

#include "content/file_contents.h"
#include "create/create_files.h"
#include "delete/delete_file.h"
#include "update/file_updator.h"
#include "display/display_files.h"

using json = nlohmann::json;

int main() {

    httplib::Server server;
    std::string folder = "files";

    std::filesystem::create_directories(folder);

    server.Post("/file", [&](const httplib::Request& req, httplib::Response& res) {

        json request = json::parse(req.body);
        int option = request["option"];

        std::string filename = request.value("filename", "");
        std::string content = request.value("content", "");
        std::string folder = request.value("folder", "files"); // default if not provided

        std::string result;

        if(option == 1)
            result = createFile(folder + "/" + filename, content);

        else if(option == 2)
            result = updateFile(folder + "/" + filename, content);

        else if(option == 3)
            result = deleteFile(folder + "/" + filename);

        else if(option == 4)
            result = displayFiles(folder);

        json response;
        response["result"] = result;

        res.set_content(response.dump(4), "application/json");
    });

    std::cout << "Microservice running on port 8180...\n";

    server.listen("localhost", 8180);
}