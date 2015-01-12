#include "troll.h"

#include <iostream>

using namespace std;

Troll:: Troll(){
   this->HP =120;
   this->MaxHP = 120;
   this->Atk = 25;
   this->Def = 15;

   Hostile = false;
}

Troll::~Troll(){}
