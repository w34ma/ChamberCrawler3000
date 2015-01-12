#include "human.h"
#include "potion.h"
#include "treasure.h"

#include <iostream>

using namespace std;

void Human::visit(Potion* p)
{
  p->accept(this);
}

void Human::visit(Treasure* p)
{
  p->accept(this);
}

Human:: Human(){
   this->HP = 140;
   this->MaxHP = 140;
   this->Atk = 20;
   this->Def = 20;
   
   dead = false;
   Gold = 0;
   TempAtk = 0;
   TempDef = 0;
}

Human::~Human(){}
