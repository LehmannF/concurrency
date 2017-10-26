#include <iostream>
#include "Terrain.h"
#include "Obstacle.h"
#include "Personne.h"
#include <vector>
#include <array>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <string>
#include <cmath>



void* task(void* p){
  static_cast<Personne*>(p)->run();
  return NULL;
}

int main(int argc, char *argv[])
{


  clock_t start, end;
  double duration[5];
  bool measure = false;
  Terrain terrain;
  Obstacle obstacle;
  terrain.addObstacle(obstacle);
  int nb_threads = 512;
  int nb_mesure= 1;
  
  for(int i=1; i < argc; i++) {
    if (std::string(argv[i])=="-m") {
      measure = true;
      nb_mesure= 5;
      
    }


    if (std::string(argv[i])=="-p") {
      if ( atoi(argv[i+1]) <= 9 && atoi(argv[i+1])>=0)
	nb_threads = pow(2,atoi(argv[i+1]));
    }
  }

  
  
  std::vector<Personne*> personnes(nb_threads);
  std::vector<pthread_t> threads(nb_threads);

  for(int j=0; j < nb_mesure; j++) {
  
    for (int i = 0; i < nb_threads; ++i) {
      personnes.at(i) = new Personne(terrain,i);
    }
    
    if (!measure)
      std::cout << "Running" << std::endl;
    
    if(measure)
      start = clock();
    
    for (int i = 0; i < nb_threads; ++i) {
      pthread_create( &(threads.at(i)), NULL, task,personnes.at(i));
    }
    
    for (int i = 0; i < nb_threads; ++i) {
      
      if (!measure)
	std::cout<< "over " << i << std::endl;
      
      pthread_join(threads.at(i), NULL);
    }

    if (measure)
      end = clock();

    duration[j] = (double)(end-start)/CLOCKS_PER_SEC;

    if (!measure)
      std::cout << "End" << std::endl;
    
    for (int i = 0; i < nb_threads; ++i) {
      delete personnes.at(i);
    }
  }

  if(measure) {
    double sum = 0;
    for(int i=1; i < nb_mesure-1; i++) {
      sum += duration[i];
    }
    double mean = sum/(nb_mesure-2);
    std::cout << "Le temps d'éxécution est de de" << mean  << " secondes" << std::endl;
    }
  
  return 0;
}
