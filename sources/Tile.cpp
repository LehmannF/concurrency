#include "Tile.h"

Tile::Tile() {
  element = Element::Empty;
  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
  pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
}

Element Tile::getElement() {
  return element;
}


void Tile::setElement(Element element) {
  this->element = element;
}

void Tile::removePerson() {
    pthread_mutex_lock(&mutex);
    if (Element::Obstacle != element) {
        element = Element::Empty;
        pthread_cond_signal(&condition);
    }
    pthread_mutex_unlock(&mutex);
}


void Tile::lock() {
    pthread_mutex_lock(&mutex);
}

void Tile::unlock() {
    pthread_mutex_unlock(&mutex);
}

pthread_mutex_t* Tile::getMutex() {
    return &mutex;
}

pthread_cond_t* Tile::getCondition() {
    return &condition;
}
