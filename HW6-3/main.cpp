//
//  main.cpp
//  HW6-3
//
//  Created by Alyaev Roman on 17.03.2021.
//

#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>

void ls(const std::__fs::filesystem::path & directory)
{
    if (std::__fs::filesystem::exists(directory) and std::__fs::filesystem::is_directory(directory))
    {
        for (auto element: std::__fs::filesystem::directory_iterator(directory))
        {
            auto filename = element.path().filename().string();
            auto extention = directory.extension().string();
            auto last_wtime = std::__fs::filesystem::last_write_time(directory);
            std::time_t last_wtime_to_time = decltype(last_wtime)::clock::to_time_t(last_wtime);

            std::cout << "Filename: " << filename << std::endl
            << "Extension: " << extention << std::endl
            << "Last write time: " << std::asctime(std::localtime(&last_wtime_to_time)) << std::endl;
        }
    }
}

int main(int argc, const char * argv[])
{
    std::string string_directory;
    
    std::cout << "Enter the directory: ";
    std::cin >> string_directory;
    
    std::__fs::filesystem::path directory = string_directory;
    
    if (!std::__fs::filesystem::exists(directory))
    {
        std::cerr << "This directory: " << directory << " doesn't exist!" << std::endl;
        exit(1);
    }

    ls(directory);

    return 0;
}
