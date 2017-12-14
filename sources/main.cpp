//
// Created by florian on 14/12/17.
//
#include <unistd.h>
#include <iostream>
#include <string.h>

int main(int argc, char *argv[])
{
    for(int i=1; i < argc; i++) {

        if (strcmp("-t0", argv[i])==0) {
            char * argv_tmp[10] = {"main1"};
            for (int j = 1; j < argc; ++j) {
                //std::cout << argv[j] << std::endl;
                argv_tmp[j] = argv[j];
            }
            argv_tmp[9] = NULL;
            execv("./main1", argv_tmp);
        }

        if (strcmp("-t1", argv[i])==0) {
            char * argv_tmp[10] = {"main2"};
            for (int j = 1; j < argc; ++j) {
                //std::cout << argv[j] << std::endl;
                argv_tmp[j] = argv[j];
            }
            argv_tmp[9] = NULL;
            execv("./main2", argv_tmp);
        }
    }

}