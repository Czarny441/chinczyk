#include "Pole.h"
#include "Pionek.h"
#include "Player.h"


Pole::Pole(int _id, int _height, int _weigth, zawartosc_pola x)
{
  id = _id;
  height = _height;
  weight = _weigth;
  pionek = nullptr;
  zawartosc_pola_ = x;
}

void Pole::Ustaw_pionka(Pionek * _pionek, zawartosc_pola x)
{
  pionek = _pionek;
  zawartosc_pola_ = x;
}

void Pole::Sciagnij_pionka()
{
//  if(zawartosc_pola_ == czerwony1) pionek->rusz_pionka(Schowek)
  zawartosc_pola_ = puste;
}


Pole::~Pole()
{
}
