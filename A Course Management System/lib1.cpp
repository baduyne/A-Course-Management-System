#include"lib1.h"
using namespace std;
void init_ds_mh(ds_khoa_hoc & mh)
{
	mh.head = NULL;
}
void innit_khoa_hoc(khoa_hoc& a)
{
	a.ca_hoc[0] = a.ma_khoa[0] = a.ngay[0] = a.ten_giao_vien[0] = a.ten_khoa_hoc[0] = a.ten_lop_hoc[0] = '\0';
	a.so_luong = a.so_tin_chi = 0;
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
	cout << "Nhap ten hoc ki : ";
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
	cout << "Ngay bat dau : ";
	textcolor(7);
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(h.day_began, 20);
	y += 4;
	gotoxy(x, y);
	textcolor(2);
	cout << "Ngay ket thuc ";
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
	cout << "Ma khoa :";
	textcolor(7);
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin.getline(a.ma_khoa, 20);
	y+=4;
	textcolor(2);
	gotoxy(x, y);
	cout << "Ten khoa hoc : ";
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
	cout << "Giao vien : ";
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
		cout << "So tin chi : ";
		textcolor(7);
		o(x, y + 1, 25);
		gotoxy(x + 1, y + 2);
		cin >> a.so_tin_chi;
		cin.ignore();
		y+=4;
		gotoxy(x, y);
		textcolor(2);
		cout << "Ngay hoc trong tuan : ";
		strcpy(a.ngay, ngay_hoc_trong_tuan(x, y+1));
		y+=2;
		textcolor(2);
		gotoxy(x, y);
		cout << "Ca hoc : ";
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
//node_sv* pos_node_sv(ds_sinh_vien  l,int pos)
//{
//	int pos = 1;
//	while (l.head != NULL)
//	{
//		if (strcmp(l.head ->data.ma_sinh_vien, p->data.ms)==1)
//		{
//			return pos;
//		}
//		l.head = l.head->next;
//		pos++;
//	}
//	return -1;
//
//}
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
void nhap_ds_sinh_vien(ds_sinh_vien &l,int x , int y)
{
	int n;
	cout << "Nhap so luong sinh vien ";
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
	box(x, y, so_node_sv, 100);
	gotoxy(x, y);
	cout << "Ma so" << setw(15) << "Ho Va Ten" << setw(18) << "Gioi Tinh" << setw(12) << "Ngay sinh" << setw(12) << "So CMND";
	y++;
	while (l.head != NULL)
	{
		textcolor(2);
		gotoxy(x, y);
		ToMau(x, y, l.head->data.ma_sinh_vien, 2);
		ToMau(x + 11, y, l.head->data.ho_ten, 2);
		ToMau(x + 31, y, l.head->data.gioi_tinh, 2);
		ToMau(x + 41, y, l.head->data.ngay_sinh, 2);
		ToMau(x + 55, y, l.head->data.cmnd, 2);
		l.head = l.head->next;
		y++;
	}
	/*cin.ignore();*/
}
void xuat_ds_sinh_vien_khoa_hoc(ds_sinh_vien l, int x, int y)
{
	x = 15;
	system("cls");
	int so_node_sv = so_node_ds_sinh_vien(l);
	box(x, y, so_node_sv, 100);
	gotoxy(x, y);
	cout << "Ma so" << setw(15) << "Ho Va Ten" << setw(18) << "Gioi Tinh" << setw(12) << "Ngay sinh" << setw(12) << "So CMND" << setw(13) << "Diem TB";
	y++;
	while (l.head != NULL)
	{
		textcolor(2);
		gotoxy(x, y);
		ToMau(x, y, l.head->data.ma_sinh_vien, 7);
		ToMau(x + 11, y, l.head->data.ho_ten, 7);
		ToMau(x + 31, y, l.head->data.gioi_tinh, 7);
		ToMau(x + 41, y, l.head->data.ngay_sinh, 7);
		ToMau(x + 55, y, l.head->data.cmnd, 7);
		gotoxy(x + 69, y);
		cout << l.head->data.dtb;
		l.head = l.head->next;
		y++;
	}
	/*cin.ignore();*/
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
		filesv << "STT" << ',' << "Ma So" << ',' << "Ho va ten" << ',' << "Gioi tinh" << ',' << "Ngay sinh" << ',' << "So CMND" << ',' << "Diem GK" << ',' << "Diem CK" << ',' << "Diem TB" << endl;
	filesv << pos << ',' << infor.ma_sinh_vien << ',' << infor.ho_ten << ',' << infor.gioi_tinh << ',' << infor.ngay_sinh << ',' << infor.cmnd <<","<<infor.diemgk << "," << infor.diemck << "," << infor.dtb << endl;
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
		filesv << "STT" << ',' << "Ma So" << ',' << "Ho va ten" << ',' << "Gioi tinh" << ',' << "Ngay sinh" << ',' << "So CMND" << ',' << "Diem GK" << ',' << "Diem CK" << ',' << "Diem TB" << endl;
	while (infor.head != NULL)
	{
		filesv << i << ',' << infor.head->data.ma_sinh_vien << ',' << infor.head->data.ho_ten << ',' << infor.head->data.gioi_tinh << ',' << infor.head->data.ngay_sinh << ',' << infor.head->data.cmnd << ',' << infor.head->data.diemgk<< ',' << infor.head->data.diemck<< ',' << infor.head->data.dtb << endl;
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
	if (check_empty_file(address))
		filesv << "STT" << ',' << "Ma So" << ',' << "Ho va ten" << ',' << "Gioi tinh" << ',' << "Ngay sinh" << ',' << "So CMND" << endl;
	filesv << pos << ',' << infor.ma_sinh_vien << ',' << infor.ho_ten << ',' << infor.gioi_tinh << ',' << infor.ngay_sinh << ',' << infor.cmnd << endl;
	filesv.close();
	delete[]address;
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

	cout << "Ten lop :"; 
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
	cout << "So luong to da: ";
	o(x, y + 1, 25);
	gotoxy(x + 1, y + 2);
	cin >> a.so_luong;
	cin.ignore();
	y += 4;
	gotoxy(x, y);
	cout << "Khoa hoc: ";
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
		filemh  <<i<<',' << a.head->data.ma_khoa << ',' << a.head->data.ten_khoa_hoc <<','<<a.head->data.ten_lop_hoc << ',' << a.head->data.ten_giao_vien << ',' << a.head->data.so_tin_chi << ',' << a.head->data.so_luong << ',' << a.head->data.ngay << ',' << a.head->data.ca_hoc;
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
void xuat_ds_khoa_hoc(int x, int y, ds_khoa_hoc l)
{
	int sl = so_node_khoa_hoc(l), py = y;
	x = 12;
	system("cls");
	box(x, y, sl, 110);
	gotoxy(x, y);
	cout << "Ma khoa" << setw(11) << "Khoa hoc" << setw(20) << "Lop hoc" << setw(11) << "Giao vien" << setw(17) << "So luong" << setw(9) << "Tin chi" << setw(10) << "Ngay hoc" << setw(8) << "Ca hoc";
	y++;
	while (l.head != NULL)
	{
		ToMau(x, y, l.head->data.ma_khoa, 2);
		ToMau(x + 10, y, l.head->data.ten_khoa_hoc, 2);
		ToMau(x + 31, y, l.head->data.ten_lop_hoc, 2);
		ToMau(x + 40, y, l.head->data.ten_giao_vien, 2);
		gotoxy(x + 58, y);
		textcolor(2);
		cout << l.head->data.so_luong;
		gotoxy(x + 69, y);
		cout << l.head->data.so_tin_chi;
		ToMau(x + 78, y, l.head->data.ngay, 2);
		ToMau(x + 87, y, l.head->data.ca_hoc, 2);
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
void delete_file(char ten_file[])
{
	int x=remove(ten_file);
	return;
}
void nhap_nam_hoc(nam_hoc& nh,int x , int y)
{
	system("cls");
	box(x, y, 5, 40);
	textcolor(7);
	gotoxy(x , y);
	cout << "Niem khoa : ";
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
void xuat_nam_hoc(nam_hoc nh,int x,int y)
{
	gotoxy(x, y);
	cout << nh.ten << endl;
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

void nd_khoi_tao(int x, int y)
{
	system("cls");
	box(x, y, 3, 30);
	char nd1[20] = "Tao Nam Hoc";
	char nd2[20] = "Tao Hoc Hi";
	char  exit[20] = "Thoat";
	ToMau(x+8 -strlen(nd1) / 2, y, nd1, 2);
	ToMau(x + 8 - strlen(nd2) / 2, y + 1, nd2, 2);
	ToMau(x + 8 - strlen(exit) / 2, y + 2, exit, 2);
}
int  so_node_ds_sinh_vien(ds_sinh_vien l)
{
	int vt=0;
	while (l.head != NULL)
	{
		l.head = l.head->next;
		vt++;
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
void xuat_ds_nam_hoc(nam_hoc* a, int n, int x , int y)
{
	system("cls");
	box(x, y, n, 40);
	for (int i = 0; i < n; i++)
	{
		xuat_nam_hoc(a[i],x,y);
		y++;
	}
}
void nd_nam_hoc(nam_hoc*& a, int sl, int x , int y )
{
	system("cls");
	box(x, y, sl+1, 25);
	textcolor(2);
	gotoxy(x-1, y);
	cout << "Niem Khoa :";
	y++;
	for (int i = 0; i < sl; i++)
	{
		ToMau(x, y, a[i].ten, 2);
		y++;
	}
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
	box(x, y, sl, 35);
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
	char nd1[20] = "Tao 1 khoa hoc";
	char nd2[20] = "Them 1 sinh vien";
	char nd3[30] = "Them sinh vien tu file";
	char nd4[40] = "Xem danh sach sinh vien";
	char nd5[20] = "Xoa 1 sinh vien";
	char nd6[20] = "Xoa 1 khoa hoc";
	char nd7[20] = "Nhap diem";
	char nd8[20] = "Nhap diem tu file";
	char nd9[20] = "Thoat";
	ToMau(x+ 13 -strlen(nd1)/2, y, nd1, 2);
	ToMau(x + 13 - strlen(nd2)/2, y+1, nd2, 2);
	ToMau(x + 13 - strlen(nd3)/2, y+2, nd3, 2);
	ToMau(x + 13 - strlen(nd4)/2, y+3, nd4, 2);
	ToMau(x + 13 - strlen(nd5)/2, y+4, nd5, 2);
	ToMau(x + 13 - strlen(nd6)/2, y + 5, nd6, 2);
	ToMau(x + 13 - strlen(nd7)/2, y + 6, nd7, 2);
	ToMau(x + 13 - strlen(nd8)/2, y + 7, nd8, 2);
	ToMau(x + 13 - strlen(nd9)/2, y + 8, nd9, 2);
}
void nd_lop_hoc(int x, int y)
{
	system("cls");
	box(x, y, 6, 35);
	char nd1[20] = "Them 1 lop hoc";
	char nd2[30] = "Danh sach lop hoc";
	char nd3[30] = "Them 1 sinh vien";
	char nd4[30] = "Them danh sach tu file";
	char nd5[30] = "Xem danh sach sinh vien";
	char nd6[30] = "Thoat";
	ToMau(x +11 - strlen(nd1) / 2, y, nd1, 2);// canh giua 
	ToMau(x +11- strlen(nd2) / 2, y+1, nd2, 2);
	ToMau(x +11- strlen(nd3) / 2, y+2, nd3, 2);
	ToMau(x +11 - strlen(nd4) / 2, y + 3, nd4, 2);
	ToMau(x +11 - strlen(nd5) / 2, y + 4, nd5, 2);
	ToMau(x +11- strlen(nd6) / 2, y + 5, nd6, 2);
}
void draw_load(int x, int y, int w)
{
	gotoxy(x, y);
	for (int i = 0; i < w; i++)
	{
		cout << char(178);
	}
	gotoxy(x, y);
	for (int i = 0; i < w; i++)
	{
		textcolor(3);
		cout << char(178);
		/*Sleep(80);*/
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

