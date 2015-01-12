#include "enemy.h"
#include "floor.h"
#include <string>
#include <iostream>

using namespace std;

void Enemy::visit(Player* p)
{
  p->accept(this);
}

void Enemy::notifyFloor()
{
  f->beingNotified(this);
}


void Enemy::setHostile(bool status){
   this->Hostile = status;
}


Enemy::~Enemy(){
}
