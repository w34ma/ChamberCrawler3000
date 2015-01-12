#ifndef __WEREWOLF_H_
#define __WEREWOLF_H_

#include <iostream>
#include "generalenemy.h"
using namespace std;

class Werewolf:public GeneralEnemy{
   public:
     Werewolf();
     ~Werewolf();
};

#endif
