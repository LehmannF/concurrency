#include "Terrain.h"
#include "Tile.h"


#define _ROWS 128
#define _COLUMNS 512

using Row = std::vector<Tile>;
using Matrix = std::vector<Row>;

Terrain::Terrain() {
  this->terrain = Matrix(_COLUMNS, Row(_ROWS));

  // for (int i = 0; i < _Rows; ++i)
  //   for (int j = 0; j < _COLUMNS; ++j)
  //     te


}

Terrain::Terrain(const Terrain& terrain){
  this->terrain = terrain.terrain;
}

bool Terrain::isBorder(int x, int y) {
  if (x==_COLUMNS || y== _ROWS)
    return true;
  if ((y==-1 && x>=2) || (y>=2 && x==-1) )
    return true;
  return false;
}

  
