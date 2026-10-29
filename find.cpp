#include<iostream>
#include<filesystem>
#include<string>
#include<cstdlib>

namespace fs = std::filesystem;

static inline void find_file(std::string dir, std::string file){
    
    auto options = fs::directory_options::skip_permission_denied;
    for(auto const dir_it : fs::recursive_directory_iterator(dir, options)){
       
        try {
            std::string file_name = dir_it.path().filename().string();

            if(file_name.find(file) != std::string::npos){
                std::cout<<dir_it.path().string()<<"\n";
            }
        } catch (const fs::filesystem_error& e){
            continue;
        }
        
    }
}
int main(int argc, char *argv[]){

    if(argc != 3){
        std::cerr<<"Usage : <input directory path> <input file u want to find>\n";
        return EXIT_SUCCESS;
    }
    
    std::string dir = argv[1];
    std::string file = argv[2];

    if(fs::is_directory(dir)){
        find_file(dir, file);
    } else {
        std::cerr<<"directory path not found\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
