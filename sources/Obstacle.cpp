#include <random>

#include "Obstacle.h"

Obstacle::Obstacle() {

  std::random_device seed;
  std::default_random_engine generator(seed());
  std::uniform_int_distribution<int> distribution(0,1));
 

  width = 10;
  width = 10;

distribution(generator);
}
