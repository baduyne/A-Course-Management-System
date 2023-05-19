#include"lib1.h"
using namespace std;
void init_ds_mh(ds_mon_hoc & mh)
{
	mh.head = NULL;
}
node_mon_hoc * tao_node_mh(mon_hoc a)
{
	node_mon_hoc* add = new node_mon_hoc;
	add->data = a;
	add->next = NULL;
	return add;
}
void addfirst(ds_mon_hoc& mh, node_mon_hoc* add)
{
	if (mh.head == NULL)
		mh.head = add;
	else
	{
		add->next = mh.head;
		mh.head = add;
	}
}
void addlast_mh(ds_mon_hoc& mh, node_mon_hoc* add)
{
	if (mh.head == NULL)
		mh.head = add;
	else
	{
		node_mon_hoc* t = mh.head;
		while (t->next != NULL)
		{
			t = t->next;
		}
		t->next = add;
	}
}
void xuat_ds_mon_hoc(ds_mon_hoc l, int x, int y)
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
void nhap_hoc_ki(hoc_ki& h, int x, int y)
{
	x = x + 30;
	textcolor(2);
	gotoxy(x, y);
	cout << "Nhap ten hoc ki : ";
	cin.getline(h.ten, 100);
	y++;
	gotoxy(x, y);
	cout << "Niem khoa : ";
	cin.getline(h.nien_khoa, 100);
	y++;
	gotoxy(x, y);
	cout << "Ngay bat dau : ";
	cin.getline(h.day_began, 100);
	y++;
	gotoxy(x, y);
	cout << "Ngay ket thuc ";
	cin.getline(h.day_end, 100);
}
void nhap_mon_hoc(mon_hoc& a, int x , int y)
{
	x = x + 30;
	textcolor(2);
	gotoxy(x, y);
	cout << "Ma khoa : ";
	cin.getline(a.ma_khoa, 100);
	y++;
	gotoxy(x, y);
	cout << "Ten khoa hoc : ";
	cin.getline(a.ten_khoa_hoc, 100);
	y++;
	gotoxy(x, y);
	cout << "Ten lop hoc : ";
	cin.getline(a.ten_lop_hoc, 100);
	y++;
	gotoxy(x, y);
	cout << "Ten giao vien : ";
	cin.getline(a.ten_giao_vien, 100);
	y++;
	gotoxy(x, y);
	cout << "So tin chi : ";
	cin >> a.so_tin_chi;
	cin.ignore();
	y++;
	gotoxy(x, y);
	cout << "Ngay hoc trong tuan : ";
	cin.getline(a.ngay, 100);
	y++;
	gotoxy(x, y);
	cout << "Ca hoc : ";
	cin.getline(a.ca_hoc, 100);
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
	gotoxy(x, y);
	cout << "Ma so sinh vien :";
	cin.getline(a.ma_sinh_vien, 100);
	y++;
	gotoxy(x, y);
	cout << "Ho va ten : ";
	cin.getline(a.ho_ten, 100);
	y++;
	gotoxy(x, y);
	cout << "Gioi tinh : ";
	cin.getline(a.gioi_tinh, 100);
	y++;
	gotoxy(x, y);
	cout << "Ngay sinh : ";
	cin.getline(a.ngay_sinh, 100);
	y++;
	gotoxy(x, y);
	cout << "So chung minh dan nhan (hoac cccd) : ";
	cin.getline(a.cmnd, 100);
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
void nhap_sinh_vien_tu_file(ds_sinh_vien& l, char ten_file[100])
{
	sinh_vien a;
	make_address(ten_file);
	ifstream filesv;
	filesv.open(ten_file);
	/*filesv.seekg(56, ios_base::beg);*/
	if (filesv.fail())
	{
		cout << "Khong the mo tep ";
		return;
	}
	// bo qua hang dau tien
	char ar[100];
	filesv.getline(ar, 100, ',');
	filesv.getline(ar, 100, ',');
	filesv.getline(ar, 100, ',');
	filesv.getline(ar, 100, ',');
	filesv.getline(ar, 100, ',');
	filesv.getline(ar, 100, '\n');
	while (!filesv.eof())
	{
		char r[100];
		filesv.getline(r, 100, ',');
		if (strcmp(r," ") == 0)
			break;
		filesv.getline(a.ma_sinh_vien, 100, ',');
		xoa_dau_cach(a.ma_sinh_vien);
		filesv.getline(a.ho_ten, 100, ',');
		xoa_dau_cach(a.ho_ten);
		filesv.getline(a.gioi_tinh, 100, ',');
		xoa_dau_cach(a.gioi_tinh);
		filesv.getline(a.ngay_sinh, 100, ',');
		xoa_dau_cach(a.ngay_sinh);
		filesv.getline(a.cmnd, 100, '\n');
		xoa_dau_cach(a.cmnd);
		xoa_dau_phay(a.cmnd);
		node_sv* add = tao_node_sv(a);
		addlast_sv(l, add);
	}
	filesv.close();
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
	char address[100];
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
	char address[100];
	strcpy(address, a.ten);
	xoa_dau_cach(address);
	make_link(address);
	filehkread.open(address);
	filehkread.seekg(49, ios_base::beg);
	while (!filehkread.eof())
	{
		filehkread.getline(arr[i].ten,100,',');
		filehkread.getline(arr[i].nien_khoa, 100, ',');
		filehkread.getline(arr[i].day_began, 100, ',');
		filehkread.getline(arr[i].day_end, 100, '\n');
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
	for (int i = 0; i < n; i++)
	{
		cout <<left<< a[i].ten << setw(10)<<right<< a[i].nien_khoa << endl;
	}
}
void ghi_ds_mon_hoc(hoc_ki h, mon_hoc a, nam_hoc b)
{
	strcat(b.ten, h.ten);
	char address[100];
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
void doc_ds_mon_hoc_tu_file(hoc_ki h,nam_hoc b , ds_mon_hoc &l)
{
	strcat(b.ten, h.ten);
	char ad[100];
	strcpy(ad, b.ten);
	xoa_dau_cach(ad);
	make_link(ad);
	mon_hoc a;
	ifstream filemhread;
	filemhread.open(ad);
	filemhread.seekg(99, ios_base::beg);// bo qua dong dau tien
	while (!filemhread.eof())
	{
		filemhread.getline(a.ma_khoa, 100, ',');
		filemhread.getline(a.ten_khoa_hoc, 100, ',');
		filemhread.getline(a.ten_lop_hoc, 100, ',');
		filemhread.getline(a.ten_giao_vien, 100, ',');
		filemhread >> a.so_tin_chi;
		/*char s[100];
		filemhread.getline(s, 100, ',');*/
		filemhread.ignore();
		filemhread >> a.so_luong;
		filemhread.ignore();
		filemhread.getline(a.ngay, 50, ',');
		filemhread.getline(a.ca_hoc, 50, '\n');
		node_mon_hoc* add = tao_node_mh(a);
		addlast_mh(l, add);
	}
	filemhread.close();
}
void nhap_nam_hoc(nam_hoc& nh,int x , int y)
{
	textcolor(2);
	gotoxy(x + 30, y);
	cout << "Nam hoc : ";
	cin.getline(nh.ten,100);
}
void xuat_nam_hoc(nam_hoc& nh)
{
	cout << nh.ten << endl;
}
void ghi_1_nam_hoc_vao_file(nam_hoc a)
{
	char ten_file[100] = "filenh";
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
		fileoutnh.getline(arr[i].ten, 100, '\n');
		i++;
	}
	fileoutnh.close();
	size = i;
}
void xuat_ds_nam_hoc(nam_hoc* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		xuat_nam_hoc(a[i]);
	}
}
void nd_nam_hoc(nam_hoc*& a, int sl, int x , int y )
{
	x = x + 30;
	for (int i = 0; i < sl; i++)
	{
		ToMau(x, y, a[i].ten, 2);
		y++;
	}
}
void nd_hoc_ki(hoc_ki*& a, int sl, int x, int y)
{
	x = x + 30;
	for (int i = 0; i < sl; i++)
	{
		ToMau(x, y, a[i].ten, 2);
		y++;
	}
}