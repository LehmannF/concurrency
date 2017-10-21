#include <iostream>
#include "Terrain.h"
#include "Obstacle.h"
#include "Personne.h"
#include <vector>
#include <array>
#include <pthread.h>
#include <unistd.h>

#define NB 512

void* task(Personne* p){
  p->run();
  return NULL;
}

int main(int argc, char *argv[])
{
  
  Terrain terrain;
  Obstacle obstacle;
  //terrain.addObstacle(obstacle);

  std::vector<Personne*> personnes(NB);

  for (int i = 0; i < NB; ++i) {
    personnes.at(i) = new Personne(terrain,i);
  }

  
  std::array<pthread_t, NB> threads;

  std::cout << "Running" << std::endl;

  for (int i = 0; i < NB; ++i) {
    pthread_create( &(threads.at(i)), NULL, task,(void*) personnes.at(i));
  }

  for (int i = 0; i < NB; ++i) {
    std::cout<< "over " << i << std::endl;
    pthread_join(threads.at(i), NULL);
  }
  
  std::cout << "End" << std::endl;

  for (int i = 0; i < NB; ++i) {
    delete personnes.at(i);
  }

  return 0;
}
