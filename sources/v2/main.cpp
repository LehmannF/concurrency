//
// Created by florian on 08/12/2017.
//

#include <vector>
#include "SliceTerrain.h"
#include <pthread.h>
#include <string>
#include <iostream>
#include <cmath>
#include <sys/resource.h>
#define NB_SLIDE 4


void* task(void* p){
    static_cast<SliceTerrain*>(p)->run();
    return NULL;
}

int main(int argc, char *argv[]) {

    struct rusage usage;
    clock_t start, end;
    double CPUTime[5] = {0};
    double responseTime[5] = {0};
    bool measure = false;
    int nb_mesure= 1;
    int nb_persons= 512;

    for(int i=1; i < argc && argv[i]!=NULL; i++) {


        if (std::string(argv[i])=="-m") {
            measure = true;
        }


        if (std::string(argv[i])=="-p") {
            if ( atoi(argv[i+1]) <= 9 && atoi(argv[i+1])>=0)
                nb_persons = pow(2,atoi(argv[i+1]));
        }

    }



    for(int j=0; j < nb_mesure; j++) {
        //std::cout << "Running" << std::endl;
        std::vector<SliceTerrain *> slices;
        std::vector<pthread_t> threads(NB_SLIDE);

        Terrain terrain(nb_persons);

        slices.push_back(new SliceTerrain(0, 128, 128, terrain));
        slices.push_back(new SliceTerrain(128, 256, 128, terrain));
        slices.push_back(new SliceTerrain(256, 384, 128, terrain));
        slices.push_back(new SliceTerrain(384, 512, 128, terrain));

        // Lancement des threads

        if (!measure) {
            std::cout << "Running" << std::endl;
        }
        else {
            start = clock();
            getrusage(RUSAGE_SELF, &usage);
        }


        for (int i = 0; i < NB_SLIDE; ++i) {
            if (!measure)
                std::cout << "created "  << i << std::endl;
            pthread_create(&(threads.at(i)), NULL, task, slices.at(i));
        }


        for (int i = 0; i < NB_SLIDE; ++i) {
            if (!measure)
                std::cout<< "over " << i << std::endl;
            pthread_join(threads.at(i), NULL);

        }

        if (measure) {
            end = clock();
            getrusage(RUSAGE_SELF, &usage);
        }

        responseTime[j] = (double)(end-start)/CLOCKS_PER_SEC;
        CPUTime[j] = ((long int)usage.ru_utime.tv_sec) + ((long int)usage.ru_stime.tv_sec);

        if (!measure)
            std::cout << "End" << std::endl;

        for (int k = 0; k < slices.size(); ++k) {
            delete slices.at(k);
            slices.erase(slices.begin(), slices.begin()+4);
            threads.erase(threads.begin(), threads.end());
        }

    }

    if(measure) {
        double sum = 0;
        for(int i=1; i < nb_mesure-1; i++) {
            sum += responseTime[i];
        }
        double mean = responseTime[0];
        std::cout << "Le temps de reponse est de " << mean  << " secondes" << std::endl;


        sum = 0;
        for(int i=1; i < nb_mesure-1; i++) {
            sum += CPUTime[i];
        }
        mean = CPUTime[0];
        std::cout << "Le consommation du cpu est de " << mean  << " secondes" << std::endl;

    }

    return 0;
}
