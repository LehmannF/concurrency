#ifndef TILE_H
#define TILE_H

#include <pthread.h>
#include <unistd.h>
#include "EnumTile.h"

class Tile
{
  
 private:
  Element element;
  pthread_mutex_t mutex;

 public:
  Tile();
  Element getElement();
  void setElement(Element);
  void lock();
  void unlock();
  
};

#endif /* TILE_H */
