#include "werewolf.h"

#include <iostream>

using namespace std;

Werewolf:: Werewolf(){
   this->HP =120;
   this->MaxHP = 120;
   this->Atk = 30;
   this->Def = 5;

   Hostile = false;
}

Werewolf::~Werewolf(){}
