#ifndef POLE_H
#define POLE_H

class Pionek;

class Pole
{
public:
  int id;
  int height;
  int weight;
  Pionek* pionek;
  Pole(int id, int heigth, int weigth);
  void Ustaw_pionka(Pionek* _pionek);
  ~Pole();
};

#endif /* !POLE_H */

