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
	while(x != 0 || y!= 0){
	  Tile* mini = terrain->getTile(x,y);
		double distance = 10000;
		int xNext;
		int yNext;

		//détermine la case la plus proche de la sortie
		
		if(!(*(this->terrain)).isBorder(x,y-1)){
			if((*(*(this->terrain)).getTile(x,y-1)).getElement() != Element::Obstacle){
				if(calculDistanceSortie(x,y-1) < distance ){
					distance = calculDistanceSortie(x,y-1);
					mini = terrain->getTile(x,y-1);
					xNext = x;
					yNext = y-1;
				}
			}
		}
		if(!(*(this->terrain)).isBorder(x-1,y-1)){
			if((*(*(this->terrain)).getTile(x-1,y-1)).getElement() != Element::Obstacle){
				if(calculDistanceSortie(x-1,y-1) < distance ){
					distance = calculDistanceSortie(x-1,y-1);
					mini = terrain->getTile(x-1,y-1);
					xNext = x-1;
					yNext = y-1;
				}
			}
		}
		if(!(*(this->terrain)).isBorder(x-1,y+1)){
			if((*(*(this->terrain)).getTile(x-1,y+1)).getElement() != Element::Obstacle){
				if(calculDistanceSortie(x-1,y+1) < distance ){
					distance = calculDistanceSortie(x-1,y+1);
					mini = terrain->getTile(x-1,y+1);
					xNext = x-1;
					yNext = y+1;
				}
			}
		}
		if(!(*(this->terrain)).isBorder(x-1,y)){
			if((*(*(this->terrain)).getTile(x-1,y)).getElement() != Element::Obstacle){
				if(calculDistanceSortie(x-1,y) < distance ){
					distance = calculDistanceSortie(x-1,y);
					mini = terrain->getTile(x-1,y);
					xNext = x-1;
					yNext = y;
				}
			}
		}
		if(!(*(this->terrain)).isBorder(x,y+1)){
			if((*(*(this->terrain)).getTile(x,y+1)).getElement() != Element::Obstacle){
				if(calculDistanceSortie(x,y+1) < distance ){
					distance = calculDistanceSortie(x,y+1);
					mini = terrain->getTile(x,y+1);
					xNext = x;
					yNext = y+1;
				}
			}
		}
		if(!(*(this->terrain)).isBorder(x+1,y-1)){
			if((*(*(this->terrain)).getTile(x+1,y-1)).getElement() != Element::Obstacle){
				if(calculDistanceSortie(x+1,y-1) < distance ){
					distance = calculDistanceSortie(x+1,y-1);
					mini = terrain->getTile(x+1,y-1);
					xNext = x+1;
					yNext = y-1;
				}
			}
		}
		if(!(*(this->terrain)).isBorder(x+1,y)){
			if((*(*(this->terrain)).getTile(x+1,y)).getElement() != Element::Obstacle){
				if(calculDistanceSortie(x+1,y) < distance ){
					distance = calculDistanceSortie(x+1,y);
					mini = terrain->getTile(x+1,y);
					xNext = x+1;
					yNext = y;
				}
			}
		}
		if(!(*(this->terrain)).isBorder(x+1,y+1)){
			if((*(*(this->terrain)).getTile(x+1,y+1)).getElement() != Element::Obstacle){
				if(calculDistanceSortie(x+1,y+1) < distance ){
					distance = calculDistanceSortie(x+1,y+1);
					mini = terrain->getTile(x+1,y+1);
					xNext = x+1;
					yNext = y+1;
				}
			}
		}
		
		std::cout << "Personne n°" <<id << " veut aller en x:"<< xNext<<" y:"<<yNext<<std::endl;
		// critical section
		mini->lock();
		std::cout << "Personne n°" <<id <<" à locké x:"<< xNext<<" y:"<<yNext<<std::endl;
		while(mini->getElement()!=Element::Empty){}
		//on doit changer les coordonnées de personne à l'aide d'un déplacement nord; sud ...
		//fonction membre		deplacement.....
		mini->setElement(Element::Person);
		(terrain->getTile(x,y))->setElement(Element::Empty);
		
		x= xNext;
		y= yNext;
		
		if(x==0 && y==0){
			mini->setElement(Element::Empty);
		}
		std::cout << "Personne n°" <<id <<" s'est déplacé en x:"<< xNext<<" y:"<<yNext<<std::endl;
		
		mini->unlock();
		// end of critical section
		
		std::cout << "Personne n°" <<id <<" à délocké x:"<< xNext<<" y:"<<yNext<<std::endl;


		
	}
	return NULL;
}


double Personne::calculDistance(int x, int y){
	return sqrt(std::pow((this->x -x),2)+std::pow((this->y -y),2));
}

double Personne::calculDistanceSortie(int x, int y){
	return sqrt(std::pow((0 -x),2)+std::pow((0 -y),2));
}
	
	
// 1) Calcul de distance entre l'emplacement courant et la sortie
// 2) Calcul de distance entre chacune des cases autour et la sortie
// 3) Ne prendre que les cases qui ont une distance < a celle courante
// 4) Parmis ces cases, executer le deplacement vers la 1ere possible


