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
    pthread_cond_t condition;

 public:
  Tile();
  Element getElement();
  void setElement(Element);
  void removePerson();
  void lock();
  void unlock();
  pthread_mutex_t* getMutex();
  pthread_cond_t* getCondition();
};

#endif /* TILE_H */
