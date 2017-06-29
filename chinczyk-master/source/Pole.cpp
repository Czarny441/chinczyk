#include "Pole.h"
#include "Pionek.h"


Pole::Pole(int _id, int _height, int _weigth)
{
  id = _id;
  height = _height;
  weight = _weigth;
  pionek = nullptr;
}

void Pole::Ustaw_pionka(Pionek * _pionek)
{
  pionek = _pionek;
}

Pole::~Pole()
{
}
