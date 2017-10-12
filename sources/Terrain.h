#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>

class Terrain
{

 public:
  Terrain();
  Terrain(const Terrain& terrain);
  bool isBorder(int x, int y);
  
 private:
  std::vector<std::vector<char> > terrain;
  
};

#endif /* TERRAIN_H */
