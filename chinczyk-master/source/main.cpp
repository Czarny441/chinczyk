#include <Windows.h>
#include "board.h"
#include "cube.h"
#include "Player.h"
#include "res.h"
#include "Pole.h"
#include <cstdlib>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
int plansza[40][2] = {{ 10, 258 }, // start czerwony
                      { 70, 258 },
                      { 130, 258 },
                      { 190, 258 },
                      { 250, 258 },
                      { 250, 195 }, 
                      { 250, 135 },
                      { 250, 75 },
                      { 250, 15 },
                      { 313, 15 },
                      { 375, 15 }, // start niebieski 
                      { 375, 75 },
                      { 375, 135 },
                      { 375, 195 }, 
                      { 375, 258 },
                      { 435, 258 }, 
                      { 495, 258 }, 
                      { 555, 258 },
                      { 615, 258 },
                      { 615, 318 },
                      { 615, 378 }, // start zielony
                      { 555, 378 },
                      { 495, 378 },
                      { 435, 378 },
                      { 375, 378 },
                      { 375, 438 },
                      { 375, 498 },
                      { 375, 558 },
                      { 375, 618 },
                      { 313, 618 },
                      { 250, 618 }, // start zolty
                      { 250, 558 },
                      { 250, 498 },
                      { 250, 438 },
                      { 250, 378 },
                      { 190, 378 },
                      { 130, 378 },
                      { 70, 378 },
                      { 10, 378 },
                      { 10, 318 }};
int domek_czerwony[4][2] = { { 70, 318 },
                             { 130, 318 },
                             { 190, 318 },
                             { 250, 318 } };
int domek_niebieski[4][2] = { { 313, 75},
                              { 313, 135 },
                              { 313, 195 },
                              { 313, 255 } };
int domek_zielony[4][2] = { { 555, 318},
                            { 495, 318 },
                            { 435, 318 },
                            { 375, 318 } };
int domek_zolty[4][2] = { { 313, 558},
                          { 313, 498 },
                          { 313, 438 },
                          { 313, 378 } };
int ilosc_czerwonych_w_domku = 0, ilosc_niebieskich_w_domku = 0, ilosc_zielonych_w_domku = 0, ilosc_zoltych_w_domku = 0;
bool isGameOn = false;  //czy gra zosta³a zaczêta
bool isPlayerdrawn;   //czy zaczynaj¹cy gracz zosta³ ju¿ wylosowany
//int value;   //wartoœæ rzutu kostk¹, do przesuwania po planszy
int y_val, r_val, b_val, g_val;   //wartoœci rzutu kostk¹ dla poszczególnych graczy

///////////////test////////////////////


vector <kolor> grajace_kolory;
kolor aktualny;

void next()
{
  for (int i = 0; i < grajace_kolory.size(); i++)
  {
    if (i < grajace_kolory.size() - 1)
    {
      if (aktualny == grajace_kolory[i])
      {
        aktualny = grajace_kolory[i + 1];
        break;
      }
    }
    else
    {
      aktualny = grajace_kolory[0];
      break;
    }
  }
};

Player *zolty = new Player(yellow);
Player *czerwony = new Player(red);
Player *niebieski = new Player(blue);
Player *zielony = new Player(green);

Pole *Pole0 = new Pole(0, 10, 258);
Pole *Pole1 = new Pole(1, 70, 258);
Pole *Pole2 = new Pole(2, 130, 258);
Pole *Pole3 = new Pole(3, 190, 258);
Pole *Pole4 = new Pole(4, 250, 258);
Pole *Pole5 = new Pole(5, 250, 195);
Pole *Pole6 = new Pole(6, 250, 135);
Pole *Pole7 = new Pole(7, 250, 75);
Pole *Pole8 = new Pole(8, 250, 15);
Pole *Pole9 = new Pole(9, 313, 15);
Pole *Pole10 = new Pole(10, 375, 15);
Pole *Pole11 = new Pole(11, 375, 75);
Pole *Pole12 = new Pole(12, 375, 135);
Pole *Pole13 = new Pole(13, 375, 195);
Pole *Pole14 = new Pole(14, 375, 258);
Pole *Pole15 = new Pole(15, 435, 258);
Pole *Pole16 = new Pole(16, 495, 258);
Pole *Pole17 = new Pole(17, 555, 258);
Pole *Pole18 = new Pole(18, 615, 258);
Pole *Pole19 = new Pole(19, 615, 318);
Pole *Pole20 = new Pole(20, 615, 378);
Pole *Pole21 = new Pole(21, 555, 378);
Pole *Pole22 = new Pole(22, 495, 378);
Pole *Pole23 = new Pole(23, 435, 378);
Pole *Pole24 = new Pole(24, 375, 378);
Pole *Pole25 = new Pole(25, 375, 438);
Pole *Pole26 = new Pole(26, 375, 498);
Pole *Pole27 = new Pole(27, 375, 558);
Pole *Pole28 = new Pole(28, 375, 618);
Pole *Pole29 = new Pole(29, 313, 618);
Pole *Pole30 = new Pole(30, 250, 618);
Pole *Pole31 = new Pole(31, 250, 558);
Pole *Pole32 = new Pole(32, 250, 498);
Pole *Pole33 = new Pole(33, 250, 438);
Pole *Pole34 = new Pole(34, 250, 378);
Pole *Pole35 = new Pole(35, 190, 378);
Pole *Pole36 = new Pole(36, 130, 378);
Pole *Pole37 = new Pole(37, 70, 378);
Pole *Pole38 = new Pole(38, 10, 378);
Pole *Pole39 = new Pole(39, 10, 318);

vector <Pole*> Plansza;


Pole *Domek_Red1 = new Pole(100, 15, 10);
Pole *Domek_Red2 = new Pole(101, 75, 10);
Pole *Domek_Red3 = new Pole(102, 15, 75);
Pole *Domek_Red4 = new Pole(103, 75, 75);

Pole *Domek_Blue1 = new Pole(200, 313, 75);
Pole *Domek_Blue2 = new Pole(201, 313, 135);
Pole *Domek_Blue3 = new Pole(202, 313, 195);
Pole *Domek_Blue4 = new Pole(203, 313, 255);

Pole *Domek_Green1 = new Pole(300, 555, 318);
Pole *Domek_Green2 = new Pole(301, 495, 318);
Pole *Domek_Green3 = new Pole(302, 435, 318);
Pole *Domek_Green4 = new Pole(303, 375, 318);

Pole *Domek_Yellow1 = new Pole(400, 313, 558);
Pole *Domek_Yellow2 = new Pole(401, 313, 498);
Pole *Domek_Yellow3 = new Pole(402, 313, 438);
Pole *Domek_Yellow4 = new Pole(403, 313, 378);




//////////test/////////////////////////


HINSTANCE hInst;
Board board;
Cube cube;
vector <int> drawing;  //wektor rzutów przy losowaniu
vector <int> placing;  //wektor pokazuj¹cy, ogo nale¿y usun¹æ z losowania (kto rzuci³ najmniej)
int drawing_max;    //najwiêkszy rzut
int tries = 0;    //iloœæ prób wyjœcia z domku
int length = 0; //sprawdzanie d³ugoœci wektora do czyszczenia drawing
int size_kolor = 0; //d³ugoœæ wektora kolorów
bool firstdraw = true;   //dotyczy pierwszego losowania
int wartosc_kostki = 0;
bool dice_click = false; //czy kostka zosta³a naciœniêta
bool moved = true; //czy kostka zosta³a rzucona przed ruchem

//zmienne zawierajace aktualne pozycje wszystkich pionkow
int akt_pozycja_red1[2]{ 15, 10 }, akt_pozycja_red2[2]{ 75, 10 }, akt_pozycja_red3[2]{ 15, 75 }, akt_pozycja_red4[2]{ 75, 75 };
int akt_pozycja_green1[2]{ 555, 565 }, akt_pozycja_green2[2]{ 614, 565 }, akt_pozycja_green3[2]{ 555, 630 }, akt_pozycja_green4[2]{ 614, 630 };
int akt_pozycja_blue1[2]{ 555, 10 }, akt_pozycja_blue2[2]{ 614, 10 }, akt_pozycja_blue3[2]{ 555, 75 }, akt_pozycja_blue4[2]{ 614, 75 };
int akt_pozycja_yellow1[2]{ 15, 565 }, akt_pozycja_yellow2[2]{ 75, 565 }, akt_pozycja_yellow3[2]{ 15, 630 }, akt_pozycja_yellow4[2]{ 75, 630 };
//---!!!---
//zmienne do wyliczania przesuniecia pionka
int pop_pozycja_red1 = 0, pop_pozycja_red2 = 0, pop_pozycja_red3 = 0, pop_pozycja_red4 = 0;
int pop_pozycja_green1 = 20, pop_pozycja_green2 = 0, pop_pozycja_green3 = 0, pop_pozycja_green4 = 0;
int pop_pozycja_blue1 = 10, pop_pozycja_blue2 = 0, pop_pozycja_blue3 = 0, pop_pozycja_blue4 = 0;
int pop_pozycja_yellow1 = 30, pop_pozycja_yellow2 = 0, pop_pozycja_yellow3 = 0, pop_pozycja_yellow4 = 0;
//---!!!---
//zmienne do umieszczenia pionków w domkach
int poczatkowy_ruch_red1 = 0;
int poczatkowy_ruch_green1 = 0;
int poczatkowy_ruch_blue1 = 0;
int poczatkowy_ruch_yellow1 = 0;
//---!!!---
//zmienne zawierajace informacje o tym czy dany pionek jest wystawiony 
bool red1_wystawiony = false, red2_wystawiony = false, red3_wystawiony = false, red4_wystawiony = false;
bool green1_wystawiony = false, green2_wystawiony = false, green3_wystawiony = false, green4_wystawiony = false;
bool blue1_wystawiony = false, blue2_wystawiony = false, blue3_wystawiony = false, blue4_wystawiony = false;
bool yellow1_wystawiony = false, yellow2_wystawiony = false, yellow3_wystawiony = false, yellow4_wystawiony = false;
//---!!!---
//zmienne zawierajace informacje o tym czy dany pionek jest w domku 
bool red1_w_domku = false, red2_w_domku = false, red3_w_domku = false, red4_w_domku = false;
bool green1_w_domku = false, green2_w_domku = false, green3_w_domku = false, green4_w_domku = false;
bool blue1_w_domku = false, blue2_w_domku = false, blue3_w_domku = false, blue4_w_domku = false;
bool yellow1_w_domku = false, yellow2_w_domku = false, yellow3_w_domku = false, yellow4_w_domku = false;
//---!!!---
void RysowaniePionkow(HDC hdc)
{
  board.drawBoard(hdc);
  board.drawGreen(hdc, akt_pozycja_green1[0], akt_pozycja_green1[1]);
  board.drawGreen(hdc, akt_pozycja_green2[0], akt_pozycja_green2[1]);
  board.drawGreen(hdc, akt_pozycja_green3[0], akt_pozycja_green3[1]);
  board.drawGreen(hdc, akt_pozycja_green4[0], akt_pozycja_green4[1]);
  board.drawBlue(hdc, akt_pozycja_blue1[0], akt_pozycja_blue1[1]);
  board.drawBlue(hdc, akt_pozycja_blue2[0], akt_pozycja_blue2[1]);
  board.drawBlue(hdc, akt_pozycja_blue3[0], akt_pozycja_blue3[1]);
  board.drawBlue(hdc, akt_pozycja_blue4[0], akt_pozycja_blue4[1]);
  board.drawYellow(hdc, akt_pozycja_yellow1[0], akt_pozycja_yellow1[1]);
  board.drawYellow(hdc, akt_pozycja_yellow2[0], akt_pozycja_yellow2[1]);
  board.drawYellow(hdc, akt_pozycja_yellow3[0], akt_pozycja_yellow3[1]);
  board.drawYellow(hdc, akt_pozycja_yellow4[0], akt_pozycja_yellow4[1]);
  board.drawRed(hdc, akt_pozycja_red1[0], akt_pozycja_red1[1]);
  board.drawRed(hdc, akt_pozycja_red2[0], akt_pozycja_red2[1]);
  board.drawRed(hdc, akt_pozycja_red3[0], akt_pozycja_red3[1]);
  board.drawRed(hdc, akt_pozycja_red4[0], akt_pozycja_red4[1]);
}
void fillPlacing()
{
  placing.clear();
  for (int i = 0; i < drawing.size(); i++)
  {
    placing.push_back(i);
  }
}
void maxdraw()
{
  int max = 0;
  int place = 0;
  int erasing = 0;
  for (int i = 0; i < drawing.size(); i++)
  {
    if ((drawing[i]) > max)
    {
      max = drawing[i];

      fillPlacing();
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
void losuj_gracza(HWND hwndDlg)
{
  if (length == size_kolor)
  {
    drawing.clear();
    placing.clear();
    length = 0;
  }
  if (length == 0)
  {
    size_kolor = grajace_kolory.size();
  }
  switch (aktualny)
  {
  case yellow: {
    y_val = cube.kostka(hwndDlg);
    CHAR szText[500];
    HWND hwndstatic_y = GetDlgItem(hwndDlg, IDC_STATIC_YELLOW);
    wsprintf(szText, "Wylosowano: %d", y_val);
    SetWindowText(hwndstatic_y, szText);
    CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_YELLOW);
    drawing.push_back(y_val);
    if (grajace_kolory.size() != 1)
    {
      next();
    }
    break;
  }
  case red: {
    r_val = cube.kostka(hwndDlg);
    CHAR szText[500];
    HWND hwndstatic_r = GetDlgItem(hwndDlg, IDC_STATIC_RED);
    wsprintf(szText, "Wylosowano: %d", r_val);
    SetWindowText(hwndstatic_r, szText);
    CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_RED);
    drawing.push_back(r_val);
    if (drawing.size() == size_kolor)
    {
      int erasing = 0;
      maxdraw();
      for (int i = 0; i < placing.size(); i++)
      {
        for (int j = 0; j < 4; j++)
        {
          if (placing[i] == j)
          {
            if ((grajace_kolory[j - erasing]) == (grajace_kolory[grajace_kolory.size() - 1]))
            {
              grajace_kolory.pop_back();
              erasing++;
            }
            else
            {
              grajace_kolory.erase(grajace_kolory.begin() + j - erasing);
              erasing++;
            }
            break;
          }
        }
      }
    }
    if (grajace_kolory.size() != 1)
    {
      next();
    }
    break;
  }
  case blue: {
    b_val = cube.kostka(hwndDlg);
    CHAR szText[500];
    HWND hwndstatic_b = GetDlgItem(hwndDlg, IDC_STATIC_BLUE);
    wsprintf(szText, "Wylosowano: %d", b_val);
    SetWindowText(hwndstatic_b, szText);
    CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_BLUE);
    drawing.push_back(b_val);
    if (drawing.size() == size_kolor)
    {
      int erasing = 0;
      maxdraw();
      for (int i = 0; i < placing.size(); i++)
      {
        for (int j = 0; j < 4; j++)
        {
          if (placing[i] == j)
          {
            if ((grajace_kolory[j - erasing]) == (grajace_kolory[grajace_kolory.size() - 1]))
            {
              grajace_kolory.pop_back();
              erasing++;
            }
            else
            {
              grajace_kolory.erase(grajace_kolory.begin() + j - erasing);
              erasing++;
            }
            break;
          }
        }
      }
    }
    if (grajace_kolory.size() != 1)
    {
      next();
    }
    break;
  }
  case green: {
    g_val = cube.kostka(hwndDlg);
    CHAR szText[500];
    HWND hwndstatic_g = GetDlgItem(hwndDlg, IDC_STATIC_GREEN);
    wsprintf(szText, "Wylosowano: %d", g_val);
    SetWindowText(hwndstatic_g, szText);
    CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_GREEN);
    drawing.push_back(g_val);
    if (drawing.size() == size_kolor)
    {
      int erasing = 0;
      maxdraw();
      for (int i = 0; i < placing.size(); i++)
      {
        for (int j = 0; j < 4; j++)
        {
          if (placing[i] == j)
          {
            if ((grajace_kolory[j - erasing]) == (grajace_kolory[grajace_kolory.size() - 1]))
            {
              grajace_kolory.pop_back();
              erasing++;
            }
            else
            {
              grajace_kolory.erase(grajace_kolory.begin() + j - erasing);
              erasing++;
            }
            break;
          }
        }
      }
    }
      if (grajace_kolory.size() != 1)
      {
        next();
      }
      break;
    }
  }
  length++;
}
void wystaw_pionka(HWND hwnDlg, HDC hdc)
{
  switch (aktualny)
  {
  case yellow:
    if(!yellow1_wystawiony && akt_pozycja_yellow2[0] != 250 && akt_pozycja_yellow2[1] != 618 //sprawdz czy pionek nie jest wystawiony i czy nie stoi tam inny pionek
                           && akt_pozycja_yellow3[0] != 250 && akt_pozycja_yellow3[1] != 618
                           && akt_pozycja_yellow4[0] != 250 && akt_pozycja_yellow4[1] != 618)
    {
      akt_pozycja_yellow1[0] = 250;
      akt_pozycja_yellow1[1] = 618;
      board.drawYellow(hdc, akt_pozycja_yellow1[0], akt_pozycja_yellow1[1]);
      RysowaniePionkow(hdc);//odrysowanie planszy z aktualnymi pozycjami wszystkich pionkow
      yellow1_wystawiony = true;
      break;
    }
    if (!yellow2_wystawiony && akt_pozycja_yellow1[0] != 250 && akt_pozycja_yellow1[1] != 618 //sprawdz czy pionek nie jest wystawiony i czy nie stoi tam inny pionek
                            && akt_pozycja_yellow3[0] != 250 && akt_pozycja_yellow3[1] != 618
                            && akt_pozycja_yellow4[0] != 250 && akt_pozycja_yellow4[1] != 618)
    {
      akt_pozycja_yellow2[0] = 250;
      akt_pozycja_yellow2[1] = 618;
      board.drawYellow(hdc, akt_pozycja_yellow2[0], akt_pozycja_yellow2[1]);
      RysowaniePionkow(hdc);
      yellow2_wystawiony = true;
      break;
    }
    if (!yellow3_wystawiony && akt_pozycja_yellow2[0] != 250 && akt_pozycja_yellow2[1] != 618 //sprawdz czy pionek nie jest wystawiony i czy nie stoi tam inny pionek
                            && akt_pozycja_yellow1[0] != 250 && akt_pozycja_yellow1[1] != 618
                            && akt_pozycja_yellow4[0] != 250 && akt_pozycja_yellow4[1] != 618)
    {
      akt_pozycja_yellow3[0] = 250;
      akt_pozycja_yellow3[1] = 618;
      board.drawYellow(hdc, akt_pozycja_yellow3[0], akt_pozycja_yellow3[1]);
      RysowaniePionkow(hdc);
      yellow3_wystawiony = true;
      break;
    }
    if (!yellow4_wystawiony && akt_pozycja_yellow2[0] != 250 && akt_pozycja_yellow2[1] != 618 //sprawdz czy pionek nie jest wystawiony i czy nie stoi tam inny pionek
                            && akt_pozycja_yellow3[0] != 250 && akt_pozycja_yellow3[1] != 618
                            && akt_pozycja_yellow1[0] != 250 && akt_pozycja_yellow1[1] != 618)
    {
      akt_pozycja_yellow4[0] = 250;
      akt_pozycja_yellow4[1] = 618;
      board.drawYellow(hdc, akt_pozycja_yellow4[0], akt_pozycja_yellow4[1]);
      RysowaniePionkow(hdc);
      yellow4_wystawiony = true;
      break;
    }
    break;
  case red:
    if (!red1_wystawiony && akt_pozycja_red2[0] != 10 && akt_pozycja_red2[1] != 258 //sprawdz czy pionek nie jest wystawiony i czy nie stoi tam inny pionek
                         && akt_pozycja_red3[0] != 10 && akt_pozycja_red3[1] != 258
                         && akt_pozycja_red4[0] != 10 && akt_pozycja_red4[1] != 258 && !red1_w_domku)
    {
      akt_pozycja_red1[0] = 10;
      akt_pozycja_red1[1] = 258;
      board.drawRed(hdc, akt_pozycja_red1[0], akt_pozycja_red1[1]);
      RysowaniePionkow(hdc);
      red1_wystawiony = true;
      break;
    }
    if (!red2_wystawiony && akt_pozycja_red1[0] != 10 && akt_pozycja_red1[1] != 258 //sprawdz czy pionek nie jest wystawiony i czy nie stoi tam inny pionek
                          && akt_pozycja_red3[0] != 10 && akt_pozycja_red3[1] != 258
                          && akt_pozycja_red4[0] != 10 && akt_pozycja_red4[1] != 258)
    {
      akt_pozycja_red2[0] = 10;
      akt_pozycja_red2[1] = 258;
      board.drawRed(hdc, akt_pozycja_red2[0], akt_pozycja_red2[1]);
      RysowaniePionkow(hdc);
      red2_wystawiony = true;
      break;
    }
    if (!red3_wystawiony && akt_pozycja_red2[0] != 10 && akt_pozycja_red2[1] != 258 //sprawdz czy pionek nie jest wystawiony i czy nie stoi tam inny pionek
                          && akt_pozycja_red1[0] != 10 && akt_pozycja_red1[1] != 258
                          && akt_pozycja_red4[0] != 10 && akt_pozycja_red4[1] != 258)
    {
      akt_pozycja_red3[0] = 10;
      akt_pozycja_red3[1] = 258;
      board.drawRed(hdc, akt_pozycja_red3[0], akt_pozycja_red3[1]);
      RysowaniePionkow(hdc);
      red3_wystawiony = true;
      break;
    }
    if (!red4_wystawiony && akt_pozycja_red2[0] != 10 && akt_pozycja_red2[1] != 258 //sprawdz czy pionek nie jest wystawiony i czy nie stoi tam inny pionek
                          && akt_pozycja_red3[0] != 10 && akt_pozycja_red3[1] != 258
                          && akt_pozycja_red1[0] != 10 && akt_pozycja_red1[1] != 258)
    {
      akt_pozycja_red4[0] = 10;
      akt_pozycja_red4[1] = 258;
      board.drawRed(hdc, akt_pozycja_red4[0], akt_pozycja_red4[1]);
      RysowaniePionkow(hdc);
      red4_wystawiony = true;
      break;
    }
    break;
  case blue:
    if (!blue1_wystawiony && akt_pozycja_blue2[0] != 375 && akt_pozycja_blue2[1] != 15 //sprawdz czy pionek nie jest wystawiony i czy nie stoi tam inny pionek
                          && akt_pozycja_blue3[0] != 375 && akt_pozycja_blue3[1] != 15
                          && akt_pozycja_blue4[0] != 375 && akt_pozycja_blue4[1] != 15)
    {
      akt_pozycja_blue1[0] = 375;
      akt_pozycja_blue1[1] = 15;
      board.drawBlue(hdc, akt_pozycja_blue1[0], akt_pozycja_blue1[1]);
      RysowaniePionkow(hdc);
      blue1_wystawiony = true;
      break;
    }
    if (!blue2_wystawiony && akt_pozycja_blue1[0] != 375 && akt_pozycja_blue1[1] != 15 //sprawdz czy pionek nie jest wystawiony i czy nie stoi tam inny pionek
                          && akt_pozycja_blue3[0] != 375 && akt_pozycja_blue3[1] != 15
                          && akt_pozycja_blue4[0] != 375 && akt_pozycja_blue4[1] != 15)
    {
      akt_pozycja_blue2[0] = 375;
      akt_pozycja_blue2[1] = 15;
      board.drawBlue(hdc, akt_pozycja_blue2[0], akt_pozycja_blue2[1]);
      RysowaniePionkow(hdc);
      blue2_wystawiony = true;
      break;
    }
    if (!blue3_wystawiony && akt_pozycja_blue2[0] != 375 && akt_pozycja_blue2[1] != 15 //sprawdz czy pionek nie jest wystawiony i czy nie stoi tam inny pionek
                          && akt_pozycja_blue1[0] != 375 && akt_pozycja_blue1[1] != 15
                          && akt_pozycja_blue4[0] != 375 && akt_pozycja_blue4[1] != 15)
    {
      akt_pozycja_blue3[0] = 375;
      akt_pozycja_blue3[1] = 15;
      board.drawBlue(hdc, akt_pozycja_blue3[0], akt_pozycja_blue3[1]);
      RysowaniePionkow(hdc);
      blue3_wystawiony = true;
      break;
    }
    if (!blue4_wystawiony && akt_pozycja_blue2[0] != 375 && akt_pozycja_blue2[1] != 15 //sprawdz czy pionek nie jest wystawiony i czy nie stoi tam inny pionek
                          && akt_pozycja_blue3[0] != 375 && akt_pozycja_blue3[1] != 15
                          && akt_pozycja_blue1[0] != 375 && akt_pozycja_blue1[1] != 15)
    {
      akt_pozycja_blue4[0] = 375;
      akt_pozycja_blue4[1] = 15;
      board.drawBlue(hdc, akt_pozycja_blue4[0], akt_pozycja_blue4[1]);
      RysowaniePionkow(hdc);
      blue4_wystawiony = true;
      break;
    }
    break;
  case green:
    if (!green1_wystawiony && akt_pozycja_green2[0] != 615 && akt_pozycja_green2[1] != 378 //sprawdz czy pionek nie jest wystawiony i czy nie stoi tam inny pionek
                           && akt_pozycja_green3[0] != 615 && akt_pozycja_green3[1] != 378
                           && akt_pozycja_green4[0] != 615 && akt_pozycja_green4[1] != 378)
    {
      akt_pozycja_green1[0] = 615;
      akt_pozycja_green1[1] = 378;
      board.drawGreen(hdc, akt_pozycja_green1[0], akt_pozycja_green1[1]);
      RysowaniePionkow(hdc);
      green1_wystawiony = true;
      break;
    }
    if (!green2_wystawiony && akt_pozycja_green1[0] != 615 && akt_pozycja_green1[1] != 378
                           && akt_pozycja_green3[0] != 615 && akt_pozycja_green3[1] != 378
                           && akt_pozycja_green4[0] != 615 && akt_pozycja_green4[1] != 378)
    {
      akt_pozycja_green2[0] = 615;
      akt_pozycja_green2[1] = 378;
      board.drawGreen(hdc, akt_pozycja_green2[0], akt_pozycja_green2[1]);
      RysowaniePionkow(hdc);
      green2_wystawiony = true;
      break;
    }
    if (!green3_wystawiony && akt_pozycja_green1[0] != 615 && akt_pozycja_green1[1] != 378
                           && akt_pozycja_green2[0] != 615 && akt_pozycja_green2[1] != 378
                           && akt_pozycja_green4[0] != 615 && akt_pozycja_green4[1] != 378)
    {
      akt_pozycja_green3[0] = 615;
      akt_pozycja_green3[1] = 378;
      board.drawGreen(hdc, akt_pozycja_green3[0], akt_pozycja_green3[1]);
      RysowaniePionkow(hdc);
      green3_wystawiony = true;
      break;
    }
    if (!green4_wystawiony && akt_pozycja_green1[0] != 615 && akt_pozycja_green1[1] != 378
                            && akt_pozycja_green2[0] != 615 && akt_pozycja_green2[1] != 378
                            && akt_pozycja_green3[0] != 615 && akt_pozycja_green3[1] != 378)
    {
      akt_pozycja_green4[0] = 615;
      akt_pozycja_green4[1] = 378;
      board.drawGreen(hdc, akt_pozycja_green4[0], akt_pozycja_green4[1]);
      RysowaniePionkow(hdc);
      green4_wystawiony = true;
      break;
    }
    break;

  }
}
void rzut_kostka3(HWND hwndDlg, HDC hdc, int draw)
{
      tries++;
      //int draw = kostka(hwndDlg);
      if (draw == 6)
      {
        wystaw_pionka(hwndDlg, hdc);
        switch (aktualny)
        {
        case yellow:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_RED);
          next();
          break;
        case red:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_BLUE);
          next();
          break;
        case blue:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_GREEN);
          next();
          break;
        case green:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_YELLOW);
          next();
          break;
        }
        tries = 0;
        return;
      }
      if (tries == 3)
      {
        switch (aktualny)
        {
        case yellow:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_RED);
          next();
          break;
        case red:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_BLUE);
          next();
          break;
        case blue:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_GREEN);
          next();
          break;
        case green:
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_YELLOW);
          next();
          break;
        }
        tries = 0;
      }
}
void sprawdz_wygranego(HWND hwndDlg)
{
  if (grajace_kolory.size() == 1)
  {
    Sleep(2000);
    aktualny = grajace_kolory[0];
    char szText[500];
    switch (aktualny)
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
    grajace_kolory.clear();
    grajace_kolory.push_back(yellow);
    grajace_kolory.push_back(red);
    grajace_kolory.push_back(blue);
    grajace_kolory.push_back(green);
    firstdraw = false;
  }
}

INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
  switch (uMsg)
  {
  case WM_INITDIALOG:
  {
    Plansza.push_back(Pole0);
    Plansza.push_back(Pole1);
    Plansza.push_back(Pole2);
    Plansza.push_back(Pole3);
    Plansza.push_back(Pole4);
    Plansza.push_back(Pole5);
    Plansza.push_back(Pole6);
    Plansza.push_back(Pole7);
    Plansza.push_back(Pole8);
    Plansza.push_back(Pole9);
    Plansza.push_back(Pole10);
    Plansza.push_back(Pole11);
    Plansza.push_back(Pole12);
    Plansza.push_back(Pole13);
    Plansza.push_back(Pole14);
    Plansza.push_back(Pole15);
    Plansza.push_back(Pole16);
    Plansza.push_back(Pole17);
    Plansza.push_back(Pole18);
    Plansza.push_back(Pole19);
    Plansza.push_back(Pole20);
    Plansza.push_back(Pole21);
    Plansza.push_back(Pole22);
    Plansza.push_back(Pole23);
    Plansza.push_back(Pole24);
    Plansza.push_back(Pole25);
    Plansza.push_back(Pole26);
    Plansza.push_back(Pole27);
    Plansza.push_back(Pole28);
    Plansza.push_back(Pole29);
    Plansza.push_back(Pole30);
    Plansza.push_back(Pole31);
    Plansza.push_back(Pole32);
    Plansza.push_back(Pole33);
    Plansza.push_back(Pole34);
    Plansza.push_back(Pole35);
    Plansza.push_back(Pole36);
    Plansza.push_back(Pole37);
    Plansza.push_back(Pole38);
    Plansza.push_back(Pole39);
    board.init_dialog(hInst);
    cube.init_dialog(hInst);
    HWND hwndButton = GetDlgItem(hwndDlg, IDC_BUTTON_START);//    WNDPROC wpOrgButtonProc = (WNDPROC)SetWindowLong(hwndButton, -4, (LONG)ButtonWndProc);
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
          RysowaniePionkow(hdc);
          cube.DrawOne(hdc);
          board.DrawDog(hdc);
          board.DrawDog2(hdc);
          board.DrawDog3(hdc);
          board.DrawDog4(hdc);
          ReleaseDC(hwndDlg, hdc);
          kolor aktualny = yellow;
          grajace_kolory.push_back(yellow);
          grajace_kolory.push_back(red);
          grajace_kolory.push_back(blue);
          grajace_kolory.push_back(green);



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
        }
      return TRUE;
    }
  }
    return FALSE;
  case WM_LBUTTONDOWN: {
    if (isGameOn == true)
    {
      HDC hdc = GetDC(hwndDlg);
      int x = LOWORD(lParam); int y = HIWORD(lParam);

      if ((x > 750 && x < 845) && (y > 400 && y < 495))
        {
          if (isGameOn == true && isPlayerdrawn == true)
          {
            switch (aktualny)
            {
            case yellow:
            {
              if (!yellow1_wystawiony && !yellow2_wystawiony && !yellow3_wystawiony && !yellow4_wystawiony)
              {
                wartosc_kostki = cube.kostka(hwndDlg);
                rzut_kostka3(hwndDlg, hdc, wartosc_kostki);
              }
              else if (dice_click == false)
              {
                cube.kostka(hwndDlg);
                dice_click = true;
                moved = false;
              }
              break;
            }
            case red:
            {
              if (!red1_wystawiony && !red2_wystawiony && !red3_wystawiony && !red4_wystawiony)
              {
                wartosc_kostki = cube.kostka(hwndDlg);
                rzut_kostka3(hwndDlg, hdc, wartosc_kostki);
              }
              else if (dice_click == false)
              {
                cube.kostka(hwndDlg);
                dice_click = true;
                moved = false;
              }
              break;
            }
            case blue:
            {
              if (!blue1_wystawiony && !blue2_wystawiony && !blue3_wystawiony && !blue4_wystawiony)
              {
                wartosc_kostki = cube.kostka(hwndDlg);
                rzut_kostka3(hwndDlg, hdc, wartosc_kostki);
              }
              else if (dice_click == false)
              {
                cube.kostka(hwndDlg);
                dice_click = true;
                moved = false;
              }
              break;
            }
            case green:
            {
              if (!green1_wystawiony && !green2_wystawiony && !green3_wystawiony && !green4_wystawiony && aktualny == green)
              {
                wartosc_kostki = cube.kostka(hwndDlg);
                rzut_kostka3(hwndDlg, hdc, wartosc_kostki);
              }
              else if (dice_click == false)
              {
                cube.kostka(hwndDlg);
                dice_click = true;
                moved = false;
              }
              break;
            }
            }
          }
          if (isGameOn == true && isPlayerdrawn == false)
          {
            losuj_gracza(hwndDlg);
            sprawdz_wygranego(hwndDlg);
          }
        }
      if (moved == false)
      {
        if ((x > akt_pozycja_red1[0] && x < (akt_pozycja_red1[0] + 59)) && (y > akt_pozycja_red1[1] && y < (akt_pozycja_red1[1] + 59)) && red1_wystawiony
          && aktualny == red && red1_w_domku) // obsluga ruchu pierwszego czerwonego pionka
        {
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_BLUE);
          next();
          RysowaniePionkow(hdc);
          dice_click = false;
        }
        if ((x > akt_pozycja_red1[0] && x < (akt_pozycja_red1[0] + 59)) && (y > akt_pozycja_red1[1] && y < (akt_pozycja_red1[1] + 59)) && red1_wystawiony
          && aktualny == red && !red1_w_domku) // obsluga ruchu pierwszego czerwonego pionka
        {
          poczatkowy_ruch_red1 += cube.value;
          if (poczatkowy_ruch_red1 < 40)
          {
            czerwony->pionki[0]->rusz_pionka(Plansza[poczatkowy_ruch_red1], akt_pozycja_red1);
            Plansza[poczatkowy_ruch_red1]->Ustaw_pionka(czerwony->pionki[0]);
          }
          else if (poczatkowy_ruch_red1 >= 40 && poczatkowy_ruch_red1 < 44)
          {
            akt_pozycja_red1[0] = domek_czerwony[(poczatkowy_ruch_red1)-40][0];
            akt_pozycja_red1[1] = domek_czerwony[(poczatkowy_ruch_red1)-40][1];
            red1_w_domku = true;
          }
          else
          {
            akt_pozycja_red1[0] = domek_czerwony[3 - (poczatkowy_ruch_red1 - 43)][0];
            akt_pozycja_red1[1] = domek_czerwony[3 - (poczatkowy_ruch_red1 - 43)][1];
            red1_w_domku = true;
          }
          moved = true;
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_BLUE);
          next();
          RysowaniePionkow(hdc);
          dice_click = false;
        }
        if ((x > akt_pozycja_red2[0] && x < (akt_pozycja_red2[0] + 59)) && (y > akt_pozycja_red2[1] && y < (akt_pozycja_red2[1] + 59)) && red2_wystawiony
          && aktualny == red) // obsluga ruchu pierwszego czerwonego pionka
        {
          if (pop_pozycja_red2 + cube.value < 40)
          {
            akt_pozycja_red2[0] = plansza[pop_pozycja_red2 + cube.value][0];
            akt_pozycja_red2[1] = plansza[pop_pozycja_red2 + cube.value][1];
            pop_pozycja_red2 += cube.value;
          }
          else
          {
            akt_pozycja_red2[0] = domek_czerwony[(pop_pozycja_red2 + cube.value) - 40][0];
            akt_pozycja_red2[1] = domek_czerwony[(pop_pozycja_red2 + cube.value) - 40][1];
            pop_pozycja_red2 += cube.value;
          }
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_BLUE);
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_red3[0] && x < (akt_pozycja_red3[0] + 59)) && (y > akt_pozycja_red3[1] && y < (akt_pozycja_red3[1] + 59)) && red3_wystawiony
          && aktualny == red) // obsluga ruchu pierwszego czerwonego pionka
        {
          if (pop_pozycja_red3 + cube.value < 40)
          {
            akt_pozycja_red3[0] = plansza[pop_pozycja_red3 + cube.value][0];
            akt_pozycja_red3[1] = plansza[pop_pozycja_red3 + cube.value][1];
            pop_pozycja_red3 += cube.value;
          }
          else
          {
            akt_pozycja_red3[0] = domek_czerwony[(pop_pozycja_red3 + cube.value) - 40][0];
            akt_pozycja_red3[1] = domek_czerwony[(pop_pozycja_red3 + cube.value) - 40][1];
            pop_pozycja_red3 += cube.value;
          }
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_BLUE);
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_red4[0] && x < (akt_pozycja_red4[0] + 59)) && (y > akt_pozycja_red4[1] && y < (akt_pozycja_red4[1] + 59)) && red4_wystawiony
          && aktualny == red) // obsluga ruchu pierwszego czerwonego pionka
        {
          if (pop_pozycja_red4 + cube.value < 40)
          {
            akt_pozycja_red4[0] = plansza[pop_pozycja_red4 + cube.value][0];
            akt_pozycja_red4[1] = plansza[pop_pozycja_red4 + cube.value][1];
            pop_pozycja_red4 += cube.value;
          }
          else
          {
            akt_pozycja_red4[0] = domek_czerwony[(pop_pozycja_red4 + cube.value) - 40][0];
            akt_pozycja_red4[1] = domek_czerwony[(pop_pozycja_red4 + cube.value) - 40][1];
            pop_pozycja_red4 += cube.value;
          }
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_BLUE);
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_blue1[0] && x < (akt_pozycja_blue1[0] + 59)) && (y > akt_pozycja_blue1[1] && y < (akt_pozycja_blue1[1] + 59)) && blue1_wystawiony
          && aktualny == blue && blue1_w_domku) // obsluga ruchu pierwszego czerwonego pionka
        {
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_GREEN);
          next();
          RysowaniePionkow(hdc);
          dice_click = false;
        }
        if ((x > akt_pozycja_blue1[0] && x < (akt_pozycja_blue1[0] + 59)) && (y > akt_pozycja_blue1[1] && y < (akt_pozycja_blue1[1] + 59)) && blue1_wystawiony
          && aktualny == blue && !blue1_w_domku) // obsluga ruchu pierwszego czerwonego pionka
        {
          poczatkowy_ruch_blue1 += cube.value;
          if (poczatkowy_ruch_blue1 >= 40 && poczatkowy_ruch_blue1 < 44)
          {
            akt_pozycja_blue1[0] = domek_niebieski[(poczatkowy_ruch_blue1)-40][0];
            akt_pozycja_blue1[1] = domek_niebieski[(poczatkowy_ruch_blue1)-40][1];
            blue1_w_domku = true;
          }
          else if (poczatkowy_ruch_blue1 >= 44)
          {
            akt_pozycja_blue1[0] = domek_niebieski[3 - (poczatkowy_ruch_blue1 - 43)][0];
            akt_pozycja_blue1[1] = domek_niebieski[3 - (poczatkowy_ruch_blue1 - 43)][1];
            blue1_w_domku = true;
          }
          else if (poczatkowy_ruch_blue1 + pop_pozycja_blue1 < 40)
          {
            niebieski->pionki[0]->rusz_pionka(Plansza[poczatkowy_ruch_blue1 + pop_pozycja_blue1], akt_pozycja_blue1);
          }
          else if (poczatkowy_ruch_blue1 + pop_pozycja_blue1 >= 40)
          {
            pop_pozycja_blue1 -= 40;
            niebieski->pionki[0]->rusz_pionka(Plansza[poczatkowy_ruch_blue1 + pop_pozycja_blue1], akt_pozycja_blue1);

          }
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_GREEN);
          dice_click = false;
          moved = true;
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_blue2[0] && x < (akt_pozycja_blue2[0] + 59)) && (y > akt_pozycja_blue2[1] && y < (akt_pozycja_blue2[1] + 59)) && blue2_wystawiony
          && aktualny == blue) // obsluga ruchu pierwszego czerwonego pionka
        {
          akt_pozycja_blue2[0] = plansza[pop_pozycja_blue2 + cube.value][0];
          akt_pozycja_blue2[1] = plansza[pop_pozycja_blue2 + cube.value][1];
          pop_pozycja_blue2 += cube.value;
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_GREEN);
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_blue3[0] && x < (akt_pozycja_blue3[0] + 59)) && (y > akt_pozycja_blue3[1] && y < (akt_pozycja_blue3[1] + 59)) && blue3_wystawiony
          && aktualny == blue) // obsluga ruchu pierwszego czerwonego pionka
        {
          akt_pozycja_blue3[0] = plansza[pop_pozycja_blue3 + cube.value][0];
          akt_pozycja_blue3[1] = plansza[pop_pozycja_blue3 + cube.value][1];
          pop_pozycja_blue3 += cube.value;
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_GREEN);
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_blue4[0] && x < (akt_pozycja_blue4[0] + 59)) && (y > akt_pozycja_blue4[1] && y < (akt_pozycja_blue4[1] + 59)) && blue4_wystawiony
          && aktualny == blue) // obsluga ruchu pierwszego czerwonego pionka
        {
          akt_pozycja_blue4[0] = plansza[pop_pozycja_blue4 + cube.value][0];
          akt_pozycja_blue4[1] = plansza[pop_pozycja_blue4 + cube.value][1];
          pop_pozycja_blue4 += cube.value;
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_GREEN);
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_green1[0] && x < (akt_pozycja_green1[0] + 59)) && (y > akt_pozycja_green1[1] && y < (akt_pozycja_green1[1] + 59)) && green1_wystawiony
          && aktualny == green && green1_w_domku) // obsluga ruchu pierwszego czerwonego pionka
        {
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_YELLOW);
          dice_click = false;
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_green1[0] && x < (akt_pozycja_green1[0] + 59)) && (y > akt_pozycja_green1[1] && y < (akt_pozycja_green1[1] + 59)) && green1_wystawiony
          && aktualny == green && !green1_w_domku) // obsluga ruchu pierwszego czerwonego pionka
        {
          poczatkowy_ruch_green1 += cube.value;
          if (poczatkowy_ruch_green1 >= 40 && poczatkowy_ruch_green1 < 44)
          {
            akt_pozycja_green1[0] = domek_zielony[(poczatkowy_ruch_green1)-40][0];
            akt_pozycja_green1[1] = domek_zielony[(poczatkowy_ruch_green1)-40][1];
            green1_w_domku = true;
          }
          else if (poczatkowy_ruch_green1 >= 44)
          {
            akt_pozycja_green1[0] = domek_zielony[3 - (poczatkowy_ruch_green1 - 43)][0];
            akt_pozycja_green1[1] = domek_zielony[3 - (poczatkowy_ruch_green1 - 43)][1];
            green1_w_domku = true;
          }
          else if (poczatkowy_ruch_green1 + pop_pozycja_green1 < 40)
          {
            zielony->pionki[0]->rusz_pionka(Plansza[poczatkowy_ruch_green1 + pop_pozycja_green1], akt_pozycja_green1);
          }
          else if (poczatkowy_ruch_green1 + pop_pozycja_green1 >= 40)
          {
            pop_pozycja_green1 -= 40;
            zielony->pionki[0]->rusz_pionka(Plansza[poczatkowy_ruch_green1 + pop_pozycja_green1], akt_pozycja_green1);
          }
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_YELLOW);
          dice_click = false;
          moved = true;
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_green2[0] && x < (akt_pozycja_green2[0] + 59)) && (y > akt_pozycja_green2[1] && y < (akt_pozycja_green2[1] + 59)) && green2_wystawiony
          && aktualny == green) // obsluga ruchu pierwszego czerwonego pionka
        {
          akt_pozycja_green2[0] = plansza[pop_pozycja_green2 + cube.value][0];
          akt_pozycja_green2[1] = plansza[pop_pozycja_green2 + cube.value][1];
          pop_pozycja_green2 += cube.value;
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_YELLOW);
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_green3[0] && x < (akt_pozycja_green3[0] + 59)) && (y > akt_pozycja_green3[1] && y < (akt_pozycja_green3[1] + 59)) && green3_wystawiony
          && aktualny == green) // obsluga ruchu pierwszego czerwonego pionka
        {
          akt_pozycja_green3[0] = plansza[pop_pozycja_green3 + cube.value][0];
          akt_pozycja_green3[1] = plansza[pop_pozycja_green3 + cube.value][1];
          pop_pozycja_green3 += cube.value;
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_YELLOW);
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_green4[0] && x < (akt_pozycja_green4[0] + 59)) && (y > akt_pozycja_green4[1] && y < (akt_pozycja_green4[1] + 59)) && green4_wystawiony
          && aktualny == green) // obsluga ruchu pierwszego czerwonego pionka
        {
          akt_pozycja_green4[0] = plansza[pop_pozycja_green4 + cube.value][0];
          akt_pozycja_green4[1] = plansza[pop_pozycja_green4 + cube.value][1];
          pop_pozycja_green4 += cube.value;
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_YELLOW);
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_yellow1[0] && x < (akt_pozycja_yellow1[0] + 59)) && (y > akt_pozycja_yellow1[1] && y < (akt_pozycja_yellow1[1] + 59)) && yellow1_wystawiony
          && aktualny == yellow && yellow1_w_domku) // obsluga ruchu pierwszego czerwonego pionka
        {
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_RED);
          dice_click = false;
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_yellow1[0] && x < (akt_pozycja_yellow1[0] + 59)) && (y > akt_pozycja_yellow1[1] && y < (akt_pozycja_yellow1[1] + 59)) && yellow1_wystawiony
          && aktualny == yellow && !yellow1_w_domku) // obsluga ruchu pierwszego czerwonego pionka
        {
          poczatkowy_ruch_yellow1 += cube.value;
          if (poczatkowy_ruch_yellow1 >= 40 && poczatkowy_ruch_yellow1 < 44)
          {
            akt_pozycja_yellow1[0] = domek_zolty[(poczatkowy_ruch_yellow1)-40][0];
            akt_pozycja_yellow1[1] = domek_zolty[(poczatkowy_ruch_yellow1)-40][1];
            yellow1_w_domku = true;
          }
          else if (poczatkowy_ruch_yellow1 >= 44)
          {
            akt_pozycja_yellow1[0] = domek_zolty[3 - (poczatkowy_ruch_yellow1 - 43)][0];
            akt_pozycja_yellow1[1] = domek_zolty[3 - (poczatkowy_ruch_yellow1 - 43)][1];
            yellow1_w_domku = true;
          }
          else if (poczatkowy_ruch_yellow1 + pop_pozycja_yellow1 < 40)
          {
            zolty->pionki[0]->rusz_pionka(Plansza[poczatkowy_ruch_yellow1 + pop_pozycja_yellow1], akt_pozycja_yellow1);
          }
          else if (poczatkowy_ruch_yellow1 + pop_pozycja_yellow1 >= 40)
          {
            pop_pozycja_yellow1 -= 40;
            zolty->pionki[0]->rusz_pionka(Plansza[poczatkowy_ruch_yellow1 + pop_pozycja_yellow1], akt_pozycja_yellow1);
          }
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_RED);
          dice_click = false;
          moved = true;
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_yellow2[0] && x < (akt_pozycja_yellow2[0] + 59)) && (y > akt_pozycja_yellow2[1] && y < (akt_pozycja_yellow2[1] + 59)) && yellow2_wystawiony
          && aktualny == yellow) // obsluga ruchu pierwszego czerwonego pionka
        {
          akt_pozycja_yellow2[0] = plansza[pop_pozycja_yellow2 + cube.value][0];
          akt_pozycja_yellow2[1] = plansza[pop_pozycja_yellow2 + cube.value][1];
          pop_pozycja_yellow2 += cube.value;
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_RED);
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_yellow3[0] && x < (akt_pozycja_yellow3[0] + 59)) && (y > akt_pozycja_yellow3[1] && y < (akt_pozycja_yellow3[1] + 59)) && yellow3_wystawiony
          && aktualny == yellow) // obsluga ruchu pierwszego czerwonego pionka
        {
          akt_pozycja_yellow3[0] = plansza[pop_pozycja_yellow3 + cube.value][0];
          akt_pozycja_yellow3[1] = plansza[pop_pozycja_yellow3 + cube.value][1];
          pop_pozycja_yellow3 += cube.value;
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_RED);
          next();
          RysowaniePionkow(hdc);
        }
        if ((x > akt_pozycja_yellow4[0] && x < (akt_pozycja_yellow4[0] + 59)) && (y > akt_pozycja_yellow4[1] && y < (akt_pozycja_yellow4[1] + 59)) && yellow4_wystawiony
          && aktualny == yellow) // obsluga ruchu pierwszego czerwonego pionka
        {
          akt_pozycja_yellow4[0] = plansza[pop_pozycja_yellow4 + cube.value][0];
          akt_pozycja_yellow4[1] = plansza[pop_pozycja_yellow4 + cube.value][1];
          pop_pozycja_yellow4 += cube.value;
          CheckRadioButton(hwndDlg, IDC_RADIO_RED, IDC_RADIO_YELLOW, IDC_RADIO_RED);
          next();
          RysowaniePionkow(hdc);
        }
        ReleaseDC(hwndDlg, hdc);
      }
    }
  }
    return TRUE;
  case WM_PAINT:{
    HDC hdc = GetDC(hwndDlg);
    board.drawBoard(hdc);
    RysowaniePionkow(hdc);
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
    board.close();
  }
    return TRUE;
  }
  return FALSE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) 
{
  hInst = hInstance;
  Board board;
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