#include<iostream>

int main(int argc, char *argv[]){
    
    for(int it = 1; it < argc; ++it){
        
        if(it > 0){
            std::cout<<" ";
        }
        std::cout<<argv[it];
    }

    return 0;
}
