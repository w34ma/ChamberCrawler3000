#ifndef __ORC_H_
#define __ORC_H_

#include <iostream>
#include "player.h"
using namespace std;

class Potion;
class Treasure;

class Orc:public Player{
   public:
     void visit(Potion* p);
     void visit(Treasure* t);
     Orc();
     ~Orc();
};

#endif
