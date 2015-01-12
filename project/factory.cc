#include <iostream>
#include <cstdlib>

#include "enemy.h"
#include "potion.h"
#include "treasure.h"
#include "factory.h"
#include "vampire.h"
#include "phoenix.h"
#include "troll.h"
#include "werewolf.h"
#include "dragon.h"
#include "merchant.h"
#include "goblin.h"

using namespace std;


Enemy* Factory::CreateEnemy(char** d){
     int r,c;
     int i;
     i = rand() % 5 + 1; //stands for random chamber
     int e;
     e = rand() % 18 + 1;//stands for type of enemy
     Enemy* type;
     if(i == 1){             //if it's in the chamber 1 choose an available postion
       r = rand() % 6 + 2;
       c = rand() % 28 + 2;
       while(d[r][c] != '.'){
           r = rand() % 6 + 2;
           c = rand() % 28 + 2;
       }
     }
     if(i == 2){             //if it's in the chamber 2 choose an available position
       r = rand() % 9 + 14;
       c = rand() % 23 + 3;
       while(d[r][c] != '.'){
          r = rand() % 9 + 14;
          c = rand() % 23 + 3;
       }
     }
     if(i == 3){            //if it's in the  chamber 3 choose an available postion
       r = rand() % 5 + 9;
       c = rand() % 14 + 37;
       while(d[r][c] != '.'){
          r = rand() % 5 + 9;
          c = rand() % 14 + 37;
       }
     }
     if(i == 5){            //if it's in the chamber 5 choose an available position
       r = rand() % 6 + 2;
       c = rand() % 39 + 38;
       while(d[r][c] != '.'){
          r = rand() % 6 + 2;
          c = rand() % 39 + 38;
       }
     }
     if(i == 4){            //if it's in the chamber 4 choose an available position
       c = rand() % 41 + 36;
       r = rand() % 8 + 15;
       while(d[r][c] != '.'){
          c = rand() % 41 + 36;
          r = rand() % 8 + 15;
       }
     }
     //decide what type of enemy created
      if(e>=1 && e<=3){
        type = new Vampire;
        type->setX(r);
        type->setY(c);
        d[r][c] = 'V';
      }
      if(e>=4 && e<=7){
        type = new Werewolf;
        type->setX(r);
        type->setY(c);
        d[r][c] = 'W';
      }
      if(e>=8 && e<=9){
        type = new Troll;
        type->setX(r);
        type->setY(c);
        d[r][c] = 'T';
      }
      if(e>=10 && e<=15){
        type = new Goblin;
        type->setX(r);
        type->setY(c);
        d[r][c] = 'N';
      }
      if(e>=16 && e<=17){
        type = new Phoenix;
        type->setX(r);
        type->setY(c);
        d[r][c] = 'X';
      }
      if(e==18){
        type = new Merchant;
        type->setX(r);
        type->setY(c);
        d[r][c] = 'M';
      }       
      return type;
}

Potion* Factory::CreatePotion(char** d){
     int r,c;
     int i = rand() % 5 + 1; //stands for random chamber
     int p = rand() % 6 + 1;//stands for type of potion
     Potion* type;
     if(i == 1){             //if it's in the chamber 1 choose an available postion
       r = rand() % 6 + 2;
       c = rand() % 28 + 2;
       while(d[r][c] != '.'){
           r = rand() % 6 + 2;
           c = rand() % 28 + 2;
       }
     }
     if(i == 2){             //if it's in the chamber 2 choose an available position
       r = rand() % 9 + 14;
       c = rand() % 23 + 3;
       while(d[r][c] != '.'){
          r = rand() % 9 + 14;
          c = rand() % 23 + 3;
       }
     }
     if(i == 3){            //if it's in the  chamber 3 choose an available postion
       r = rand() % 5 + 9;
       c = rand() % 14 + 37;
       while(d[r][c] != '.'){
          r = rand() % 5 + 9;
          c = rand() % 14 + 37;
       }
     }
     if(i == 5){            //if it's in the chamber 5 choose an available position
       r = rand() % 6 + 2;
       c = rand() % 39 + 38;
       while(d[r][c] != '.'){
          r = rand() % 6 + 2;
          c = rand() % 39 + 38;
       }
     }
     if(i == 4){            //if it's in the chamber 4 choose an available position
       c = rand() % 41 + 36;
       r = rand() % 8 + 15;
       while(d[r][c] != '.'){
          c = rand() % 40 + 36;
          r = rand() % 8 + 15;
       }
     }
     //decide what type of potion created
       if(p == 1){
          type = new Potion(10,"RH");
          type->setX(r);
          type->setY(c);
       }
       if(p == 2){
          type = new Potion(5,"BA");
          type->setX(r);
          type->setY(c);
       }
       if(p == 3){
          type = new Potion(5,"BD");
          type->setX(r);
          type->setY(c);
       }
       if(p == 4){
          type = new Potion(-10,"PH");
          type->setX(r);
          type->setY(c);
       }
       if(p == 5){
          type = new Potion(-5,"WA");
          type->setX(r);
          type->setY(c);
       }
       if(p == 6){
          type = new Potion(-5,"WD");
          type->setX(r);
          type->setY(c);
       }
       d[r][c] = 'P';
       return type;
}
    
Treasure* Factory::CreateTreasure(char** d){
     int r,c;
     int i = rand() % 5 + 1; //stands for random chamber
     int t = rand() % 8 + 1;//stands for type of treasure
     Treasure* type;
     if(i == 1){             //if it's in the chamber 1 choose an available position
       r = rand() % 6 + 2;
       c = rand() % 28 + 2;
       while(d[r][c] != '.'){
           r = rand() % 6 + 2;
           c = rand() % 28 + 2;
       }
     }
     if(i == 2){             //if it's in the chamber 2 choose an available position
       r = rand() % 9 + 14;
       c = rand() % 23 + 3;
       while(d[r][c] != '.'){
          r = rand() % 9 + 14;
          c = rand() % 23 + 3;
       }
     }
     if(i == 3){            //if it's in the  chamber 3 choose an available postion
       r = rand() % 5 + 9;
       c = rand() % 14 + 37;
       while(d[r][c] != '.'){
          r = rand() % 5 + 9;
          c = rand() % 14 + 37;
       }
     }
     if(i == 5){            //if it's in the chamber 5 choose an available position
       r = rand() % 6 + 2;
       c = rand() % 39 + 38;
       while(d[r][c] != '.'){
          r = rand() % 6 + 2;
          c = rand() % 39 + 38;
       }
     }
     if(i == 4){            //if it's in the chamber 4 choose an available position
       c = rand() % 41 + 36;
       r = rand() % 8 + 15;
       while(d[r][c] != '.'){
          c = rand() % 40 + 36;
          r = rand() % 8 + 15;
       }
     }
     //decide what type of treasure created
       if(t >= 1 && t<= 5){
          type = new Treasure(1);
          type->setX(r);
          type->setY(c);
       }//normal gold
       if(t == 6){
          type = new Treasure(6);
          type->setX(r);
          type->setY(c);
          type->adddragon(d,r,c);
          int r1 = type->d->getX();
          int c1 = type->d->getY();
          d[r1][c1] = 'D';
       }//dragon hoard
       if(t>=7 && t<= 8){
          type = new Treasure(2);
          type->setX(r);
          type->setY(c);
       }//small hoard
       d[r][c] = 'G';
       
       return type;
}

Factory::~Factory(){}
