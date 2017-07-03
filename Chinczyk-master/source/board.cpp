#include "board.h"

void Board::init_dialog(HINSTANCE hInst) 
{
  hBitmapGameBoard = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_PLANSZA));
  hBitmapYellow = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_ZOLTY));
  hBitmapRed = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_CZERWONY));
  hBitmapBlue = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_NIEBIESKI));
  hBitmapGreen = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_ZIELONY));
  hBitmapDog = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_PIES));
  hBitmapDog2 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_PIES2));
  hBitmapWood = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_WOOD));
}
void Board::drawBoard(HDC hdc) 
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapGameBoard);
  BitBlt(hdc, 0, 0, 700, 703, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Board::drawYellow(HDC hdc, int x, int y) 
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapYellow);
  BitBlt(hdc, x, y, 59, 59, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Board::drawRed(HDC hdc, int x, int y) 
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapRed);
  BitBlt(hdc, x, y, 59, 59, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Board::drawBlue(HDC hdc, int x, int y) 
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapBlue);
  BitBlt(hdc, x, y, 59, 59, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Board::drawGreen(HDC hdc, int x, int y) 
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapGreen);
  BitBlt(hdc, x, y, 59, 59, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Board::DrawDog(HDC hdc)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapDog);
  BitBlt(hdc, 140, 160, 100, 96, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Board::DrawDog2(HDC hdc)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapDog);
  BitBlt(hdc, 140, 450, 100, 96, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Board::DrawDog3(HDC hdc)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapDog2);
  BitBlt(hdc, 455, 155, 100, 96, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Board::DrawDog4(HDC hdc) 
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapDog2);
  BitBlt(hdc, 460, 450, 100, 96, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Board::DrawWood(HDC hdc)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapWood);
  BitBlt(hdc, 700, 0, 905, 703, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Board::close() 
{
  for (int i = 0; i < 12; i++) { DeleteObject(hBitmapGameBoard + i); }
}