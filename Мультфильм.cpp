#include "TXLib.h"

const COLORREF TX_PURPLE   = RGB (186,  85, 211),
               TX_CHERRY   = RGB ( 80,   3,  28),
               TX_MYRED    = RGB (255,   0,   0),
               TX_MYYELLOW = RGB (255, 255,   0),
               TX_MYGREEN  = RGB ( 46, 139,  87),
               TX_MYBLUE   = RGB (175, 238, 238),
               TX_DARKCYAN = RGB (  0, 139, 139),
               TX_MYBROWN  = RGB (139,  69,  19);

void SolnceDraw    (int x, int y, int DlinaLucha);
void OblakoDraw    (int x, int y, double sizeX, double sizeY);
void CvetokDraw    (int x, int y, double size,
                    COLORREF centr, COLORREF lepestki);
void STODraw       (int x, int y, int VorotaOpen, int DverOpen);
void ZaborDraw     (int x, int y);
void RazmetkaDraw  (int x, int y);
void PerehodDraw   (int x, int y);
void MadamDraw     (int x, int y, int Glaza, COLORREF Zrachki, int Rot,
                    int UpRukaL, int UpRukaP, int UpNogaL, int UpNogaP, double Size);
void MadamBokDraw  (int x, int y, int UpRukaL, int UpRukaP,
                    int UpNogaL, int UpNogaP, double Size);
void MadamZadDraw  (int x, int y, int UpRukaL, int UpRukaP,
                    int UpNogaL, int UpNogaP, double Size);
void MisterDraw    (int x, int y, int Glaza, COLORREF Zrachki, int Rot,
                    int UpRukaL, int UpRukaP, double Size);
void MisterBokDraw (int x, int y, int UpNogaL, int UpNogaP, double Size);
void MisterZadDraw (int x, int y, double Size);
void SvetoforDraw  (int x, int y, int Visota,
                    COLORREF Red, COLORREF Yellow, COLORREF Green,
                    COLORREF Go, COLORREF Stop);
void SemerkaDraw   (int x, int y);
void MoskvichDraw  (int x, int y, int KapotUp, int OknoDown, int Antena,
                    int Avariika,  double size);
void DimokDraw     (int x, int y, double Size);
void Serdechko     (int x, int y, double Size);
void Background    ();
void TitlesBegin   ();
void ZadniiPlan    (int t);
void Scena1        (int t);
void Scena2        (int t);
void Scena3        (int t);
void TitlesEnd     ();
void KameraMotor   ();

int main ()
    {
    txCreateWindow (1400, 700);

	TitlesBegin ();
	KameraMotor ();
    TitlesEnd ();
    }

void SolnceDraw   (int x, int y, int DlinaLucha)
    {
    txSetColor (TX_ORANGE, 3);
    txLine (x-90+DlinaLucha, y,               x+90-DlinaLucha, y              );
    txLine (x,               y-90+DlinaLucha, x,               y+90-DlinaLucha);
    txLine (x-75+DlinaLucha, y-75+DlinaLucha, x+75-DlinaLucha, y+75-DlinaLucha);
    txLine (x-75+DlinaLucha, y+75-DlinaLucha, x+75-DlinaLucha, y-75+DlinaLucha);

    txSetColor (TX_ORANGE, 1);
    txLine (x-1-DlinaLucha, y-2-DlinaLucha*2, x+1+DlinaLucha, y+2+DlinaLucha*2);
    txLine (x-1-DlinaLucha, y+2+DlinaLucha*2, x+1+DlinaLucha, y-2-DlinaLucha*2);
    txLine (x-2-DlinaLucha*2, y-1-DlinaLucha, x+2+DlinaLucha*2, y+1+DlinaLucha);
    txLine (x-2-DlinaLucha*2, y+1+DlinaLucha, x+2+DlinaLucha*2, y-1-DlinaLucha);

    txSetColor (TX_MYBLUE, 4);
    txSetFillColor (TX_ORANGE);
    txCircle (x, y, 35);
    }

void OblakoDraw (int x, int y, double sizeX, double sizeY)
    {
    txSetColor     (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txEllipse (x,          y,          x+ 80*sizeX, y+40*sizeY);
    txEllipse (x+40*sizeX, y-10*sizeY, x+120*sizeX, y+40*sizeY);
    }

void CvetokDraw (int x, int y, double size,
                COLORREF centr, COLORREF lepestki)
    {
    txSetColor     (lepestki);
    txSetFillColor (lepestki);
    txCircle (x-15*size, y- 5*size, 10*size);
    txCircle (x-15*size, y+ 8*size, 10*size);
    txCircle (x,         y+14*size, 10*size);
    txCircle (x+15*size, y+ 8*size, 10*size);
    txCircle (x+15*size, y- 5*size, 10*size);
    txCircle (x,         y-14*size, 10*size);

    txSetColor     (centr);
    txSetFillColor (centr);
    txCircle (x, y, 10*size);
    }

void STODraw (int x, int y, int VorotaOpen, int DverOpen)
    {
    txSetColor (TX_BLACK);
	txSetFillColor (TX_GRAY);
    POINT PerednyayaStena [10] = {{x,     y    }, {x-20,  y    },
                                  {x-20,  y-140}, {x+160, y-140},
                                  {x+160, y-100}, {x+260, y-100},
                                  {x+260, y    }, {x+140, y    },
                                  {x+140, y-120}, {x,     y-120}};
    txPolygon (PerednyayaStena, 10);

    txSetFillColor (TX_DARKGRAY);
    POINT VnutrennyayaStena [7] = {{x+50,  y-120}, {x+50,  y-60 },
                                   {x,     y    }, {x,     y-120},
                                   {x+140, y-120}, {x+140, y-60 },
                                   {x+50,  y-60 }};
    txPolygon (VnutrennyayaStena, 7);

    txSetFillColor (TX_BLACK);
    POINT Pol [4] = {{x,     y   }, {x+50,  y-60},
                     {x+140, y-60}, {x+140, y   }};
    txPolygon (Pol, 4);

    txSetColor (TX_WHITE);
    txSelectFont ("Arial Black", 30);
    txTextOut (x+32,  y-80, "√Œ“Œ¬‹");
    txTextOut (x+13, y-60, "¡¿¡Œ—» »!");

    txSetColor (TX_BLACK);
    txSetFillColor (TX_WHITE);
    txRectangle (x, y-120, x+140, y-VorotaOpen);

    txSetFillColor (TX_DARKGRAY);
    POINT Krischa [16] = {{x-20,  y-140}, {x+20,  y-180},
                          {x+200, y-180}, {x+160, y-140},
                          {x+160, y-100}, {x+200, y-140},
                          {x+290, y-140}, {x+260, y-100},
                          {x+260, y    }, {x+290, y-40 },
                          {x+290, y-140}, {x+260, y-100},
                          {x+160, y-100}, {x+200, y-140},
                          {x+200, y-180}, {x+160, y-140}};
    txPolygon (Krischa, 16);

    txSetFillColor (TX_BLACK);
    txRectangle (x+20, y-150, x+120, y-110);
    txSetColor (TX_WHITE);
    txSelectFont ("Comic Sans MS", 40, 0, FW_BOLD);
    txDrawText  (x+20, y-150, x+120, y-110, "—“Œ");

    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txRectangle (x+200, y-60, x+240, y);
    txSetFillColor (TX_WHITE);
    POINT DverSTO [4] = {{x+200,             y               },
                         {x+200,             y-60            },
                         {x+240-80*DverOpen, y-60+10*DverOpen},
                         {x+240-80*DverOpen, y+10*DverOpen   }};
    txPolygon (DverSTO, 4);
    }

void ZaborDraw (int x, int y)
    {
    txSetColor     (TX_BLACK, 3);
    txSetFillColor (TX_TRANSPARENT);
    txRectangle (x,    y,    x+80, y+40);
    txRectangle (x,    y+40, x+80, y+50);
    txLine      (x,    y,    x+80, y+40);
    txLine      (x+80, y,    x,    y+40);
    }

void RazmetkaDraw (int x, int y)
    {
    POINT razmetka[4] = {{x,     y   }, {x+20, y-15},
                         {x+100, y-15}, {x+80, y   }};
    txPolygon (razmetka, 4);
    }

void PerehodDraw (int x, int y)
    {
    txSetColor     (TX_GRAY);
    txSetFillColor (TX_WHITE);
    POINT perehod1[4] = {{x,     y   }, {x+120, y   },
                         {x+100, y+20}, {x- 20, y+20}};
    txPolygon (perehod1, 4);

   	txSetFillColor (TX_YELLOW);
    POINT perehod2[4] = {{x-20, y+20}, {x+100, y+20},
                         {x+80, y+40}, {x- 40, y+40}};
    txPolygon (perehod2, 4);
    }

void MadamDraw (int x, int y, int Glaza, COLORREF Zrachki, int Rot,
                int UpRukaL, int UpRukaP, int UpNogaL, int UpNogaP, double Size)
    {
    txSetColor (TX_MYBROWN);
    txSetFillColor (TX_MYBROWN);
    POINT volosy[6] = {{ROUND(x-10*Size), ROUND(y+30*Size)},
                       {ROUND(x+10*Size), ROUND(y+30*Size)},
                       {ROUND(x+30*Size), ROUND(y+15*Size)},
                       {ROUND(x+15*Size), ROUND(y-30*Size)},
                       {ROUND(x-15*Size), ROUND(y-30*Size)},
                       {ROUND(x-30*Size), ROUND(y+15*Size)}};
    txPolygon (volosy, 6);

    txSetColor (TX_MYBROWN);
    txSetFillColor (TX_WHITE);
    txCircle (x, y, 20*Size);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_WHITE);
    txCircle (x-7*Size, y-5*Size, 2*Glaza*Size);
    txCircle (x+7*Size, y-5*Size, 2*Glaza*Size);

    txSetColor (TX_BLACK);
    txSetFillColor (Zrachki);
    txCircle (x-7*Size, y-5*Size, 2*Size);
    txCircle (x+7*Size, y-5*Size, 2*Size);

    txSetColor (TX_RED);
    txSetFillColor (TX_RED);
    txEllipse (x-7*Size, y+(10-Rot)*Size, x+7*Size, y+(10+Rot)*Size);

    txSetColor (TX_PINK);
    txSetFillColor (TX_PINK);
    POINT telo[3] = {{      x,          ROUND(y+20*Size)},
                     {ROUND(x+30*Size), ROUND(y+80*Size)},
                     {ROUND(x-30*Size), ROUND(y+80*Size)}};
    txPolygon (telo, 3);

    txSetColor (TX_BLACK, 2);
    txLine (x-13*Size, y+45*Size, x-40*Size, y+(55-30*UpRukaL)*Size);
    txLine (x+13*Size, y+45*Size, x+40*Size, y+(55-30*UpRukaP)*Size);

    txLine (x-13*Size, y+80*Size, x-13*Size, y+(110-20*UpNogaL)*Size);
    txLine (x+13*Size, y+80*Size, x+13*Size, y+(110-20*UpNogaP)*Size);
    }

void MadamBokDraw  (int x, int y, int UpRukaL, int UpRukaP,
                    int UpNogaL, int UpNogaP, double Size)
    {
    txSetColor (TX_MYBROWN);
    txSetFillColor (TX_WHITE);
    txCircle (x, y, 20*Size);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_WHITE);
    txCircle (x+11*Size, y-5*Size, 4*Size);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLUE);
    txCircle (x+11*Size, y-5*Size, 2*Size);

    txSetColor (TX_MYBROWN);
    txSetFillColor (TX_MYBROWN);
    POINT volosy[7] = {{      x,          ROUND(y+40*Size)},
                       {ROUND(x-30*Size), ROUND(y+40*Size)},
                       {ROUND(x-40*Size), ROUND(y+20*Size)},
                       {ROUND(x-20*Size), ROUND(y-30*Size)},
                       {      x,          ROUND(y-30*Size)},
                       {ROUND(x+10*Size), ROUND(y-20*Size)},
                       {      x,          ROUND(y+5*Size)}};
    txPolygon (volosy, 7);

    txSetColor (TX_BLACK, 2);
    txLine (x, y+50*Size, x+(20-10*UpRukaL)*Size, y+(40-10*UpRukaL)*Size);

    txSetColor (TX_PINK);
    txSetFillColor (TX_PINK);
    POINT telo[3] = {{      x,          ROUND(y+20*Size)},
                     {ROUND(x+30*Size), ROUND(y+80*Size)},
                     {ROUND(x-30*Size), ROUND(y+80*Size)}};
    txPolygon (telo, 3);

    txSetColor (TX_BLACK, 2);
    txLine (x, y+50*Size, x+(20-10*UpRukaP)*Size, y+(40-10*UpRukaP)*Size);

    txLine (x-13*Size, y+80*Size, x-13*Size, y+(110-20*UpNogaL)*Size);
    txLine (x+13*Size, y+80*Size, x+13*Size, y+(110-20*UpNogaP)*Size);
    }

void MadamZadDraw (int x, int y, int UpRukaL, int UpRukaP,
                       int UpNogaL, int UpNogaP, double Size)
    {
    txSetColor (TX_PINK);
    txSetFillColor (TX_PINK);
    POINT telo[3] = {{x,                ROUND(y+20*Size)},
                     {ROUND(x+30*Size), ROUND(y+80*Size)},
                     {ROUND(x-30*Size), ROUND(y+80*Size)}};
    txPolygon (telo, 3);

    txSetColor (TX_MYBROWN);
    txSetFillColor (TX_MYBROWN);
    POINT volosy[6] = {{ROUND(x-10*Size), ROUND(y+30*Size)},
                       {ROUND(x+10*Size), ROUND(y+30*Size)},
                       {ROUND(x+30*Size), ROUND(y+15*Size)},
                       {ROUND(x+15*Size), ROUND(y-30*Size)},
                       {ROUND(x-15*Size), ROUND(y-30*Size)},
                       {ROUND(x-30*Size), ROUND(y+15*Size)}};
    txPolygon (volosy, 6);

    txSetColor (TX_BLACK, 2);
    txLine (x-13*Size, y+45*Size, x-40*Size, y+(55-30*UpRukaL)*Size);
    txLine (x+13*Size, y+45*Size, x+40*Size, y+(55-30*UpRukaP)*Size);

    txLine (x-13*Size, y+80*Size, x-13*Size, y+(110-20*UpNogaL)*Size);
    txLine (x+13*Size, y+80*Size, x+13*Size, y+(110-20*UpNogaP)*Size);
    }

void MisterDraw (int x, int y, int Glaza, COLORREF Zrachki, int Rot,
                int UpRukaL, int UpRukaP, double Size)
    {
    txSetColor (TX_MYBROWN);
    txSetFillColor (TX_WHITE);
    txCircle (x, y, 20*Size);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txRectangle (x-20*Size, y-25*Size, x+20*Size, y-10*Size);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_WHITE);
    txCircle (x-7*Size, y-5*Size, 2*Glaza*Size);
    txCircle (x+7*Size, y-5*Size, 2*Glaza*Size);

    txSetColor (TX_BLACK);
    txSetFillColor (Zrachki);
    txCircle (x-7*Size, y-5*Size, 2*Size);
    txCircle (x+7*Size, y-5*Size, 2*Size);

    txSetColor (TX_RED);
    txSetFillColor (TX_RED);
    txEllipse (x-7*Size, y+(10-Rot)*Size, x+7*Size, y+(10+Rot)*Size);

    txSetColor (TX_BLUE);
    txSetFillColor (TX_BLUE);
    POINT telo[3] = {{ROUND(x-20*Size), ROUND(y+20*Size)},
                     {ROUND(x+20*Size), ROUND(y+20*Size)},
                     {      x,          ROUND(y+80*Size)}};
    txPolygon (telo, 3);

    txSetColor (TX_BLACK, 2);
    txLine (x-13*Size, y+40*Size, x-(25+15*UpRukaL)*Size, y+(70-50*UpRukaL)*Size);
    txLine (x+13*Size, y+40*Size, x+(25+15*UpRukaL)*Size, y+(70-50*UpRukaP)*Size);

    txLine (x, y+80*Size, x-15*Size, y+110*Size);
    txLine (x, y+80*Size, x+15*Size, y+110*Size);
    }

void MisterBokDraw (int x, int y, int UpNogaL, int UpNogaP, double Size)
    {
    txSetColor (TX_MYBROWN);
    txSetFillColor (TX_WHITE);
    txCircle (x, y, 20*Size);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_WHITE);
    txCircle (x-7*Size, y-5*Size, 4*Size);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_BROWN);
    txCircle (x-7*Size, y-5*Size, 2*Size);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_BLACK);
    txRectangle (x-20*Size, y-25*Size, x+20*Size, y-10*Size);
    txLine (x-40*Size, y-10*Size, x-20*Size, y-10*Size);

    txSetColor (TX_BLUE);
    txSetFillColor (TX_BLUE);
    POINT telo[3] = {{ROUND(x-20*Size), ROUND(y+20*Size)},
                     {ROUND(x+20*Size), ROUND(y+20*Size)},
                     {      x,          ROUND(y+80*Size)}};
    txPolygon (telo, 3);

    txSetColor (TX_BLACK, 2);
    txLine (x, y+40*Size, x-20*Size, y+60*Size);

    txLine (x, y+80*Size, x-15*Size, y+(110-15*UpNogaL)*Size);
    txLine (x, y+80*Size, x+15*Size, y+(110-15*UpNogaP)*Size);
    }

void MisterZadDraw (int x, int y, double Size)
    {
    txSetColor (TX_MYBROWN);
    txSetFillColor (TX_WHITE);
    txCircle (x, y, 20*Size);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txRectangle (x-20*Size, y-25*Size, x+20*Size, y-10*Size);

    txSetColor (TX_BLUE);
    txSetFillColor (TX_BLUE);
    POINT telo[3] = {{ROUND(x-20*Size), ROUND(y+20*Size)},
                     {ROUND(x+20*Size), ROUND(y+20*Size)},
                     {      x,          ROUND(y+80*Size)}};
    txPolygon (telo, 3);

    txSetColor (TX_BLACK, 2);
    txLine (x-13*Size, y+40*Size, x-25*Size, y+70*Size);
    txLine (x+13*Size, y+40*Size, x+25*Size, y+70*Size);

    txLine (x, y+80*Size, x-15*Size, y+110*Size);
    txLine (x, y+80*Size, x+15*Size, y+110*Size);
    }

void SvetoforDraw (int x, int y, int Visota,
                   COLORREF Red, COLORREF Yellow, COLORREF Green,
                   COLORREF Go, COLORREF Stop)
    {
	txSetColor     (Red);
	txSetFillColor (Red);
	txEllipse (x-25, y-130-Visota, x+35, y-90-Visota);

	txSetColor     (Yellow);
	txSetFillColor (Yellow);
	txEllipse (x-25, y-90 -Visota, x+35, y-50-Visota);

    txSetColor     (Green);
	txSetFillColor (Green);
	txEllipse (x-25, y-50 -Visota, x+35, y-10-Visota);

    txSetColor     (TX_BLACK);
	txSetFillColor (TX_BLACK);
	POINT Svetofor [8] = {{x,    y    +Visota}, {x+10, y    +Visota},
                          {x+10, y    -Visota}, {x+25, y    -Visota},
                          {x+25, y-140-Visota}, {x-15, y-140-Visota},
                          {x-15, y    -Visota}, {x,    y    -Visota}};
    txPolygon (Svetofor, 8);

    txSetColor     (Go);
	txSetFillColor (Go);
	txCircle (x+5, y-60-Visota, 15);

    txSetColor     (Stop);
	txSetFillColor (Stop);
	txCircle (x+5, y-25-Visota, 15);
    }

void SemerkaDraw (int x, int y)
    {
    txSetColor (TX_CHERRY);
    txSetFillColor (TX_CHERRY);
    POINT kuzov[16] = {{x,     y    }, {x- 10, y-60}, {x+ 60, y-60}, {x+100, y-120},
                       {x+240, y-120}, {x+280, y-60}, {x+360, y-60}, {x+350, y    },
                       {x+330, y    }, {x+310, y-20}, {x+290, y-20}, {x+270, y    },
                       {x+ 90, y    }, {x+ 70, y-20}, {x+ 50, y-20}, {x+ 30, y    }};
    txPolygon (kuzov, 16);

    txSetColor     (TX_BLACK);
    txSetFillColor (TX_TRANSPARENT);
    POINT dveri[10] = {{x+170, y-110}, {x+170, y- 10},
                       {x+100, y- 10}, {x+ 70, y- 40},
                       {x+ 70, y- 60}, {x+100, y-110},
                       {x+240, y-110}, {x+270, y- 60},
                       {x+270, y- 10}, {x+170, y- 10}};
    txPolygon (dveri, 10);

    txRectangle (x+30, y-50, x+50, y-33);

    txSetColor     (TX_BLACK);
    txSetFillColor (TX_BLACK);
    POINT okno1[6] = {{x+102, y-60}, {x+102, y-105}, {x+165, y-105},
                      {x+165, y-60}, {x+ 75, y- 60}, {x+102, y-105}};
    txPolygon (okno1, 6);
    POINT okno2[4] = {{x+175, y- 60}, {x+265, y- 60},
                      {x+238, y-105}, {x+175, y-105}};
    txPolygon (okno2, 4);

    txSetFillColor (TX_BLACK);
    txRectangle (x+ 80, y-55, x+100, y-47);
    txRectangle (x+180, y-55, x+200, y-47);

    txCircle (x+ 60, y+8, 25);
    txCircle (x+300, y+8, 25);
    txSetFillColor (TX_WHITE);
    txCircle (x+ 60, y+8, 17);
    txCircle (x+300, y+8, 17);

    txSetFillColor (TX_BLACK);
    txRectangle (x- 10, y-20, x+ 10, y-10);
    txRectangle (x+345, y-20, x+365, y-10);

    txSetColor     (TX_ORANGE);
    txSetFillColor (TX_ORANGE);
    txRectangle (x+330, y-45, x+340, y-40);
    }

void MoskvichDraw (int x, int y, int KapotUp, int OknoDown, int Antena,
                   int Avariika,  double size)
    {
    txSetColor (TX_DARKCYAN);
    txSetFillColor (TX_DARKCYAN);
    POINT KuzovMoskvicha [19] = {{      x,                 y          },
                                 {ROUND(x- 40*size),       y          },
                                 {ROUND(x- 50*size), ROUND(y- 60*size)},
                                 {ROUND(x+ 35*size), ROUND(y- 60*size)},
                                 {ROUND(x+ 80*size), ROUND(y-120*size)},
                                 {ROUND(x+220*size), ROUND(y-120*size)},
                                 {ROUND(x+270*size), ROUND(y- 60*size)},
                                 {ROUND(x+268*size),       y          },
                                 {ROUND(x+240*size),       y          },
                                 {ROUND(x+238*size), ROUND(y- 10*size)},
                                 {ROUND(x+228*size), ROUND(y- 20*size)},
                                 {ROUND(x+210*size), ROUND(y- 20*size)},
                                 {ROUND(x+203*size), ROUND(y- 10*size)},
                                 {ROUND(x+200*size),       y          },
                                 {ROUND(x+ 40*size),       y          },
                                 {ROUND(x+ 37*size), ROUND(y- 10*size)},
                                 {ROUND(x+ 28*size), ROUND(y- 20*size)},
                                 {ROUND(x+ 10*size), ROUND(y- 20*size)},
                                 {ROUND(x+  3*size), ROUND(y- 10*size)}};
    txPolygon (KuzovMoskvicha, 19);
    txSetColor (TX_BLACK);
    POINT Kapot [4] = {{ROUND(x+ 35           *size), ROUND(y- 60         *size)},
                       {ROUND(x-(50+KapotUp/3)*size), ROUND(y-(60-KapotUp)*size)},
                       {ROUND(x-(50+KapotUp/3)*size), ROUND(y-(64-KapotUp)*size)},
                       {ROUND(x+ 38           *size), ROUND(y- 64         *size)}};
    txPolygon (Kapot, 4);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    POINT OknoVoditel [4] {{ROUND(x+ 47*size), ROUND(y- 60*size) },
                           {ROUND(x+135*size), ROUND(y- 60*size)},
                           {ROUND(x+135*size), ROUND(y-110*size)},
                           {ROUND(x+ 81*size), ROUND(y-110*size)}};
    txPolygon (OknoVoditel, 4);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_WHITE);
    txRectangle (x+143*size, y-110*size, x+210*size, y-60*size);

    txSetColor (TX_MYBROWN);
    txSetFillColor (TX_MYBROWN);
    POINT Volosy [4] = {{ROUND(x+150*size), ROUND(y- 60*size)},
                        {ROUND(x+160*size), ROUND(y-105*size)},
                        {ROUND(x+200*size), ROUND(y-105*size)},
                        {ROUND(x+210*size), ROUND(y- 60*size)}};
    txPolygon (Volosy, 4);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_WHITE);
    txCircle (x+180*size, y-80*size, 20*size);

    txCircle (x+173*size, y-85*size, 8*size);
    txCircle (x+187*size, y-85*size, 8*size);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLUE);
    txCircle (x+173*size, y-85*size, 2*size);
    txCircle (x+187*size, y-85*size, 2*size);

    txSetColor (TX_RED);
    txSetFillColor (TX_RED);
    txEllipse (x+173*size, y-76*size, x+187*size, y-66*size);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txRectangle (x+143*size, y-(110+OknoDown)*size, x+210*size, y-60*size);

    POINT OknoBagage [3] {{ROUND(x+217*size), ROUND(y-110*size)},
                          {ROUND(x+217*size), ROUND(y- 60*size)},
                          {ROUND(x+257*size), ROUND(y- 60*size)}};
    txPolygon (OknoBagage, 3);

    txSetColor (TX_BLACK, 2);
    txCircle (x+270*size, y-60*size, 3*size);
    txLine (x+270*size, y-60*size, x+(270+Antena)*size, y-(120+Antena/3)*size);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_TRANSPARENT);
    POINT DveriMoskvicha [10] = {{ROUND(x+139*size), ROUND(y-114*size)},
                                 {ROUND(x+139*size), ROUND(y-  3*size)},
                                 {ROUND(x+ 43*size), ROUND(y-  3*size)},
                                 {ROUND(x+ 43*size), ROUND(y- 60*size)},
                                 {ROUND(x+ 80*size), ROUND(y-114*size)},
                                 {ROUND(x+212*size), ROUND(y-114*size)},
                                 {ROUND(x+212*size), ROUND(y- 25*size)},
                                 {ROUND(x+200*size), ROUND(y- 15*size)},
                                 {ROUND(x+196*size), ROUND(y-  3*size)},
                                 {ROUND(x+139*size), ROUND(y-  3*size)}};
    txPolygon (DveriMoskvicha, 10);

    txSetFillColor (TX_BLACK);
    txRectangle (x+113*size, y-53*size, x+133*size, y-45*size);
    txRectangle (x+188*size, y-53*size, x+208*size, y-45*size);
    txRectangle (x- 51*size, y-20*size, x- 26*size, y- 8*size);
    txRectangle (x+255*size, y-20*size, x+275*size, y- 8*size);

    txSetColor (TX_ORANGE);
    txSetFillColor (TX_ORANGE);
    txCircle (x-20*size, y-45*size, 5*size);
    txLine (x-20, y-55, x-20, y-(55+5*Avariika));
    txLine (x-20, y-35, x-20, y-(35-5*Avariika));
    txLine (x-30, y-45, x-(30+5*Avariika), y-45);
    txLine (x-10, y-45, x-(10-5*Avariika), y-45);

    txLine (x-25, y-50, x-(25+5*Avariika), y-(50+5*Avariika));
    txLine (x-15, y-50, x-(15-5*Avariika), y-(50+5*Avariika));
    txLine (x-25, y-40, x-(25+5*Avariika), y-(40-5*Avariika));
    txLine (x-15, y-40, x-(15-5*Avariika), y-(40-5*Avariika));

    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txCircle (x+ 20*size, y, 21*size);
    txCircle (x+220*size, y, 21*size);
    txSetFillColor (TX_WHITE);
    txCircle (x+ 20*size, y, 15*size);
    txCircle (x+220*size, y, 15*size);
    }

void DimokDraw (int x, int y, double Size)
    {
    txSetColor (TX_DARKGRAY);
    txSetFillColor (TX_DARKGRAY);
    txCircle (x-10*Size, y,         20*Size);
    txCircle (x,         y-20*Size, 20*Size);
    txCircle (x+10*Size, y+10*Size, 30*Size);
    }

void Serdechko (int x, int y, double Size)
    {
    txSetColor (TX_MYRED);
    txSetFillColor (TX_MYRED);
    POINT Serdechko [10] = {{      x,          ROUND(y+20*Size)},
                            {ROUND(x-20*Size),       y         },
                            {ROUND(x-20*Size), ROUND(y-10*Size)},
                            {ROUND(x-15*Size), ROUND(y-20*Size)},
                            {ROUND(x- 5*Size), ROUND(y-20*Size)},
                            {      x,          ROUND(y-10*Size)},
                            {ROUND(x+ 5*Size), ROUND(y-20*Size)},
                            {ROUND(x+15*Size), ROUND(y-20*Size)},
                            {ROUND(x+20*Size), ROUND(y-10*Size)},
                            {ROUND(x+20*Size),       y         }};
    txPolygon (Serdechko, 10);
    }

void Background ()
    {
    txSetColor     (TX_MYBLUE);
    txSetFillColor (TX_MYBLUE);
    txRectangle (0, 0, 1400, 200);

    txSetColor     (TX_MYGREEN);
    txSetFillColor (TX_MYGREEN);
    txRectangle (0, 200, 1400, 420);

    CvetokDraw ( 40, 240,    1, TX_ORANGE,   TX_WHITE);
    CvetokDraw (110, 280,    1, TX_MYYELLOW, TX_PURPLE);
    CvetokDraw (190, 240,    1, TX_WHITE,    TX_ORANGE);
    CvetokDraw (220, 330,    1, TX_ORANGE,   TX_WHITE);
    CvetokDraw (310, 240,    1, TX_MYYELLOW, TX_PURPLE);
    CvetokDraw ( 50, 320,  0.5, TX_MYRED,    TX_MYYELLOW);
    CvetokDraw (120, 230,  0.5, TX_ORANGE,   TX_WHITE);
    CvetokDraw (140, 340,  0.5, TX_WHITE,    TX_ORANGE);
    CvetokDraw (180, 290,  0.5, TX_ORANGE,   TX_WHITE);
    CvetokDraw (265, 270,  0.5, TX_ORANGE,   TX_WHITE);
    CvetokDraw (335, 300, 0.75, TX_MYRED,    TX_MYYELLOW);
    CvetokDraw (280, 340,  0.5, TX_MYYELLOW, TX_PURPLE);

    for (int x=0; x<=480; x+=80)
        {
        ZaborDraw (x, 320);
        }
    for (int x=800; x<=960; x+=80)
        {
        ZaborDraw (x, 320);
        }
    for (int x=1280; x<=1360; x+=80)
        {
        ZaborDraw (x, 320);
        }

    txSetColor     (TX_GRAY);
    txSetFillColor (TX_GRAY);
    txRectangle (0, 380, 1400, 657);

    txSetColor     (TX_MYGREEN);
    txSetFillColor (TX_MYGREEN);
    txRectangle (0, 657, 1400, 700);

    txSetColor     (TX_WHITE);
	txSetFillColor (TX_WHITE);
    txRectangle (0, 396, 1400, 400);

    for (int x=20; x<=380; x+=120)
        {
        RazmetkaDraw (x, 510);
        }
    for (int x=650; x<=1370; x+=120)
        {
        RazmetkaDraw (x, 510);
        }

    txRectangle (0, 641, 1400, 645);

    int x=600;
    int y=400;
    while (x>=380)
        {
        PerehodDraw (x, y);
        x-=40;
        y+=40;
        }
    }

void TitlesBegin ()
    {
    txBegin ();
    for (int t=0; t<=300; t++)
        {
        txClear ();
        txSetColor (TX_WHITE);
        txSetFillColor (TX_WHITE);
        txRectangle (0, 0, 1400, 700);

        if (t<=100)
            {
            txSetColor (TX_BLACK);
            txSelectFont ("Arial Black", 10+t);
            txTextOut (600-t*3, 200, "COLUMBIA PICTURES");
            txSelectFont ("Arial", 5+t);
            txTextOut (630-t*2, 300, "ÔÂ‰ÒÚ‡‚ÎˇÂÚ");
            }
        if ((t>100)&(t<150))
            {
            txSetColor (TX_BLACK);
            txSelectFont ("Arial Black", 110);
            txTextOut (300, 200, "COLUMBIA PICTURES");
            txSelectFont ("Arial", 105);
            txTextOut (430, 300, "ÔÂ‰ÒÚ‡‚ÎˇÂÚ");
            }
        if ((t>=150)&(t<300))
            {
            txSetColor (TX_BLACK);
            txSelectFont ("Arial Black", 100);
            txTextOut (100, 200, "Ã”À‹“»œÀ» ¿÷»ŒÕÕ€… ‘»À‹Ã");
            }
        if ((t>=200)&(t<300))
            {
            txSetColor (TX_MYRED);
            txSelectFont ("Arial Blac", 130);
            txTextOut (475, 300, "¬—“–≈◊¿");
            }
        txSleep (1);
        }
    txEnd ();
    }

void ZadniiPlan (int t)
    {
    OblakoDraw (  20+t/2, 20,     1,     1);
    OblakoDraw ( 280+t/2, 60, -0.75,     1);
    OblakoDraw ( 300+t/2, 50,     1, -0.75);
    OblakoDraw ( 600-t/2, 80, -0.75, -0.75);
    OblakoDraw ( 750-t/2, 50,    -1,    -1);
    OblakoDraw ( 800-t/2, 70,     1,    -1);
    OblakoDraw (1100-t/2, 60,    -1,     1);

    if ((t/40)%2<1)
        {
        SolnceDraw (1300, 80, 1+t%40);
        }
    else
        {
        SolnceDraw (1300, 80, 39-t%40);
        }

    if ((t<475)|(t>=1600))
        {
        STODraw (1100, 300, 0, 0);
        }
    if ((t>=475)&(t<635))
        {
        STODraw (1100, 300, 0+(t-474)/2, 0);
        }
    if ((t>=635)&(t<1440))
        {
        STODraw (1100, 300, 80, 1);
        }
    if ((t>=1440)&(t<1600))
        {
        STODraw (1100, 300, 80-(t-1439)/2, 0);
        }
    }

void Scena1 (int t)
    {
    if (t<=300)
        {
        if (t<100)
            {
            SvetoforDraw (750, 300, 70, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                          TX_DARKGRAY, TX_MYRED);
            SemerkaDraw (-990+t*5, 580);
            SvetoforDraw (310, 570, 100, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                          TX_BLACK, TX_BLACK);
            }
        else
            {
            if (t<200)
                {
                SvetoforDraw (750, 300, 70, TX_DARKGRAY, TX_MYYELLOW, TX_DARKGRAY,
                              TX_DARKGRAY, TX_MYRED);
                SemerkaDraw (-990+t*5, 580);
                SvetoforDraw (310, 570, 100, TX_DARKGRAY, TX_MYYELLOW, TX_DARKGRAY,
                              TX_BLACK, TX_BLACK);
                }
            else
                {
                SvetoforDraw (750, 300, 70, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                              TX_DARKGRAY, TX_MYRED);
                SemerkaDraw (10, 580);
                SvetoforDraw (310, 570, 100, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                              TX_BLACK, TX_BLACK);
                }
            }
        MadamDraw (660, 260, 2, TX_BLUE, 1, 0, 0, 0, 0, 1);
        MoskvichDraw (1700-t*3, 460, 0, 0, 30, 0, 1);
        }
    }

void Scena2 (int t)
    {
    if ((t>300)&(t<=700))
        {
        if (t>450)
            {
            if (t>=475)
                {
                if (t>=525)
                    {
                    if (t>=620)
                        {
                        if (t>=650)
                            {
                            SvetoforDraw  (750, 300, 70, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                                           TX_GREEN, TX_DARKGRAY);
                            SemerkaDraw   (10, 580);
                            SvetoforDraw  (310, 570, 100, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                                           TX_BLACK, TX_BLACK);
                            MoskvichDraw  (800, 460, -60, 0, 0, (t/15)%2, 1);
                            MisterZadDraw (776, 380, 1);
                            MadamZadDraw  (338, 582, 0, 0, 0, 0, 1);
                            }
                        else
                            {
                            SvetoforDraw  (750, 300, 70, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                                           TX_GREEN, TX_DARKGRAY);
                            SemerkaDraw   (10, 580);
                            SvetoforDraw  (310, 570, 100, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                                           TX_BLACK, TX_BLACK);
                            MoskvichDraw  (800, 460, -60, 0, 0, (t/15)%2, 1);
                            MisterZadDraw (776, 380, 1);
                            MadamDraw     (367-(t-619), 553+(t-619), 2, TX_BLUE, 1,
                                           0, 0, 0+(t/10)%2, 1-(t/10)%2, 1);
                            }
                        }
                    else
                        {
                        SvetoforDraw  (750, 300, 70, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                                       TX_GREEN, TX_DARKGRAY);
                        SemerkaDraw   (10, 580);
                        SvetoforDraw  (310, 570, 100, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                                       TX_BLACK, TX_BLACK);
                        MoskvichDraw  (800, 460, -60, 0, 0, (t/15)%2, 1);
                        MisterBokDraw (900-(t-524), 380, 0+((t-524)/10%2), 1-((t-524)/10%2), 1);
                        MadamDraw     (462-(t-524), 458+(t-524), 2, TX_BLUE, 1,
                                       0, 0, 0+(t/10)%2, 1-(t/10)%2, 1);
                        }
                    }
                else
                    {
                    SvetoforDraw (750, 300, 70, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                                  TX_GREEN, TX_DARKGRAY);
                    SemerkaDraw  (10, 580);
                    SvetoforDraw (310, 570, 100, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                                  TX_BLACK, TX_BLACK);
                    MoskvichDraw (800, 460, -60, 0, 0, (t/15)%2, 1);
                    MisterDraw   (900, 380, 2, TX_BROWN, 1, 0, 0, 1);
                    MadamDraw    (512-(t-474), 408+(t-474), 2, TX_BLUE, 1,
                                  0, 0, 0+(t/10)%2, 1-(t/10)%2, 1);
                    }
                }
            else
                {
                SvetoforDraw (750, 300, 70, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                              TX_GREEN, TX_DARKGRAY);
                SemerkaDraw  (10, 580);
                SvetoforDraw (310, 570, 100, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                              TX_BLACK, TX_BLACK);
                MoskvichDraw (800, 460, -60, 0, 0, 1, 1);
                DimokDraw    (800, 360-(t-449), 0.5+(t-449)/10);
                MadamDraw    (512, 408-30, 4, TX_MYRED, 4, 1, 1, 0, 0, 1);
                }
            }
        else
            {
            SvetoforDraw (750, 300, 70, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                          TX_GREEN, TX_DARKGRAY);
            SemerkaDraw (10, 580);
            SvetoforDraw (310, 570, 100, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                          TX_BLACK, TX_BLACK);
            MoskvichDraw (800, 460, 0, 0, 0, 0, 1);
            MadamDraw  (660-(t-299), 260+(t-299), 2, TX_BLUE, 1,
                        0, 0, 0+(t/10)%2, 1-(t/10)%2, 1);
            }
        }
    }

void Scena3 (int t)
    {
    if (t>700)
        {
        if (t>775)
            {
            if (t>=900)
                {
                if (t>=1000)
                    {
                    if (t>1223)
                        {
                        if (t>=1373)
                            {
                            if (t>1550)
                                {
                                if (t>=1600)
                                    {
                                    if (t>=1650)
                                        {
                                        SvetoforDraw  (750, 300, 70, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                                                       TX_DARKGRAY, TX_MYRED);
                                        MoskvichDraw  (800-(t-1649)*5, 460, 0, -50, 30, 0, 1);
                                        SvetoforDraw  (310, 570, 100, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                                                       TX_BLACK, TX_BLACK);
                                        }
                                    else
                                        {
                                        SvetoforDraw  (750, 300, 70, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                                                       TX_DARKGRAY, TX_MYRED);
                                        MoskvichDraw  (800, 460, 0, 0, 0, (t/15)%2, 1);
                                        MisterBokDraw (776, 380, 0, 0, 1);
                                        MadamBokDraw  (709, 360, 0, 0, 0, 0, 1);
                                        SvetoforDraw  (310, 570, 100, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                                                       TX_BLACK, TX_BLACK);
                                        }
                                    }
                                else
                                    {
                                    SvetoforDraw  (750, 300, 70, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                                                   TX_DARKGRAY, TX_MYRED);
                                    MoskvichDraw  (800, 460, -60, 0, 0, (t/15)%2, 1);
                                    MisterBokDraw (776, 380, 0, 0, 1);
                                    MadamBokDraw  (709, 360, 0, 0, 0, 0, 1);
                                    Serdechko     (742, 370-(t-1549)*2, 0.1+(t-1549)/20);
                                    SvetoforDraw  (310, 570, 100, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                                                   TX_BLACK, TX_BLACK);
                                    }
                                }
                            else
                                {
                                SvetoforDraw  (750, 300, 70, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                                               TX_DARKGRAY, TX_MYRED);
                                MoskvichDraw  (800, 460, -60, 0, 0, (t/15)%2, 1);
                                MisterZadDraw (776, 380, 1);
                                SvetoforDraw  (310, 570, 100, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                                               TX_BLACK, TX_BLACK);
                                MadamBokDraw  (709, 360, 0+(t/20)%2, 1-(t/20)%2,
                                               0, 0, 1);
                                }
                            }
                        else
                            {
                            SvetoforDraw  (750, 300, 70, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                                           TX_DARKGRAY, TX_MYRED);
                            MoskvichDraw  (800, 460, -60, 0, 0, (t/15)%2, 1);
                            MisterZadDraw (776, 380, 1);
                            SvetoforDraw  (310, 570, 100, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                                           TX_BLACK, TX_BLACK);
                            MadamBokDraw  (560+(t-1222), 360, 0, 0,
                                           0+(t/10)%2, 1-(t/10)%2, 1);
                            }
                        }
                    else
                        {
                        SvetoforDraw  (750, 300, 70, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                                       TX_DARKGRAY, TX_MYRED);
                        MoskvichDraw  (800, 460, -60, 0, 0, (t/15)%2, 1);
                        MisterZadDraw (776, 380, 1);
                        SemerkaDraw   (510+(t-999)*5, 580);
                        SvetoforDraw  (310, 570, 100, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                                       TX_BLACK, TX_BLACK);
                        MadamZadDraw  (338+(t-999), 582-(t-999),
                                       0, 0, 0+(t/10)%2, 1-(t/10)%2, 1);
                        }
                    }
                else
                    {
                    SvetoforDraw  (750, 300, 70, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                                   TX_DARKGRAY, TX_MYRED);
                    MoskvichDraw  (800, 460, -60, 0, 0, (t/15)%2, 1);
                    MisterZadDraw (776, 380, 1);
                    SemerkaDraw   (10+(t-899)*5, 580);
                    SvetoforDraw  (310, 570, 100, TX_DARKGRAY, TX_DARKGRAY, TX_GREEN,
                                   TX_BLACK, TX_BLACK);
                    MadamZadDraw  (338, 582, 0, 0, 0, 0, 1);
                    }
                }
            else
                {
                SvetoforDraw  (750, 300, 70, TX_DARKGRAY, TX_MYYELLOW, TX_DARKGRAY,
                               TX_DARKGRAY, TX_MYRED);
                MoskvichDraw  (800, 460, -60, 0, 0, (t/15)%2, 1);
                MisterZadDraw (776, 380, 1);
                SemerkaDraw   (10, 580);
                SvetoforDraw  (310, 570, 100, TX_DARKGRAY, TX_MYYELLOW, TX_DARKGRAY,
                               TX_BLACK, TX_BLACK);
                MadamZadDraw  (338, 582, 0, 0, 0, 0, 1);
                }
            }
        else
            {
            SvetoforDraw (750, 300, 70, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                          TX_DARKGRAY, TX_MYRED);
            MoskvichDraw (800, 460, -60, 0, 0, (t/15)%2, 1);
            MisterDraw   (776, 380, 4, TX_MYRED, 4, 1, 1, 1);
            SemerkaDraw  (10, 580);
            SvetoforDraw (310, 570, 100, TX_MYRED, TX_DARKGRAY, TX_DARKGRAY,
                          TX_BLACK, TX_BLACK);
            MadamZadDraw (338, 582, 0, 0, 0, 0, 1);
            }
        }
    }

void TitlesEnd ()
    {
    txBegin ();
    for (int t=0; t<=300; t++)
        {
        txClear ();
        txSetColor (TX_WHITE);
        txSetFillColor (TX_WHITE);
        txRectangle (0, 0, 1400, 700);

        txSetColor (TX_BLACK);
        txSelectFont ("Arial Black", 90);
        txTextOut (300, 750-t*5, "’Û‰ÓÊÌËÍ-ÏÛÎ¸ÚËÔÎËÍ‡ÚÓ:");
        txSelectFont ("Arial", 70);
        txTextOut (300, 850-t*5, "–ÓÏ‡ÌÓ‚ÒÍ‡ˇ ¿ÌÌ‡ ¿ÎÂÍÒ‡Ì‰Ó‚Ì‡");
        txSelectFont ("Arial Black", 130);
        txTextOut (100, 1250-t*5, "—œ¿—»¡Œ «¿ ¬Õ»Ã¿Õ»≈!!!");
        txSleep (1);
        }
    txEnd ();
    }

void KameraMotor ()
    {
    txBegin ();
    for (int t=0; t<2000; t++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        Background ();

        ZadniiPlan (t);
        Scena1 (t);
        Scena2 (t);
        Scena3 (t);

        txSleep (1);
        }
    txEnd ();
    }
