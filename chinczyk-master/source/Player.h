#ifndef PROJEKT1_PLAYER_H
#define PROJEKT1_PLAYER_H
#include <vector>
#include "Pionek.h"

using namespace std;
enum kolor { yellow, red, blue, green };

class Player
{
public:
  friend class Pole;

  vector <Pionek*> pionki;

  Player(kolor x);

};


#endif // !PROJEKT1_PLAYER_H