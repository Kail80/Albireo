#include <filesystem>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <dirent.h>
namespace fs = std::filesystem;

int cd() {
    fs::path path = std::filesystem::current_path();
    fs::path path = fs::absolute(path);
    if (fs::exists(path)) {
        if(fs::is_regular_file(path)) {
            std::cout << path << '\n';
            return 0;
        } else if(fs::is_directory(path)) {
            if(opendir(path.c_str())); {
                std::cout << "opened " << path << '\n';
                return 1;
            }
            return -1;
        } else {
            std::cout << "ERR: Object not found" << '\n';
            return -1;
        }
    }
    return -2;
}

int ls() {
    fs::path path = std::filesystem::current_path();
    fs::path path = fs::absolute(path);
    if(fs::exists(path)) {
        if(fs::is_directory(path)) {
            for (const auto& entry : std::filesystem::directory_iterator(".")) 
            std::cout << entry.path() << '\n';
            return 1;
        } else if(fs::is_regular_file(path)) {
            std::cout << path << '\n';
            return 1;
        } else {
            std::cout << "ERR: Object not found" << '\n';
            return -1;
        }
    }
    return -2;
}

int mkdir() {
    fs::path path = std::filesystem::current_path();
    fs::path path = fs::absolute(path);
    try {
        if(std::filesystem::create_directory(path)) {
            std::cout << "Directory created successfully\n";
            return 1;
        } else {
            std::cout << "Failed to create directory\n";
            return -1;
        }
    } catch (const fs::filesystem_error& e) {
                std::cout << "ERR: Error deleting file: " << e.what() << '\n';
    }
    return -2;
}

int rm(char *rmpath) {
    fs::path path = std::filesystem::current_path();
    fs::path path = fs::absolute(path);
    if(fs::exists(path)) {
        if(fs::is_directory(path)) {
            try {
                if (std::filesystem::remove(path)) {
                    std::cout << "Directory removed\n";
                    ls();
                    return 1;
                } else {
                    std::cout << "Failed to remove the directory << \n";
                    return -1;
                }
            } catch (const fs::filesystem_error& e) {
                std::cout << "ERR: Error deleting file: " << e.what() << '\n';
            }
        }
        } else if(fs::is_regular_file(path)) {
            
            return 1;
        } else {
            std::cout << "ERR: Object not found" << '\n';
            return -1;
        }
        return -2;
    }

int echo(char *txt) {
    std::cout << txt << '\n';
    return 1;
}