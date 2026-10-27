#include<iostream>
#include<string>
#include<filesystem>
#include<cstdlib>

namespace fs = std::filesystem;

static inline void remove_file(std::string &path){  

    std::error_code perr;    
    fs::remove(path, perr);

    if(perr){
        std::cerr<<"failed to remove the given file :"<<path<<"\n"; 
    }
}

static inline void parse_rm(std::string &path){
    
    std::error_code perr;
    fs::remove_all(path, perr);

    if(perr){
        std::cerr<<"failed to delete the dir :"<<path<<"\n";
    }
}
int main(int argc, char *argv[]){

    if(argc == 1){
        std::cerr<<"Usage : rm <input path>\n";
        return EXIT_FAILURE;
    }

    std::string path = argv[1];
    
    if(fs::is_regular_file(path)){
        remove_file(path);        
    } else if(fs::is_directory(path)){
        parse_rm(path);
    } else {
        std::cout<<"target destination invalid\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
