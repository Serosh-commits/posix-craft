#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

int main(int argc , char *argv[]){

    if(argc == 1){
        std::cerr<<"Usage : cat <filename>\n";
        return EXIT_FAILURE;
    }

    for(int it = 1; it < argc; ++it){
        std::string path = argv[it];
        std::ifstream file(path, std::ios::app);

        if(!file){
           std::cerr<<"failed to open the file"<<path<<"\n";
           return EXIT_FAILURE;
        }

        std::string line;
        while(std::getline(file, line)){
            std::cout<<line<<"\n";
        }

    }
    return EXIT_SUCCESS;
}
