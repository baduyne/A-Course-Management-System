﻿#include"do_hoa.h"// Hàm tô màu.void textcolor(int x){	HANDLE mau;	mau = GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(mau, x);}// Hàm lấy Key từ bàn phím/* GetAsyncKeyState(VK_ESCAPE) => bắt sự kiện phím Esc */// Hàm tự viếtvoid ToMau(int x, int y, char* a, int color) // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.{	gotoxy(x, y);	textcolor(color);	cout << a;	textcolor(7);}void gotoxy(int x, int y){	static HANDLE h = NULL;	if (!h)		h = GetStdHandle(STD_OUTPUT_HANDLE);	COORD c = { x, y };	SetConsoleCursorPosition(h, c);}void GoTo(int posX, int posY){	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);	COORD Position;	Position.X = posX;	Position.Y = posY;	SetConsoleCursorPosition(hStdout, Position);}void o(int x, int y, int w){	for (int i = 0; i < w; i++)	{		gotoxy(x + i, y);		cout << char(196);		gotoxy(x + i, y + 2);		cout << char(196);	}	for (int i = 0; i < 2; i++)	{		gotoxy(x, y + i);		cout << char(179);		gotoxy(x + w, y + i);		cout << char(179);	}	gotoxy(x, y);	cout << char(218);	gotoxy(x + w, y);	cout << char(191);	gotoxy(x, y + 2);	cout << char(192);	gotoxy(x + w, y + 2);	cout << char(217);}void ba_cham(int x, int y, int w){	for (int i = 0; i < w; i++)	{		gotoxy(x + 1, y);		cout << char(59);	}}