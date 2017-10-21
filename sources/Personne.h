#ifndef PERSONNE_H
#define PERSONNE_H

#include "Terrain.h"

#include <random>

class Personne{
	
	private:
	Terrain* terrain = nullptr;
	int id;
	
	int x;
	int y;
	
	public:
	Personne(Terrain& terrain, int id);
	
	void* run();
	
	double calculDistance(int x, int y);
	double calculDistanceSortie(int x, int y);
};

#endif