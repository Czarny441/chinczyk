#ifndef POLE_H
#define POLE_H

class Pionek;

enum zawartosc_pola
{
  puste,
  czerwony1, czerwony2, czerwony3, czerwony4,
  niebieski1, niebieski2, niebieski3, niebieski4,
  zielony1, zielony2, zielony3, zielony4,
  zolty1, zolty2, zolty3, zolty4
};

class Pole
{
public:
  int id;
  int height;
  int weight;
  Pionek* pionek;
  zawartosc_pola zawartosc_pola_;
  Pole(int id, int heigth, int weigth, zawartosc_pola puste);
  void Ustaw_pionka(Pionek* _pionek, zawartosc_pola x);
  void Sciagnij_pionka();
  ~Pole();
};

#endif /* !POLE_H */

