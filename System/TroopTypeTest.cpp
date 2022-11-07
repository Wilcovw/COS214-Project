/*#include <iostream>
#include <gtest/gtest.h>
#include "TroopType.h"

// cd "/Users/ruanrossouw/Library/Mobile Documents/com~apple~CloudDocs/University/2022/S2/COS214/Assignment/Code/" && g++ -std=c++14 TroopTypeTest.cpp  -lgtest -lgtest_main -pthread -o test && ./test

TEST(IntegerInputsSuite, testTroopTypeGetDamage) { 
  TroopType* testGeneral = new Generals();
  EXPECT_EQ(testGeneral->getDamage(), 15) << "Output for getDamage is incorrect";
}

TEST(IntegerInputsSuite, testTroopTypegetMaxHP) { 
  TroopType* testGeneral = new Generals();
  EXPECT_EQ(testGeneral->getMaxHP(), 15) << "Output for getMaxHP is incorrect";
}

TEST(IntegerInputsSuite, testTroopTypegetSpeed) { 
  TroopType* testGeneral = new Generals();
  
  EXPECT_EQ(testGeneral->getSpeed(), 15) << "Output for getSpeed is incorrect";
}

TEST(IntegerInputsSuite, testTroopTypegetType) { 
  TroopType* testGeneral = new Generals();
  EXPECT_EQ(testGeneral->getType(), theTroopTypes::theGenerals) << "Output for getType is incorrect";
}

TEST(IntegerInputsSuite, testTroopTypeaddMaxHP) { 
  TroopType* testGeneral = new Generals();
  testGeneral->addMaxHP(15);
  EXPECT_EQ(testGeneral->getMaxHP(), 30) << "Output for addMaxHP and getMaxHP is incorrect";
}

TEST(IntegerInputsSuite, testTroopTypeaddDamage) { 
  TroopType* testGeneral = new Generals();
  testGeneral->addDamage(15);
  EXPECT_EQ(testGeneral->getDamage(), 30) << "Output for addDamage and getDamage is incorrect";
}

TEST(IntegerInputsSuite, testTroopTypechangeType) { 
  TroopType* testTroop = new Generals();
  testTroop = testTroop->changeType(theTroopTypes::theMedics);
  EXPECT_EQ(testTroop->getType(), theTroopTypes::theMedics) << "Output for addDamage and getDamage is incorrect";
}

int main(int argc, char **argv) {
  //testing::InitGoogleTest(&argc, argv);
  //return RUN_ALL_TESTS();
}*/