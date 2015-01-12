#ifndef __CHARACTER_H_
#define __CHARACTER_H_

#include <iostream>
#include "object.h"

using namespace std;

class Character: public Object{
   protected:
     int HP;
     int MaxHP;
     int Atk;
     int Def;
     int TempChar;
   public:
     void addHP(int);
     int getHP();
     char getTempChar();
     void setTempChar(char);
     virtual int getAtk();
     virtual int getDef();
     virtual ~Character() = 0;
};

#endif
