#include"lib2.h"
void xu_ly_lop_hoc( int x, int y)
{
	while (true)
	{
		nd_lop_hoc(x, y);
		int cl = click(x, y, 6, 25);
		if (cl == y + 5)
			return;
		int sl;
		ds_khoa_hoc ds_kh;
		init_ds_mh(ds_kh);
		khoa_hoc mh;
		nam_hoc* nh = new nam_hoc[3];
		doc_ds_nam_hoc_tu_file(nh, sl);
		nd_nam_hoc(nh, sl, x, y);
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
		}
		else
		{
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
				cout << "Duong dan : ";
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
				int cl_lh = click(19, y + 1, sl_lop_hoc, 62) - y - 1;
				doc_ds_sinh_vien_lop_hoc(nh[cl_nam_hoc], lh[cl_lh], ds_sv);
				xuat_ds_sinh_vien(ds_sv, x, y);
			}
		}
	}
}
void xu_ly_khoa_hoc(int x ,int y)
{
	while (true)
	{
		nd_khoa_hoc(x, y);
		int cl = click(x, y, 9, 30);
		if (cl == y + 8)
			return;
		int sl, sl_hk, w = 15;
		nam_hoc* nh = new nam_hoc[3];
		doc_ds_nam_hoc_tu_file(nh, sl);
		nd_nam_hoc(nh, sl, x, y);
		int cl_nam_hoc = click(x, y + 1, sl, w) - y - 1;
		hoc_ki* hk = new hoc_ki[3];
		doc_ds_hoc_ki_tu_file(hk, nh[cl_nam_hoc], sl_hk);
		system("cls");
		nd_hoc_ki(hk, sl_hk, x, y);
		int cl_hoc_ki = click(x, y, sl_hk, w) - y;
		ds_khoa_hoc ds_kh;
		init_ds_mh(ds_kh);
		doc_ds_khoa_hoc_tu_file(hk[cl_hoc_ki], nh[cl_nam_hoc], ds_kh);
		ds_sinh_vien ds_sv;
		init_ds_sinh_vien(ds_sv);
		int sl_kh = so_node_khoa_hoc(ds_kh);
		system("cls");
		if (cl == y)
		{
			khoa_hoc mh;
			nhap_khoa_hoc(mh, x, y);
			ghi_1_khoa_hoc(hk[cl_hoc_ki], mh, nh[cl_nam_hoc], so_node_khoa_hoc(ds_kh)+1);
		}
		else
		{
			if (sl_kh == 0)
			{
					box(x, y, sl, 30);
					textcolor(4);
					gotoxy(x, y);
					cout << "NO COURSE";
					cin.ignore();
					continue;
			}
			xuat_ds_khoa_hoc(x, y, ds_kh);
			int cl_khoa_hoc = click(12, y + 1, sl_kh,90) - y;
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
				char tf[100];
				system("cls");
				box(x, y, 2, 50);
				gotoxy(x, y);
				cout << "Duong dan : ";
				cin.getline(tf, 100);
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
				while (ds_sv.head != NULL)
				{
					ghi_1_sinh_vien_vao_khoa_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, ds_sv.head->data, so_node_ds_sinh_vien(ds_sv)+1);
					ds_sv.head = ds_sv.head->next;
				}
			}
			else if (cl == y + 3)
			{
				system("cls");
				gotoxy(x, y);
				doc_ds_sinh_vien_khoa_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, ds_sv);
				int node_sv = so_node_ds_sinh_vien(ds_sv);
				xuat_ds_sinh_vien(ds_sv, x, y);
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
					box(x, y, sv, 30);
					textcolor(4);
					gotoxy(x, y);
					cout << "NO MEMBER";
					cin.ignore();
					continue;
				}
				xuat_ds_sinh_vien(ds_sv, x, y);
				int cl_sv = click(15, y + 1, sv, 73) - y;
				remove_node_sv(ds_sv, cl_sv);
				ghi_ds_sinh_vien_vao_khoa_hoc(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, ds_sv);
			}
			else if (cl == y + 5)
			{
				// xoa file khoa hoc 
				cout << cl_khoa_hoc;
				system("pause");
				char address[70];
				strcpy(address, nh[cl_nam_hoc].ten);
				strcat(address, "/");
				strcat(address, hk[cl_hoc_ki].ten);
				strcat(address, kh.ma_khoa);
				strcat(address, kh.ten_lop_hoc);
				xoa_dau_cach(address);
				make_link(address);
				delete_file(address);
				remove_khoa_hoc(ds_kh, cl_khoa_hoc);
				ghi_ds_khoa_hoc(hk[cl_hoc_ki], ds_kh, nh[cl_nam_hoc]);
			}
		}
	}
}
