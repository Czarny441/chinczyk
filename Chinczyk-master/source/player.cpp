#include "Player.h"
#include "Pole.h"

Player::Player(kolor x)
{
    Pionek* pierwszy = new Pionek(x);
    Pionek* drugi = new Pionek(x);
    Pionek* trzeci = new Pionek(x);
    Pionek* czwarty = new Pionek(x);

    pionki.push_back(pierwszy);
    pionki.push_back(drugi);
    pionki.push_back(trzeci);
    pionki.push_back(czwarty);
};

