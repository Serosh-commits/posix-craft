#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
int main(int argc, char *argv[]){
    
    if(argc == 1){
        std::cerr<<"Usage : touch <enter file>\n";
        return EXIT_FAILURE;
    }

    for(int it = 1; it < argc; ++it){
    
        std::string path = argv[it];
        std::ofstream file(path, std::ios::app);

        if(!file){
            std::cerr<<"failed to create the the file : "<<path<<"\n";
            return EXIT_FAILURE;
        }
    }


    return EXIT_SUCCESS;
}
