#ifndef PIONEK_H
#define PIONEK_H
enum kolor { yellow, red, blue, green };


class Pionek
{
public:
  friend class Pole;
  kolor colour;
  Pole* pole;
  Pionek(kolor _colour);
  int id;
  ~Pionek();
  void rusz_pionka(Pole *pole, int wektor[2]);
};

#endif /* !PIONEK_H */#pragma once
