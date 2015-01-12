#include "floor.h"
#include "enemy.h"
#include "player.h"
#include "potion.h"
#include "treasure.h"
#include "object.h"
#include "merchant.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Floor::~Floor()
{
  for (int r = 0; r < 25; r++)
    delete [] display[r];
  delete [] display;
}

bool Floor::isDone()
{
  return done;
}

void Floor::setDone(bool b)
{
  done = b;
}

Floor::Floor(){
   Floornum = 1;
   display = new char* [25];
   for(int r = 0;r<25;r++){
     display[r] = new char [79];
     for(int c = 0;c<79;c++){
        display[r][c] = ' ';
     }
   }//initialize all the position to space
   done = false;
   numEnemy = 0;
   numPotion = 0;
   numTreasure = 0;
}

void Floor::clear(){
   for(int r = 0;r<25;r++){
        display[r][0] = '|';
        display[r][78] = '|';
   }
   for(int i = 1;i<=77;i++){
        display[0][i] = '-';
    	display[24][i] = '-';
   } 
   for(int i =2;i<=7;i++){
	display[i][2] = '|';
    	display[i][29] ='|';
  }
   for(int r = 2;r<=7;r++){
      for(int c = 3;c<=28;c++){
         if(r == 2||r==7){
           display[r][c] = '-';
         }else{
           display[r][c] = '.';
         }   
      }
  }
  //chamber 1
   for(int i =14;i<=22;i++){
        display[i][3] = '|';
    	display[i][25] = '|';
   }
   for(int r = 14;r<=22;r++){
       for(int c = 4;c<=24;c++){
          if(r == 14 || r == 22){
             display[r][c]='-';
          }else{
             display[r][c]='.';
          }
       }
   } 
  //chamber 2
   for(int r = 9;r<=13;r++){
        display[r][37] = '|';
        display[r][50] = '|';
   }
   for(int r = 9;r<=13;r++){
       for(int c = 38;c<=49;c++){
         if(r == 9 || r==13){
            display[r][c] ='-';
         }else{
            display[r][c] ='.';
         }
       }
   }
  //chamber 3
   for(int r = 18;r<=22;r++){
         display[r][36] ='|';
         display[r][76] = '|';
   }
   for(int r = 15;r<=18;r++){
         display[r][64] = '|';
         display[r][76] = '|';
     for(int c = 65;c<=75;c++){
        if(r==15){
          display[r][c] ='-';
        }else{
          display[r][c] = '.';
        }
     }  
   }
   for(int c = 37;c<=63;c++){
        display[18][c]='-';
   }
   for(int r=19;r<=22;r++){
       for(int c=37;c<=75;c++){
          if(r == 22){
            display[r][c]='-';
          }else{
            display[r][c]='.';
          }
       }
   }
   //chamber 4
   for(int r = 2;r<=13;r++){
    if(r==2||r==3){
      for(int c = 39;c<=61;c++){
       if(r==2){
       display[r][c] = '-';
       }else{
       display[r][c] = '.';
       }
      }
    }
    else if(r==4){
      for(int c = 39;c<=62;c++){
      display[r][c] = '.';
      }
      for(int c = 63;c<=69;c++){
      display[r][c] = '-';
      }
    }
    else if(r == 5||r == 6){
      for(int c = 39;c<=72;c++){
      display[r][c] = '.';
      }
    }
    else if(r==7){
      for(int c = 39;c<=59;c++){
      display[r][c]= '-';
      }
      for(int c = 61;c<=75;c++){
      display[r][c] = '.';
      }
    }
    else if(r == 13){
       for(int c = 61;c<=75;c++){
       display[r][c] = '-';
       }
    }
    else{
       for(int c = 61;c<=75;c++){
       display[r][c] = '.';
       }
     }
   }
   display[5][71] = '-';
   display[5][72] = '-';
   display[6][74] = '-';
   display[6][75] = '-';
   for(int r = 2;r<=4;r++){
   display[r][38] = '|';
   display[r][62] = '|';
   }
   display[4][70] = '|';
   display[5][70] = '|';
   display[5][73] = '|';
   display[6][73] = '|';
   display[6][76] = '|';
   for(int r = 5;r<=7;r++){
   display[r][38] = '|';
   }
   for(int r = 7;r<=13;r++){
   display[r][60] = '|';
   display[r][76] = '|';
   }
//chamber 5
   
   display[4][29] = '+';
   display[4][38] = '+';
   display[9][43] = '+';
   display[13][43] = '+';
   display[11][60] = '+';
   display[7][13] = '+';
   display[14][13] = '+';
   display[20][25] = '+';
   display[20][36] = '+';
   display[18][43] = '+';
   display[15][69] = '+';
   display[13][69] = '+';
   display[7][43] = '+';
//initialize doors

   for(int r = 8;r<=13;r++){
   display[r][13] = '#';
   }
   for(int r = 5;r<=7;r++){
   display[r][33] = '#';
   }
   for(int r = 8;r<=20;r++){
   display[r][31] = '#';
   }
   for(int r = 11;r<=16;r++){
   display[r][54] = '#';
   }
   for(int r = 14;r<=17;r++){
   display[r][43] = '#';
   }
 
   display[14][69] = '#';

   for(int c = 14;c<=30;c++){
   display[11][c] = '#';
   }
   for(int c = 26;c<=35;c++){
   display[20][c] = '#';
   }
   for(int c = 32;c<=53;c++){
   display[16][c] = '#';
   }
   for(int c = 32;c<=43;c++){
   display[8][c] = '#';
   }
   for(int c = 30;c<=37;c++){
   display[4][c] = '#';
   }
   for(int c = 54;c<=59;c++){
   display[11][c] = '#';
   }
//initialize path
}



void Floor::makeMove(Character* o,std::string dir)
{
  char temp;
  temp = display[o->getX()][o->getY()];
  display[o->getX()][o->getY()] = o->getTempChar();
  if (!dir.compare("no"))
    o->setX(o->getX()-1);
  else if (!dir.compare("so"))
    o->setX(o->getX()+1);
  else if (!dir.compare("ea"))
    o->setY(o->getY()+1);
  else if (!dir.compare("we"))
    o->setY(o->getY()-1);
  else if (!dir.compare("ne"))
  {
    o->setY(o->getY()+1);
    o->setX(o->getX()-1);
  }
  else if(!dir.compare("nw"))
  {
    o->setX(o->getX()-1);
    o->setY(o->getY()-1);
  }
  else if(!dir.compare("se"))
  {
    o->setY(o->getY()+1);
    o->setX(o->getX()+1);
  }
  else if (!dir.compare("sw"))
  {
    o->setY(o->getY()-1);
    o->setX(o->getX()+1);
  }
  o->setTempChar(display[o->getX()][o->getY()]);
  display[o->getX()][o->getY()] = temp;
  if (o->getTempChar() == 'G')
  {
    Treasure* p1;
    for (int i = 0; i < numTreasure; i++)
    {
      if (tr[i]->getX() == o->getX() &&
          tr[i]->getY() == o->getY())
          p1 = tr[i];
    }
    if (p1->CanBePicked == true)
    {
      p->visit(p1);
      o->setTempChar('.');
    }
  }
  if (o->getTempChar() == '/')
  {
    o->setTempChar('.');
    if (Floornum == 8)
    {
      printScore();
      done = true;
    }
    else
    {
      Floornum++;
      restart();
    }
  }
}

void Floor::setPlayer(Player* p)
{
  this->p = p;
}

char** Floor::getDisplay()
{
  return this->display;
}

void Floor::beingNotified(Enemy* o)
{
  Action << "Enemy is dead." << endl;
  display[o->getX()][o->getY()] = '.';
  int x = o->getX();
  int y = o->getY();
  for (int i = 0; i < numEnemy; i++)
    if (e[i]->getX() == x && e[i]->getY() == y)
    {
      for (int j = i; j < numEnemy-1; i++)
        e[j] = e[j+1];
    }
  numEnemy--;
  delete o;
}

void Floor::beingNotified(Merchant* m)
{
  Action << "Merchant has been slained. Merchant horde appears." << endl;
  display[m->getX()][m->getY()] = 'G';
  Treasure* p = new Treasure(4);
  int x = m->getX();
  int y = m->getY();
  tr[numTreasure] = p;
  numTreasure++;
  p->setX(m->getX());
  p->setY(m->getY());
  for (int i = 0; i < numEnemy; i++)
    if (e[i]->getX() == x && e[i]->getY() == y)
    {
      for (int j = i; j < numEnemy-1; j++)
        e[j] = e[j+1];
    }
  delete m;
  numEnemy--;
}

void Floor::beingNotified(Player* p)
{
  printScore();
  p->setDeath();
}

void Floor::beingNotified(Potion* p)
{
  display[p->getX()][p->getY()] = '.';
  for (int i = 0; i < numPotion; i++)
  {
    if (!po[i]->getName().compare(p->getName()))
      po[i]->setRevealed();
  }
  int x = p->getX();
  int y = p->getY();
  Action << "Player uses " << p->getName() << "." << endl;
  for (int i = 0; i < numPotion; i++)
    if (po[i]->getX() == x && po[i]->getY() == y)
    {
      for (int j = i; j < numPotion-1; j++)
        po[j] = po[j+1];
    }
  delete p;
  numPotion --;
}

void Floor::beingNotified(Treasure* t)
{
  Action << "Player obtains " << t->getValue() << " gold." << endl;
  int x = t->getX();
  int y = t->getY();
  for (int i = 0; i < numTreasure; i++)
    if (tr[i]->getX() == x && tr[i]->getY() == y)
    {
      for (int j = i; j < numTreasure-1; j++)
        tr[j] = tr[j+1];
    }
  delete t;
  numTreasure--;
}

void Floor::init(Player* p)
{ 
  p->clearTemp();
  done = false;
  Factory *f = new Factory;//create a factory to access it's methods
  int r,c;
  int r1,c1;
  int i = rand() % 5 + 1;//stand for the chamber the player in 
  int ii = rand() % 5 + 1;//stand for the chamber the stairway in 

  while(ii == i){
     ii = rand() % 5 + 1;
  }//to avoid player and stairway in the same chamber
  
  if(i == 1){             //if it's in the chamber 1 choose an available postion
     r = rand() % 6 + 2;
     c = rand() % 28 + 2;
     while(display[r][c] != '.'){
        r = rand() % 6 + 2;
        c = rand() % 28 + 2;
     }
  }
  if(i == 2){            //if it's in the chamber 2 choose an available position
     r = rand() % 9 + 14;
     c = rand() % 23 + 3;
     while(display[r][c] != '.'){
        r = rand() % 9 + 14;
        c = rand() % 23 + 3;
     }
  }
  if(i == 3){            //if it's in the  chamber 3 choose an available postion
     r = rand() % 5 + 9;
     c = rand() % 14 + 37;
     while(display[r][c] != '.'){
        r = rand() % 5 + 9;
        c = rand() % 14 + 37;
     }
  }
  if(i == 5){            //if it's in the chamber 5 choose an available position
     r = rand() % 6 + 2;
     c = rand() % 39 + 38;
     while(display[r][c] != '.'){
        r = rand() % 6 + 2;
        c = rand() % 39 + 38; 
     }
  }
  if(i == 4){            //if it's in the chamber 4 choose an available position
     c = rand() % 41 + 36;
     r = rand() % 8 + 15;
     while(display[r][c] != '.'){
        c = rand() % 41 + 36;
        r = rand() % 8 + 15;
     }
  }

  p->setX(r);
  p->setY(c);
  display[r][c] ='@';

  if(ii == 1){             //if it's in the chamber 1 choose an available postion
     r1 = rand() % 6 + 2;
     c1 = rand() % 28 + 2;
     while(display[r1][c1] != '.'){
        r1 = rand() % 6 + 2;
        c1 = rand() % 28 + 2;
     }
  }
  if(ii == 2){             //if it's in the chamber 2 choose an available position
     r1 = rand() % 9 + 14;
     c1 = rand() % 23 + 3;
     while(display[r1][c1] != '.'){
        r1 = rand() % 9 + 14;
        c1 = rand() % 23 + 3;
     }
  }
  if(ii == 3){            //if it's in the  chamber 3 choose an available postion
     r1 = rand() % 5 + 9;
     c1 = rand() % 14 + 37;
     while(display[r1][c1] != '.'){
         r1 = rand() % 5 + 9;
         c1 = rand() % 14 + 37;
    }
  }
  if(ii == 5){            //if it's in the chamber 5 choose an available position
     r1 = rand() % 6 + 2;
     c1 = rand() % 39 + 38;
     while(display[r1][c1] != '.'){
        r1 = rand() % 6 + 2;
        c1 = rand() % 39 + 38;
     }
  }
  if(ii == 4){            //if it's in the chamber 4 choose an available position
     c1 = rand() % 41 + 36;
     r1 = rand() % 8 + 15;
     while(display[r1][c1] != '.'){
        c1 = rand() % 41 + 36;
        r1 = rand() % 8 + 15;
     }
  }

  display[r1][c1] = '/';

  for(int i = 1;i<=10;i++){
    Potion* p = f->CreatePotion(this->display);
    p->setFloor(this);
    po[numPotion] = p;
    numPotion++;
  }//create 10 potion for a floor

  for(int i = 1;i<=10;i++){
    Treasure* t = f->CreateTreasure(this->display);
    t->setFloor(this);
    tr[numTreasure] = t;
    numTreasure++;
  }//create 10 treasure for a floor

  for(int i = 1;i<=20;i++){
    Enemy* en = f->CreateEnemy(this->display);
    e[numEnemy] = en;
    en->setTempChar('.');
    en->setFloor(this);
    numEnemy++;   
  }//create 20 enemy for a floor
}

void Floor::restart()
{
  clear();
  for (int i = 0; i < numEnemy; i++)
    delete e[i];
  numEnemy = 0;
  for (int i = 0; i < numPotion; i++)
    delete po[i];
  numPotion = 0;
  for (int i = 0; i < numTreasure; i++)
    delete tr[i];
  numTreasure = 0;
  init(p);
}

void Floor::printScore()
{
  Human* h = dynamic_cast<Human*>(p);
  if (h == NULL)
    cout << "Your final score is: " << p->getGold() << endl;
  else
    cout << "Your final score is: " << p->getGold() * 1.5 << endl;
}

void Floor::tick()
{
  for (int i = 0; i < numEnemy; i++)
    e[i]->makeMove();
  for (int i = 0; i < numPotion; i++)
    po[i]->makeMove();
  for (int i = 0; i < numTreasure; i++)
    tr[i]->makeMove();
}
