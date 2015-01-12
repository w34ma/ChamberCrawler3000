#ifndef __HUMAN_H_
#define __HUMAN_H_

#include <iostream>
#include "player.h"

using namespace std;

class Potion;
class Treasure;

class Human:public Player{
   public:
     void visit(Potion*);
     void visit(Treasure*);
     Human();
     ~Human();
};

#endif
