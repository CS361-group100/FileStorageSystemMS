# FileStorageSystemMS

This MS users will be able to upload files and request to view them. Also, you will be able to edit files through the CRUD MS.

# For C users:

1. Open MSYS2 UCRT64
2. Open path to folder
3. Run: 

        g++ -D_WIN32_WINNT=0x0A00 main.cpp create/create_files.cpp delete/delete_file.cpp update/file_updator.cpp display/display_files.cpp -o microservice -lws2_32

4. Then Run:

        ./microservice

5. Go into API tester (Postman recommended)
6. Enter into POST http://localhost:8180/file the body raw JSON section your json code ex.

        {
            "option": 4,
            "folder": "testerFolder"
        }

7. Should return the result!

# For Python Users:

1. Follow steps 1-4 for C users
2. Then run : pip install requests
3. Then make a call to microservice! Ex. below:

        import requests

        url = "http://localhost:8080/file"

        data = {
            "option": 4,
            "folder": "files"
        }

        response = requests.post(url, json=data)

        print(response.json())
