#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle
{


 public:
  Obstacle();
  int getWidth();
  int getLength();
  int getX();
  int getY();


 private:
  int width;
  int length;
  int x;
  int y;
};

#endif /* OBSTACLE_H */
