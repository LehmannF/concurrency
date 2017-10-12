#include <iostream>
#include "gtest/gtest.h"

#include "../sources/Terrain.h"

TEST(Terrain, defineContext){
  Terrain terrain;
}

TEST(Terrain, shouldBeAborder){
  Terrain terrain;
  EXPECT_EQ(true, terrain.isBorder(512,1));
  EXPECT_EQ(true, terrain.isBorder(512,128));
}

TEST(Terrain, shouldNotBeAborder){
  Terrain terrain;
  EXPECT_EQ(false, terrain.isBorder(0,0));
  EXPECT_EQ(false, terrain.isBorder(1,0));
  EXPECT_EQ(false, terrain.isBorder(0,1));
  EXPECT_EQ(false, terrain.isBorder(1,1));
  EXPECT_EQ(false, terrain.isBorder(511,1));
}
