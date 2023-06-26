#include"lib2.h"
void xu_ly_lop_hoc( int x, int y)
{
	while (true)
	{
		nd_lop_hoc(x, y);
		int cl = click(x, y, 8, 25);
		if (cl == y + 7)
			return;
		int sl;
		ds_khoa_hoc ds_kh;
		khoa_hoc mh;
		nam_hoc* nh = new nam_hoc[3];
		doc_ds_nam_hoc_tu_file(nh, sl);
		if (sl == 0)
		{
			system("cls");
			box(x, y, 2, 30);
			gotoxy(x, y);
			textcolor(12);
			cout << "NO SCHOOL YEAR ";
			cin.ignore();
			return;
		}
		xuat_nam_hoc(nh, sl, x, y);
		int cl_nam_hoc = click(x, y + 1, sl, 12) - y - 1;
		int sl_lop_hoc = 1;
		lop_hoc* lh = new lop_hoc[sl_lop_hoc];// co the cap phat them
		doc_ds_lop_hoc_tu_file(lh, nh[cl_nam_hoc], sl_lop_hoc);
		system("cls");
		if (cl == y)
		{
			lop_hoc a;
			nhap_lop_hoc(a, x, y);
			ghi_1_lop_hoc_vao_file(a, nh[cl_nam_hoc], sl_lop_hoc + 1);
			tao_file_ds_sinh_vien_lop_hoc_rong(nh[cl_nam_hoc], a);
		}
		else
		{
			if (sl_lop_hoc == 0)
			{
				system("cls");
				box(x, y, 3, 35);
				textcolor(4);
				gotoxy(x + 5, y);
				cout << "NO CLASS";
				cin.ignore();
				break;
			}
			ds_sinh_vien ds_sv;
			init_ds_sinh_vien(ds_sv);
			doc_ds_lop_hoc_tu_file(lh, nh[cl_nam_hoc], sl_lop_hoc);
			if (cl == y + 1)
			{
				xuat_lop_hoc(lh, sl_lop_hoc, x, y);
			}
			else if (cl == y + 2)
			{
				xuat_lop_hoc(lh, sl_lop_hoc, x, y);
				int cl_lh = click(19, y + 1, sl_lop_hoc, 62) - y - 1;
				doc_ds_sinh_vien_lop_hoc(nh[cl_nam_hoc], lh[cl_lh], ds_sv);
				sinh_vien a;
				nhap_sinh_vien(a, x, y);
				ghi_1_sinh_vien_vao_lop_hoc(nh[cl_nam_hoc], lh[cl_lh], a, so_node_ds_sinh_vien(ds_sv)+1);
			}
			else if (cl == y + 3)
			{
				xuat_lop_hoc(lh, sl_lop_hoc, x, y);
				int cl_lh = click(19, y + 1, sl_lop_hoc, 62) - y - 1;
				doc_ds_sinh_vien_lop_hoc(nh[cl_nam_hoc], lh[cl_lh], ds_sv);
				char tf[200];
				system("cls");
				box(x, y, 2, 50);
				gotoxy(x, y);
				cout << "Duong Dan : ";
				cin.getline(tf, 200);
				xoa_dau_cach(tf);
				if (nhap_sinh_vien_tu_file(ds_sv, tf) == true)
				{
					draw_load(x, y + 1, 20);
				}
				else
				{
					char a[20] = "Fail.....";
					ToMau(x, y + 1, a, 4);
					Sleep(200);
				}
				ghi_ds_sinh_vien_vao_lop_hoc(nh[cl_nam_hoc], lh[cl_lh], ds_sv);
			}
			else if (cl == y + 4)
			{
				xuat_lop_hoc(lh, sl_lop_hoc, x, y);
				int cl_lh = click(19, y + 1, sl_lop_hoc, 62) - y - 1;// lop hoc la mang bat dau tu 0
				doc_ds_sinh_vien_lop_hoc(nh[cl_nam_hoc], lh[cl_lh], ds_sv);
				xuat_ds_sinh_vien_lop_hoc(ds_sv, x, y);
				cin.ignore();
			}
			else if (cl == y + 5)
			{
				xuat_lop_hoc(lh, sl_lop_hoc, x, y);
				int cl_lh = click(19, y + 1, sl_lop_hoc, 62) - y - 1;// lop hoc la mang bat dau tu 0
				doc_ds_sinh_vien_lop_hoc(nh[cl_nam_hoc], lh[cl_lh], ds_sv);
				int  sv = so_node_ds_sinh_vien(ds_sv);
				if (sv == 0)
				{
					box(x, y, 2, 30);
					textcolor(4);
					gotoxy(x, y);
					cout << "NO MEMBER";
					cin.ignore();
					continue;
				}
				xuat_ds_sinh_vien_lop_hoc(ds_sv, x, y);
				int cl_sv = click(15, y + 3, sv, 77) - y - 2;
				remove_node_sv(ds_sv, cl_sv);
				ghi_ds_sinh_vien_vao_lop_hoc(nh[cl_nam_hoc], lh[cl_lh],ds_sv);
			}
			else if (cl == y + 6)
			{
				int sl_hk = 3;
				xuat_lop_hoc(lh, sl_lop_hoc, x, y);
				int cl_lh = click(19, y + 1, sl_lop_hoc, 62) - y - 1;
				hoc_ki* hk = new hoc_ki[sl_hk];
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
				int cl_hoc_ki = click(x, y, sl_hk, 15) - y;// bat dau tu 0
				while (true)
				{
					system("cls");
					nd_xem_diem_lop_hoc(x, y);
				   int cl_nhap_diem_lh = click(x,y,4,27);
				  if (cl_nhap_diem_lh == y + 3)
					 break;
				xem_diem_lop_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], lh[cl_lh], x, y, cl_nhap_diem_lh);
				}
			}
		}
	}
}
void xu_ly_khoa_hoc(int x ,int y)
{
	while (true)
	{
		nd_khoa_hoc(x, y);
		int cl = click(x+2, y, 9, 26);
		if (cl == y + 8)
			return;
		int sl, sl_hk, w = 15;
		nam_hoc* nh = new nam_hoc[3];
		doc_ds_nam_hoc_tu_file(nh, sl);
		if(sl == 0)
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
		int cl_nam_hoc = click(x, y + 1, sl, 11) - y - 1;// bay dau tu 0
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
		int cl_hoc_ki = click(x, y, sl_hk, 10) - y;// bat dau tu 0
		ds_khoa_hoc ds_kh;
		init_ds_kh(ds_kh);
		doc_ds_khoa_hoc_tu_file(hk[cl_hoc_ki], nh[cl_nam_hoc], ds_kh);
		ds_sinh_vien ds_sv;
		init_ds_sinh_vien(ds_sv);
		int sl_kh = so_node_khoa_hoc(ds_kh);
		system("cls");
		if (cl == y)
		{
			khoa_hoc kh;
			while (true)
			{
                nhap_khoa_hoc(kh, x, y);
				if (kt_trung_ca_khoa_hoc(ds_kh, kh) == true)
				{
					gotoxy(x + 10, y + 10);
					textcolor(12);
					cout << "Trung Gio Hoc !";
					cin.ignore();
					continue;
				}
				break;
			}
			ghi_1_khoa_hoc(hk[cl_hoc_ki], kh, nh[cl_nam_hoc], so_node_khoa_hoc(ds_kh)+1);
			tao_file_ds_sv_khoa_hoc_rong(nh[cl_nam_hoc], hk[cl_hoc_ki], kh);
		}
		else
		{
			if (sl_kh == 0)
			{
				    system("cls");
					box(x, y, sl, 30);
					textcolor(4);
					gotoxy(x, y);
					cout << "NO COURSE";
					cin.ignore();
					continue;
			}
			xuat_ds_khoa_hoc(x, y, ds_kh);
			int cl_khoa_hoc = click(12, y + 1, sl_kh,97) - y;// -y de no bat dau tu 1 
			khoa_hoc kh = tim_khoa_hoc(ds_kh, cl_khoa_hoc);
			ds_sinh_vien ds_sv;
			init_ds_sinh_vien(ds_sv);
			if (cl == y + 1)
			{
				sinh_vien a;
				nhap_sinh_vien(a, x, y);
				doc_ds_sinh_vien_khoa_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, ds_sv);
				ghi_1_sinh_vien_vao_khoa_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, a, so_node_ds_sinh_vien(ds_sv)+1);
			}
			else if (cl == y + 2)
			{
				char *tf=new char [500];
				system("cls");
				box(x, y, 5, 55);
				gotoxy(x, y);
				cout << "Link : ";
				o(x, y+1, 40);
				gotoxy(x+1, y + 2);
				cin.getline(tf, 500);
				if (nhap_sinh_vien_tu_file(ds_sv, tf) == true)
				{
					draw_load(x, y + 4, 20);
				}
				else
				{
					char a[20] = "Fail.....";
					ToMau(x, y + 4, a, 4);
					Sleep(200);
					continue;
				}
				while (ds_sv.head != NULL)
				{
					ghi_1_sinh_vien_vao_khoa_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, ds_sv.head->data, so_node_ds_sinh_vien(ds_sv)+1);
					ds_sv.head = ds_sv.head->next;
				}
				delete[]tf;
			}
			else if (cl == y + 3)
			{
				system("cls");
				gotoxy(x, y);
				doc_ds_sinh_vien_khoa_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, ds_sv);
				if (so_node_ds_sinh_vien(ds_sv) == 0)
				{
					box(x, y, 2, 30);
					textcolor(4);
					gotoxy(x, y);
					cout << "NO MEMBER";
					cin.ignore();
					continue;
				}
				xuat_ds_sinh_vien_khoa_hoc(ds_sv, x, y);
				char c = _getch();
			}
			else if (cl == y + 4)
			{
				system("cls");
				gotoxy(x, y);
				doc_ds_sinh_vien_khoa_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, ds_sv);
				int  sv = so_node_ds_sinh_vien(ds_sv);
				if (sv == 0)
				{
					box(x, y, 2, 30);
					textcolor(4);
					gotoxy(x, y);
					cout << "NO MEMBER";
					cin.ignore();
					continue;
				}
				xuat_ds_sinh_vien_lop_hoc(ds_sv, x, y);
				int cl_sv = click(15, y + 3, sv, 77) - y-2;
				remove_node_sv(ds_sv, cl_sv);
				ghi_ds_sinh_vien_vao_khoa_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, ds_sv);
			}
			else if (cl == y + 5)
			{
				// xoa file khoa hoc 
				char *address=new char [100];
				strcpy(address, nh[cl_nam_hoc].ten);
				strcat(address, "/");
				strcat(address, hk[cl_hoc_ki].ten);
				strcat(address, "/");
				strcat(address, kh.ten_khoa_hoc);
				strcat(address, kh.ten_lop_hoc);
				make_link(address);
				delete_file(address);
				remove_khoa_hoc(ds_kh, cl_khoa_hoc);
				ghi_ds_khoa_hoc(hk[cl_hoc_ki], ds_kh, nh[cl_nam_hoc]);
				delete[]address;
			}
			else if (cl == y + 7)
			{
				while (true)
				{
					system("cls");
					char* ten_file = new char[300];
					doc_ds_sinh_vien_khoa_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, ds_sv);
					int  sv = so_node_ds_sinh_vien(ds_sv);
					if (sv == 0)
					{
						box(x, y, 2, 30);
						textcolor(4);
						gotoxy(x, y);
						cout << "NO MEMBER";
						cin.ignore();
						continue;

					}
					nd_nhap_diem(x, y);
					int click_nhap_diem = click(x, y, 4, 20);
					if (click_nhap_diem == y + 2)
					{
						system("cls");
						box(x, y, 5, 55);
						gotoxy(x, y);
						cout << "Link : ";
						o(x, y + 1, 40);
						gotoxy(x + 1, y + 2);
						cin.getline(ten_file, 300);
						make_address(ten_file);
						if (nhap_diem(ds_sv, ten_file) == true)
						{
							draw_load(x, y + 4, 20);
						}
						else
						{
							char a[20] = "Fail.....";
							ToMau(x, y + 4, a, 4);
							Sleep(200);
							continue;
						}
						ghi_ds_sinh_vien_vao_khoa_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, ds_sv);
					}
					else if (click_nhap_diem == y)
					{
						tao_file_nhap_diem(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, ds_sv);
					}
					else if (click_nhap_diem == y + 3)
					{
						break;
					}
					else if (click_nhap_diem == y + 1)
					{

					}
				}
			}
		}
	}
}
bool nhap_diem(ds_sinh_vien &ds_sv_kh, char ten_file[])
{
		ds_sinh_vien l;
		init_ds_sinh_vien(l);
		if (doc_file_diem(l, ten_file) == false)
			return false;
		node_sv* temp_ds = ds_sv_kh.head;
		while (temp_ds != NULL)
		{
			for (node_sv* temp = l.head; temp != NULL; temp = temp->next)
			{
				if (strcmp(temp_ds->data.ma_sinh_vien, temp->data.ma_sinh_vien) == 0)
				{
					temp_ds->data.dqt = temp->data.dqt;
					temp_ds->data.diemgk = temp->data.diemgk;
					temp_ds->data.diemck = temp->data.diemck;
					temp_ds->data.dtb = temp->data.dtb;
				}
			}
			temp_ds = temp_ds->next;
		}
		return true;
}
void xem_diem(tai_khoan infor, int x, int y)
{
	int sl = 2, w = 15, sl_hk = 2, px = x, py = y;
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
	int cl_nam_hoc = click(x, y + 1, sl, w) - y - 1;
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
	int cl_hoc_ki = click(x, y, sl_hk, w) - y;
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
	x = 15;
	system("cls");
	ds_khoa_hoc kh_da_dk;
	init_ds_kh(kh_da_dk);
	xem_khoa_hoc_da_dk(nh[cl_nam_hoc], hk[cl_hoc_ki], kh_da_dk, x, y, infor);
	box(x, y, so_node_khoa_hoc(ds_kh), 90);
	gotoxy(x, y);
	textcolor(2);
	cout << "Ma KHoa" << setw(16) << "Ten Khoa Hoc" << setw(19) << "Ten Lop" << setw(10) << "Diem QT" << setw(10) << "Diem GK" << setw(10) << "Diem Ck" << setw(10) << "Diem TB" << endl;
	y++;
	textcolor(7);
	ds_sinh_vien l;
	while (kh_da_dk.head!=NULL)
	{
		ToMau(x, y, kh_da_dk.head->data.ma_khoa,7);
		ToMau(x+15, y, kh_da_dk.head->data.ten_khoa_hoc, 7);
		ToMau(x+35, y, kh_da_dk.head->data.ten_lop_hoc, 7);
		init_ds_sinh_vien(l);
		doc_ds_sinh_vien_khoa_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], kh_da_dk.head->data, l);
		while (l.head != NULL)
		{
			if (strcmp(l.head->data.ma_sinh_vien, infor.ms) == 0)
			{
				gotoxy(x+45, y);
				cout << l.head->data.dqt << setw(10) << l.head->data.diemgk << setw(10) << l.head->data.diemck << setw(10) << l.head->data.dtb;
				y++;
			}
			l.head = l.head->next;
		}
		kh_da_dk.head = kh_da_dk.head->next;
	}
}
void xem_diem_lop_hoc(nam_hoc a, hoc_ki b, lop_hoc c, int x, int y,int cl)
{
	system("cls");
	x = 15;
	ds_khoa_hoc ds_kh;
	ds_sinh_vien l;
	init_ds_kh(ds_kh);
	kt_khoa_hoc_thuoc_lop_hoc(a, b, c, ds_kh, x, y);
	int sl_khoa_hoc = so_node_khoa_hoc(ds_kh);
	float dtb_hoc_ki = 0;
	if (sl_khoa_hoc == 0)
		return;
	if (cl == y)
	{
		textcolor(2);
		box(x, y, so_node_khoa_hoc(ds_kh), 90);
		gotoxy(x, y);
		cout << "Ma Khoa" << setw(18) << "Ten Khoa Hoc" << setw(19) << "Ten Lop" << setw(30) << "Diem Trung Binh Cuoi Ki" << endl;
		y++;
		textcolor(7);
		while (ds_kh.head != NULL)
		{
			ToMau(x, y, ds_kh.head->data.ma_khoa, 7);
			ToMau(x + 13, y, ds_kh.head->data.ten_khoa_hoc, 7);
			ToMau(x + 37, y, ds_kh.head->data.ten_lop_hoc, 7);
			init_ds_sinh_vien(l);
			doc_ds_sinh_vien_khoa_hoc(a, b, ds_kh.head->data, l);
			float s = 0;
			int  sl_sv = so_node_ds_sinh_vien(l);
			while (l.head != NULL)
			{
				s = s + l.head->data.diemck;
				l.head = l.head->next;
			}
			gotoxy(x + 62, y);
			s = s == 0 ? 0 : s / sl_sv;
			cout << s;
			ds_kh.head = ds_kh.head->next;
			y++;
		}
	}
	else if (cl == y + 1)
	{
		while (ds_kh.head != NULL)
		{
			
			init_ds_sinh_vien(l);
			doc_ds_sinh_vien_khoa_hoc(a, b, ds_kh.head->data, l);
			int sl_sv= so_node_ds_sinh_vien(l);
			float dtb=0;
			while (l.head != NULL)
			{
				dtb = dtb + l.head->data.dtb;
				l.head = l.head->next;
			}
			dtb = dtb == 0 ? 0 : dtb / sl_sv;
			ds_kh.head = ds_kh.head->next;
			dtb_hoc_ki = dtb_hoc_ki + dtb;
		}
		dtb_hoc_ki = dtb_hoc_ki == 0 ? 0 : dtb_hoc_ki / sl_khoa_hoc;
		box(x, y, 3, 50);
		gotoxy(x, y+1);
		cout << " Diem Trung Binh Trong Hoc Ki : " << dtb_hoc_ki;
		gotoxy(x-3, y+3);
		textcolor(3);
		cout << "Press Enter To Continue";
		}
		cin.ignore();
}
