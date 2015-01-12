#ifndef __FACTORY_H_
#define __FACTORY_H_

#include <iostream>

class Enemy;
class Potion;
class Treasure;
using namespace std;

class Factory{
   public:
     Enemy* CreateEnemy(char**);
     Potion* CreatePotion(char**);
     Treasure* CreateTreasure(char**);
     ~Factory();
};

#endif
