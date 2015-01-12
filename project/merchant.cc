#include "merchant.h"
#include "floor.h"
#include <cstdlib>
using namespace std;

Merchant::Merchant()
{
  HP = 30;
  Atk = 70;
  Def = 5;
  Hostile = 0;
}

void Merchant::accept(Player* p)
{
  HP -= 1 + ((100/(100+Def))*p->getAtk()); 
  if (HP <= 0)
  {
    this->notifyFloor();
  }
  else
  {
    cout << "Merchant is attacked. HP remains " << HP << "." << endl;
  }
}

void Merchant::notifyFloor()
{
  f->beingNotified(this);
}

void Merchant::makeMove()
{
  bool flag = false;
  for (int i = getX()-1; i < getX()+2; i++)
    for (int j = getY()-1; j < getY()+2; j++)
      if (f->getDisplay()[i][j] == '@')
        flag = true;
  if (this->Hostile == false || flag == false)
  {
    bool success = false; 
    while (success == false)
    {
      int dir;
      dir = rand() % 8 + 1;
      if (dir == 1 && f->getDisplay()[getX()][getY()+1] == '.')
      {
        f->makeMove(this,"ea");
        success = true;
      }
      else if (dir == 2 && f->getDisplay()[getX()][getY()-1] == '.')
      {
        f->makeMove(this,"we");
        success = true;
      }
      else if (dir == 3 && f->getDisplay()[getX()+1][getY()] == '.')
      {
        f->makeMove(this,"so");
        success = true;
      }
      else if (dir == 4 && f->getDisplay()[getX()-1][getY()] == '.')
      {
        f->makeMove(this,"no");
        success = true;
      }
      else if (dir == 5 && f->getDisplay()[getX()+1][getY()+1] == '.')
      {
        f->makeMove(this,"se");
        success = true;
      }
      else if (dir == 6 && f->getDisplay()[getX()-1][getY()+1] == '.')
      {
        f->makeMove(this,"ne");
        success = true;
      }
      else if (dir == 7 && f->getDisplay()[getX()+1][getY()-1] == '.')
      {
        f->makeMove(this,"sw");
        success = true;
      }
      else if (dir == 8 && f->getDisplay()[getX()-1][getY()-1] == '.')
      {
        f->makeMove(this,"nw");
        success = true;
      }
    }
  }
  else
    this->visit(f->p);
}

Merchant::~Merchant(){}
