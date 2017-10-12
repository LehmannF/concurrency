#include "Terrain.h"



#define _ROWS 128
#define _COLUMNS 512

using Row = std::vector<char>;
using Matrix = std::vector<Row>;

Terrain::Terrain() {
  Matrix terrain(_COLUMNS, Row(_ROWS));
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
