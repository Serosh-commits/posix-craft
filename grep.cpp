#include<iostream>
#include<filesystem>
#include<string>
#include<vector>
#include<cstdlib>
#include<fstream>

namespace fs = std::filesystem;
int main(int argc, char *argv[]){
    bool show_line_numbers = false;
    bool invert_match = false;
    
    int arg_index = 1;

    while(arg_index < argc && argv[arg_index][0] == '-'){
        std::string option =  argv[arg_index];

        if(option == "-n"){
            show_line_numbers = true;
        } else if (option == "-v"){
           invert_match = true;
        } else {
            std::cerr<<"unknown option(check ur option) :" <<option<<"\n";
            return EXIT_FAILURE;
        }

        ++arg_index;
    }
    
    if(argc - arg_index != 2){
        std::cerr<<"Usage : ./grep [-n] [-r] <pattern> <input file name>\n";
        return EXIT_FAILURE;
    }

    std::string pattern = argv[arg_index];
    std::ifstream file(argv[arg_index + 1]);

    if(!file){
        std::cerr<<"file failed to open\n";
        return EXIT_FAILURE;
    }

    std::string line;
    int line_number = 0;
    while(std::getline(file, line)) {
        ++line_number;
        
        bool found = line.find(pattern) != std::string::npos;

        if(!(invert_match && found) || (invert_match && !found )){
            
            if(show_line_numbers){
                std::cout<<"line_number :";
            }

            std::cout<< line <<"\n";
2        }
    }
    return EXIT_SUCCESS;
}
