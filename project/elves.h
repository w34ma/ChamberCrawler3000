#ifndef __ELVES_H_
#define __ELVES_H_

#include <iostream>
#include "player.h"
using namespace std;

class Potion;
class Treasure;

class Elves:public Player{
   public:
     void visit(Potion*);
     void visit(Treasure*);
     Elves();
     ~Elves();
};

#endif
