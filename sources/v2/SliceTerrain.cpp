//
// Created by florian on 08/12/2017.
//

#include <cmath>
#include <cerrno>
#include <iostream>
#include "SliceTerrain.h"
#include "EnumTile.h"

SliceTerrain::SliceTerrain(int topLeftX, int topRightX, int height, Terrain& terrain) : topLeftX(topLeftX), topRightX(topRightX), height(height), terrain(terrain) {

}

void SliceTerrain::run() {
    while (!terrain.allCrowdEvacuate()) {
        for (int y = 0; y < height; ++y) {
            for (int x = topLeftX; x < topRightX; ++x) {
                if (((x == 0 && y == 0) || (x == 0 && y == 1) ||(x == 1 && y == 0)) && terrain.getTile(x, y)->getElement() == Element::Person) {
                    terrain.getTile(x, y)->setElement(Element::Empty);
                    terrain.incrementCompteurPersonOut();
                }
                else if (terrain.getTile(x, y)->getElement() == Element::Person) {
                    int xNext, yNext;
                    double distance = std::numeric_limits<double>::max();
                    checkTile(x, y - 1, xNext, yNext, distance);
                    checkTile(x - 1, y - 1, xNext, yNext, distance);
                    checkTile(x - 1, y + 1, xNext, yNext, distance);
                    checkTile(x - 1, y, xNext, yNext, distance);
                    checkTile(x, y + 1, xNext, yNext, distance);
                    checkTile(x + 1, y - 1, xNext, yNext, distance);
                    checkTile(x + 1, y, xNext, yNext, distance);
                    checkTile(x + 1, y + 1, xNext, yNext, distance);

                    // check if the case is empty and is not outside of the border
                    if (pthread_mutex_trylock(terrain.getTile(xNext, yNext)->getMutex()) != EBUSY) {
                        if (terrain.getTile(xNext, yNext)->getElement() == Element::Empty && isOutside(xNext, yNext) &&
                            !terrain.isBorder(x, y)) {
                            move(x, y, xNext, yNext);
                        } else if (terrain.getTile(xNext, yNext)->getElement() == Element::Empty &&
                                   !terrain.isBorder(x, y)) {
                            move(x, y, xNext, yNext);
                        }
                        terrain.getTile(xNext, yNext)->unlock();
                    }


                }
            }
        }
    }
}

bool SliceTerrain::isOutside(int x, int y) {
    return !(topLeftX <= x && topRightX > x);
}

double SliceTerrain::calculDistanceSortie00(int x, int y){
    return sqrt(std::pow((0 -x),2)+std::pow((0 -y),2));
}
double SliceTerrain::calculDistanceSortie01(int x, int y){
    return sqrt(std::pow((0 -x),2)+std::pow((1 -y),2));
}
double SliceTerrain::calculDistanceSortie10(int x, int y){
    return sqrt(std::pow((1 -x),2)+std::pow((0 -y),2));
}

void SliceTerrain::checkTile(int i,int j,int& xNext,int& yNext,double& distance){
    if(!terrain.isBorder(i,j)){
        if((terrain.getTile(i,j))->getElement() != Element::Obstacle){
            if(calculDistanceSortie00(i,j) < distance ){
                distance = calculDistanceSortie00(i,j);
                xNext = i;
                yNext = j;
            }
            if(calculDistanceSortie01(i,j) < distance ){
                distance = calculDistanceSortie01(i,j);
                xNext = i;
                yNext = j;
            }
            if(calculDistanceSortie10(i,j) < distance ){
                distance = calculDistanceSortie10(i,j);
                xNext = i;
                yNext = j;
            }
        }
    }
}

void SliceTerrain::move(int x, int y, int xNext, int yNext) {
    terrain.getTile(xNext,yNext)->setElement(Element::Person);
    terrain.getTile(x,y)->setElement(Element::Empty);
    //std::cout << "La personne s'est déplacée de "<< "(" << x << "," << y << ")" <<  "en" << "(" << xNext << "," << yNext << ")" << std::endl;
}
