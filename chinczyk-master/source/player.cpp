#include "Player.h"
#include "Pole.h"





Player::Player(kolor x)
{
    Pionek* pierwszy = new Pionek();
    Pionek* drugi = new Pionek();
    Pionek* trzeci = new Pionek();
    Pionek* czwarty = new Pionek();

    pionki.push_back(pierwszy);
    pionki.push_back(drugi);
    pionki.push_back(trzeci);
    pionki.push_back(czwarty);
};

