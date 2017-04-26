#include <Windows.h>
#include "res.h"
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

bool isGameOn = false;  //czy gra zosta³a zaczêta
//bool isFirstPlayerTurn = true;  //czyj ruch
enum player {yellow, red, blue, green};   //który gracz wykonuje ruch
bool isPlayerdrawn;
int value;
int y_val, r_val, b_val, g_val;
HBITMAP hBitmapGameBoard;
HBITMAP hBitmapYellow;
HBITMAP hBitmapRed;
HBITMAP hBitmapBlue;
HBITMAP hBitmapGreen;
HINSTANCE hInst;
player gracz;
vector <int> drawing;
int drawing_max;

void drawBoard(HDC hdc) 
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapGameBoard);
  BitBlt(hdc, 0, 0, 700, 703, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void drawYellow(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapYellow);
  BitBlt(hdc, x, y, 59, 59, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void drawRed(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapRed);
  BitBlt(hdc, x, y, 59, 59, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
} 
void drawBlue(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapBlue);
  BitBlt(hdc, x, y, 59, 59, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}
void drawGreen(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapGreen);
  BitBlt(hdc, x, y, 59, 59, hDCBitmap, 0, 0, SRCCOPY);
  DeleteDC(hDCBitmap);
}


int kostka(HWND hwndDlg)
{
  value = rand() % 6 + 1;
  HWND hwndButton = GetDlgItem(hwndDlg, IDC_BUTTON_KOSTKA);
  CHAR szText[500];
  wsprintf(szText, "%d", value);
  SetWindowText(hwndButton, szText);
  return value;
}
//void drawhome();
void losuj_gracza(HWND hwndDlg, player &gracz, vector<int> &drawing) 
{
  switch (gracz)
  {
  case yellow:
    y_val = kostka(hwndDlg);
    //statictext=(
    CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_YELLOW);
    drawing.push_back(y_val);
    gracz = red;
    break;
  case red:
    r_val= kostka(hwndDlg);
    CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_RED);
    if (r_val > drawing[0])
    {
      drawing.pop_back();
      drawing.push_back(r_val);
    }
    gracz = blue;
    break;
  case blue:
    b_val = kostka(hwndDlg);
    CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_BLUE);
    if (b_val > drawing[0])
    {
      drawing.pop_back();
      drawing.push_back(b_val);
    }
    gracz = green;
    break;
  case green:
    g_val = kostka(hwndDlg);
    CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_GREEN);
    if (g_val > drawing[0])
    {
      drawing.pop_back();
      drawing.push_back(g_val);
    }
    gracz = yellow;
    Sleep(2000);

    if (drawing[0] == y_val)
    {
      gracz = yellow;
      CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_YELLOW);
    }
    else if (drawing[0] == r_val)
    {
      gracz = red;
      CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_RED);
    }
    else if (drawing[0] == b_val)
    {
      gracz = blue;
      CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_BLUE);
    }
    else if (drawing[0] == g_val)
    {
      gracz = green;
      CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_GREEN);
    }
    //static1234-""   ||| statucred = "wygra red" || 
    isPlayerdrawn = true;
    break;
  }

}


/*LRESULT CALLBACK ButtonWndProc( HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
  case WM_PAINT:
  {
    HDC hdc = GetDC(hwndDlg);
    HDC hDCBitmap = CreateCompatibleDC(hdc);
    SelectObject(hDCBitmap, hBitmapGameBoard);
    BitBlt(hdc, 0, 0, 1920,1280, hDCBitmap, 0, 0, SRCCOPY);
    DeleteDC(hDCBitmap);
    ReleaseDC(hwndDlg, hdc);
    return 0;
  }
  default:
    return DefWindowProc(hwndDlg, uMsg, wParam, lParam);
    //return CallWindowProc(wpOrgButtonProc, hwnd, uMsg, wParam, lParam);
  }
}*/

INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
  switch (uMsg)
  {
  case WM_INITDIALOG:
  {
    hBitmapGameBoard = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_PLANSZA));
    hBitmapYellow = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_ZOLTY));
    hBitmapRed = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_CZERWONY));
    hBitmapBlue = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_NIEBIESKI));
    hBitmapGreen = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_ZIELONY));

    HWND hwndButton = GetDlgItem(hwndDlg, IDC_BUTTON_START);
//    WNDPROC wpOrgButtonProc = (WNDPROC)SetWindowLong(hwndButton, -4, (LONG)ButtonWndProc);
  }
    return TRUE;

  case WM_COMMAND:
  {
    switch (HIWORD(wParam))
    {
    case BN_CLICKED:    //zdarzenie klikniêcia na przycisk
      switch (LOWORD(wParam))
      {
      case IDC_BUTTON_START:
        if (isGameOn == false)
        {
          isGameOn = true; 
          isPlayerdrawn = false;
          //ustawienie poczatkowego gracza
          gracz = yellow;
         
          CHAR szText[500];
          HWND hwndButtonStart = GetDlgItem(hwndDlg, IDC_BUTTON_START);
          wsprintf(szText, "Stop");
          SetWindowText(hwndButtonStart, szText);

          //Rysowanie siatki gry
          HDC hdc = GetDC(hwndDlg);
          drawGreen(hdc, 555,565);
          drawGreen(hdc, 615, 565);
          drawGreen(hdc, 555, 630);
          drawGreen(hdc, 615, 630);

          drawBlue(hdc, 555, 10);
          drawBlue(hdc, 555, 75);
          drawBlue(hdc, 615, 10);
          drawBlue(hdc, 615, 75);

          drawYellow(hdc, 15, 565);
          drawYellow(hdc, 75, 565);
          drawYellow(hdc, 15, 630);
          drawYellow(hdc, 75, 630);

          drawRed(hdc, 15, 10);
          drawRed(hdc, 15, 75);
          drawRed(hdc, 75, 10);
          drawRed(hdc, 75, 75);

          ReleaseDC(hwndDlg, hdc);
        }
        else
        {
          isGameOn = false;
          HWND hwndButtonStart = GetDlgItem(hwndDlg, IDC_BUTTON_START);
          CHAR szText[500];
          wsprintf(szText, "Start");
          SetWindowText(hwndButtonStart, szText);
        }
        return TRUE;
        //RZUT KOSTKA
      case IDC_BUTTON_KOSTKA:
        if (isGameOn == true && isPlayerdrawn == false) 
        {
          losuj_gracza(hwndDlg, gracz, drawing);

        }
        return TRUE;

      }
      return TRUE;
    }
  }
    return FALSE;

  case WM_LBUTTONDOWN: {
    //CHAR szText[200];
    if (isGameOn == true)
    {
      HDC hdc = GetDC(hwndDlg);

      int x = LOWORD(lParam); int y = HIWORD(lParam);
      if ((x > 0 && x < 700) && (y > 0 && y < 703))
      {
        drawBlue(hdc, 100, 100);
      }
      ReleaseDC(hwndDlg, hdc);
    }
  }
    return TRUE;

  case WM_PAINT:{
    HDC hdc = GetDC(hwndDlg);
    drawBoard(hdc);
    ReleaseDC(hwndDlg, hdc);
    return DefWindowProc(hwndDlg, uMsg, wParam, lParam);
  }
    return TRUE;
    //
    //komunikat zamkniêcia okienka
    //
  case WM_CLOSE: {
    DestroyWindow(hwndDlg);
    PostQuitMessage(0);
    for (int i = 0; i < 5; i++) { DeleteObject(hBitmapGameBoard + i); }
  }
    return TRUE;
  }
  return FALSE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) 
{
  hInst = hInstance;
  HWND hwndMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogProc);
  ShowWindow(hwndMainWindow, iCmdShow); 
  srand(time(NULL));
  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0)) 
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return 0;
}