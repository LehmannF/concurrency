#include <iostream>
#include "gtest/gtest.h"

#include "../sources/Personne.h"
#include "../sources/Terrain.h"

TEST(Personne, defineContext){
	Terrain terrain;
	Personne personne(terrain);
}

TEST(Personne, distanceIsDefine){
	Terrain terrain;
	Personne personne(terrain);
	EXPECT_TRUE(personne.calculDistance(-1,-1) > 0);

}