#ifndef __GENERALENEMY_H__
#define __GENERALENEMY_H__

#include "enemy.h"

class GeneralEnemy: public Enemy
{
  public:
    void accept(Player*);
    void makeMove();
    ~GeneralEnemy();
};

#endif
