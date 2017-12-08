//
// Created by florian on 08/12/2017.
//

#include <vector>
#include "SliceTerrain.h"
#include <pthread.h>
#define NB_SLIDE 4


void* task(void* p){
    static_cast<SliceTerrain*>(p)->run();
    return NULL;
}

int main() {

    std::vector<SliceTerrain*> slices;
    std::vector<pthread_t> threads(NB_SLIDE);

    Terrain terrain(512);

    slices.push_back(new SliceTerrain(0,128,128,terrain));
    slices.push_back(new SliceTerrain(128,256,128, terrain));
    slices.push_back(new SliceTerrain(256,384,128, terrain));
    slices.push_back(new SliceTerrain(384,512,128, terrain));

    // Lancement des threads

    for (int i = 0; i < NB_SLIDE; ++i) {
        pthread_create( &(threads.at(i)), NULL, task,slices.at(i));
    }

    for (int i = 0; i < NB_SLIDE; ++i) {

        pthread_join(threads.at(i), NULL);
    }


    return 0;
}