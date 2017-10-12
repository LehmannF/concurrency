#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "Tile.h"

class Terrain
{

 public:
  Terrain();
  Terrain(const Terrain& terrain);
  bool isBorder(int x, int y);
  int getNumberOfRows();
  int getNumberOfColumns();
  Tile* getTile(int, int);
  
 private:
  std::vector<std::vector<Tile> > terrain;

};

#endif /* TERRAIN_H */
