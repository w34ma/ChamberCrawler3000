#include "character.h"


void Character::addHP(int amount)
{
	this->HP += amount;
        if (HP > MaxHP)
          HP = MaxHP;
        if (HP < 0)
          HP = 0;
}

int Character::getHP()
{
	return this->HP;
}

int Character::getAtk()
{
	return this->Atk;
}

int Character::getDef()
{
	return this->Def;
}

char Character::getTempChar()
{
	return this->TempChar;
}

void Character::setTempChar(char input)
{
	this->TempChar = input;
}

Character::~Character(){}
