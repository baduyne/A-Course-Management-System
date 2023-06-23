#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
void resizeConsole(int width, int height);
void textcolor(int x);
void gotoxy(int x, int y);
void XoaManHinh();
void ToMau(int x, int y, char* a, int color);
void o(int x, int y, int w);
void box(int x, int y, int sl, int w);
void ba_cham(int x, int y, int w);
void press_enter();
void draw_load(int x, int y, int w);
