#include "Pionek.h"
#include "Pole.h"


Pionek::Pionek()
{

}


Pionek::~Pionek()
{
}

void Pionek::rusz_pionka(Pole * _pole, int wektor[2])
{
  pole = _pole;
  wektor[0] = pole->height;
  wektor[1] = pole->weight;
}
