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
void xuat_ds_khoa_hoc(ds_khoa_hoc l, int x, int y)
{
	x += 30;
	gotoxy(x , y);
	y++;
	cout << "Ma khoa" << setw(8) << "Ten" << setw(8) << "Lop hoc" << setw(8) << "Giao vien" << setw(8) << "So tin chi" << setw(8) << "So luong" << setw(8) << "Ngay hoc trong tuan" << setw(8) << "Ca hoc" << endl;
	while (l.head != NULL)
	{
		gotoxy(x, y);
		cout << l.head->data.ma_khoa << setw(8) << l.head->data.ten_khoa_hoc << setw(8) << l.head->data.ten_lop_hoc << setw(8) << l.head->data.ten_giao_vien << setw(8) << l.head->data.so_tin_chi << setw(8) << l.head->data.so_luong << setw(8) << l.head->data.ngay << setw(8) << l.head->data.ca_hoc << endl;
		l.head = l.head->next;
		y++;
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
	box(x, y, 5, 30);
	gotoxy(x, y);
	cout << "Ma so :";
	cin.getline(a.ma_sinh_vien, 10);
	y++;
	gotoxy(x, y);
	cout << "Ho va ten : ";
	cin.getline(a.ho_ten, 50);
	y++;
	gotoxy(x, y);
	cout << "Gioi tinh : ";
	cin.getline(a.gioi_tinh, 10);
	y++;
	gotoxy(x, y);
	cout << "Ngay sinh : ";
	cin.getline(a.ngay_sinh, 20);
	y++;
	gotoxy(x, y);
	cout << "So CMND : ";
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
bool nhap_sinh_vien_tu_file(ds_sinh_vien& l, char ten_file[50])
{
	sinh_vien a;
	make_address(ten_file);
	ifstream filesv;
	filesv.open(ten_file);
	if (filesv.fail())
	{
		
		return false;
	}
	// bo qua hang dau tien
	char ar[50];
	filesv.getline(ar, 50, '\n');
	while (!filesv.eof())
	{
		char r[50];
		filesv.getline(r, 50, ',');
		if (strcmp(r," ") == 0)
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
	char address[30];
	strcpy(address, a.ten);
	strcpy(address, c.ma_khoa);
	strcpy(address, c.ten_khoa_hoc);
	xoa_dau_cach(address);
	make_link(address);
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
bool kiem_tra_file_empty(char ten_file[])
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
	if(kiem_tra_file_empty(address))
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
	if (kiem_tra_file_empty(address))
		filemh << "Ma khoa hoc" << ',' << "Ten khoa hoc" << ',' << "Ten lop hoc" << ',' << "Ten giao vien" << ',' << "So tin chi" << ',' << "So luong" << ',' << "Ngay hoc trong tuan" << ',' << "Ca hoc";
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
		/*char s[50];
		filemhread.getline(s, 50, ',');*/
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
	if (kiem_tra_file_empty(ten_file))
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