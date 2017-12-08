#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "Tile.h"
#include "Obstacle.h"
#include "Obstacle.h"


class Terrain
{

 public:
  Terrain(int);
  Terrain(const Terrain&);
  bool isBorder(int, int);
  int getNumberOfRows();
  int getNumberOfColumns();
  Tile *getTile(int, int);
  void addObstacle(Obstacle);
    bool allCrowdEvacuate();
    void incrementCompteurPersonOut();
private:
  std::vector<std::vector<Tile> > terrain;
    int compteurPersonne;


};

#endif /* TERRAIN_H */
