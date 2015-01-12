#include <cstdlib>
#include "treasure.h"
#include <string>
#include <iostream>
#include "dragon.h"
#include "floor.h"
using namespace std;


void Treasure::notifyFloor()
{
  f->beingNotified(this);
}

void Treasure::setDragon(Dragon *d)
{
  this->d = d;
}

Treasure::Treasure(int value)
{
  this->Value = value;
  if (value == 6)
    CanBePicked = false;
  else
    CanBePicked = true;
}

void Treasure::accept(Human* h){
     h->addGold(Value);
     notifyFloor();
}

void Treasure::accept(Dwarf* d){
    d->addGold(Value * 2);
    notifyFloor();
}

void Treasure::accept(Elves* e){
    e->addGold(Value);
    notifyFloor();
}

void Treasure::accept(Orc* o){
    o->addGold(Value * 1/2);
    notifyFloor();
}

void Treasure::notifyDragon(bool status){
   d->setHostile(status);
}

int Treasure::getValue(){
   return this->Value;
}

void Treasure::makeMove()
{
  if (Value == 6)
  {
    bool flag = false;
    for (int i = getX(); i < getX()+2; i++)
      for (int j = getY(); j < getY()+2; j++)
        if (f->getDisplay()[i][j] == '@')
          flag = true;
    notifyDragon(flag);
  } 
}

void Treasure::adddragon(char** f,int r,int c){
     Dragon* dd = new Dragon;
     int x,y;
     x = rand() % 1 + -1;
     y = rand() % 1 + -1;
     while(f[r+x][c+y] != '.'){
       x = rand() % 1 + -1;
       y = rand() % 1 + -1;
    }
    d = dd;
    d->setX(r+x);
    d->setY(c+y);
    f[r+x][c+y] = 'D';
}

Treasure::~Treasure(){}
