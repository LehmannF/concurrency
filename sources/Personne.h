#ifndef PERSONNE_H
#define PERSONNE_H

#include "Terrain.h"
#include "Tile.h"

#include <random>

class Personne{
	
	private:
	Terrain* terrain = nullptr;
	int id;
	int x;
	int y;
	void checkTile(int i,int j,int& xNext,int& yNext,double& distance,Tile*& mini);
	
	public:
	Personne(Terrain& terrain, int id);
	
	void* run();
	
	double calculDistance(int x, int y);
	double calculDistanceSortie00(int x, int y);
	double calculDistanceSortie01(int x, int y);
	double calculDistanceSortie10(int x, int y);
};

#endif