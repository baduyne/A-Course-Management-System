#include"lib1.h"
using namespace std;
void init_ds_kh(ds_khoa_hoc & mh)
{
	mh.head = NULL;
}
node_khoa_hoc * tao_node_mh(khoa_hoc a)
{
	node_khoa_hoc* add = new node_khoa_hoc;
	add->data = a;
	add->next = NULL;
	return add;
}
void addfirst(ds_khoa_hoc& mh, node_khoa_hoc* add)
{
	if (mh.head == NULL)
		mh.head = add;
	else
	{
		add->next = mh.head;
		mh.head = add;
	}
}
void addlast_mh(ds_khoa_hoc& mh, node_khoa_hoc* add)
{
	if (mh.head == NULL)
		mh.head = add;
	else
	{
		node_khoa_hoc* t = mh.head;
		while (t->next != NULL)
		{
			t = t->next;
		}
		t->next = add;
	}
}
void nhap_hoc_ki(hoc_ki& h, int x, int y, nam_hoc a)
{
	system("cls");
	box(x, y, 15, 35);
	textcolor(7);
	gotoxy(x, y);
	textcolor(2);
	cout << "Nhap Ten Hoc Ki : ";
	textcolor(7);
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(h.ten, 20);
	y += 4;
	strcpy(h.nien_khoa, a.ten);
	gotoxy(x, y);
	textcolor(2);
	cout << "Niem Khoa : " << h.nien_khoa;
	y++;
	gotoxy(x, y);
	textcolor(2);
	cout << "Ngay Bat Dau : ";
	textcolor(7);
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(h.day_began, 20);
	y += 4;
	gotoxy(x, y);
	textcolor(2);
	cout << "Ngay Ket Thuc ";
	textcolor(7);
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(h.day_end, 20);
}
bool kt_hoc_ki(hoc_ki* arr, int sl, hoc_ki a)
{
	for (int i = 0; i < sl; i++)
	{
		if (strcmp(arr[i].ten, a.ten) == 0)
			return true;
	}
	return false;
}
void nhap_khoa_hoc(khoa_hoc& a, int x , int y)
{
	int px = x, py = y;
	system("cls");
	box(x, y, 20, 45);
	textcolor(2);
	gotoxy(x, y);
	cout << "Ma Khoa :";
	textcolor(7);
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(a.ma_khoa, 20);
	y+=4;
	textcolor(2);
	gotoxy(x, y);
	cout << "Ten Khoa Hoc : ";
	textcolor(7);
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(a.ten_khoa_hoc, 50);
	y+=4;
	gotoxy(x, y);
	textcolor(2);
	cout << "Ten Lop Hoc: ";
	textcolor(7);
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(a.ten_lop_hoc, 50);
	y+=4;
	gotoxy(x, y);
	textcolor(2);
	cout << "Giao Vien : ";
	textcolor(7);
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(a.ten_giao_vien, 50);
	gotoxy(x + 1, y + 4);
	textcolor(3);
	cout << "->Press Enter To Continue";
	a.so_luong = 50;
	char c = _getch();
	if (c == 13)
	{
		x=px;
		y = py;
		system("cls");
		box(x, y, 10, 49);
		textcolor(2);
		gotoxy(x, y);
		cout << "So Tin Chi : ";
		textcolor(7);
		o(x, y + 1, 25);
		gotoxy(x + 1, y + 2);
		cin >> a.so_tin_chi;
		cin.ignore();
		y+=4;
		gotoxy(x, y);
		textcolor(2);
		cout << "Ngay Hoc Trong Tuan : ";
		strcpy(a.ngay, ngay_hoc_trong_tuan(x, y+1));
		y+=2;
		textcolor(2);
		gotoxy(x, y);
		cout << "Ca Hoc : ";
		strcpy(a.ca_hoc, ca_hoc_trong_ngay(x, y + 1));
	}
}
void init_ds_sinh_vien(ds_sinh_vien & sv)
{
	sv.head = NULL;
}
node_sv* tao_node_sv(sinh_vien a)
{
	node_sv* add = new node_sv;
	add->data = a;
	add->next = NULL;
	return add;
}
void addfirst_sv(ds_sinh_vien& mh, node_sv * add)
{
	if (mh.head == NULL)
		mh.head = add;
	else
	{
		add->next = mh.head;
		mh.head = add;
	}
}
void addlast_sv(ds_sinh_vien& mh, node_sv* add)
{
	if (mh.head == NULL)
		mh.head = add;
	else
	{
		node_sv* t = mh.head;
		while (t->next != NULL)
		{
			t = t->next;
		}
		t->next = add;
	}
}

void remove_node_sv(ds_sinh_vien& l, int pos)
{
	int n =so_node_ds_sinh_vien(l);
	if (pos<=0|| pos>n)
		return;
	if (pos == 1)
	{
		node_sv* temp = l.head;
		l.head = l.head->next;
		temp = NULL;
		return;
	}
	else if (pos == n)
	{
		node_sv* temp = l.head;
		while (temp->next->next!= NULL)
		{
			temp = temp->next;
		}
		temp->next = NULL;
	}
	else
	{
		node_sv* truoc = l.head;
		node_sv* sau = l.head;
		for (int i = 1; i < pos; i++)
		{
			truoc = sau;
			sau = sau->next;
		}
		truoc->next= sau->next;
	}
}
void nhap_sinh_vien(sinh_vien& a, int x ,int y)
{
	system("cls");
	box(x, y, 19, 40);
	gotoxy(x, y);
	cout << "ID:";
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(a.ma_sinh_vien, 20);
	y+=4;
	gotoxy(x, y);
	cout << "Your Name : ";
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(a.ho_ten, 50);
	y+=4;
	gotoxy(x, y);
	cout << "Gender : ";
	strcpy(a.gioi_tinh, gender(x, y));
	y+=2;
	gotoxy(x, y);
	cout << "Birthday : ";
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(a.ngay_sinh, 20);
	y+=4;
	gotoxy(x, y);
	cout << "Number CMND : ";
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(a.cmnd, 20);
}
//void swap_sv(sinh_vien& a, sinh_vien& b)
//{
//	sinh_vien t = a;
//	a = b;
//	b = t;
//}
//void sap_xep_sv(ds_sinh_vien& l)
//{
//	for()
//}

bool nhap_sinh_vien_tu_file(ds_sinh_vien & l, char ten_file[])
{
	sinh_vien a;
	make_address(ten_file);
	ifstream filesv;
	filesv.open(ten_file);
	if (!filesv.is_open())
		return false;
	// bo qua hang dau tien
	char *ar=new char [200];
	filesv.getline(ar, 200, '\n');
	while (!filesv.eof())
	{
		char r[50];
		filesv.getline(r, 50, ',');
		if (strcmp(r,"") == 0) // k doc khoang  trang cuoi file
			break;
		filesv.getline(a.ma_sinh_vien, 10, ',');
		filesv.getline(a.ho_ten, 50, ',');
		filesv.getline(a.gioi_tinh, 10, ',');
		filesv.getline(a.ngay_sinh, 20, ',');
		filesv.getline(a.cmnd, 20, '\n');
		node_sv* add = tao_node_sv(a);
		addlast_sv(l, add);
	}
	filesv.close();
	delete[]ar;
	return true;
}

void nhap_ds_sinh_vien(ds_sinh_vien &l,int x , int y)
{
	int n;
	cout << "Nhap So Luong Sinh Vien ";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		system("cls");
		sinh_vien a;
		nhap_sinh_vien(a, 0, 0);
		node_sv* add = tao_node_sv(a);
		addlast_sv(l, add);
	}
}
void xuat_ds_sinh_vien_lop_hoc(ds_sinh_vien l, int x ,int y)
{
	x = 15;
	system("cls");
	int so_node_sv = so_node_ds_sinh_vien(l);
	box(x, y, so_node_sv+4, 88);
	gotoxy(x-1, y);
	cout << "_____________________________________________________________________________";
	y++;
	gotoxy(x-1, y);
	cout << "|Ma so" << setw(15) << "|Ho Va Ten" << setw(23) << "|Gioi Tinh" << setw(12) << "|Ngay sinh" << setw(12) << "|So CMND" << "        |";
	y++;
	gotoxy(x-1, y);
	cout << "|__________|______________________|___________|_____________|_______________|";
	y++;
	while (l.head != NULL)
	{
		char c[2] ="|";
		gotoxy(x, y);
		ToMau(x-1, y,c, 7);
		ToMau(x, y, l.head->data.ma_sinh_vien, 7);
		ToMau(x +10, y, c, 7);
		ToMau(x + 11, y, l.head->data.ho_ten, 7);
		ToMau(x + 33, y, c, 7);
		ToMau(x + 34, y, l.head->data.gioi_tinh, 7);
		ToMau(x + 45, y, c, 7);
		ToMau(x + 46, y, l.head->data.ngay_sinh, 7);
		ToMau(x + 59, y, c, 7);
		ToMau(x + 60, y, l.head->data.cmnd, 7);
		ToMau(x + 75, y, c, 7);
		l.head = l.head->next;
		y++;
	}
	gotoxy(x - 1, y);
	cout << "|__________|______________________|___________|_____________|_______________|";
}
void xuat_ds_sinh_vien_khoa_hoc(ds_sinh_vien l, int x, int y)
{
	x = 15;
	system("cls");
	int so_node_sv = so_node_ds_sinh_vien(l);
	box(x, y, so_node_sv+4, 110);
	gotoxy(x - 1, y);
	cout << "________________________________________________________________________________________________";
	y++;
	gotoxy(x-1, y);
	cout << "|Ma so" << setw(15) << "|Ho Va Ten" << setw(24) << "|Gioi Tinh" << setw(12) << "|Ngay Sinh" << setw(12) << "|So CMND" << setw(16) << "|Diem CK" <<setw(11)<< "|Diem TB |";
	y++;
	gotoxy(x - 1, y);
	cout << "|__________|_______________________|___________|_____________|_______________|________|________|";
	y++;
	while (l.head != NULL)
	{
		char c[2] = "|";
		ToMau(x - 1, y, c, 7);
		ToMau(x, y, l.head->data.ma_sinh_vien, 7);
		ToMau(x +10, y, c, 7);
		ToMau(x + 11, y, l.head->data.ho_ten, 7);
		ToMau(x +34, y, c, 7);
		ToMau(x + 35, y, l.head->data.gioi_tinh, 7);
		ToMau(x +46, y, c, 7);
		ToMau(x + 47, y, l.head->data.ngay_sinh, 7);
		ToMau(x +60, y, c, 7);
		ToMau(x + 61, y, l.head->data.cmnd, 7);
		ToMau(x+76, y, c, 7);
		gotoxy(x + 79, y);
		cout << l.head->data.diemck;
		ToMau(x +85, y, c, 7);
		gotoxy(x + 88, y);
		cout << l.head->data.dtb;
		ToMau(x +94, y, c, 7);
		l.head = l.head->next;
		y++;
	}
	gotoxy(x - 1, y);
	cout << "|__________|_______________________|___________|_____________|_______________|________|________|";
}
void ghi_1_sinh_vien_vao_khoa_hoc(nam_hoc a, hoc_ki b, khoa_hoc c, sinh_vien infor, int pos)
{
	char *address=new char [100];
	strcpy(address, a.ten);
	strcat(address,"/");
	strcat(address, b.ten);
	strcat(address, "/");
	strcat(address, c.ten_khoa_hoc);
	strcat(address, c.ten_lop_hoc);
	make_link(address);
	xoa_dau_cach(address);
	ofstream filesv;
	filesv.open(address,ios::app);
	if (check_empty_file(address))
		filesv << "STT" << ',' << "Ma So" << ',' << "Ho va ten" << ',' << "Gioi tinh" << ',' << "Ngay sinh" << ',' << "So CMND" << ','<<"Diem QT" <<',' << "Diem GK" << ',' << "Diem CK" << ',' << "Diem TB" << endl;
	filesv << pos << ',' << infor.ma_sinh_vien << ',' << infor.ho_ten << ',' << infor.gioi_tinh << ',' << infor.ngay_sinh << ',' << infor.cmnd <<","<<infor.dqt<<","<<infor.diemgk << "," << infor.diemck << "," << infor.dtb << endl;
	filesv.close();
	delete[]address;
}
void tao_file_ds_sv_khoa_hoc_rong(nam_hoc a, hoc_ki b, khoa_hoc c)
{
	char* address = new char[100];
	strcpy(address, a.ten);
	strcat(address, "/");
	strcat(address, b.ten);
	strcat(address, "/");
	strcat(address, c.ten_khoa_hoc);
	strcat(address, c.ten_lop_hoc);
	make_link(address);
	xoa_dau_cach(address);
	ofstream filesv;
	filesv.open(address);
	filesv << "STT" << ',' << "Ma So" << ',' << "Ho va ten" << ',' << "Gioi tinh" << ',' << "Ngay sinh" << ',' << "So CMND" << ',' << "Diem QT" << ',' << "Diem GK" << ',' << "Diem CK" << ',' << "Diem TB" << endl;
	filesv.close();
	delete[]address;
}
void ghi_ds_sinh_vien_vao_khoa_hoc(nam_hoc a, hoc_ki b, khoa_hoc c, ds_sinh_vien infor)
{
	char *address=new char [70];
	int i = 1;
	strcpy(address, a.ten);
	strcat(address, "/");
	strcat(address, b.ten);
	strcat(address, "/");
	strcat(address, c.ten_khoa_hoc);
	strcat(address, c.ten_lop_hoc);
	xoa_dau_cach(address);
	make_link(address);
	ofstream filesv;
	filesv.open(address);
	if (check_empty_file(address))
		filesv << "STT" << ',' << "Ma So" << ',' << "Ho va ten" << ',' << "Gioi tinh" << ',' << "Ngay sinh" << ',' << "So CMND" << ','<<"Diem QT" <<',' << "Diem GK" << ',' << "Diem CK" << ',' << "Diem TB" << endl;
	while (infor.head != NULL)
	{
		filesv << i << ',' << infor.head->data.ma_sinh_vien << ',' << infor.head->data.ho_ten << ',' << infor.head->data.gioi_tinh << ',' << infor.head->data.ngay_sinh << ',' << infor.head->data.cmnd << ','<< infor.head->data.dqt<<','<< infor.head->data.diemgk << ',' << infor.head->data.diemck << ',' << infor.head->data.dtb << endl;
		infor.head = infor.head->next;
		i++;
	}
	filesv.close();
	delete[]address;
}
void ghi_1_sinh_vien_vao_lop_hoc(nam_hoc a, lop_hoc  c, sinh_vien infor, int pos)
{
	char *address=new char[70];
	strcpy(address, a.ten);
	strcat(address, "/");
	strcat(address, c.ten);
	xoa_dau_cach(address);
	make_link(address);
	ofstream filesv;
	filesv.open(address, ios::app);
	filesv << pos << ',' << infor.ma_sinh_vien << ',' << infor.ho_ten << ',' << infor.gioi_tinh << ',' << infor.ngay_sinh << ',' << infor.cmnd << endl;
	filesv.close();
	delete[]address;
}
void tao_file_ds_sinh_vien_lop_hoc_rong(nam_hoc a, lop_hoc c)
{
	char* address = new char[70];
	strcpy(address, a.ten);
	strcat(address, "/");
	strcat(address, c.ten);
	xoa_dau_cach(address);
	make_link(address);
	ofstream filesv;
	filesv.open(address);
	filesv << "STT" << ',' << "Ma So" << ',' << "Ho va ten" << ',' << "Gioi tinh" << ',' << "Ngay sinh" << ',' << "So CMND" << endl;
	filesv.close();

}
void ghi_ds_sinh_vien_vao_lop_hoc(nam_hoc a,lop_hoc c, ds_sinh_vien infor)
{
	int i = 1;
	char *address=new char[70];
	strcpy(address, a.ten);
	strcat(address, "/");
	strcat(address, c.ten);
	xoa_dau_cach(address);
	make_link(address);
	ofstream filesv;
	filesv.open(address);
	if (check_empty_file(address))
		filesv <<"STT"<<',' << "Ma So" << ',' << "Ho va ten" << ',' << "Gioi tinh" << ',' << "Ngay sinh" << ',' << "So CMND";
	while (infor.head != NULL)
	{
		filesv << endl<<i<<','<< infor.head->data.ma_sinh_vien << ',' << infor.head->data.ho_ten << ',' << infor.head->data.gioi_tinh << ',' << infor.head->data.ngay_sinh << ',' << infor.head->data.cmnd;
		infor.head = infor.head->next;
		i++;
	}
	filesv.close();
	delete[]address;
}

void nhap_lop_hoc(lop_hoc& a, int x, int y)
{
	box(x, y, 15, 50);
	gotoxy(x, y);

	cout << "Ten Lop :"; 
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(a.ten, 30);
	y += 4;
	gotoxy(x, y);
	cout << "Khoa : ";
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(a.khoa, 50);
	y+=4;
	gotoxy(x, y);
	cout << "So Luong To Da: ";
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin >> a.so_luong;
	cin.ignore();
	y += 4;
	gotoxy(x, y);
	cout << "Khoa Hoc (K20,K21): ";
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin >> a.k;
}
void cap_phat_them_lop_hoc(lop_hoc*& a, int& size)
{
	lop_hoc* temp = new lop_hoc[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = a[i];
	}
	delete[]a;
	int size_new = size + 3;
	a = new lop_hoc[size_new];
	for (int i = 0; i < size; i++)
	{
		a[i] = temp[i];
	}
	delete[]temp;
	size = size_new;
}
void doc_ds_lop_hoc_tu_file(lop_hoc *&a, nam_hoc b,int & sl)
{
	int i = 0;
	char *address=new char [50];
	strcpy(address, b.ten);
	strcat(address, "/lop_hoc");
	xoa_dau_cach(address);
	make_link(address);
	ifstream filein;
	filein.open(address);
	if (check_empty_file(address))
	{
		sl = i;
		delete[]address;
		return;
	 }
	 else
	 {
		 char r[100];
		 filein.getline(r, 100,'\n');// bo di dong dau tien
		 while (!filein.eof())
		 {
			 if (i == sl - 1)
				 cap_phat_them_lop_hoc(a, sl);
			 filein.getline(r, 10, ',');
			 if (strcmp(r, "") == 0)
				 break;
			 filein.getline(a[i].ten, 30, ',');
			 filein.getline(a[i].khoa, 30, ',');
			 filein >> a[i].so_luong;
			 filein.ignore();
			 filein.getline(a[i].k, 30, '\n');
			 i++;
		 }
		 filein.close();
		 sl = i;
	 }
	delete[]address;
}
void xuat_lop_hoc(lop_hoc* a,int sl, int  x, int y)
{
	int py = y;
	x = 17;
	box(x, y, sl + 2, 80);
	textcolor(2);
	int i = 0;
	gotoxy(x +2, y);
	cout << "Lop Hoc" <<setw(13)<< "Khoa" << setw(28) << "So luong" << setw(15) << "Khoa hoc";
	y++;
	while (i < sl)
	{
			ToMau(x+2, y, a[i].ten, 2);
			ToMau(x+18, y, a[i].khoa, 2);
			gotoxy(x+42, y);
			textcolor(2);
			cout << a[i].so_luong;
			ToMau(x+57, y, a[i].k, 2);
			y++;
			i++;
	}
	gotoxy(x-3, py+sl+2);
	cout << "<<BACK";
	char c=_getch();
}
void ghi_1_lop_hoc_vao_file(lop_hoc a, nam_hoc b, int pos)
{
	if (pos == 0)
		pos++;
	char *address=new char[40];
	strcpy(address, b.ten);
	strcat(address, "/lop_hoc");
	xoa_dau_cach(address);
	make_link(address);
	ofstream filein;
	filein.open(address,ios::app);
	if (check_empty_file(address))
		filein << "STT" << ',' << "Lop hoc" << ',' << "Khoa" << ',' << "So luong" << ',' << "Khoa Hoc" << endl;
	filein << pos << ',' << a.ten << ',' << a.khoa << ',' << a.so_luong << ',' << a.k << endl;
	filein.close();
	delete[]address;
}
void ghi_1_hoc_ki_vao_file(hoc_ki h, nam_hoc a)
{
	char *address=new char[30];
	strcpy(address, a.ten);
	strcat(address, "/hoc_ki");
	xoa_dau_cach(address);
	make_link(address);
	ofstream filehk;
	filehk.open(address, ios::app);
	if(check_empty_file(address))
	{
		filehk << "Ten hoc ki" << ',' << "Niem khoa" << ',' << "Ngay bat dau" << ',' << "Ngay ket thuc" << endl;
	}
	filehk << h.ten << ',' << h.nien_khoa << ',' << h.day_began << ',' << h.day_end << endl;
	filehk.close();
	delete[]address;
}
void doc_ds_hoc_ki_tu_file(hoc_ki *&arr,nam_hoc a, int& sl)
{
	int i = 0;
	char *address=new char[50];
	strcpy(address, a.ten);
	strcat(address, "/hoc_ki");
	xoa_dau_cach(address);
	make_link(address);
	ifstream filehkread;
	filehkread.open(address);
	filehkread.seekg(49, ios_base::beg);
	while (!filehkread.eof())
	{
		filehkread.getline(arr[i].ten,50,',');
		if (strcmp(arr[i].ten,"") == 0)
			break;
		filehkread.getline(arr[i].nien_khoa, 50, ',');
		filehkread.getline(arr[i].day_began, 50, ',');
		filehkread.getline(arr[i].day_end, 50, '\n');
		i++;
	}
	filehkread.close();
	 sl=i;
	 delete[]address;
}
void xuat_hoc_ki(hoc_ki h, int x , int y )
{
	cout<< h.ten << ',' << h.nien_khoa << /*',' << h.day_began << ',' <<*/ h.day_end;
}
void xuat_ds_hoc_ki(hoc_ki* a,int n, int x, int y)
{
	system("cls");
	box(x, y, n, 24);
	for (int i = 0; i < n; i++)
	{
		cout <<left<< a[i].ten << setw(10)<<right<< a[i].nien_khoa << endl;
	}
}
void ghi_1_khoa_hoc(hoc_ki h, khoa_hoc a, nam_hoc b, int pos)
{
	char *address=new char[100];
	strcpy(address, b.ten);
	strcat(address, "/");
	strcat(address, h.ten);
	strcat(address, "/khoa_hoc");
	xoa_dau_cach(address);
	xoa_dau_cach(address);
	make_link(address);
	ofstream filemh;
	filemh.open(address, ios::app);
	if (check_empty_file(address))
	{
		filemh << "STT" << ',' << "Ma khoa hoc" << ',' << "Khoa hoc" << ',' << "Lop hoc" << ',' << "Giao vien" << ',' << "So tin chi" << ',' << "So luong" << ',' << "Ngay hoc trong tuan" << ',' << "Ca hoc" << endl;
	}
	filemh << pos << ',' << a.ma_khoa << ',' << a.ten_khoa_hoc << ',' << a.ten_lop_hoc << ',' << a.ten_giao_vien << ',' << a.so_tin_chi << ',' << a.so_luong << ',' << a.ngay << ',' << a.ca_hoc << endl;
	filemh.close();
	delete[]address;
}
void ghi_ds_khoa_hoc(hoc_ki h, ds_khoa_hoc a, nam_hoc b)
{
	int i = 1;
	char *address=new char[100];
	strcpy(address, b.ten);
	strcat(address, "/");
	strcat(address, h.ten);
	strcat(address, "/khoa_hoc");
	xoa_dau_cach(address);
	make_link(address);
	ofstream filemh;
	filemh.open(address);
	if (check_empty_file(address))
	{
		filemh << "STT" << ',' << "Ma khoa hoc" << ',' << "Ten khoa hoc" << ',' << "Ten lop hoc" << ',' << "Ten giao vien" << ',' << "So tin chi" << ',' << "So luong" << ',' << "Ngay hoc trong tuan" << ',' << "Ca hoc" << endl;
	}
	while (a.head != NULL)
	{
		filemh << i << ',' << a.head->data.ma_khoa << ',' << a.head->data.ten_khoa_hoc << ',' << a.head->data.ten_lop_hoc << ',' << a.head->data.ten_giao_vien << ',' << a.head->data.so_tin_chi << ',' << a.head->data.so_luong << ',' << a.head->data.ngay << ',' << a.head->data.ca_hoc << endl;
		a.head = a.head->next;
		i++;
	}
	filemh.close();
	delete[]address;
}
void doc_ds_khoa_hoc_tu_file(hoc_ki h,nam_hoc b , ds_khoa_hoc &l)
{
	char *address=new char [100];
	strcpy(address, b.ten);
	strcat(address, "/");
	strcat(address, h.ten);
	strcat(address, "/");
	strcat(address, "khoa_hoc");
	xoa_dau_cach(address);
	xoa_dau_cach(address);
	make_link(address);
	khoa_hoc a;
	ifstream filemhread;
	filemhread.open(address);
	if (!filemhread.is_open())
	{
		filemhread.close();
		return;
	}
	char c[200];// bo qua dong dau tien
	filemhread.getline(c, 200,'\n');
	while (!filemhread.eof())
	{
		filemhread.getline(c,5,',');
		if (strcmp(c,"") == 0)
			break;
		filemhread.getline(a.ma_khoa, 50, ',');
		filemhread.getline(a.ten_khoa_hoc, 50, ',');
		filemhread.getline(a.ten_lop_hoc, 50, ',');
		filemhread.getline(a.ten_giao_vien, 50, ',');
		filemhread >> a.so_tin_chi;
		filemhread.ignore();
		filemhread >> a.so_luong;
		filemhread.ignore();
		filemhread.getline(a.ngay, 50, ',');
		filemhread.getline(a.ca_hoc, 50, '\n');
		node_khoa_hoc* add = tao_node_mh(a);
		addlast_mh(l, add);
	}
	filemhread.close();
	delete[]address;
}
int so_node_khoa_hoc(ds_khoa_hoc l)
{
	int pos = 0;
	while (l.head != NULL)
	{
		l.head = l.head->next;
		pos++;
	}
	return pos;
}
khoa_hoc tim_khoa_hoc(ds_khoa_hoc l, int vt)
{
	for (int i = 1;i<vt; i++)
	{
		l.head = l.head->next;
   }
	return l.head->data;
}
node_sv* tim_node_sinh_vien(ds_sinh_vien l, int vt)
{
	for (int i = 1; i <=vt; i++)
	{
		l.head = l.head->next;
	}
	return l.head;
}
void xuat_ds_khoa_hoc(int x, int y, ds_khoa_hoc l)
{
	int  py = y;
	x = 12;
	system("cls");
	box(x, y, so_node_khoa_hoc(l), 110);
	gotoxy(x, y);
	textcolor(2);
	cout << "Ma Khoa" << setw(11) << "Khoa Hoc" << setw(20) << "Lop Hoc" << setw(11) << "Giao Vien" << setw(17) << "So Luong" << setw(9) << "Tin Chi" << setw(10) << "Ngay Hoc" << setw(8) << "Ca Hoc";
	y++;
	while (l.head != NULL)
	{
		ToMau(x, y, l.head->data.ma_khoa, 7);
		ToMau(x + 10, y, l.head->data.ten_khoa_hoc, 7);
		ToMau(x + 31, y, l.head->data.ten_lop_hoc, 7);
		ToMau(x + 40, y, l.head->data.ten_giao_vien, 7);
		gotoxy(x + 58, y);
		textcolor(7);
		cout << l.head->data.so_luong;
		gotoxy(x + 69, y);
		cout << l.head->data.so_tin_chi;
		ToMau(x + 78, y, l.head->data.ngay, 7);
		ToMau(x + 87, y, l.head->data.ca_hoc, 7);
		y++;
		l.head = l.head->next;
	}
	cin.ignore();
}
void remove_khoa_hoc(ds_khoa_hoc& kh, int pos)
{
	int n = so_node_khoa_hoc(kh);
	if (pos < 0 || pos > n)
		return;
	if (pos == 1)
	{
		node_khoa_hoc* temp = kh.head;
		kh.head = kh.head->next;
		temp = NULL;
	}
	else if (pos == n)
	{
		node_khoa_hoc* temp = kh.head;
		while (temp->next->next!= NULL)
		{
			temp = temp->next;
		}
		temp->next = NULL;
	}
	else
	{
		node_khoa_hoc* truoc = kh.head;
		node_khoa_hoc* sau = kh.head;
		for (int i = 1; i < pos; i++)
		{
			truoc = sau;
			sau = sau->next;
		}
		truoc->next = sau->next;
	}
}

void nhap_nam_hoc(nam_hoc& nh,int x , int y)
{
	system("cls");
	box(x, y, 5, 40);
	textcolor(7);
	gotoxy(x , y);
	cout << "Niem Khoa : ";
	y += 1;
	o(x, y, 15);
	gotoxy(x+1, y + 1);
	cin.getline(nh.ten,50);
}
bool kt_nam_hoc(nam_hoc* a, int size, nam_hoc b)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(a[i].ten, b.ten) == 0)
			return true;
	}
	return false;
}
void ghi_1_nam_hoc_vao_file(nam_hoc a)
{
	char ten_file[30] = "Danh_sach_cac_nam_hoc.csv";
	ofstream filenh;
	filenh.open(ten_file, ios::app);
	if (check_empty_file(ten_file) == true)
		filenh << "Nam hoc" << endl;
	filenh << a.ten << endl;
	filenh.close();
}
void cap_phat_them_nam_hoc(nam_hoc *& a, int& sz)
{
	nam_hoc * temp = new nam_hoc[sz];
	for (int i = 0; i < sz; i++)
	{
		temp[i] = a[i];
	}
	delete[]a;
	int size_new = sz + 3;
	a = new nam_hoc[size_new];
	for (int j = 0; j < sz; j++)
	{
		a[j] = temp[j];
	}
	sz = size_new;
}
void doc_ds_nam_hoc_tu_file(nam_hoc*& arr, int &size)
{
	int i = 0;
	ifstream fileoutnh;
	fileoutnh.open("Danh_sach_cac_nam_hoc.csv");
	char* r = new char[40];
	fileoutnh.getline(r, 40, '\n');
	while (!fileoutnh.eof())
	{
		if (i == size - 1)
			cap_phat_them_nam_hoc(arr, size);
		fileoutnh.getline(arr[i].ten, 50, '\n');
		if (strcmp(arr[i].ten, "") == 0)
			break;
		i++;
	}
	fileoutnh.close();
	size = i;
	delete[]r;
}


int  so_node_ds_sinh_vien(ds_sinh_vien l)
{
	int vt=0;
	while (l.head != NULL)
	{
		++vt;
		l.head = l.head->next;
	}
	return vt;
}
void doc_ds_sinh_vien_khoa_hoc(nam_hoc a, hoc_ki b, khoa_hoc c, ds_sinh_vien& l)
{
	char* address = new char[100];
	strcpy(address, a.ten);
	strcat(address, "/");
	strcat(address, b.ten);
	strcat(address, "/");
	strcat(address, c.ten_khoa_hoc);
	strcat(address, c.ten_lop_hoc);
	make_link(address);
	xoa_dau_cach(address);
	ifstream filesv;
	filesv.open(address);
	if (!filesv.is_open())
	{
		delete[]address;
		return;
	}
	char r[100] ;
	filesv.getline(r, 100, '\n');// bo qua dong dau tien
	while (!filesv.eof())
	{
		sinh_vien sv;
		filesv.getline(r, 50, ',');
		filesv.getline(sv.ma_sinh_vien, 50, ',');
		if (strcmp(sv.ma_sinh_vien, "") == 0) // k doc khoang  trang cuoi file
			break;
		filesv.getline(sv.ho_ten, 50, ',');
		filesv.getline(sv.gioi_tinh, 50, ',');
		filesv.getline(sv.ngay_sinh, 50, ',');
		filesv.getline(sv.cmnd, 50, ',');
		filesv >> sv.dqt;
		filesv.ignore();
		filesv>>sv.diemgk;
		filesv.ignore();
		filesv >> sv.diemck;
		filesv.ignore();
		filesv >> sv.dtb;
		filesv.ignore();
		node_sv* add = tao_node_sv(sv);
		addlast_sv(l, add);
	}
	filesv.close();
	delete[]address;
}
void doc_ds_sinh_vien_lop_hoc(nam_hoc a, lop_hoc  c, ds_sinh_vien& l)
{
	char *address= new char [100];
	strcpy(address, a.ten);
	strcat(address, "/");
	strcat(address, c.ten);
	xoa_dau_cach(address);
	make_link(address);
	ifstream filesv;
	filesv.open(address);
	if (!filesv.is_open())
	{
		delete[]address;
		return;
	}
	char r[100];
	filesv.getline(r, 100, '\n');// bo qua dong dau tien
	while (!filesv.eof())
	{
		sinh_vien sv;
		filesv.getline(r, 50, ',');
		if (strcmp(r, "") == 0) // k doc khoang  trang cuoi file
			break;
		filesv.getline(sv.ma_sinh_vien, 50, ',');
		filesv.getline(sv.ho_ten, 50, ',');
		filesv.getline(sv.gioi_tinh, 50, ',');
		filesv.getline(sv.ngay_sinh, 50, ',');
		filesv.getline(sv.cmnd, 50, '\n');
		node_sv* add = tao_node_sv(sv);
		addlast_sv(l, add);
	}
	filesv.close();
	delete[]address;
}

void xuat_nam_hoc(nam_hoc*& a, int sl, int x , int y )
{
	system("cls");
	box(x, y, sl + 1, 25);
	textcolor(2);
	gotoxy(x - 1, y);
	cout << "Niem Khoa :";
	y++;
	for (int i = 0; i < sl; i++)
	{
		ToMau(x, y, a[i].ten, 2);
		y++;
	}
}
bool kt_trung_ca_khoa_hoc(ds_khoa_hoc l, khoa_hoc a)
{
	while (l.head != NULL)
	{
		if (strcmp(l.head->data.ten_lop_hoc, a.ten_lop_hoc) == 0 &&strcmp(l.head->data.ca_hoc, a.ca_hoc) == 0 && strcmp(l.head->data.ngay, a.ngay) == 0)
			return true;
		l.head = l.head->next;
	}
	return false;
}
bool doc_file_diem(ds_sinh_vien& l, char tf[])
{
	sinh_vien a;
	ifstream file_diem;
	file_diem.open(tf);
	if (!file_diem.is_open())
		return false;
	char* r = new char[100];
	file_diem.getline(r, 100, '\n');// doc hang dau tien
	while (!file_diem.eof())
	{
		file_diem.getline(r, 50, ',');
		file_diem.getline(a.ma_sinh_vien, 50, ',');
		if (strcmp(a.ma_sinh_vien, "") == 0)
			break;
		file_diem.getline(a.ho_ten, 50, ',');
		file_diem >> a.dqt;
		file_diem.ignore();
		file_diem >> a.diemgk;
		file_diem.ignore();
		file_diem >> a.diemck;
		file_diem.ignore();
		file_diem >> a.dtb;
		file_diem.ignore();
		node_sv *add =  tao_node_sv(a);
		addlast_sv(l, add);
	}
	file_diem.close();
	delete[]r;
	return true;
}
void tao_file_nhap_diem(nam_hoc a , hoc_ki b ,khoa_hoc c,  ds_sinh_vien l)
{
	char* address = new char[300];
	int i = 1;
	strcpy(address, a.ten);
	strcat(address, "/");
	strcat(address, b.ten);
	strcat(address, "/Bang_diem_");
	strcat(address, c.ten_khoa_hoc);
	strcat(address, c.ten_lop_hoc);
	make_link(address);
	xoa_dau_cach(address);
	ofstream file_d;
	file_d.open(address);
	file_d << "STT"<<',' << "Ma so" << ',' << "Ho Va Ten" << ',' << "Diem qua trinh" << ',' << "Diem Giua Ki" << ',' << "Diem Cuoi Ki" << ',' << "Diem Trung Binh" << endl;
	while (l.head != NULL)
	{
		file_d << i << ',' << l.head->data.ma_sinh_vien << ',' << l.head->data.ho_ten << ',' << l.head->data.dqt << ',' << l.head->data.diemgk << ',' << l.head->data.diemck << ',' << l.head->data.dtb << endl;
		i++;
		l.head = l.head->next;
	}
	file_d.close();
	delete[]address;
}
void kt_khoa_hoc_thuoc_lop_hoc(nam_hoc a, hoc_ki b, lop_hoc c, ds_khoa_hoc& l, int x, int y)
{
	ds_khoa_hoc ds_kh;
	init_ds_kh(ds_kh);
	doc_ds_khoa_hoc_tu_file(b, a, ds_kh);
	if (so_node_khoa_hoc(ds_kh) == 0)
	{
		system("cls");
		box(x, y, 3, 30);
		textcolor(4);
		gotoxy(x, y);
		cout << "NO COURSE";
		cin.ignore();
		return;
	}
	node_khoa_hoc* temp = ds_kh.head;
	while (temp != NULL)
	{
		khoa_hoc tam = temp->data;
		if (strcmp(temp->data.ten_lop_hoc, c.ten) == 0)
		{
			node_khoa_hoc* add = tao_node_mh(tam);
			addlast_mh(l, add);
		}
		temp = temp->next;
	}
}
void dk_khoa_hoc(int x, int y, tai_khoan temp)
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
	hoc_ki* hk = new hoc_ki[3];
	doc_ds_hoc_ki_tu_file(hk, nh[cl_nam_hoc], sl_hk);
	if (sl_hk == 0)
	{
		system("cls");
		box(x, y, 2, 30);
		gotoxy(x, y);
		textcolor(12);
		cout << "NO SEMESTER";
		cin.ignore();
		return;
	}
	system("cls");
	nd_hoc_ki(hk, sl_hk, x, y);
	int cl_hoc_ki = click(x, y, sl_hk, 10) - y;
	ds_khoa_hoc ds_kh;
	init_ds_kh(ds_kh);
	doc_ds_khoa_hoc_tu_file(hk[cl_hoc_ki], nh[cl_nam_hoc], ds_kh);
	int sl_kh = so_node_khoa_hoc(ds_kh);
	if (sl_kh == 0)
	{
		system("cls");
		box(x, y, sl, 30);
		textcolor(4);
		gotoxy(x, y);
		cout << "NO COURSE";
		cin.ignore();
		return;
	}
	xuat_ds_khoa_hoc(x, y, ds_kh);
	int cl_khoa_hoc = click(12, y + 1, sl_kh, 97) - y;// -y de no bat dau tu 1 
	khoa_hoc kh = tim_khoa_hoc(ds_kh, cl_khoa_hoc);
	ds_sinh_vien ds_sv;
	init_ds_sinh_vien(ds_sv);
	system("cls");
	doc_ds_sinh_vien_khoa_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, ds_sv);
	if (check_ds_trong_lop(temp, nh[cl_nam_hoc], hk[cl_hoc_ki], kh) == true)
	{
		system("cls");
		box(x, y, sl, 30);
		textcolor(4);
		gotoxy(x, y);
		cout << "ALREADY EXIST";
		cin.ignore();
		return;
	}
	sinh_vien a;
	strcpy(a.ho_ten, temp.ho_ten);
	strcpy(a.ngay_sinh, temp.ngay_sinh);
	strcpy(a.ma_sinh_vien, temp.ms);
	strcpy(a.gioi_tinh, temp.gioitinh);
	strcpy(a.cmnd, temp.cccd);
	ghi_1_sinh_vien_vao_khoa_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, a, so_node_ds_sinh_vien(ds_sv) + 1);
	delete[]nh;
	delete[]hk;
}
bool check_ds_trong_lop(tai_khoan infor, nam_hoc a, hoc_ki b, khoa_hoc c)
{
	ds_sinh_vien ds_sv;
	init_ds_sinh_vien(ds_sv);
	doc_ds_sinh_vien_khoa_hoc(a, b, c, ds_sv);
	while (ds_sv.head != NULL)
	{
		if (strcmp(ds_sv.head->data.ma_sinh_vien, infor.ms) == 0 && strcmp(ds_sv.head->data.cmnd, infor.cccd) == 0)
			return true;
		ds_sv.head = ds_sv.head->next;
	}
	return false;
}
void xem_khoa_hoc_da_dk(nam_hoc a, hoc_ki b, ds_khoa_hoc& l, int x, int y, tai_khoan t)
{
	ds_khoa_hoc ds_kh;
	init_ds_kh(ds_kh);
	doc_ds_khoa_hoc_tu_file(b, a, ds_kh);
	if (so_node_khoa_hoc(ds_kh) == 0)
	{
		system("cls");
		box(x, y, 3, 30);
		textcolor(4);
		gotoxy(x, y);
		cout << "NO COURSE";
		cin.ignore();
		return;
	}
	node_khoa_hoc* temp = ds_kh.head;
	while (temp != NULL)
	{
		khoa_hoc tam = temp->data;
		if (check_ds_trong_lop(t, a, b, tam) == true)
		{
			node_khoa_hoc* add = tao_node_mh(tam);
			addlast_mh(l, add);
		}
		temp = temp->next;
	}
}
