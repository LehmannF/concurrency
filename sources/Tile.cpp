#include "Tile.h"

Tile::Tile() {
  element = Empty;
  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
}

Element Tile::getElement() {
  return element;
}

void Tile::setElement(Element element) {
  this->element = element;
}

void Tile::lock() {
  pthread_mutex_lock(&mutex);
}

void Tile::unlock() {
  pthread_mutex_unlock(&mutex);
}
