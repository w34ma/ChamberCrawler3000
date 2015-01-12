#include "dwarf.h"
#include "potion.h"
#include "treasure.h"
#include <iostream>

using namespace std;

void Dwarf::visit(Potion* p)
{
  p->accept(this);
}

void Dwarf::visit(Treasure *t)
{
  t->accept(this);
}

Dwarf:: Dwarf(){
   this->HP = 100;
   this->MaxHP = 100;
   this->Atk = 20;
   this->Def = 30;

   dead = false;
   Gold = 0;
   TempAtk = 0;
   TempDef = 0;
}

Dwarf::~Dwarf(){}
