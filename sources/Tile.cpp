#include "Tile.h"

Tile::Tile() {
  element = Empty;
  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
}
