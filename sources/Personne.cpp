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
	} while((*(*(this->terrain)).getTile(x,y)).getElement() != Element::Empty);
	(*(*(this->terrain)).getTile(x,y)).setElement(Element::Person);
	
}

void Personne::run(){
	while(x != -1 && y!= -1){
	  Tile* mini = terrain->getTile(x,y);
		double distance = calculDistanceSortie(x,y);

		//détermine la case la plus proche de la sortie
		
		if(!(*(this->terrain)).isBorder(x,y-1) && (*(*(this->terrain)).getTile(x,y-1)).getElement() != Element::Obstacle){
			if(calculDistanceSortie(x,y-1) < distance ){
				distance = calculDistanceSortie(x,y-1);
				mini = terrain->getTile(x,y-1);
			}
		}
		
		// critical section
		mini->lock();
		while(mini->getElement()!=Element::Empty){}
		//on doit changer les coordonnées de personne à l'aide d'un déplacement nord; sud ...
		//fonction membre		deplacement.....
		mini->setElement(Element::Person);
		// ici c'est le x,y initial ??
		(terrain->getTile(x,y))->setElement(Element::Person);
		mini->unlock();


		
	}
	
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

double Personne::calculDistanceSortie(int x, int y){
	return sqrt(std::pow((-1 -x),2)+std::pow((-1 -y),2));
}
	
	
// 1) Calcul de distance entre l'emplacement courant et la sortie
// 2) Calcul de distance entre chacune des cases autour et la sortie
// 3) Ne prendre que les cases qui ont une distance < a celle courante
// 4) Parmis ces cases, executer le deplacement vers la 1ere possible


