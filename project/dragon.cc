#include "dragon.h"
#include <string>
#include <iostream>
#include "player.h"
#include "floor.h"
using namespace std;

void Dragon::setTreasure(Treasure *t)
{
  this->t = t;
}

Dragon::Dragon()
{
  HP = 150;
  Atk = 20;
  Def = 20;
  Hostile = false;
}

void Dragon::accept(Player* p){
   HP -= ((100 / (100 + Def)) * p->getAtk()) + 1;
   if (HP <= 0)
   {
     this->notifyFloor();
     this->notifyTreasure();
   }
   else
     cout << "Dragon is attacked. HP remains " << HP << "." << endl;
}

void Dragon::notifyTreasure(){
   t->CanBePicked = true;
}

void Dragon::makeMove(){   
  if (this->Hostile == true)
  {
    for (int i = this->getX()-1; i < this->getX()+2; i++)
      for (int j = this->getY()-1; j < this->getY()+2; i++)
        if (f->getDisplay()[i][j] == '@')
          this->visit(f->p);
  }
}

Dragon::~Dragon(){}
