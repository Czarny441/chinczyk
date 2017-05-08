#include "Player.h"

Player::Player()
{
  kolor aktualny = yellow;
  grajace_kolory.push_back(yellow);
  grajace_kolory.push_back(red);
  grajace_kolory.push_back(blue);
  grajace_kolory.push_back(green);
};

void Player::next()
{
  for (int i = 0; i < grajace_kolory.size(); i++)
  {
    if (i < grajace_kolory.size() - 1)
    {
      if (aktualny == grajace_kolory[i])
      {
        aktualny = grajace_kolory[i + 1];
        break;
      }
    }
    else
    {
      aktualny = grajace_kolory[0];
      break;
    }
  }
};