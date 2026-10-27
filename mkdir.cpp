#include<iostream>
#include<filesystem>
#include<string>
#include<cstdlib>

int main(int argc, char *argv[]){
    
    if(argc == 1){
        std::cerr<<"Usage : mkdir <filename>\n";
        return EXIT_FAILURE;
    }

    for(int it = 1; it < argc; ++it){
        std::string path = argv[it];
        
        if(!(std::filesystem::create_directory(path))){
            std::cerr<<"failed to create the directory\n";
            return EXIT_FAILURE;
        }

    }
    return EXIT_SUCCESS;
}
