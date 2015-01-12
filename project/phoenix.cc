#include "phoenix.h"

#include <iostream>

using namespace std;

Phoenix:: Phoenix(){
   this->HP =50;
   this->MaxHP = 50;
   this->Atk = 35;
   this->Def = 20;

   Hostile = false;
}

Phoenix::~Phoenix(){}
