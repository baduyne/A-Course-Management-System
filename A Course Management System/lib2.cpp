#include"lib2.h"
void xu_ly_lop_hoc(int cl, int x ,int y)
{
	if (cl == y)
	{
		int sl, sl_hk, w = 15;
		khoa_hoc mh;
		nam_hoc* nh = new nam_hoc[2];
		doc_ds_nam_hoc_tu_file(nh, sl);
		nd_nam_hoc(nh, sl, x, y);
		int cl_nam_hoc = click(x, y + 1, sl, w) - y - 1;
		hoc_ki* hk = new hoc_ki[3];
		doc_ds_hoc_ki_tu_file(hk, nh[cl_nam_hoc], sl_hk);
		system("cls");
		nd_hoc_ki(hk, sl_hk, x, y);
		int cl_hoc_ki= click(x, y, sl_hk, w) - y;
		system("cls");
		nhap_khoa_hoc(mh, x, y);
		ghi_ds_khoa_hoc(hk[cl_hoc_ki], mh, nh[cl_nam_hoc]);
	}
	else if (cl == y + 1)
	{
		system("cls ");
		sinh_vien a;
		nhap_sinh_vien(a, x+30, y);

	}
}