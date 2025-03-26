#include <windows.h>
#include <string>
#include <iostream>
#include <filesystem>


namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        std::string inputPath = argv[1];
        DWORD fileAttributes = GetFileAttributesA(inputPath.c_str());

        if (fileAttributes != INVALID_FILE_ATTRIBUTES)
        {
            std::string command;
            if (fileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                command = "cmd.exe /k cd \"" + inputPath + "\"";
            }
            else
            {
                fs::path filePath(inputPath);
                command = "cmd.exe /k cd \"" + filePath.parent_path().string() + "\"";
            }

            STARTUPINFOA si = { sizeof(STARTUPINFOA) };
            PROCESS_INFORMATION pi;
            CreateProcessA(
                NULL,
                const_cast<char*>(command.c_str()),
                NULL,
                NULL,
                FALSE,
                0,
                NULL,
                NULL,
                &si,
                &pi
            );

            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
        else
        {
            std::cerr << "Invalid path: " << inputPath << std::endl;
        }
    }
    else
    {
        std::cerr << "Usage: LaunchCmd <path>" << std::endl;
    }

    return 0;
}
