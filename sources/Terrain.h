#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>

class Terrain
{

 public:
  Terrain();
  bool isBorder(int x, int y);
  
 private:
  std::vector<std::vector<char> > _terrain;
  
};

#endif /* TERRAIN_H */
