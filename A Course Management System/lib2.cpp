#include"lib2.h"
void xu_ly_lop_hoc(int cl, int x ,int y)
{
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
	system("cls");
	if (cl == y)
	{
		khoa_hoc mh;
		nhap_khoa_hoc(mh, x, y);
		ghi_ds_khoa_hoc(hk[cl_hoc_ki], mh, nh[cl_nam_hoc]);
	}
	else if (cl == y + 1)
	{
		ds_khoa_hoc ds_kh;
		init_ds_mh(ds_kh);
		doc_ds_khoa_hoc_tu_file(hk[cl_hoc_ki], nh[cl_nam_hoc], ds_kh);
		int sl_kh = so_node_khoa_hoc(ds_kh)-1;
		xuat_khoa_hoc_them_sv(x, y, ds_kh);
		int cl_khoa_hoc = click(x, y+1, sl_kh, 30)-y;
		khoa_hoc kh = tim_khoa_hoc(ds_kh,cl_khoa_hoc);
		sinh_vien a;
		nhap_sinh_vien(a, x, y);
		ghi_1_sinh_vien_vao_file(nh[cl_nam_hoc], hk[cl_hoc_ki],kh,a);
	}
	else if (cl == y + 2)
	{
		ds_khoa_hoc ds_kh;
		init_ds_mh(ds_kh);
		doc_ds_khoa_hoc_tu_file(hk[cl_hoc_ki], nh[cl_nam_hoc], ds_kh);
		int sl_kh = so_node_khoa_hoc(ds_kh) - 1;
		xuat_khoa_hoc_them_sv(x, y, ds_kh);
		int cl_khoa_hoc = click(x, y + 1, sl_kh, 30) - y;
		khoa_hoc kh = tim_khoa_hoc(ds_kh, cl_khoa_hoc);
		ds_sinh_vien ds_sv;
		init_ds_sinh_vien(ds_sv);
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
			ghi_1_sinh_vien_vao_file(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, ds_sv.head->data);
			ds_sv.head = ds_sv.head->next;
		}
	}
	else if (cl == y + 3)
	{
		ds_khoa_hoc ds_kh;
		init_ds_mh(ds_kh);
		doc_ds_khoa_hoc_tu_file(hk[cl_hoc_ki], nh[cl_nam_hoc], ds_kh);
		int sl_kh = so_node_khoa_hoc(ds_kh) - 1;
		xuat_khoa_hoc_them_sv(x, y, ds_kh);
		int cl_khoa_hoc = click(x, y + 1, sl_kh, 30) - y;
		khoa_hoc kh = tim_khoa_hoc(ds_kh, cl_khoa_hoc);
		ds_sinh_vien ds_sv;
		init_ds_sinh_vien(ds_sv);
		system("cls");
		
		gotoxy(x, y);
		doc_ds_sinh_vien(nh[cl_nam_hoc], hk[cl_hoc_ki], kh, ds_sv);
		int node_sv=so_node_ds_sinh_vien(ds_sv);
		xuat_ds_sinh_vien(ds_sv, x, y);
		char c = _getch();
	}
}