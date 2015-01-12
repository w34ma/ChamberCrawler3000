#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "character.h"
#include <string>
#include <iostream>

using namespace std;

class Player;

class Enemy:public Character{
  protected:
   bool Hostile;
  public:
   virtual void accept(Player*) = 0;
   virtual void makeMove() = 0;
   void visit(Player*);
   void notifyFloor();
   void setHostile(bool);
   virtual ~Enemy() = 0;   
};

#endif
