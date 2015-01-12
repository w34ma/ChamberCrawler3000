#include "elves.h"
#include "potion.h"
#include "treasure.h"

#include <iostream>

using namespace std;

void Elves::visit(Potion* p)
{
  p->accept(this);
}

void Elves::visit(Treasure *t)
{
  t->accept(this);
}

Elves:: Elves(){
   this->HP = 140;
   this->MaxHP = 140;
   this->Atk = 30;
   this->Def = 10;
   
   dead = false;
   Gold = 0;
   TempAtk = 0;
   TempAtk = 0;
}

Elves::~Elves(){}
