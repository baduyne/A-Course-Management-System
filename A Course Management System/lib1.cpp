#include"lib1.h"
using namespace std;
void init_ds_mh(ds_khoa_hoc & mh)
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
	box(x, y, 4, 35);
	textcolor(2);
	gotoxy(x, y);
	cout << "Nhap ten hoc ki : ";
	cin.getline(h.ten, 20);
	strcpy(h.nien_khoa, a.ten);
	y++;
	gotoxy(x, y);
	cout << "Niem Khoa :" << h.nien_khoa;
	y++;
	gotoxy(x, y);
	cout << "Ngay bat dau : ";
	cin.getline(h.day_began, 20);
	y++;
	gotoxy(x, y);
	cout << "Ngay ket thuc ";
	cin.getline(h.day_end, 20);
}
void nhap_khoa_hoc(khoa_hoc& a, int x , int y)
{
	system("cls");
	box(x, y, 7, 50);
	textcolor(2);
	gotoxy(x, y);
	cout << "Ma khoa : ";
	cin.getline(a.ma_khoa, 20);
	y++;
	gotoxy(x, y);
	cout << "Ten khoa hoc : ";
	cin.getline(a.ten_khoa_hoc, 50);
	y++;
	gotoxy(x, y);
	cout << "Ten lop hoc : ";
	cin.getline(a.ten_lop_hoc, 50);
	y++;
	gotoxy(x, y);
	cout << "Giao vien : ";
	cin.getline(a.ten_giao_vien, 50);
	/*cin.ignore();*/
	y++;
	gotoxy(x, y);
	cout << "So tin chi : ";
	cin >> a.so_tin_chi;
	cin.ignore();
	y++;
	gotoxy(x, y);
	cout << "Ngay hoc trong tuan : ";
	cin.getline(a.ngay, 10);
	y++;
	gotoxy(x, y);
	cout << "Ca hoc : ";
	cin.getline(a.ca_hoc, 20);
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
void nhap_sinh_vien(sinh_vien& a, int x ,int y)
{
	system("cls");
	box(x, y, 5, 40);
	gotoxy(x, y);
	cout << "ID:";
	cin.getline(a.ma_sinh_vien, 10);
	y++;
	gotoxy(x, y);
	cout << "Your Name : ";
	cin.getline(a.ho_ten, 50);
	y++;
	gotoxy(x, y);
	cout << "Gender : ";
	cin.getline(a.gioi_tinh, 10);
	y++;
	gotoxy(x, y);
	cout << "Birthday : ";
	cin.getline(a.ngay_sinh, 20);
	y++;
	gotoxy(x, y);
	cout << "Number CMND : ";
	cin.getline(a.cmnd, 20);
	
}
void make_address(char a[])
{
	xoa_dau_cach(a);
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
	xoa_dau_cach(ten_file);
	ifstream filesv;
	filesv.open(ten_file);
	if (check_empty_file(ten_file)==true)
		return false;
	// bo qua hang dau tien
	char ar[200];
	filesv.getline(ar, 100, '\n');
	while (!filesv.eof())
	{
		char r[50];
		filesv.getline(r, 50, ',');
		if (strcmp(r,"") == 0) // k doc khoang  trang cuoi file
			break;
		filesv.getline(a.ma_sinh_vien, 10, ',');
		xoa_dau_cach(a.ma_sinh_vien);
		filesv.getline(a.ho_ten, 50, ',');
		xoa_dau_cach(a.ho_ten);
		filesv.getline(a.gioi_tinh, 10, ',');
		xoa_dau_cach(a.gioi_tinh);
		filesv.getline(a.ngay_sinh, 20, ',');
		xoa_dau_cach(a.ngay_sinh);
		filesv.getline(a.cmnd, 20, '\n');
		xoa_dau_cach(a.cmnd);
		xoa_dau_phay(a.cmnd);
		node_sv* add = tao_node_sv(a);
		addlast_sv(l, add);
	}
	filesv.close();
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
void xuat_ds_sinh_vien(ds_sinh_vien l)
{
	system("cls");
	while (l.head != NULL)
	{
		cout << l.head->data.ma_sinh_vien << ',' << l.head->data.ho_ten << ',' << l.head->data.gioi_tinh << ',' << l.head->data.ngay_sinh << ',' << l.head->data.cmnd<< endl;
		l.head = l.head->next;
	}
}
void ghi_1_sinh_vien_vao_file(nam_hoc a, hoc_ki b, khoa_hoc c, sinh_vien infor)
{
	char address[70];
	strcpy(address, a.ten);
	strcat(address, b.ten);
	strcat(address, c.ma_khoa);
	strcat(address, c.ten_lop_hoc);
	xoa_dau_cach(address);
	make_link(address);
	ofstream filesv;
	filesv.open(address,ios::app);
	if (check_empty_file(address))
		filesv << "Ma So" << ',' << "Ho va ten" << ',' << "Gioi tinh" << ',' << "Ngay sinh" << ',' << "So CMND";
	filesv << endl << infor.ma_sinh_vien << ',' << infor.ho_ten << ',' << infor.gioi_tinh << ',' << infor.ngay_sinh << ',' << infor.cmnd;
	filesv.close();
}
void make_link(char a[])
{
	strcat(a ,".csv");
}
void xoa_dau_cach(char a[])
{
	int i = 0;
	while (i < strlen(a))
	{
		if (a[i] == ' ')
		{
			for(int j=i;j<strlen(a);j++)
			a[j] = a[j + 1];
			i--;// tra lai y de xet nhieu khoang cach lien tiep nhau 
		}
		i++;
	}
}
bool check_empty_file(char ten_file[])
{
	ifstream filehkemty;
	filehkemty.open(ten_file, ios::binary | ios::ate);
	if (filehkemty.tellg() == 0)
	{
		filehkemty.close();
		return true;
	}
	filehkemty.close();
	return false;
}
void ghi_1_hoc_ki_vao_file(hoc_ki h, nam_hoc a)
{
	char address[30];
	strcpy(address, a.ten);
	xoa_dau_cach(address);
	make_link(address);
	ofstream filehk;
	filehk.open(address, ios::app);
	if(check_empty_file(address))
	{
		filehk << "Ten hoc ki" << ',' << "Niem khoa" << ',' << "Ngay bat dau" << ',' << "Ngay ket thuc";
	}
	filehk << endl << h.ten << ',' << h.nien_khoa << ',' << h.day_began << ',' << h.day_end;
	filehk.close();
}
void doc_ds_hoc_ki_tu_file(hoc_ki *&arr,nam_hoc a, int& sl)
{
	int i = 0;
	ifstream filehkread;
	char address[30];
	strcpy(address, a.ten);
	xoa_dau_cach(address);
	make_link(address);
	filehkread.open(address);
	filehkread.seekg(49, ios_base::beg);
	while (!filehkread.eof())
	{
		filehkread.getline(arr[i].ten,50,',');
		filehkread.getline(arr[i].nien_khoa, 50, ',');
		filehkread.getline(arr[i].day_began, 50, ',');
		filehkread.getline(arr[i].day_end, 50, '\n');
		i++;
	}
	filehkread.close();
	 sl=i;
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
void ghi_ds_khoa_hoc(hoc_ki h, khoa_hoc a, nam_hoc b)
{
	strcat(b.ten, h.ten);
	char address[30];
	strcpy(address, b.ten);
	xoa_dau_cach(address);
	make_link(address);
	ofstream filemh;
	filemh.open(address, ios::app);
	if (check_empty_file(address))
	{
		filemh << "Ma khoa hoc" << ',' << "Ten khoa hoc" << ',' << "Ten lop hoc" << ',' << "Ten giao vien" << ',' << "So tin chi" << ',' << "So luong" << ',' << "Ngay hoc trong tuan" << ',' << "Ca hoc";
	}
	filemh << endl << a.ma_khoa << ',' << a.ten_khoa_hoc << ',' << a.ten_lop_hoc << ',' << a.ten_giao_vien << ',' << a.so_tin_chi <<','<< a.so_luong << ',' << a.ngay << ',' << a.ca_hoc;
	filemh.close();
}
void doc_ds_khoa_hoc_tu_file(hoc_ki h,nam_hoc b , ds_khoa_hoc &l)
{
	strcat(b.ten, h.ten);
	char ad[30];
	strcpy(ad, b.ten);
	xoa_dau_cach(ad);
	make_link(ad);
	khoa_hoc a;
	ifstream filemhread;
	filemhread.open(ad);
	filemhread.seekg(99, ios_base::beg);// bo qua dong dau tien
	while (!filemhread.eof())
	{
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
}
int so_node_khoa_hoc(ds_khoa_hoc l)
{
	int vt = 1;
	while (l.head != NULL)
	{
		l.head = l.head->next;
		vt++;
	}
	return vt;
}
void xuat_khoa_hoc_them_sv(int  x, int y, ds_khoa_hoc l)
{
	int sl = so_node_khoa_hoc(l);
	system("cls");
	box(x, y, sl, 40);
	gotoxy(x, y);
	cout << "Mon Hoc" << setw(21) << "Lop Hoc";
	y++;
	while (l.head != NULL)
	{
		ToMau(x, y, l.head->data.ten_khoa_hoc, 2);
		ToMau(x+20, y, l.head->data.ten_lop_hoc, 2);
		y++;
		l.head = l.head->next;
	}
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
	x = 12;
	int sl = so_node_khoa_hoc(l),  py = y;
	system("cls");
	box(x, y, sl, 110);
	gotoxy(x, y);
	cout << "Ma khoa" << setw(11) << "Khoa hoc" << setw(20) << "Lop hoc" << setw(11) << "Giao vien" << setw(17) << "So luong" << setw(9) << "Tin chi" << setw(10) << "Ngay hoc" <<setw(8)<< "Ca hoc";
	y++;
	while(l.head !=NULL)
	{
		ToMau(x, y, l.head->data.ma_khoa, 2);
		ToMau(x+10, y, l.head->data.ten_khoa_hoc, 2);
		ToMau(x+31, y, l.head->data.ten_lop_hoc, 2);
		ToMau(x+40, y, l.head->data.ten_giao_vien, 2);
		gotoxy(x +58, y);
		textcolor(2);
		cout << l.head->data.so_luong;
		gotoxy(x + 69, y );
		cout << l.head->data.so_tin_chi;
	     ToMau(x + 78, y, l.head->data.ngay, 2);
		 ToMau(x + 87, y, l.head->data.ca_hoc, 2);
		y++;
		l.head =l.head ->next;
	}
	gotoxy(x-3, py+sl);
	cout << char(174) << "Back";
	char c = _getch();
	if (c == 13)
	{
		return;
	}
}
void nhap_nam_hoc(nam_hoc& nh,int x , int y)
{
	system("cls");
	box(x, y, 1, 30);
	textcolor(2);
	gotoxy(x , y);
	cout << "Niem khoa : ";
	cin.getline(nh.ten,50);
}
void xuat_nam_hoc(nam_hoc& nh)
{
	cout << nh.ten << endl;
}
void ghi_1_nam_hoc_vao_file(nam_hoc a)
{
	char ten_file[20] = "filenh";
	ofstream filenh;
	if (check_empty_file(ten_file))
		filenh << "Nam hoc";
	filenh.open("Danh_sach_cac_nam_hoc.csv",ios::app);
	filenh << endl << a.ten;
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
	fileoutnh.seekg(9,::ios_base::beg);
	while (!fileoutnh.eof())
	{
		if (i == size - 1)
			cap_phat_them_nam_hoc(arr, size);
		fileoutnh.getline(arr[i].ten, 50, '\n');
		i++;
	}
	fileoutnh.close();
	size = i;
}
void xuat_ds_nam_hoc(nam_hoc* a, int n, int x , int y)
{
	system("cls");
	box(x, y, n, 35);
	for (int i = 0; i < n; i++)
	{
		xuat_nam_hoc(a[i]);
	}
}
void nd_nam_hoc(nam_hoc*& a, int sl, int x , int y )
{
	system("cls");
	box(x, y, sl, 25);
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
	box(x, y, sl, 35);
	for (int i = 0; i < sl; i++)
	{
		ToMau(x, y, a[i].ten, 2);
		y++;
	}
}
void nd_lop_hoc(int x, int y)
{
	system("cls");
	box(x, y, 5, 40);
	char nd1[20] = "Tao 1 lop hoc";
	char nd2[20] = "Them 1 sinh vien";
	char nd3[30] = "Them danh sach sinh vien";
	char nd4[20] = "Xoa 1 sinh vien";
	char nd5[20] = "Xoa 1 khoa hoc";
	ToMau(x, y, nd1, 2);
	ToMau(x, y+1, nd2, 2);
	ToMau(x, y+2, nd3, 2);
	ToMau(x, y+3, nd4, 2);
	ToMau(x, y+4, nd5, 2);
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
		Sleep(100);
	}
}