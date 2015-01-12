#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "character.h"
#include <string>
#include "enemy.h"
#include <vector>

class Floor;
class Potion;
class Treasure;
class Player: public Character
{
  protected:
    int Gold;
    int TempAtk;
    int TempDef;
    bool dead;
  public:
    virtual void visit(Potion*) = 0;
    virtual void visit(Treasure*) = 0;
    void visit(Enemy*);
    void notifyFloor();
    void setDeath();
    bool isDead();
    void addGold(int);
    int getGold();
    void accept(Enemy*);
    void addTempAtk(int);
    void addTempDef(int);
    void clearTemp();
    int getAtk();
    int getDef();
    virtual ~Player() = 0;
};

#endif
