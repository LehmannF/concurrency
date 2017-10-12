#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle
{
 private:
  int width;
  int length;
  int x;
  int y;

 public:
  Obstacle();
  Obstacle(const Obstacle& obstacle);
}

#endif /* OBSTACLE_H */
