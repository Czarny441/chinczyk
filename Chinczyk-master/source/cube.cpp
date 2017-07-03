#include "cube.h"

void Cube::init_dialog(HINSTANCE hInst) 
{
  hBitmapOne = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_JEDEN));
  hBitmapTwo = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_DWA));
  hBitmapThree = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_TRZY));
  hBitmapFour = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_CZTERY));
  hBitmapFive = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_PIEC));
  hBitmapSix = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_SZESC));
}
int Cube::kostka(HWND hwndDlg)
{
  HDC hdc = GetDC(hwndDlg);
  value = rand() % 6 + 1;
  //value = rand() % 2 + 5;
  switch (value)
  {
  case 1:
    DrawOne(hdc);
    break;
  case 2:
    DrawTwo(hdc);
    break;
  case 3:
    DrawThree(hdc);
    break;
  case 4:
    DrawFour(hdc);
    break;
  case 5:
    DrawFive(hdc);
    break;
  case 6:
    DrawSix(hdc);
    break;
  }
  /*
  HWND hwndButton = GetDlgItem(hwndDlg, IDC_BUTTON_KOSTKA);
  CHAR szText[500];
  wsprintf(szText, "%d", value);
  SetWindowText(hwndButton, szText);*/
  return value;
}
void Cube::DrawOne(HDC hdc)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapOne);
  BitBlt(hdc, 750, 400, 95, 95, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Cube::DrawTwo(HDC hdc)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapTwo);
  BitBlt(hdc, 750, 400, 95, 95, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Cube::DrawThree(HDC hdc)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapThree);
  BitBlt(hdc, 750, 400, 95, 95, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Cube::DrawFour(HDC hdc)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapFour);
  BitBlt(hdc, 750, 400, 95, 95, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Cube::DrawFive(HDC hdc)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapFive);
  BitBlt(hdc, 750, 400, 95, 95, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void Cube::DrawSix(HDC hdc)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapSix);
  BitBlt(hdc, 750, 400, 95, 95, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}