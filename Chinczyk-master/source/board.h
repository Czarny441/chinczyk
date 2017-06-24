#ifndef PROJEKT1_BOARD_H
#define PROJEKT1_BOARD_H

#include <Windows.h>
#include "res.h"

class Board 
{
public:
  void init_dialog(HINSTANCE);
  void drawBoard(HDC hdc);
  void drawYellow(HDC hdc, int x, int y);
  void drawRed(HDC hdc, int x, int y);
  void drawBlue(HDC hdc, int x, int y);
  void drawGreen(HDC hdc, int x, int y);
  void Board::DrawDog(HDC hdc);
  void Board::DrawDog2(HDC hdc);
  void DrawDog3(HDC hdc);
  void DrawDog4(HDC hdc);
  void close();
private:
  HBITMAP hBitmapGameBoard;
  HBITMAP hBitmapYellow;
  HBITMAP hBitmapRed;
  HBITMAP hBitmapBlue;
  HBITMAP hBitmapGreen;
  HBITMAP hBitmapDog;
  HBITMAP hBitmapDog2;
};
#endif // !PROJEKT_1_BOARD_H
