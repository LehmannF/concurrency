#include <iostream>
#include "gtest/gtest.h"

#include "../sources/v1/Personne.h"
#include "../sources/v1/Terrain.h"

TEST(Personne, defineContext){
	Terrain terrain;
	Personne personne(terrain);
}

TEST(Personne, distanceIsDefine){
	Terrain terrain;
	Personne personne(terrain);
	EXPECT_TRUE(personne.calculDistance(-1,-1) > 0);

}