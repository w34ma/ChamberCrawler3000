#include "vampire.h"

#include <iostream>

using namespace std;

Vampire:: Vampire(){
   this->HP =50;
   this->MaxHP = 50;
   this->Atk = 25;
   this->Def = 25;

   Hostile = false;
}

Vampire::~Vampire(){}
