#include "object.h"
#include <iostream>
#include "floor.h"

void Object::setFloor(Floor* f)
{
  this->f = f;
}

int Object::getX(){
  return this->x;
}

int Object::getY(){
  return this->y;
}

void Object::setX(int i){
   x = i;
}

void Object::setY(int i){
   y = i;
}

Object::~Object(){}
