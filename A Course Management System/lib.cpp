#include "lib.h"
void log_in(list_log_in& l, tai_khoan& infor, int x, int y)
{
	/*resizeConsole(700, 100);*/
	noi_dung1(x, y);
	int cl = click(x, y, 2, 10);
	if (cl == y + 1)
	{
		while (true)
		{
			char tf[50] = "Tai_khoan_sinh_vien.csv";
			system("cls");
			noi_dung2(x, y);
			int cl_1 = click(x, y, 2, 10);
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
					draw_load(x, y + 8, 20);
					system("cls");
					nd_sv(x, y, infor);
					option_student(infor, l, x, y);
				}
				else
				{
					textcolor(4);
					gotoxy(x, y + 8);
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
			char tf[50] = "Tai_khoan_giao_vien.csv";
			noi_dung2(x, y);
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
					draw_load(x, y + 8, 20);
					system("cls");
					nd_gv(x, y, infor);
					option_teacher(infor, l, x, y);
				}
				else
				{
					textcolor(4);
					gotoxy(x, y + 8);
					cout << "Failure  !! ";
					Sleep(500);
				}
			}
		}
	}
}
void option_teacher(tai_khoan& temp, list_log_in l, int x, int y)
{
	char tf[50] = "Tai_khoan_giao_vien.csv";
	while (true)
	{
		int sl = 7;
		system("cls");
		nd_gv(x, y, temp);
		int n = click(x+5, y, sl,15);
		if (n == y + 6)
		{
			system("cls");
			clearn(l);
			log_in(l, temp, x, y);
		}
		else if (n == y)
		{
			infor(x, y, temp);
		}
		else if (n == y + 5)
		{
			reset_key(l, temp, tf, x, y);
			system("cls");
			clearn(l);
			log_in(l, temp, x, y);
		}
		else if (n == y + 4)
		{
			int sl, sl_hk;
			ds_khoa_hoc ds_kh;
			init_ds_kh(ds_kh);
			khoa_hoc mh;
			nam_hoc* nh = new nam_hoc[3];
			doc_ds_nam_hoc_tu_file(nh, sl);
			if (sl == 0)
			{
				system("cls");
				box(x, y, 2, 30);
				gotoxy(x, y);
				textcolor(12);
				cout << "NO SCHOOL YEAR";
				cin.ignore();
				return;
			}
			xuat_nam_hoc(nh, sl, x, y );
			int cl_nam_hoc = click(x, y+1, sl,12) - y - 1;
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
			int cl_hoc_ki = click(x, y, sl_hk,10) - y;
			system("cls");
			doc_ds_khoa_hoc_tu_file(hk[cl_hoc_ki], nh[cl_nam_hoc], ds_kh);
			if (so_node_khoa_hoc(ds_kh) == 0)
			{
				system("cls");
				box(x, y, sl, 30);
				textcolor(4);
				gotoxy(x, y);
				cout << "NO COURSE";
				cin.ignore();
				continue;
			}
         	xuat_ds_khoa_hoc( x,y,ds_kh, nh[cl_nam_hoc], hk[cl_hoc_ki]);
		}
		else if (n == y + 3)
		{
			xu_ly_khoa_hoc(x,y);
		}
		else if (n == y + 1)//create year and semer
		{
			nd_khoi_tao(x, y);
			int cl_kt = click(x+3, y, 3,12);
			func_khoi_tao(x, y, cl_kt);
		}
		else if (n == y + 2)
		{
			xu_ly_lop_hoc(x, y);
		}
	}
}
void option_student(tai_khoan temp, list_log_in l, int x, int y)
{
	char tf[50] = "Tai_khoan_sinh_vien.csv";
	int sl = 6, w = 20;
	while (true)
	{
		system("cls");
		nd_sv(x, y, temp);
		int n = click(x + 3, y, sl, w);
		if (n == y + 5)
		{
			system("cls");
			clearn(l);
			log_in(l, temp, x, y);
		}
		if (n == y)
		{
			infor(x, y, temp);
		}
		else if (n == y + 4)
		{
			reset_key(l, temp, tf, x, y);
			system("cls");
			clearn(l);
			log_in(l, temp, x, y);
		}
		else if (n == y + 1)
		{
			dk_khoa_hoc(x, y, temp);
		}
		else if (n == y + 2)
		{
			int sl = 2, sl_hk = 2;
			nam_hoc* nh = new nam_hoc[sl];
			doc_ds_nam_hoc_tu_file(nh, sl);
			if (sl == 0)
			{
				system("cls");
				box(x, y, 2, 30);
				gotoxy(x, y);
				textcolor(12);
				cout << "NO SCHOOL YEAR";
				cin.ignore();
				return;
			}
			xuat_nam_hoc(nh, sl, x, y);
			int cl_nam_hoc = click(x, y + 1, sl, 11) - y - 1;
			hoc_ki* hk = new hoc_ki[sl_hk];
			doc_ds_hoc_ki_tu_file(hk, nh[cl_nam_hoc], sl_hk);
			system("cls");
			if (sl_hk == 0)
			{
				box(x, y, 2, 30);
				gotoxy(x, y);
				textcolor(12);
				cout << "NO SEMESTER";
				cin.ignore();
				return;
			}
			nd_hoc_ki(hk, sl_hk, x, y);
			int cl_hoc_ki = click(x, y, sl_hk, 10) - y;
			ds_khoa_hoc ds_kh;
			init_ds_kh(ds_kh);
			doc_ds_khoa_hoc_tu_file(hk[cl_hoc_ki], nh[cl_nam_hoc], ds_kh);
			if (so_node_khoa_hoc(ds_kh) == 0)
			{
				system("cls");
				box(x, y, 2, 30);
				textcolor(4);
				gotoxy(x, y);
				cout << "NO COURSE";
				cin.ignore();
				return;
			}
			ds_khoa_hoc l;
			init_ds_kh(l);
			xem_khoa_hoc_da_dk( nh[cl_nam_hoc], hk[cl_hoc_ki],l, x, y, temp);
			if (l.head == NULL)
			{
				system("cls");
				box(x, y, 2, 30);
				textcolor(4);
				gotoxy(x, y);
				cout << "NO COURSE";
				cin.ignore();
				return;
			}
			xuat_ds_khoa_hoc(x, y, l, nh[cl_nam_hoc], hk[cl_hoc_ki]);
			delete[]nh;
			delete[]hk;
		}
		else if (n == y + 3)
		{
			xem_diem(temp, x, y);
			cin.ignore();
		}
	}
}
void  nd_sv(int x, int y, tai_khoan temp)
{
	char hi[60] = "Hello !";
	ToMau(x - 4, y - 3, hi, 2);
	ToMau(x-2, y-2, temp.ho_ten, 2);
	char nd1[40] = "Xem Ho so";
	char nd2[40] = "Dang ki mon hoc";
	char nd3[40] = "Ket qua dang ki HP";
	char nd4[40] = "Ket qua hoc tap";
	char dmk[40] = "Doi mat khau";
	char dx[40] = "Dang xuat";
	ToMau(x + 11 - strlen(nd1) / 2, y, nd1, 2);
	ToMau(x + 11 - strlen(nd2) / 2, y + 1, nd2, 2);
	ToMau(x + 12 - strlen(nd3) / 2, y + 2, nd3, 2);
	ToMau(x + 11 - strlen(nd4) / 2, y + 3, nd4, 2);
	ToMau(x + 11 - strlen(dmk) / 2, y + 4, dmk, 2);
	ToMau(x + 11 - strlen(dx) / 2, y + 5, dx, 2);
	box(x, y - 3, 11, 35);
}
void nd_gv(int x, int y, tai_khoan temp)
{
	char hi[60] = "Hello !";
	ToMau(x - 4, y - 3, hi, 2);
	ToMau(x - 2, y - 2, temp.ho_ten, 2);
	char nd1[40] = "Xem Ho So";
	char nd2[40] = "Khoi Tao";
	char nd3[40] = "Xu Ly Lop Hoc";
	char nd4[40] = "Xu Ly Khoa Hoc";
	char nd5[40] = "Cac Khoa Hoc";
	char dmk[40] = "Doi Mat Khau";
	char dx[40] = "Dang Xuat";
	ToMau(x+11 - strlen(nd1) / 2, y, nd1, 2);
	ToMau(x + 11 - strlen(nd2) / 2, y + 1, nd2, 2);
	ToMau(x + 11 - strlen(nd3) / 2, y + 2, nd3, 2);
	ToMau(x + 12 - strlen(nd4) / 2, y + 3, nd4, 2);// doi xung
	ToMau(x + 11 - strlen(nd5) / 2, y + 4, nd5, 2);
	ToMau(x + 11 - strlen(dmk) / 2, y + 5, dmk, 2);
	ToMau(x + 11 - strlen(dx) / 2, y + 6, dx, 2);
	box(x, y-2, 10, 35);
}
void nd_hoc_ki(hoc_ki*& a, int sl, int x, int y)
{
	system("cls");
	if (sl == 0)
	{
		system("cls");
		box(x, y, 1, 40);
		gotoxy(x, y);
		textcolor(4);
		cout << "NO SEMER";
		char c = _getch();
		return;
	}
	box(x, y, sl, 24);
	for (int i = 0; i < sl; i++)
	{
		ToMau(x, y, a[i].ten, 2);
		y++;
	}
}
void nd_khoa_hoc(int x, int y)
{
	system("cls");
	box(x, y, 9, 40);
	char nd1[20] = "Tao 1 Khoa Hoc";
	char nd2[20] = "Them 1 Sinh Vien";
	char nd3[30] = "Them Sinh Vien Tu File";
	char nd4[40] = "Xem Danh Sach Sinh Vien";
	char nd5[20] = "Xoa 1 Sinh Vien";
	char nd6[20] = "Xoa 1 Khoa Hoc";
	char nd7[20] = "Cap Nhat Khoa Hoc";
	char nd8[20] = "Nhap Diem Tu File";
	char nd9[20] = "Thoat";
	ToMau(x + 13 - strlen(nd1) / 2, y, nd1, 2);
	ToMau(x + 13 - strlen(nd2) / 2, y + 1, nd2, 2);
	ToMau(x + 13 - strlen(nd3) / 2, y + 2, nd3, 2);
	ToMau(x + 13 - strlen(nd4) / 2, y + 3, nd4, 2);
	ToMau(x + 13 - strlen(nd5) / 2, y + 4, nd5, 2);
	ToMau(x + 13 - strlen(nd6) / 2, y + 5, nd6, 2);
	ToMau(x + 13 - strlen(nd7) / 2, y + 6, nd7, 2);
	ToMau(x + 13 - strlen(nd8) / 2, y + 7, nd8, 2);
	ToMau(x + 13 - strlen(nd9) / 2, y + 8, nd9, 2);
}
void nd_lop_hoc(int x, int y)
{
	system("cls");
	box(x, y, 8, 35);
	char nd1[20] = "Tao 1 Lop Hoc";
	char nd2[30] = "Danh Sach Lop Hoc";
	char nd3[30] = "Them 1 Sinh Vien";
	char nd4[30] = "Them Danh Sach Tu File";
	char nd5[30] = "Xem Danh Sach Sinh Vien";
	char nd6[30] = "Xoa 1 Sinh Vien";
	char nd7[30] = "Xem Diem Lop Hoc";
	char nd8[30] = "Xoa 1 Lop Hoc";
	char nd9[30] = "Thoat";
	ToMau(x + 11 - strlen(nd1) / 2, y, nd1, 2);// canh giua 
	ToMau(x + 11 - strlen(nd2) / 2, y + 1, nd2, 2);
	ToMau(x + 11 - strlen(nd3) / 2, y + 2, nd3, 2);
	ToMau(x + 11 - strlen(nd4) / 2, y + 3, nd4, 2);
	ToMau(x + 11 - strlen(nd5) / 2, y + 4, nd5, 2);
	ToMau(x + 11 - strlen(nd6) / 2, y + 5, nd6, 2);
	ToMau(x + 11 - strlen(nd7) / 2, y + 6, nd7, 2);
	ToMau(x + 11 - strlen(nd8) / 2, y + 7, nd8, 2);
	ToMau(x + 11 - strlen(nd9) / 2, y + 8, nd9, 2);
}
void nd_khoi_tao(int x, int y)
{
	system("cls");
	box(x, y, 3, 30);
	char nd1[20] = "Tao Nam Hoc";
	char nd2[20] = "Tao Hoc Hi";
	char  exit[20] = "Thoat";
	ToMau(x + 8 - strlen(nd1) / 2, y, nd1, 2);
	ToMau(x + 8 - strlen(nd2) / 2, y + 1, nd2, 2);
	ToMau(x + 8 - strlen(exit) / 2, y + 2, exit, 2);
}
void nd_nhap_diem(int x, int y)
{
	box(x, y, 5, 30);
	char nd1[30] = "Tao File Nhap Diem";
	char nd2[30] = "Nhap Diem";
	char nd3[30] = "Nhap Diem Tu File";
	char nd4[30] = "Thoat";
	ToMau(x + 9 - strlen(nd1) / 2, y, nd1, 2);
	ToMau(x + 9 - strlen(nd2) / 2, y + 1, nd2, 2);
	ToMau(x + 9 - strlen(nd3) / 2, y + 2, nd3, 2);
	ToMau(x + 9 - strlen(nd4) / 2, y + 3, nd4, 2);
}
void nd_xem_diem_lop_hoc(int x, int y)
{
	box(x, y, 5, 38);
	char nd1[30] = "Diem Cuoi Ki Cac Khoa Hoc";
	char nd2[30] = "Diem Trung Binh Hoc Ki";
	char nd3[30] = "Diem Trung Binh Chung";
	char nd4[30] = "Thoat";
	ToMau(x + 12 - strlen(nd1) / 2, y, nd1, 2);
	ToMau(x + 12 - strlen(nd2) / 2, y + 1, nd2, 2);
	ToMau(x + 12 - strlen(nd3) / 2, y + 2, nd3, 2);
	ToMau(x + 12 - strlen(nd4) / 2, y + 3, nd4, 2);
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
	cout << char(175) ;//175
	gotoxy(x + w, y);
	cout << char(174) ;//174
}
void remove_symbol_click(int x, int y, int w)
{
	gotoxy(x - 3, y);
	cout << char(32) ;//khoang trang
	gotoxy(x + w, y);
	cout << char(32) ;
}
void noi_dung1( int x , int y)
{
	char nd1[50] = "Teacher";
	char nd2[50] = "Student";
	ToMau(x+4-strlen(nd1)/2, y, nd1, 2);
	ToMau(x + 4 - strlen(nd2) / 2, y+1, nd2, 2);
	box(x, y, 2, 20);
}
void dk(int x, int y, char tf[])// dang ki tai khoan
{
	int px = x, py = y;
	y = y - 5;
	box(x, y, 18, 50);
	gotoxy(x, y);
	tai_khoan a;
	textcolor(2);
	cout << "Your Name:";
	textcolor(7);
	o(x, y+1, 25);
	gotoxy(x+1, y+2);
	cin.getline(a.ho_ten, 50);
	y+=4;
	gotoxy(x, y);
	textcolor(2);
	cout << "ID:";
	textcolor(7);
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(a.ms, 50);
	y += 4;
	gotoxy(x, y);
	textcolor(2);
	cout << "Birthday :";
	textcolor(7);
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(a.ngay_sinh, 20);
	y +=4;
	gotoxy(x, y);
	textcolor(7);
	cout << "Gender :";
	textcolor(7);
	strcpy(a.gioitinh,gender(x, y));
	gotoxy(x + 5, y + 1);
	textcolor(3);
	cout << "--->Press Enter To Continue";
	char c = _getch();
	if (c == 13)
	{
		system("cls");
		y = py;// reset value x y 
		x = px;
		box(x, y, 15, 40);
		gotoxy(x, y);
		textcolor(2);
		cout << " Number CCCD :";
		textcolor(7);
		o(x, y + 1, 25);
		gotoxy(x + 1, y + 2);
		cin.getline(a.cccd, 20);
		y += 4;
		gotoxy(x, y);
		textcolor(2);
		cout << "Username :";
		textcolor(7);
		o(x, y + 1, 25);
		gotoxy(x + 1, y + 2);
		cin.getline(a.user, 50);
		xoa_xuong_dong(a.key);
		y = y + 4;
		gotoxy(x, y);
		textcolor(2);
		cout << "Password :";
		textcolor(7);
		o(x, y + 1, 25);
		gotoxy(x + 1, y + 2);
		cin.getline(a.key, 50);
		xoa_xuong_dong(a.key);
	}
	ofstream file;
	file.open(tf, ios::app);
	if (check_empty_file(tf))
		file << "Ma So" << ',' << "Ho Va Ten" << ',' << "Ngay sinh" << ',' << "Gioi tinh" << ',' << "So CCCD" << ',' << "Ten Dang nhap" << ',' << "Mat Khau" << endl;
	// endl o dau de xoa /n
	file << a.ms << ',' << a.ho_ten << ',' << a.ngay_sinh << ',' << a.gioitinh << ',' << a.cccd << ',' << a.user << ',' << a.key << endl;
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
		l.head = p;
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
void doc_file(char ten_file[], list_log_in& l)// doc cac tai khoan tu file
{
	tai_khoan t;
	ifstream filelogin;
	filelogin.open(ten_file);
	char* r = new char[100];
	filelogin.getline(r, 100, '\n');// doc dong dau tien
	while (!filelogin.eof())
	{
		filelogin.getline(t.ms, 50, ',');
		filelogin.getline(t.ho_ten, 50, ',');
		if (strcmp(t.ho_ten, "") == 0)
			break;
		filelogin.getline(t.ngay_sinh, 50, ',');
		filelogin.getline(t.gioitinh, 20, ',');
		filelogin.getline(t.cccd, 20, ',');
		filelogin.getline(t.user, 50, ',');
		filelogin.getline(t.key, 50, '\n');
		node* add = tao_node_log_in(t);
		addlast_log_in(l, add);
	}
	filelogin.close();
	delete[]r;
}
bool dn(list_log_in l, int x, int y, char tf[], tai_khoan& temp)
{
	textcolor(2);
	box(x, y, 9, 40);
	gotoxy(x, y);
	textcolor(2);
	cout << "Username :";
	textcolor(7);
	o(x, y+1, 25);
	gotoxy(x + 1, y+2);
	cin.getline(temp.user, 50);
	y+=4;
	gotoxy(x, y);
	textcolor(2);
	cout << "Password :";
	textcolor(7);
	o(x, y+1, 25);
	gotoxy(x + 1, y+2);
	cin.getline(temp.key, 50);
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
void xoa_dau_phay(char a[])
{
	int i = 0;
	while (i < strlen(a))
	{
		if (a[i] == ',')
		{
			for (int j = i; j < strlen(a); j++)
				a[j] = a[j + 1];
			i--;// tra lai y de xet nhieu khoang cach lien tiep nhau 
		}
		i++;
	}
}
void make_address(char a[])
{
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == 92)
		{
			a[i] = '/';
			i--;
		}
	}
}
void delete_file(char ten_file[])
{
	int x = remove(ten_file);
	return;
}
void reset_key(list_log_in& l, tai_khoan& a, char ten_file[], int x ,int y )
{
	system("cls");
	int py = y;
	char t[50], t1[50];
	box(x, y, 9, 40);
	gotoxy(x, y);
	textcolor(2);
	cout << "Mat Khau Cu :";
	textcolor(7);
	o(x, y+1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(t, 50);
	xoa_xuong_dong(t);
	y += 4;
	gotoxy(x, y);
	textcolor(2);
	cout << "Mat Khau Moi :";
	textcolor(7);
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(t1, 50);
	if (strcmp(t, a.key) != 0)
	{
		gotoxy(x + 10, py + 8);
		textcolor(12);
		cout << "Khong Hop Le !";
		cin.ignore();
		return;
	}
	xoa_xuong_dong(t1);
	node* temp = l.head;
	while (temp != NULL)
	{
		if (strcmp(temp->data.user, a.user) == 0 && strcmp(temp->data.key, a.key) == 0)
		{
			strcpy(temp->data.key, t1);
			strcpy(a.key, t1);
			break;
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
	cout << "Xuat Thanh Cong";
}
void clearn(list_log_in& l)
{
	l.head = NULL;
}
int click(int x, int y, int sl, int w)
{
	textcolor(3);
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
		}
		else if (c == 72)
		{
			if (py == y)
				py = py + sl - 1;
			else
				py = py - 1;
		}
	}
	return 0;
}

void ghi_file_tai_khoan(list_log_in l, char tf[])
{
	ofstream filein;
	filein.open(tf);
	if (check_empty_file(tf))
		filein << "Ma So" << ',' << "Ho Va Ten" << ',' << "Ngay sinh" << ',' << "Gioi tinh" << ',' << "So CCCD" << ',' << "Ten Dang nhap" << ',' << "Mat Khau" << endl;
	while (l.head != NULL)
	{
		filein << l.head->data.ms << ',' << l.head->data.ho_ten << ',' << l.head->data.ngay_sinh << ',' << l.head->data.gioitinh << ',' << l.head->data.cccd << ',' << l.head->data.user << ',' << l.head->data.key << endl;
		l.head = l.head->next;
	}
	filein.close();
}

void infor(int x, int y, tai_khoan a)
{
	system("cls");
	box(x, y, 7, 35);
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
	cout << " Gender :" << a.gioitinh;
	y++;
	gotoxy(x, y);
	cout << " Number CCCD :" << a.cccd;
	y++;
	gotoxy(x, y);
	cout << " Username :" << a.user;
	y++;
	gotoxy(x, y);
	textcolor(3);
	cout << " >> Press Enter <<";
	cin.ignore();
}
void make_link(char a[])
{
	xoa_dau_cach(a);
	strcat(a, ".csv");
}
void xoa_dau_cach(char a[])
{
	int i = 0;
	if (a[0] == ' ')
	{
		for (int h = 0; h < strlen(a); h++)
			a[h] = a[h+ 1];
	}
	while (i < strlen(a))
	{
		if (a[i] == ' ')
		{
			for (int j = i; j < strlen(a); j++)
				a[j] = a[j + 1];
			i--;// tra lai y de xet nhieu khoang cach lien tiep nhau 
		}
		i++;
	}
}
bool create_folder(char ten_file[])
{
	if (_mkdir(ten_file) == 0)
		return true;
	return false;
}
bool check_empty_file(char ten_file[])
{
	ifstream filehkempty;
	filehkempty.open(ten_file, ios::binary);
	filehkempty.seekg(0, ios::end);
	if (filehkempty.tellg() == 0)
	{
		filehkempty.close();
		return true;
	}
	filehkempty.close();
	return false;
}
void func_khoi_tao(int x, int y, int  cl)// khoi tao nam hoc va hoc ki
{
	if (cl == y + 2)// thoat
		return;
	else if (cl == y)// tao nam hoc 
	{
		nam_hoc a,*arr;
		int sl=2;
		arr = new nam_hoc[sl];
		doc_ds_nam_hoc_tu_file(arr, sl);
		while (true)
		{
			nhap_nam_hoc(a, x, y);
			if (kt_nam_hoc(arr, sl, a) == true)
			{
				gotoxy(x + 10, y + 4);
				textcolor(12);
				cout << "Da Ton tai !";
				cin.ignore();
				continue;
			}
			else
				break;
		}
		ghi_1_nam_hoc_vao_file(a);
		create_folder(a.ten);
		delete[]arr;
	}
	else if(cl == y + 1)// tao hoc ki
	{
		int sl = 2, sl_hoc_ki=3;
		nam_hoc* nh = new nam_hoc[sl];
		doc_ds_nam_hoc_tu_file(nh, sl);
		xuat_nam_hoc(nh, sl, x, y);
		int cl_nam_hoc = click(x, y + 1, sl, 10) - y - 1;
		hoc_ki h, * arr_hoc_ki = new hoc_ki[sl_hoc_ki];
		doc_ds_hoc_ki_tu_file(arr_hoc_ki, nh[cl_nam_hoc], sl_hoc_ki);
		if (sl_hoc_ki == 3)
		{
			gotoxy(x + 8, y + 14);
			textcolor(12);
			cout << "Hoc Ki Da Day !";
			cin.ignore();
			return;
		}
		while (true)
		{
			nhap_hoc_ki(h, x, y, nh[cl_nam_hoc]);
			if (kt_hoc_ki(arr_hoc_ki, sl_hoc_ki, h) == true)
			{
				gotoxy(x + 8, y +14);
				textcolor(12);
				cout << "Hoc Ki Da Ton Tai !";
				cin.ignore();
				continue;
			}
			else
				break;
		}
		ghi_1_hoc_ki_vao_file(h, nh[cl_nam_hoc]);
		char* address = new char[50];
		strcpy(address, nh[cl_nam_hoc].ten);
		strcat(address, "/");
		strcat(address, h.ten);
		xoa_dau_cach(address);
		create_folder(address);
		delete[]nh;
		delete[]arr_hoc_ki;
		delete[]address;
	}
}

char* gender(int x, int y)
{
	char nam[10] = "Nam", nu[10] = "Nu";
	gotoxy(x, y);
	int color[2] = { 12,7 }, px = x, py = y, count = 1;
	while (true)
	{
		ToMau(x+10, y, nam, color[0]);
		ToMau(x + 25, y, nu, color[1]);
		char c = _getch();
		color[0]= color[1] = 7;
		if (c == 77)
		{
			if (count == 1)
				count++;
			else
				count--;
		}
		else if (c == 75)
		{
			if (count == 2)
				count--;
			else
				count++;
		};
		color[count - 1] = 12;
		if (c == 13)
		{
			if (count == 1)
				return nam;
			else
				return nu;
		} 
	}
}
void in_hoa_chu_dau(char a[])
{
	int n = strlen(a);
	if (97 <= a[0] && a[0] <= 122)
		a[0] = a[0] - 32;
	for (int i = 0; i < n; i++)
	{
		if(97 <= a[i] && a[i] <= 122)
			a[i] = a[i] - 32;
	}
}
char* ngay_hoc_trong_tuan(int x , int y)
{
	char t2[5] = "Mon", t3[5] = "Tue",  t4[5] = "Wed", t5[5] = "Thu", t6[5] = "Fri", t7[5] = "Sat";
	int color[6] = {12,7,7,7,7,7}, px = x, py = y, count = 1;
	while (true)
	{
		ToMau(x , y, t2 , color[0]);
		ToMau(x + 6, y, t3, color[1]);
		ToMau(x + 12, y, t4, color[2]);
		ToMau(x + 18, y, t5, color[3]);
		ToMau(x + 24, y, t6, color[4]);
		ToMau(x + 30, y, t7, color[5]);
		char c = _getch();
		color[count - 1] = 7;
		if (c == 75)
		{
			if (count == 1)
				count = 6;
			else
				count--;
		}
		else if (c == 77)
		{
			if (count == 6)
				count=1 ;
			else
				count++;
		};
		color[count - 1] = 12;
		if (c == 13)
		{
			switch (count)
			{
			case 1:
				return t2;
			case 2:
				return t3;
			case 3:
				return t4;
			case 4:
				return t5;
			case 5:
				return t6;
			case 6:
				return t7;
			}
		}
	}
}
char* ca_hoc_trong_ngay(int x, int y)
{
	char s1[20] = "S1(07:30)", s2[20] = "S2(09:30)", s3[15] = "S3(13:30)", s4[20] = "S4(15:30)";
	int color[4] = { 12,7,7,7}, px = x, py = y, count = 1;
	while (true)
	{
		ToMau(x, y, s1, color[0]);
		ToMau(x + 11, y, s2, color[1]);
		ToMau(x + 22, y, s3, color[2]);
		ToMau(x + 33, y, s4, color[3]);
		char c = _getch();
		color[count - 1] = 7;
		if (c == 75)
		{
			if (count == 1)
				count = 4;
			else
				count--;
		}
		else if (c == 77)
		{
			if (count == 4)
				count = 1;
			else
				count++;
		};
		color[count - 1] = 12;
		if (c == 13)
		{
			switch (count)
			{
			case 1:
				return s1;
			case 2:
				return s2;
			case 3:
				return s3;
			case 4:
				return s4;
			}
		}
	}
}

