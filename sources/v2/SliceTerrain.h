//
// Created by florian on 08/12/2017.
//

#ifndef CROWD_MOVEMENT_SLICETERRAIN_H
#define CROWD_MOVEMENT_SLICETERRAIN_H


#include "Terrain.h"

class SliceTerrain {

private:
    int topLeftX, topRightX, height;
    Terrain& terrain;
    bool isOutside(int x, int y);

public:
    SliceTerrain(int topLeftX, int topRightX, int height, Terrain& terrain);
    void run();

    double calculDistanceSortie00(int x, int y);
    double calculDistanceSortie01(int x, int y);
    double calculDistanceSortie10(int x, int y);
    void checkTile(int i,int j,int& xNext,int& yNext,double& distance);

    void move(int x, int y, int next, int yNext);
};


#endif //CROWD_MOVEMENT_SLICETERRAIN_H
