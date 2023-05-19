#include "lib.h"
// de 2 ham option tren cung de code 
void option_giao_vien(tai_khoan& temp, list_log_in l, int x, int y)
{
	char tf[100] = "danh_sach_tai_khoan_gv.csv";
	int sl = 7;
	while (true)
	{
		system("cls");
		nd_gv(x, y, temp);
		int n = click(x, y, sl);
		if (n == y + 6)
		{
			system("cls");
			clearn(l);
			log_in(l, temp, x, y);
		}
		else if (n == y + 5)
		{
			reset_key(l, temp, tf, x, y);
			system("cls");
			log_in(l, temp, x, y);
		}
		else if (n == y + 4)
		{
			int sl, sl_hk;
			ds_mon_hoc ds_mh;
			init_ds_mh(ds_mh);
			mon_hoc mh;
			nam_hoc* nh = new nam_hoc[2];
			doc_ds_nam_hoc_tu_file(nh, sl);
			char a[10] = "Nam Hoc";
			ToMau(x + 30, y, a, 2);
			nd_nam_hoc(nh, sl, x, y + 1);
			int cl_nam_hoc = click(x + 29, y + 1, sl) - y - 1;
			hoc_ki* hk = new hoc_ki[3];
			doc_ds_hoc_ki_tu_file(hk, nh[cl_nam_hoc], sl_hk);
			system("cls");
			nd_gv(x, y, temp);
			nd_hoc_ki(hk, sl_hk, x, y);
			int cl_hoc_ki = click(x + 29, y, sl_hk) - y;
			system("cls");
			nd_gv(x, y, temp);
			doc_ds_mon_hoc_tu_file(hk[cl_hoc_ki], nh[cl_nam_hoc], ds_mh);
         	xuat_ds_mon_hoc(ds_mh, x,y);
			char c = _getch();
		}
		else if (n == y + 3)
		{
			int sl, sl_hk;
			mon_hoc mh;
			nam_hoc* nh = new nam_hoc[2];
			doc_ds_nam_hoc_tu_file(nh, sl);
			char a[10] = "Nam Hoc";
			ToMau(x + 30, y, a, 2);
			nd_nam_hoc(nh, sl, x, y + 1);
			int cl_nam_hoc = click(x + 29, y + 1, sl) - y - 1;
			hoc_ki* hk = new hoc_ki[3];
			doc_ds_hoc_ki_tu_file(hk, nh[cl_nam_hoc], sl_hk);
			system("cls");
			nd_gv(x, y, temp);
			nd_hoc_ki(hk, sl_hk, x, y);
			int cl_hoc_ki= click(x + 29, y, sl_hk) - y;
			system("cls");
			nd_gv(x, y, temp);
			nhap_mon_hoc(mh, x, y);
			ghi_ds_mon_hoc(hk[cl_hoc_ki], mh, nh[cl_nam_hoc]);
			
		}
		else if (n == y + 2)
		{
			int size=0;
			nam_hoc* nh = new nam_hoc[2];
			doc_ds_nam_hoc_tu_file(nh, sl);
			char a[10] = "Nam Hoc";
			ToMau(x+30, y, a, 2);
			nd_nam_hoc(nh, sl, x, y+1);
			int cl = click(x+29, y+1, sl) - y-1;
			hoc_ki h;
			system("cls");
			nd_gv(x, y, temp);
			nhap_hoc_ki(h,x, y);
			ghi_1_hoc_ki_vao_file(h,nh[cl]);
		}
		else if (n == y + 1)
		{
			nam_hoc a;
			nhap_nam_hoc(a, x, y);
			ghi_1_nam_hoc_vao_file(a);
		}
	}
}
void option_sinh_vien(tai_khoan temp, list_log_in l, int x, int y)
{
	char tf[100] = "danh_sach_tai_khoan_sv.csv";
	int sl = 7;
	nd_sv(x, y, temp);
	int n = click(x, y, sl);
	if (n == y + 6)
	{
		system("cls");
		clearn(l);
		log_in(l, temp, x, y);
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
	char hi[100] = "Hello, ";
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
}
void nd_gv(int x, int y, tai_khoan temp)
{
	//  xin chao 
	char hi[100] = "Hello, ";
	strcat(hi, temp.ho_ten);
	ToMau(x - 4, y - 2, hi, 2);
	char nd1[40] = "Xem Ho so";
	char nd2[40] = "Tao nam hoc ";
	char nd3[40] = "Tao hoc ki ";
	char nd4[40] = "Tao 1 lop hoc";
	char nd5[40] = "Cac khoa hoc";
	char dmk[40] = "Doi mat khau";
	char dx[40] = "Dang xuat";
	ToMau(x, y, nd1, 2);
	ToMau(x, y + 1, nd2, 2);
	ToMau(x, y + 2, nd3, 2);
	ToMau(x, y + 3, nd4, 2);
	ToMau(x, y + 4, nd5, 2);
	ToMau(x, y + 5, dmk, 2);
	ToMau(x, y + 6, dx, 2);
}
void log_in(list_log_in& l, tai_khoan& infor, int x , int y )
{
	noi_dung1(x,y);
	if (click_sv_gv(x, y, 2) == y + 1)
	{
		while (true)
		{
			char tf[100] = "danh_sach_tai_khoan_sv.csv";
			system("cls");
			noi_dung2(x,y);
			if (click_dn_dk(x, y, 2) == y + 1)
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
					textcolor(2);
					gotoxy(x, y + 3);
					cout << "Successful !!";
					Sleep(1000);
					system("cls");
					nd_sv(x, y, infor);
					option_sinh_vien(infor, l, x,y);
				}
				else
				{
					textcolor(2);
					gotoxy(x, y + 3);
					cout << "Failure !! ";
					Sleep(1000);
				}
			}
		}
	}
	else if (click_sv_gv(x, y, 2) == y)
	{
		while (true)
		{
			system("cls");
			char tf[100] = "danh_sach_tai_khoan_gv.csv";
			noi_dung2(x,y);
			if (click_dn_dk(x, y, 2) == y + 1)
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
					textcolor(2);
					gotoxy(x, y + 3);
					cout << "Successful !!";
					Sleep(1000);
					system("cls");
					nd_gv(x, y, infor);
					option_giao_vien(infor,l, x,y);
				}
				else
				{
					textcolor(2);
					gotoxy(x, y + 3);
					cout << "Failure  !! ";
					Sleep(1000);
				}
			}
		}
	}
}
void noi_dung2(int x , int y)
{
	char a[100] = "POTAL HCMUS";
	ToMau(40, 2, a, 2);
	char nd1[100] = " Log In ";
	char nd2[100] = " Sign Up ";
	ToMau(x, y, nd1, 2);
	ToMau(x, y+1, nd2, 2);
}
int click_dn_dk(int x, int y, int sl)
{
	int  px = x, py = y;
	char c;
	int w = 10;
	bool a = true;
	while (true)
	{
		bieu_tuong_click(px, py, w);
		c = _getch();
		xoa_bieu_tuong_click(px, py, w);
		if (c == 13)
		{
			return py;
		}
		if (c == 80)
		{
			if (py == y + 1)
				py = py - 1;
			else
				py = py + 1;
			bieu_tuong_click(px, py, w);
		}
		else if (c == 72)
		{
			if (py == y)
				py = py + 1;
			else
				py = py - 1;
			bieu_tuong_click(px, py, w);
		}

	}
}
int click_sv_gv(int x, int y, int sl)
{
	int  px = x, py = y, w = 10;
	char c;
	while (true)
	{
		bieu_tuong_click(px, py, w);
		c = _getch();
		xoa_bieu_tuong_click(px, py, w);
		if (c == 13)
		{
			return py;
		}
		if (c == 80)
		{
			if (py == y + 1)
				py = py - 1;
			else
				py = py + 1;
			bieu_tuong_click(px, py, w);
		}
		else if (c == 72)
		{
			if (py == y)
				py = py + 1;
			else
				py = py - 1;
			bieu_tuong_click(px, py, w);
		}
	}
}
void bieu_tuong_click(int x, int y, int w)
{
	gotoxy(x - 3, y);
	cout << char(175);//175
	gotoxy(x + w, y);
	cout << char(174);//174
}
void xoa_bieu_tuong_click(int x, int y, int w)
{
	gotoxy(x - 3, y);
	cout << char(32);//175
	gotoxy(x + w, y);
	cout << char(32);//174
}
void noi_dung1( int x , int y )
{
	char a[100] = "POTAL HCMUS";
	ToMau(40, 2, a, 2);
	char nd1[100] = "Teacher";
	char nd2[100] = "Student";
	ToMau(x, y, nd1, 2);
	ToMau(x, y+1, nd2, 2);
}

void dk(int x, int y, char tf[])
{
	char aff[100] = "POTAL HCMUS";
	ToMau(40, 2, aff, 2);
	textcolor(2);
	gotoxy(x, y);
	tai_khoan a;
	cout << " Ma so :";
	cin.getline(a.ms, 50);
	y++;
	gotoxy(x, y);
	cout << " Ho va ten :";
	cin.getline(a.ho_ten, 50);
	y++;
	gotoxy(x, y);
	cout << " Ten dang nhap :";
	cin.getline(a.user, 50);
	y++;
	gotoxy(x, y);
	cout << " Mat khau :";
	cin.getline(a.key, 50);
	xoa_xuong_dong(a.key);
	ofstream file;
	file.open(tf, ios::app);
	// endl o dau de xoa /n
	file << endl << a.ms << ',' << a.ho_ten << ',' << a.user << ',' << a.key;
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
		filelogin.getline(t.ms, 100, ',');
		filelogin.getline(t.ho_ten, 100, ',');
		filelogin.getline(t.user, 100, ',');
		filelogin.getline(t.key, 100, '\n');
		node* add = tao_node_log_in(t);
		addlast_log_in(l, add);
	}
	filelogin.close();
}
bool dn(list_log_in l, int x, int y, char tf[], tai_khoan& temp)
{
	char aff[100] = "POTAL HCMUS";
	ToMau(40, 2, aff, 2);
	gotoxy(x, y);
	textcolor(2);
	cout << "User :";
	cin.getline(temp.user, 50);
	y++;
	gotoxy(x, y);
	cout << "Password: ";
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
	textcolor(2);
	gotoxy(x + 30, y);
	cout << "Mat khau moi :";
	char t[100];
	cin.getline(t, 100);
	xoa_xuong_dong(t);
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
int click(int x, int y, int sl)
{
	int slt = sl;
	slt--;
	int	px = x, py = y, w = 18;
	char c = 0;
	while (true)
	{
		bieu_tuong_click(px, py, w);
		 c = _getch();
		xoa_bieu_tuong_click(px, py, w);
		if (c == 13)
			return py;
		if (c == 80)
		{
			if (py == y + slt)
				py = py - slt;
			else
				py = py + 1;
			bieu_tuong_click(px, py, w);
		}
		else if (c == 72)
		{
			if (py == y)
				py = py + sl - 1;
			else
				py = py - 1;
			bieu_tuong_click(px, py, w);
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