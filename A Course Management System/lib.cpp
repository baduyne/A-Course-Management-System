#include "lib.h"
// de 2 ham option tren cung de code 
void option_teacher(tai_khoan& temp, list_log_in l, int x, int y)
{
	char tf[50] = "danh_sach_tai_khoan_gv.csv";
	int w = 15;
	while (true)
	{
		int sl = 8;
		system("cls");
		nd_gv(x, y, temp);
		int n = click(x, y, sl,w);
		if (n == y + 7)
		{
			system("cls");
			clearn(l);
			log_in(l, temp, x, y);
		}
		else if (n == y)
		{
			infor(x, y, temp);
		}
		else if (n == y + 6)
		{
			reset_key(l, temp, tf, x, y);
			system("cls");
			log_in(l, temp, x, y);
		}
		else if (n == y + 5)
		{
			int sl, sl_hk;
			ds_khoa_hoc ds_kh;
			init_ds_mh(ds_kh);
			khoa_hoc mh;
			nam_hoc* nh = new nam_hoc[3];
			doc_ds_nam_hoc_tu_file(nh, sl);
			nd_nam_hoc(nh, sl, x, y );
			int cl_nam_hoc = click(x, y+1, sl,w ) - y - 1;
			hoc_ki* hk = new hoc_ki[3];
			doc_ds_hoc_ki_tu_file(hk, nh[cl_nam_hoc], sl_hk);
			if (sl_hk == 0)
			{
				system("cls");
				box(x, y, 1, 40);
				gotoxy(x, y);
				textcolor(4);
				cout << "NO SEMER";
				char c = _getch();
				continue;
			}
			system("cls");
			nd_gv(x, y, temp);
			nd_hoc_ki(hk, sl_hk, x, y);
			int cl_hoc_ki = click(x, y, sl_hk,w) - y;
			system("cls");
			doc_ds_khoa_hoc_tu_file(hk[cl_hoc_ki], nh[cl_nam_hoc], ds_kh);
         	xuat_ds_khoa_hoc( x,y,ds_kh);
		}
		else if (n == y + 4)
		{
			nd_khoa_hoc(x, y);
			int cl_lh = click(x, y, 8, 30);
			xu_ly_khoa_hoc(cl_lh,x,y);
		}
		else if (n == y + 2)
		{
			int sl=2;
			nam_hoc* nh = new nam_hoc[sl];
			doc_ds_nam_hoc_tu_file(nh, sl);
			nd_nam_hoc(nh, sl, x, y);
			int cl_hoc_ki = click(x, y+1, sl,w) - y-1;
			hoc_ki h;
			system("cls");
			nd_gv(x, y, temp);
			nhap_hoc_ki(h,x, y,nh[cl_hoc_ki]);
			ghi_1_hoc_ki_vao_file(h,nh[cl_hoc_ki]);
		}
		else if (n == y + 1)
		{
			nam_hoc a;
			nhap_nam_hoc(a, x, y);
			ghi_1_nam_hoc_vao_file(a);
		}
		else if (n == y + 3)
		{
			nd_lop_hoc(x, y);
			int cl_lh = click(x, y, 3, 20);
			xu_ly_lop_hoc(cl_lh, x, y);
		}
	}
}
void option_student(tai_khoan temp, list_log_in l, int x, int y)
{
	char tf[50] = "danh_sach_tai_khoan_sv.csv";
	int sl = 7, w = 20;
	nd_sv(x, y, temp);
	int n = click(x, y, sl,w);
	if (n == y + 6)
	{
		system("cls");
		clearn(l);
		log_in(l, temp, x, y);
	}
	if (n == y)
	{
		infor(x, y, temp);
	}
	else if(n == y +5)
	{
		reset_key(l, temp, tf, x, y);
		system("cls");
		clearn(l);
		log_in(l, temp, x, y);
	}
}
void  nd_sv(int x, int y, tai_khoan temp)
{
	char hi[20] = "Hello, ";
	strcat(hi, temp.ho_ten);
	ToMau(x - 4, y - 2, hi, 2);
	char nd1[40] = "Xem Ho so";
	char nd2[40] = "Dang ki mon hoc";
	char nd3[40] = "Lich hoc";
	char nd4[40] = "Lich thi ";
	char nd5[40] = "Ket qua hoc tap";
	char dmk[40] = "Doi mat khau";
	char dx[40] = "Dang xuat";
	ToMau(x, y, nd1, 2);
	ToMau(x, y + 1, nd2, 2);
	ToMau(x, y + 2, nd3, 2);
	ToMau(x, y + 3, nd4, 2);
	ToMau(x, y + 4, nd5, 2);
	ToMau(x, y + 5, dmk, 2);
	ToMau(x, y + 6, dx, 2);
	box(x, y - 2, 10, 35);
}
void nd_gv(int x, int y, tai_khoan temp)
{
	char hi[50] = "Hello, ";
	strcat(hi, temp.ho_ten);
	ToMau(x - 4, y - 2, hi, 2);
	char nd1[40] = "Xem Ho so";
	char nd2[40] = "Tao nam hoc ";
	char nd3[40] = "Tao hoc ki ";
	char nd4[40] = "Lop hoc";
	char nd5[40] = "Khoa hoc";
	char nd6[40] = "Cac khoa hoc";
	char dmk[40] = "Doi mat khau";
	char dx[40] = "Dang xuat";
	ToMau(x, y, nd1, 2);
	ToMau(x, y + 1, nd2, 2);
	ToMau(x, y + 2, nd3, 2);
	ToMau(x, y + 3, nd4, 2);
	ToMau(x, y + 4, nd5, 2);
	ToMau(x, y + 5, nd6, 2);
	ToMau(x, y + 6, dmk, 2);
	ToMau(x, y + 7, dx, 2);
	box(x, y-2, 10, 35);
}
void log_in(list_log_in& l, tai_khoan& infor, int x , int y )
{
	noi_dung1(x,y);
	int cl = click(x, y, 2, 10);
	if (cl == y + 1)
	{
		while (true)
		{
			char tf[50] = "danh_sach_tai_khoan_sv.csv";
			system("cls");
			noi_dung2(x, y);
			int cl_1= click(x, y, 2, 10);
			if (cl_1 == y + 1)
			{
				system("cls");
				dk(x, y, tf);
			}
			else
			{
				system("cls");
				doc_file(tf, l);
				if (dn(l, x, y, tf, infor))
				{
					draw_load(x, y + 2, 20);
					system("cls");
					nd_sv(x, y, infor);
					option_student(infor, l, x,y);
				}
				else
				{
					textcolor(4);
					gotoxy(x, y + 2);
					cout << "Failure !! ";
					Sleep(500);
				}
			}
		}
	}
	else if (cl == y)
	{
		while (true)
		{
			system("cls");
			char tf[50] = "danh_sach_tai_khoan_gv.csv";
			noi_dung2(x,y);
			int cl_2 = click(x, y, 2, 10);
			if (cl_2 == y + 1)
			{
				system("cls");
				dk(x, y, tf);
			}
			else
			{
				doc_file(tf, l);
				system("cls");
				if (dn(l, x, y, tf, infor))
				{
					draw_load(x, y + 2, 20);
					system("cls");
					nd_gv(x, y, infor);
					option_teacher(infor,l, x,y);
				}
				else
				{
					textcolor(4);
					gotoxy(x, y + 2);
					cout << "Failure  !! ";
					Sleep(500);
				}
			}
		}
	}
}
void noi_dung2(int x , int y)
{
	char nd1[20] = " Log In ";
	char nd2[20] = " Sign Up ";
	ToMau(x, y, nd1, 2);
	ToMau(x, y+1, nd2, 2);
	box(x, y, 2, 20);
}
void symbol_click(int x, int y, int w)
{
	gotoxy(x -3, y);
	cout << char(175);//175
	gotoxy(x + w, y);
	cout << char(174);//174
}
void remove_symbol_click(int x, int y, int w)
{
	gotoxy(x - 3, y);
	cout << char(32);//175
	gotoxy(x + w, y);
	cout << char(32);//174
}
void noi_dung1( int x , int y)
{
	char nd1[50] = "Teacher";
	char nd2[50] = "Student";
	ToMau(x, y, nd1, 2);
	ToMau(x, y+1, nd2, 2);
	box(x, y, 2, 20);
}

void dk(int x, int y, char tf[])
{
	box(x, y,5,35);
	gotoxy(x, y);
	tai_khoan a;
	cout << "Your Name :";
	cin.getline(a.ho_ten, 50);
	y++;
	gotoxy(x, y);
	cout << "ID :";
	cin.getline(a.ms, 50);
	y++;
	gotoxy(x, y);
	cout << "Birthday :";
	cin.getline(a.ngay_sinh, 20);
	y++;
	gotoxy(x, y);
	cout << "Username :";
	cin.getline(a.user, 50);
	y++;
	gotoxy(x, y);
	cout << "Password :";
	cin.getline(a.key, 50);
	xoa_xuong_dong(a.key);
	ofstream file;
	file.open(tf, ios::app);
	// endl o dau de xoa /n
	file << endl << a.ms << ',' << a.ho_ten << ',' <<a.ngay_sinh<<',' << a.user << ',' << a.key;
	file.close();
}
void khoi_tao(list_log_in& l)
{
	l.head = NULL;
}
node* tao_node_log_in(tai_khoan a)
{
	node* add = new node;
	add->data = a;
	add->next = NULL;
	return add;
}
void addlast_log_in(list_log_in& l, node* p)
{
	if (l.head == NULL)
	{
		l.head = p;
	}
	else
	{
		node* temp = l.head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = p;
	}
}
void xuat(tai_khoan a)
{
	cout << a.ms << "," << a.ho_ten << "," << a.user << "," << a.key << endl;
}
void xuat_ds(list_log_in l)
{
	while (l.head != NULL)
	{
		gotoxy(0, 0);
		xuat(l.head->data);
		l.head = l.head->next;
	}
}
void doc_file(char ten_file[], list_log_in& l)
{
	tai_khoan t;
	ifstream filelogin;
	filelogin.open(ten_file);
	filelogin.seekg(0, ios_base::beg);
	while (!filelogin.eof())
	{
		filelogin.getline(t.ms, 50, ',');
		filelogin.getline(t.ho_ten, 50, ',');
		filelogin.getline(t.ngay_sinh, 50, ',');
		filelogin.getline(t.user, 50, ',');
		filelogin.getline(t.key, 50, '\n');
		node* add = tao_node_log_in(t);
		addlast_log_in(l, add);
	}
	filelogin.close();
}
bool dn(list_log_in l, int x, int y, char tf[], tai_khoan& temp)
{
	textcolor(2);
	box(x, y, 2, 35);
	gotoxy(x, y);
	cout << "Username :";
	cin.getline(temp.user, 50);
	y++;
	gotoxy(x, y);
	cout << "Password :";
	cin.getline(temp.key, 50);
	y++;
	while (l.head != NULL)
	{
		if (strcmp(l.head->data.user, temp.user) == 0 && strcmp(l.head->data.key, temp.key) == 0)
		{
			temp = l.head->data;
			return true;
		}
		l.head = l.head->next;
	}
	return false;
}
void xoa_xuong_dong(char a[])
{
	size_t i = strlen(a);
	if (a[i - 1] == '\n')
		a[i - 1] = '\0';
}
void reset_key(list_log_in& l, tai_khoan& a, char ten_file[], int x ,int y )
{
	system("cls");
	box(x, y, 1, 30);
	gotoxy(x, y);
	cout << "Mat khau moi :";
	char t[50];
	cin.getline(t, 50);
	/*xoa_xuong_dong(t);*/
	node* temp = l.head;
	while (temp != NULL)
	{
		if (strcmp(temp->data.user, a.user) == 0)
		{
			strcpy(temp->data.key, t);
			strcpy(a.key, t);
			ghi_file_tai_khoan(l, ten_file);
			return;
		}
		temp = temp->next;
	}
	ghi_file_tai_khoan(l, ten_file);
	return;
}
void xuat_so_node(list_log_in l)
{
	while (l.head != NULL)
	{
		xuat(l.head->data);
		l.head = l.head->next;
	}
	cout << "xuat thanh cong";
}
void clearn(list_log_in& l)
{
	l.head = NULL;
}
int click(int x, int y, int sl, int w)
{
	int slt = sl;
	slt--;
	int	px = x, py = y;
	char c ;
	while (true)
	{
		symbol_click(px, py, w);
		 c = _getch();
		remove_symbol_click(px, py, w);
		if (c == 13)
			return py;
		if (c == 80)
		{
			if (py == y + slt)
				py = py - slt;
			else
				py = py + 1;
			symbol_click(px, py, w);
		}
		else if (c == 72)
		{
			if (py == y)
				py = py + sl - 1;
			else
				py = py - 1;
			symbol_click(px, py, w);
		}
	}
	return 0;
}

void ghi_file_tai_khoan(list_log_in l, char tf[])
{
	fstream filein;
	filein.open(tf, ios::out);
	/*file  << "Ma so" << ',' << "Ho va ten" << ',' << "user" << ',' << "password"<<endl;*/
	while (l.head != NULL)
	{
		filein << l.head->data.ms << ',' << l.head->data.ho_ten << ',' << l.head->data.user << ',' << l.head->data.key;
		if (l.head->next == NULL)
		{
			filein.close();
			return;
		}
		filein << endl;
		l.head = l.head->next;
	}
	filein.close();
}
void box(int x, int y, int sl, int w)
{
	char a[50] = "POTAL HCMUS";
	size_t len = strlen(a);
	ToMau(x + w / 2 - len, y - 3, a, 2);
	x = x - 6;
	y = y - 2;
	sl += 3;
	for (int i = 0; i < w; i++)
	{
		gotoxy(x + i, y);
		cout << char(196);
		gotoxy(x + i, y + sl);
		cout << char(196);
	}
	for (int i = 0; i < sl; i++)
	{
		gotoxy(x, y + i);
		cout << char(179);
		gotoxy(x + w, y + i);
		cout << char(179);
	}
	gotoxy(x, y);
	cout << char(213);
	gotoxy(x, y + sl);
	cout << char(212);
	gotoxy(x + w, y);
	cout << char(184);
	gotoxy(x + w, y + sl);
	cout << char(190);
	/*draw_load(x, y+sl-1,w);*/
}
void infor(int x, int y, tai_khoan a)
{
	system("cls");
	box(x, y, 5, 35);
	gotoxy(x, y);
	cout << " Name :" << a.ho_ten;
	y++;
	gotoxy(x, y);
	cout << " ID :" << a.ms;
	y++;
	gotoxy(x, y);
	cout << " Birthday :" << a.ngay_sinh;
	y++;
	gotoxy(x, y);
	cout << " Username :" << a.user;
	y++;
	gotoxy(x, y);
	cout << " >> Press Enter <<";
	char c = _getch();
	if (c == 13)
		return;
}
