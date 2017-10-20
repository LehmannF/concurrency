#include "Personne.h"
#include "Terrain.h"
#include "EnumTile.h"
#include <random>
#include <iostream>

#define _ROWS 128
#define _COLUMNS 512

Personne::Personne(Terrain& terrain){
	(*this).terrain=&terrain;
	
	do{
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::uniform_int_distribution<int> chooseX(0,_COLUMNS-1);
	std::uniform_int_distribution<int> chooseY(0,_ROWS-1);
	
	x= chooseX(generator);
	y= chooseY(generator);
	} while((*(*(this->terrain)).getTile(x,y)).getElement() != Empty);
	(*(*(this->terrain)).getTile(x,y)).setElement(Person);
	
}

bool deplacementNord(){
	return false;
	}
bool deplacementSud(){
	return false;
	}
bool deplacementOuest(){
	return false;
	}
bool deplacementEst(){
	return false;
	}
bool deplacementNordOuest(){
	return false;
	}
bool deplacementNordEst(){
	return false;
	}
bool deplacementSudOuest(){
	return false;
	}
bool deplacementSudEst(){
	return false;
	}
	
double Personne::calculDistance(int x, int y){
	return sqrt(std::pow((this->x -x),2)+std::pow((this->y -y),2));
}
	
	
// 1) Calcul de distance entre l'emplacement courant et la sortie
// 2) Calcul de distance entre chacune des cases autour et la sortie
// 3) Ne prendre que les cases qui ont une distance < a celle courante
// 4) Parmis ces cases, executer le deplacement vers la 1ere possible