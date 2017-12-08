#include <random>
#include "Terrain.h"

#include "Obstacle.h"
#define at(x,y) at(x).at(y)
#define _ROWS 128
#define _COLUMNS 512

using Row = std::vector<Tile>;
using Matrix = std::vector<Row>;

Terrain::Terrain(int nbPerson) {
  this->terrain = Matrix(_COLUMNS, Row(_ROWS));
  compteurPersonne =nbPerson;
  Obstacle obstacle;
  addObstacle(obstacle);

  for (int i = 0; i < nbPerson; ++i) {
    int x , y;
    do{

      std::random_device seed;
      std::default_random_engine generator(seed());
      std::uniform_int_distribution<int> chooseX(0,_COLUMNS-1);
      std::uniform_int_distribution<int> chooseY(0,_ROWS-1);

      x= chooseX(generator);
      y= chooseY(generator);
    } while(terrain.at(x,y).getElement() != Element::Empty);
    terrain.at(x,y).setElement(Element::Person);
  }


}

Terrain::Terrain(const Terrain& terrain){
  this->terrain = terrain.terrain;
}

bool Terrain::isBorder(int x, int y) {
  if (x==_COLUMNS || y== _ROWS)
    return true;
  if (x==-1 || y==-1)
    return true;
  return x == -1 || y == -1;
}

int Terrain::getNumberOfRows() {
  return _ROWS;
}

int Terrain::getNumberOfColumns() {
  return _COLUMNS;
}

Tile* Terrain::getTile(int x, int y) {
  return &terrain.at(x,y);
}

void Terrain::addObstacle(Obstacle obstacle) {


  for (int i = obstacle.getX(); i < obstacle.getWidth() ; ++i)
    for (int j = obstacle.getY(); j < obstacle.getLength(); ++j)
      terrain.at(i,j).setElement(Element::Obstacle);

}

void Terrain::incrementCompteurPersonOut() {
  compteurPersonne--;
}

bool Terrain::allCrowdEvacuate() {
  return compteurPersonne == 0;
}
