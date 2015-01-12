#include "player.h"
#include "floor.h"
#include <iostream>
using namespace std;


void Player::notifyFloor()
{
  f->beingNotified(this);
}

bool Player::isDead()
{
  return dead;
}

void Player::setDeath()
{
  dead = true;
}

void Player::addGold(int amount)
{
  Gold += amount;
}

int Player::getGold()
{
  return Gold;
}

void Player::visit(Enemy* e)
{
  e->accept(this);
}

void Player::accept(Enemy* e)
{
  HP -= ((100 / (100 + Def)) * e->getAtk()) + 1;
  if (HP <= 0)
    notifyFloor();
}

void Player::addTempAtk(int amount)
{
  TempAtk += amount;
}

void Player::addTempDef(int amount)
{
  TempDef += amount;
}

void Player::clearTemp()
{
  TempAtk = 0;
  TempDef = 0;
}

int Player::getAtk()
{
  if (Atk+TempAtk > 0)
    return Atk + TempAtk;
  else
    return 0;
}

int Player::getDef()
{
  if (Def+TempDef > 0)
    return Def + TempDef;
  else
    return 0;
}

Player::~Player()
{}
