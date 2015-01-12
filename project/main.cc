#include "floor.h"
#include "human.h"
#include "dwarf.h"
#include "elves.h"
#include "orc.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
  Floor *f = new Floor;
  Player *p;
  string input;
  input = "";
  while ((input.compare("q")) && (f->isDone() == false))
  {
    cout << "Please choose a race." << endl;
    cout << "h: Human (HP: 140, Atk: 20, Def: 20)" << endl;
    cout << "d: Dwarf (HP: 100, Atk: 20, Def: 30) Double gold" << endl;
    cout << "e: Elves (HP: 140, Atk: 30, Def: 10) Makes all negative potions positive" << endl;
    cout << "o: Orc (HP: 180, Atk: 30, Def: 25) Half gold" << endl;
    string race;
    bool suc = false;
    while (suc == false)
    {
      cin >> input;
      if (!input.compare("h"))
      {
        race = "Human";
        p = new Human;
        suc = true;
      }
      else if (!input.compare("d"))
      {
        race = "Dwarf";
        p = new Dwarf;
        suc = true;
      }
      else if (!input.compare("e"))
      {
        race = "Elves";
        p = new Elves;
        suc = true;
      }
      else if (!input.compare("o"))
      {
        race = "Orc";
        p = new Orc;
        suc = true;
      }
      else if (suc == false)
        cout << "Invalid race. Please try again." << endl;
    }
    f->setPlayer(p);
    p->setTempChar('.');
    p->setFloor(f);
    f->restart();
    while ((input.compare("q")) && (p->isDead() == false) && (input.compare("r")))
    {
      for (int r = 0; r < 25; r++)
      {
        for (int c = 0; c < 79; c++)
          cout << f->getDisplay()[r][c];
        cout << endl;
      }
      cout << "Race: " << race << " Gold: " << p->getGold() << endl;
      cout << "HP: " << p->getHP() << endl;
      cout << "Atk: "<< p->getAtk() << endl;
      cout << "Def: "<< p->getDef() << endl;
      cout << "Action: " << endl;
      string act;
      while (getline(f->Action,act))
        cout << act << endl;

      cout << "Please enter a command: " << endl;
      cout << "no,so,ea,we,ne,nw,se,sw for moving your player" << endl;
      cout << "a<direction> for attacking the enemy" << endl;
      cout << "u<direction> for using the potion" << endl;
      cout << "r for restarting the game" << endl;
      cout << "q for quit the game" << endl;
      bool flag = false;
      int mode = 0;
      while (flag == false)
      {
        cin >> input;
        if (input[0] == 'u')
        {
          mode = 1;
          string tmp;
          tmp[0] = input[2];
          tmp[1] = input[3];
          input = tmp;
        }
        else if (input[0] == 'a')
        {
          mode = 2;
          string tmp;
          tmp[0] = input[2];
          tmp[1] = input[3];
          input = tmp;
        }
        else if (input[0] == 'r')
        {
          cout << "Are you sure that you want to restart the game?(y/n)"<<endl;
          char order;
          cin >> order;
          if (order == 'y')
          {
            f->restart();
            break;
          }
          else if (order == 'n')
          {
            continue;
          }
        }
        else if (input[0] == 'q')
        {
          cout << "Are you sure that you want to quit the game?(y/n)" << endl;
          char order;
          cin >> order;
          if (order == 'y')
            break;
          else if (order == 'n')
            continue;
        }
        else
          mode = 0;
        int x,y;
        if (!input.compare("no"))
        {
          x = -1;
          y = 0;
        }
        else if (!input.compare("so"))
        {
          x = 1;
          y = 0;
        }
        else if (!input.compare("ea"))
        {
          x = 0;
          y = 1;
        }
        else if (!input.compare("we"))
        {
          x = 0;
          y = -1;
        }
        else if (!input.compare("ne"))
        {
          x = -1;
          y = 1;
        }
        else if (!input.compare("nw"))
        {
          x = -1;
          y = -1;
        }
        else if (!input.compare("se"))
        {
          x = 1;
          y = 1;
        }
        else if (!input.compare("sw"))
        {
          x = 1;
          y = -1;
        }
        if (mode == 0)
        {
          if (f->getDisplay()[p->getX()+x][p->getY()+y] == '.' ||
              f->getDisplay()[p->getX()+x][p->getY()+y] == '#' ||
              f->getDisplay()[p->getX()+x][p->getY()+y] == '+' ||
              f->getDisplay()[p->getX()+x][p->getY()+y] == 'G' ||
              f->getDisplay()[p->getX()+x][p->getY()+y] == '/')
          {
            f->makeMove(p,input);
            flag = true;
            cout << "Player moves to " << input << "." << endl;
          }
        }
        else if (mode == 1)
        {
          if (f->getDisplay()[p->getX()+x][p->getY()+y] == 'P')
          {
            for (int i = 0; i < f->numPotion; i++)
              if (f->po[i]->getX() == p->getX()+x &&
                  f->po[i]->getY() == p->getY()+y)
              {
                p->visit(f->po[i]);
                flag = true;
                cout << "Player uses " << f->po[i]->getName() << "." << endl;
              }
          }
        }
        else if (mode == 2)
        {
          for (int i = 0; i < f->numEnemy; i++)
            if (f->e[i]->getX() == p->getX()+x &&
                f->e[i]->getY() == p->getY()+y)
            {
              p->visit(f->e[i]);
              flag = true;
            }
        }
        if (flag == false)
        {
          cout << "Sorry that was an invalid command, try again." << endl;
          continue;
        }
        else
        {
          f->tick();
        }
      }
      if (p->isDead() == true)
      {
        cout << "You are dead. Do you want to try again?(y/n)" << endl;
        char order;
        cin >> order;
        if (order == 'y')
        {
          f->restart();
          delete p;
          continue;
        }
        else if (order == 'n')
        {
          break;
        }
      }
    }
  }
  delete p;
  delete f;
}
