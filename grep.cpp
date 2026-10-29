#include<iostream>
#include<filesystem>
#include<string>
#include<vector>
#include<cstdlib>
#include<fstream>
int main(int argc, char *argv[]){

    if(argc != 3){
        std::cerr<<"Usage : ./grep <input pattern> <input filename>\n";
        return EXIT_FAILURE;
    }

    std::string pattern = argv[1];
    std::ifstream file(argv[2]);

    if(!file){
        std::cerr<<"file failed to open\n";
        return EXIT_FAILURE;
    }

    std::string line;
    while(std::getline(file, line)) {
        
        if(line.find(pattern) != std::string::npos){
            std::cout<< line <<"\n";
        }
    }
    return EXIT_SUCCESS;
}
