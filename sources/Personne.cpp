#include "Personne.h"
#include "Terrain.h"
#include "EnumTile.h"
#include <random>
#include <iostream>

#define _ROWS 128
#define _COLUMNS 512

Personne::Personne(Terrain& terrain, int id){
	(*this).id=id;
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
	
	std::cout << "Personne n°" <<id<< " implanté en x:"<<x<< " y:"<<y<<std::endl;
	
}

void* Personne::run(){
	while((x != 0 || y!= 0) && (x != 0 || y!= 1) && (x != 1 || y!= 0)){
	  Tile* mini = terrain->getTile(x,y);
		double distance = 10000;
		int xNext;
		int yNext;

		//détermine la case la plus proche de la sortie
		checkTile(x,y-1,xNext,yNext,distance,mini);
		checkTile(x-1,y-1,xNext,yNext,distance,mini);
		checkTile(x-1,y+1,xNext,yNext,distance,mini);
		checkTile(x-1,y,xNext,yNext,distance,mini);
		checkTile(x,y+1,xNext,yNext,distance,mini);
		checkTile(x+1,y-1,xNext,yNext,distance,mini);
		checkTile(x+1,y,xNext,yNext,distance,mini);
		checkTile(x+1,y+1,xNext,yNext,distance,mini);


		// critical section
		mini->lock();

		while(mini->getElement()!=Element::Empty){}
		//on doit changer les coordonnées de personne à l'aide d'un déplacement nord; sud ...
		//fonction membre		deplacement.....
		mini->setElement(Element::Person);
		(terrain->getTile(x,y))->setElement(Element::Empty);
		
		x= xNext;
		y= yNext;
		
		if((x==0 && y==0) || (x==0 && y==1) || (x==1 && y==0)){
			mini->setElement(Element::Empty);
		}

		
		mini->unlock();
		// end of critical section
		



		
	}
	return NULL;
}


double Personne::calculDistance(int x, int y){
	return sqrt(std::pow((this->x -x),2)+std::pow((this->y -y),2));
}

double Personne::calculDistanceSortie00(int x, int y){
	return sqrt(std::pow((0 -x),2)+std::pow((0 -y),2));
}
double Personne::calculDistanceSortie01(int x, int y){
	return sqrt(std::pow((0 -x),2)+std::pow((1 -y),2));
}
double Personne::calculDistanceSortie10(int x, int y){
	return sqrt(std::pow((1 -x),2)+std::pow((0 -y),2));
}

void Personne::checkTile(int i,int j,int& xNext,int& yNext,double& distance,Tile*& mini){
	if(!(*(this->terrain)).isBorder(i,j)){
			if((*(*(this->terrain)).getTile(i,j)).getElement() != Element::Obstacle){
				if(calculDistanceSortie00(i,j) < distance ){
					distance = calculDistanceSortie00(i,j);
					mini = terrain->getTile(i,j);
					xNext = i;
					yNext = j;
				}
				if(calculDistanceSortie01(i,j) < distance ){
					distance = calculDistanceSortie01(i,j);
					mini = terrain->getTile(i,j);
					xNext = i;
					yNext = j;
				}
				if(calculDistanceSortie10(i,j) < distance ){
					distance = calculDistanceSortie10(i,j);
					mini = terrain->getTile(i,j);
					xNext = i;
					yNext = j;
				}
			}
		}
}
	
	
// 1) Calcul de distance entre l'emplacement courant et la sortie
// 2) Calcul de distance entre chacune des cases autour et la sortie
// 3) Ne prendre que les cases qui ont une distance < a celle courante
// 4) Parmis ces cases, executer le deplacement vers la 1ere possible


