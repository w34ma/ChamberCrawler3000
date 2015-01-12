#ifndef __FLOOR_H_
#define __FLOOR_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "potion.h"
#include "enemy.h"
#include "treasure.h"
#include "factory.h"
using namespace std;

class Object;
class Player;
class Character;
class Merchant;

class Floor{     
     int Floornum;
     char** display;
     bool done;
  public:
     stringstream Action;
     Enemy* e[20];
     int numEnemy;
     Potion* po[10];
     int numPotion;
     Treasure* tr[10];
     int numTreasure;
     Player* p;
     void clear();
     Floor();
     bool isDone();
     void setDone(bool);
     void setPlayer(Player*);
     void beingNotified(Enemy*);
     void beingNotified(Merchant*);
     void beingNotified(Potion*);
     void beingNotified(Treasure*);
     void beingNotified(Player*);
     void makeMove(Character*,std::string);
     char** getDisplay();
     void init(Player*);
     void restart();
     void printScore();
     void tick();
     void quit();
     ~Floor();
};

#endif
