#ifndef __TREASURE_H_
#define __TREASURE_H_

#include <iostream>
#include "human.h"
#include "dwarf.h"
#include "orc.h"
#include "elves.h"
#include "dragon.h"

using namespace std;

class Floor;

class Treasure:public Object{
     int Value;
   public:
     Dragon* d;
     void notifyFloor();
     bool CanBePicked;
     Treasure(int);
     void setDragon(Dragon*);
     void accept(Human*);
     void accept(Dwarf*);
     void accept(Elves*);
     void accept(Orc*);
     void notifyDragon(bool);
     int getValue();
     void makeMove();
     void adddragon(char**,int,int);
     virtual ~Treasure();
};

#endif
