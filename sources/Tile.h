#ifndef TILE_H
#define TILE_H

#include <pthread.h>
#include <unistd.h>

class Tile
{
  
 private:
  Element element;
  pthread_mutex_t mutex;

 public:
  Tile();
  
};

#endif /* TILE_H */
