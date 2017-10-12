#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>

class Terrain
{

 public:
  Terrain();
  
 private:
  std::vector<std::vector<char> > _terrain;
  
};

#endif /* TERRAIN_H */
