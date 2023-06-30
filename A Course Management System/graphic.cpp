#include"graphic.h"
// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Hàm lấy Key từ bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => bắt sự kiện phím Esc */

// Hàm tự viết
void ToMau(int x, int y, char* a, int color) // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}
void o(int x, int y, int w)
{
	for (int i = 0; i < w; i++)
	{
		gotoxy(x + i, y);
		cout << char(196);
		gotoxy(x + i, y + 2);
		cout << char(196);
	}
	for (int i = 0; i < 2; i++)
	{
		gotoxy(x, y + i);
		cout << char(179);
		gotoxy(x + w, y + i);
		cout << char(179);
	}
	gotoxy(x, y);
	cout << char(218);
	gotoxy(x + w, y);
	cout << char(191);
	gotoxy(x, y + 2);
	cout << char(192);
	gotoxy(x + w, y + 2);
	cout << char(217);
}
void box(int x, int y, int sl, int w)
{
	char a[50] = "PORTAL HCMUS";
	int len = strlen(a);
	ToMau(x + w / 2 - len, y - 3, a, 2);
	x = x - 6;
	y = y - 2;
	sl += 3;
	for (int i = 0; i < w; i++)
	{
		gotoxy(x + i, y);
		cout << char(205);
		gotoxy(x + i, y + sl);
		cout << char(205);
	}
	for (int i = 0; i < sl; i++)
	{
		gotoxy(x, y + i);
		cout << char(186);
		gotoxy(x + w, y + i);
		cout << char(186);
	}
	gotoxy(x, y);
	cout << char(201);
	gotoxy(x, y + sl);
	cout << char(200);
	gotoxy(x + w, y);
	cout << char(187);
	gotoxy(x + w, y + sl);
	cout << char(188);
	/*draw_load(x, y+sl-1,w);*/
}
void ba_cham(int x, int y, int w)
{
	for (int i = 0; i < w; i++)
	{
		gotoxy(x + 1, y);
		cout << "_";
	}
}
void press_enter()
{
	int j = 10;
	/*while (j < 15)
	{*/
		for (int i = 0; i < 30; i++)
		{
			gotoxy(10 + i, j);
			textcolor(2);
			printf(" ");
		}
	/*	j++;
	}*/
	/*gotoxy(15, 12);
	textcolor(12);
	cout<<"Press Enter To Continue";*/
}
void draw_load(int x, int y, int w)
{
	gotoxy(x, y);
	for (int i = 0; i < w; i++)
	{
		textcolor(7);
		cout << char(178);
	}
	gotoxy(x, y);
	for (int i = 0; i < w; i++)
	{
		textcolor(3);
		cout << char(178);
		Sleep(80);
	}
}