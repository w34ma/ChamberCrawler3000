#include "enemy.h"

class Merchant: public Enemy
{
  public:
    Merchant();
    void accept(Player*);
    void makeMove();
    void notifyFloor();
    ~Merchant();
};
