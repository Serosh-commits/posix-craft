#include<iostream>
#include<cerrno>
#include<unistd.h>
#include<vector>
#include<cstdio>

int main(){
    
    std::vector<char>buffer(256);

    while(true){
        
        if(getcwd(buffer.data(), buffer.size())  != nullptr){
            break;
        }

        if(errno == ERANGE){
            buffer.resize(buffer.size() * 2);
            continue;
        }

        std::perror("pwd : getcwd");
        return EXIT_FAILURE;
    }

    std::cout<<buffer.data()<<"\n";
    return EXIT_SUCCESS;
}
