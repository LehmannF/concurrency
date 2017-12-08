#include "Terrain.h"


#define at(x,y) at(x).at(y)
#define _ROWS 128
#define _COLUMNS 512

using Row = std::vector<Tile>;
using Matrix = std::vector<Row>;

Terrain::Terrain() {
  this->terrain = Matrix(_COLUMNS, Row(_ROWS));
}

Terrain::Terrain(const Terrain& terrain){
  this->terrain = terrain.terrain;
}

bool Terrain::isBorder(int x, int y) {
  if (x==_COLUMNS || y== _ROWS)
    return true;
  if (x==-1 || y==-1)
    return true;
  if(x==-1 || y==-1)
    return true;
  return false;
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


