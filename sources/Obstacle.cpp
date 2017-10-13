#include <random>

#include "Obstacle.h"

Obstacle::Obstacle() {

  // std::random_device seed;
  // std::default_random_engine generator(seed());
  // std::uniform_int_distribution<int> distribution(0,1);
 

  width = 10;
  length = 10;
  x = 30;
  y = 30;


}

int Obstacle::getWidth() {
  return width;
}

int Obstacle::getLength() {
  return length;
}

int Obstacle::getX() {
  return x;
}

int Obstacle::getY() {
  return y;
}
