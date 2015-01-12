#ifndef __DRAGON_H_
#define __DRAGON_H_

#include <iostream>
#include "enemy.h"

class Treasure;
class Player;
using namespace std;

class Dragon:public Enemy{
   public:
     Treasure *t;
     Dragon();
     void setTreasure(Treasure*);
     void accept(Player*);
     void notifyTreasure();
     void makeMove();
     ~Dragon();
};

#endif
