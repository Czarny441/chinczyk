#include <Windows.h>
#include "Player.h"
#include "res.h"
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

bool isGameOn = false;  //czy gra zosta³a zaczêta
bool isPlayerdrawn;   //czy zaczynaj¹cy gracz zosta³ ju¿ wylosowany
int value;   //wartoœæ rzutu kostk¹
int y_val, r_val, b_val, g_val;   //wartoœci rzutu kostk¹ dla poszczególnych graczy
HBITMAP hBitmapGameBoard;
HBITMAP hBitmapYellow;
HBITMAP hBitmapRed;
HBITMAP hBitmapBlue;
HBITMAP hBitmapGreen;
HINSTANCE hInst;
vector <int> drawing;  //wektor rzutów przy losowaniu
vector <int> placing;  //wektor pokazuj¹cy, ogo nale¿y usun¹æ z losowania (kto rzuci³ najmniej)
int drawing_max;    //najwiêkszy rzut
int tries = 0;    //iloœæ prób wyjœcia z domku
int length = 0; //sprawdzanie d³ugoœci wektora do czyszczenia drawing
int size_kolor = 0; //d³ugoœæ wektora kolorów
bool firstdraw = true;   //dotyczy pierwszego losowania
Player graczx = Player();

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

void fillPlacing(vector <int> &placing, vector <int> drawing)
{
  placing.clear();
  for (int i = 0; i < drawing.size(); i++)
  {
    placing.push_back(i);
  }
}

void maxdraw(vector <int> &drawing, vector <int> &placing)
{
  int max = 0;
  int place = 0;
  int erasing = 0;
  for (int i = 0; i < drawing.size(); i++)
  {
    if ((drawing[i]) > max)
    {
      max = drawing[i];

      fillPlacing(placing,drawing);
      placing.erase(placing.begin() + i);
      erasing = 0;
    }
    else if ((drawing[i]) == max)
    {
      erasing++;
      if ((placing[i - erasing]) == (placing[placing.size() - 1]))
      {
        placing.pop_back();
      }
      else
      {
        placing.erase(placing.begin() + i - erasing);
      }
    }
  }
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
void czysc(HWND hwndDlg)
{
  CHAR szText[500];
  HWND hwndstatic_y = GetDlgItem(hwndDlg, IDC_STATIC_YELLOW);
  HWND hwndstatic_r = GetDlgItem(hwndDlg, IDC_STATIC_RED);
  HWND hwndstatic_g = GetDlgItem(hwndDlg, IDC_STATIC_GREEN);
  HWND hwndstatic_b = GetDlgItem(hwndDlg, IDC_STATIC_BLUE);
  wsprintf(szText, "", y_val);  SetWindowText(hwndstatic_y, szText);
  wsprintf(szText, "", r_val);  SetWindowText(hwndstatic_r, szText);
  wsprintf(szText, "", g_val);  SetWindowText(hwndstatic_g, szText);
  wsprintf(szText, "", b_val);  SetWindowText(hwndstatic_b, szText);
}

void losuj_gracza(HWND hwndDlg, Player &graczx, vector<int> &drawing, vector <int> &placing)
{
  if (length == size_kolor)
  {
    drawing.clear();
    placing.clear();
    length = 0;
  }
  if (length == 0)
  {
    size_kolor = graczx.grajace_kolory.size();
  }

  switch (graczx.aktualny)
  {
  case yellow: {
    y_val = kostka(hwndDlg);
    CHAR szText[500];
    HWND hwndstatic_y = GetDlgItem(hwndDlg, IDC_STATIC_YELLOW);
    wsprintf(szText, "Wylosowano: %d", y_val);
    SetWindowText(hwndstatic_y, szText);
    CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_YELLOW);
    drawing.push_back(y_val);

    if (graczx.grajace_kolory.size() != 1)
    {
      graczx.next();
    }
    break;
  }
  case red: {
    r_val = kostka(hwndDlg);
    CHAR szText[500];
    HWND hwndstatic_r = GetDlgItem(hwndDlg, IDC_STATIC_RED);
    wsprintf(szText, "Wylosowano: %d", r_val);
    SetWindowText(hwndstatic_r, szText);
    CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_RED);
    drawing.push_back(r_val);

    if (drawing.size() == size_kolor)
    {
      int erasing = 0;
      maxdraw(drawing, placing);
      for (int i = 0; i < placing.size(); i++)
      {
        for (int j = 0; j < 4; j++)
        {
          if (placing[i] == j)
          {
            if ((graczx.grajace_kolory[j - erasing]) == (graczx.grajace_kolory[graczx.grajace_kolory.size() - 1]))
            {
              graczx.grajace_kolory.pop_back();
              erasing++;
            }
            else
            {
              graczx.grajace_kolory.erase(graczx.grajace_kolory.begin() + j - erasing);
              erasing++;
            }
            break;

          }
        }
      }
    }
    if (graczx.grajace_kolory.size() != 1)
    {
      graczx.next();
    }
    break;
  }
  case blue: {
    b_val = kostka(hwndDlg);
    CHAR szText[500];
    HWND hwndstatic_b = GetDlgItem(hwndDlg, IDC_STATIC_BLUE);
    wsprintf(szText, "Wylosowano: %d", b_val);
    SetWindowText(hwndstatic_b, szText);
    CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_BLUE);
    drawing.push_back(b_val);

    if (drawing.size() == size_kolor)
    {
      int erasing = 0;
      maxdraw(drawing, placing);
      for (int i = 0; i < placing.size(); i++)
      {
        for (int j = 0; j < 4; j++)
        {
          if (placing[i] == j)
          {
            if ((graczx.grajace_kolory[j - erasing]) == (graczx.grajace_kolory[graczx.grajace_kolory.size() - 1]))
            {
              graczx.grajace_kolory.pop_back();
              erasing++;
            }
            else
            {
              graczx.grajace_kolory.erase(graczx.grajace_kolory.begin() + j - erasing);
              erasing++;
            }
            break;

          }
        }
      }
    }
    if (graczx.grajace_kolory.size() != 1)
    {
      graczx.next();
    }
    break;
  }
  case green: {
    g_val = kostka(hwndDlg);
    CHAR szText[500];
    HWND hwndstatic_g = GetDlgItem(hwndDlg, IDC_STATIC_GREEN);
    wsprintf(szText, "Wylosowano: %d", g_val);
    SetWindowText(hwndstatic_g, szText);
    CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_GREEN);
    drawing.push_back(g_val);

    if (drawing.size() == size_kolor)
    {
      int erasing = 0;
      maxdraw(drawing, placing);
      for (int i = 0; i < placing.size(); i++)
      {
        for (int j = 0; j < 4; j++)
        {
          if (placing[i] == j)
          {
            if ((graczx.grajace_kolory[j - erasing]) == (graczx.grajace_kolory[graczx.grajace_kolory.size() - 1]))
            {
              graczx.grajace_kolory.pop_back();
              erasing++;
            }
            else
            {
              graczx.grajace_kolory.erase(graczx.grajace_kolory.begin() + j - erasing);
              erasing++;
            }
            break;

          }
        }
      }
    }


      if (graczx.grajace_kolory.size() != 1)
      {
        graczx.next();
      }
      break;
    }
  }
  length++;
}

void wystaw_pionka(HWND hwnDlg, Player graczx, HDC hdc)
{
  switch (graczx.aktualny)
  {
  case yellow:
    drawYellow(hdc, 250, 630);
    break;
  case red:
    drawRed(hdc, 20, 260);
    break;
  case blue:
    drawBlue(hdc, 380, 20);
    break;
  case green:
    drawGreen(hdc, 620, 380);
    break;

  }
}

void rzut_kostka3(HWND hwndDlg, Player &graczx, HDC hdc,int &tries)
{
      tries++;
      int draw = kostka(hwndDlg);
      if (draw == 6)
      {
        wystaw_pionka(hwndDlg, graczx, hdc);
        switch (graczx.aktualny)
        {
        case yellow:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_RED);
          graczx.next();
          break;
        case red:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_BLUE);
          graczx.next();
          break;
        case blue:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_GREEN);
          graczx.next();
          break;
        case green:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_YELLOW);
          graczx.next();
          break;
        }
        tries = 0;
        return;
      }
      if (tries == 3)
      {
        switch (graczx.aktualny)
        {
        case yellow:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_RED);
          graczx.next();
          break;
        case red:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_BLUE);
          graczx.next();
          break;
        case blue:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_GREEN);
          graczx.next();
          break;
        case green:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_YELLOW);
          graczx.next();
          break;
        }
        tries = 0;
      }
}

void sprawdz_wygranego(HWND hwndDlg, Player &graczx)
{

  if (graczx.grajace_kolory.size() == 1)
  {
    Sleep(2000);
    graczx.aktualny = graczx.grajace_kolory[0];
    char szText[500];
    switch (graczx.aktualny)
    {
    case 0:
      CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_YELLOW);
      wsprintf(szText, "Wygra³ ¿ó³ty");
      break;
    case 1:
      wsprintf(szText, "Wygra³ czerwony");
      CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_RED); 
      break;
    case 2:
      wsprintf(szText, "Wygra³ niebieski");
      CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_BLUE); 
      break;
    case 3:
      wsprintf(szText, "Wygra³ zielony");
      CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_GREEN); 
      break;
    }
    MessageBox(hwndDlg, szText, "Wygrana", MB_OK);
    czysc(hwndDlg);
    isPlayerdrawn = true;
    graczx.grajace_kolory.clear();
    graczx.grajace_kolory.push_back(yellow);
    graczx.grajace_kolory.push_back(red);
    graczx.grajace_kolory.push_back(blue);
    graczx.grajace_kolory.push_back(green);
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
      HDC hdc = GetDC(hwndDlg);
      switch (LOWORD(wParam))
      {
      case IDC_BUTTON_START:
        if (isGameOn == false)
        {
          isGameOn = true; 
          isPlayerdrawn = false;
          //ustawienie poczatkowego gracza
         
          CHAR szText[500];
          HWND hwndButtonStart = GetDlgItem(hwndDlg, IDC_BUTTON_START);
          wsprintf(szText, "Stop");
          SetWindowText(hwndButtonStart, szText);

          //Rysowanie siatki gry
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

        if (isGameOn == true && isPlayerdrawn == true)
        {
          rzut_kostka3(hwndDlg, graczx, hdc, tries);

        }
        if (isGameOn == true && isPlayerdrawn == false) 
        {
          losuj_gracza(hwndDlg, graczx, drawing, placing);
          sprawdz_wygranego(hwndDlg, graczx);
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