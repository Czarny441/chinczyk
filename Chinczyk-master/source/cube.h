#ifndef PROJEKT1_CUBE_H
#define PROJEKT1_CUBE_H
#include <Windows.h>
#include "res.h"

class Cube
{
public:
  void init_dialog(HINSTANCE);
  void DrawOne(HDC hdc);
  void DrawTwo(HDC hdc);
  void DrawThree(HDC hdc);
  void DrawFour(HDC hdc);
  void DrawFive(HDC hdc);
  void DrawSix(HDC hdc);
  int kostka(HWND hwndDlg);
  int value;
private:
  HBITMAP hBitmapOne;
  HBITMAP hBitmapTwo;
  HBITMAP hBitmapThree;
  HBITMAP hBitmapFour;
  HBITMAP hBitmapFive;
  HBITMAP hBitmapSix;
};
#endif // !PROJEKT1_CUBE_H