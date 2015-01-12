#ifndef __DWARF_H_
#define __DWARF_H_

#include <iostream>
#include "player.h"
using namespace std;

class Potion;
class Treasure;

class Dwarf:public Player{
   public:
     void visit(Potion*);
     void visit(Treasure*);
     Dwarf();
     ~Dwarf();
};

#endif
