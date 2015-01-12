#include "goblin.h"

#include <iostream>

using namespace std;

Goblin:: Goblin(){
   this->HP =70;
   this->MaxHP = 70;
   this->Atk = 5;
   this->Def = 10;

   Hostile = false;
}

Goblin::~Goblin(){}
