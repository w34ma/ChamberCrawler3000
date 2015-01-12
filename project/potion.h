#ifndef __POTION_H_
#define __POTION_H_

#include <iostream>
#include <string>
#include "object.h"
using namespace std;

class Human;
class Dwarf;
class Elves;
class Orc;

class Potion:public Object{
     int Value;
     string name;
     bool Revealed;
   public:
     Potion(int,std::string);
     void notifyFloor();
     void accept(Human*);
     void accept(Dwarf*);
     void accept(Elves*);
     void accept(Orc*);
     bool getRevealed();
     void setRevealed();
     string getName();
     void makeMove();
     virtual ~Potion();
};

#endif
