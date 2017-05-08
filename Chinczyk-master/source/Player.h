#pragma once
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
