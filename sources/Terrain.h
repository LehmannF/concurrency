#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "Tile.h"
#include "Obstacle.h"


class Terrain
{

 public:
  Terrain();
  Terrain(const Terrain&);
  bool isBorder(int, int);
  int getNumberOfRows();
  int getNumberOfColumns();
  Tile *getTile(int, int);
  void addObstacle(Obstacle);
  
 private:
  std::vector<std::vector<Tile> > terrain;

};

#endif /* TERRAIN_H */
