#ifndef PROJEKT1_PLAYER_H
#define PROJEKT1_PLAYER_H
#include <vector>

using namespace std;
enum kolor { yellow, red, blue, green };

class Player
{
public:

  vector <kolor> grajace_kolory;
  kolor aktualny;

  Player();
  void next();

};

#endif // !PROJEKT1_PLAYER_H