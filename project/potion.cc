#include "potion.h"
#include <string>
#include <iostream>
#include "human.h"
#include "dwarf.h"
#include "orc.h"
#include "elves.h"
#include "floor.h"

using namespace std;



void Potion::notifyFloor()
{
  f->beingNotified(this);
}

Potion::Potion(int val,string name){
    this->Value = val;
    this->name = name;
    this->Revealed = 0;
}

void Potion::accept(Human* h){
    if(getName() == "RH"){
       h->addHP(10);
    }
    if(getName() == "BA"){
       h->addTempAtk(5);
    }
    if(getName() == "BD"){
       h->addTempDef(5);
    }
    if(getName() == "PH"){
       h->addHP(-10);
    }
    if(getName() == "WA"){
       h->addTempAtk(-5);
    }
    if(getName() == "WD"){
       h->addTempDef(-5);
    }
    notifyFloor();
}

void Potion::accept(Dwarf* d){
    if(getName() == "RH"){
       d->addHP(10);
    }
    if(getName() == "BA"){
       d->addTempAtk(5);
    }
    if(getName() == "BD"){
       d->addTempDef(5);
    }
    if(getName() == "PH"){
       d->addHP(-10);
    }
    if(getName() == "WA"){
       d->addTempAtk(-5);
    }
    if(getName() == "WD"){
       d->addTempDef(-5);
    }
    notifyFloor();
}

void Potion::accept(Orc* o){
    if(getName() == "RH"){
       o->addHP(10);
    }
    if(getName() == "BA"){
       o->addTempAtk(5);
    }
    if(getName() == "BD"){
       o->addTempDef(5);
    }
    if(getName() == "PH"){
       o->addHP(-10);
    }
    if(getName() == "WA"){
       o->addTempAtk(-5);
    }
    if(getName() == "WD"){
       o->addTempDef(-5);
    }
    notifyFloor();
}

void Potion::accept(Elves* e){
    if(getName() == "RH"){
       e->addHP(10);
    }
    if(getName() == "BA"){
       e->addTempAtk(5);
    }
    if(getName() == "BD"){
       e->addTempDef(5);
    }
    if(getName() == "PH"){
       e->addHP(10);
    }
    if(getName() == "WA"){
       e->addTempAtk(5);
    }
    if(getName() == "WD"){
       e->addTempDef(5);
    }
    notifyFloor();
}

bool Potion::getRevealed(){
    return this->Revealed;       
}

void Potion::setRevealed(){
    this->Revealed = 1;
}

string Potion::getName(){
    return this->name;
}

void Potion::makeMove()
{
  for (int i = getX()-1; i < getX()+2; i++)
  {
    for (int j = getY()-1; j < getY()+2; j++)
    {
      if (f->getDisplay()[i][j] == '@')
      {
        if (Revealed == true)
        {
          cout << "PC sees a " << name << "." << endl;
        }
        else
        {
          cout << "PC sees a potion." << endl;
        }
      }
    }
  }
}

Potion::~Potion()
{}
