#include "orc.h"
#include "potion.h"
#include "treasure.h"

#include <iostream>

using namespace std;

void Orc::visit(Potion* p)
{
  p->accept(this);
}

void Orc::visit(Treasure* t)
{
  t->accept(this);
}

Orc:: Orc(){
   this->HP = 180;
   this->MaxHP = 180;
   this->Atk = 30;
   this->Def = 25;
   
   dead = false;
   Gold = 0;
   TempAtk = 0;
   TempDef = 0;
}

Orc::~Orc(){}
