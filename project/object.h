#ifndef __OBJECT_H_
#define __OBJECT_H_
#include <vector>
#include <iostream>
using namespace std;

class Floor;
class Object{
   int x;    //stands for x-coordinate
   int y;    //stands for y-coordinate
  public:
   Floor* f;
   void setFloor(Floor*);
   int getX();   
   int getY();
   void setX(int);
   void setY(int);
   virtual ~Object() = 0;
};

#endif
