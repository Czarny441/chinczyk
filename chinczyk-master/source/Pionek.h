#ifndef PIONEK_H
#define PIONEK_H

class Pionek
{
public:
  friend class Pole;
  Pole* pole;
  Pionek();
  ~Pionek();
  void rusz_pionka(Pole *pole, int wektor[2]);
};

#endif /* !PIONEK_H */#pragma once
