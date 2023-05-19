#ifndef lib1___h
#define lib1___h
#include<iostream>
#include"do_hoa.h"
#include"lib.h"
#include<fstream>
#include<iomanip>
using namespace std;
struct hoc_ki
{
	char ten[100];
	char nien_khoa[100];
	char day_began[100];
	char day_end[100];
};
struct mon_hoc
{
	char ma_khoa[100];
	char ten_khoa_hoc[100];
	char ten_lop_hoc[100];
	char ten_giao_vien[100];
	int so_tin_chi;
	int so_luong = 50;
	char ngay[50];
	char ca_hoc[50];
};
struct node_mon_hoc
{
	mon_hoc data;
	node_mon_hoc* next;
};
struct ds_mon_hoc
{
	node_mon_hoc* head;
};
struct sinh_vien
{
	char ma_sinh_vien[100];
	char ho_ten[100];
	char gioi_tinh[100];
	char ngay_sinh[100];
	char cmnd[100];
};
struct node_sv
{
	sinh_vien data;
	node_sv* next;
};
struct ds_sinh_vien
{
	node_sv* head;
};
struct nam_hoc
{
	char ten[100];
};
void nhap_nam_hoc(nam_hoc& nh,int x, int y);
void ghi_1_nam_hoc_vao_file(nam_hoc a);
void cap_phat_them_nam_hoc(nam_hoc*& a, int& sz);
void doc_ds_nam_hoc_tu_file(nam_hoc*& arr, int& sl);
void xuat_ds_nam_hoc(nam_hoc* a, int n);
void init_ds_mh(ds_mon_hoc& mh);
node_mon_hoc* tao_node_mh(mon_hoc a);
void addfirst(ds_mon_hoc& mh, node_mon_hoc* add);
void addlast_mh(ds_mon_hoc& mh, node_mon_hoc* add);
void init_ds_sinh_vien(ds_sinh_vien& mh);
node_sv* tao_node_sv(sinh_vien a);
void nhap_sinh_vien_tu_file(ds_sinh_vien& l, char ten_file[100]);
void make_address(char a[]);
void xoa_dau_phay(char a[]);
void addfirst_sv(ds_sinh_vien& mh, node_sv* add);
void ghi_ds_mon_hoc(hoc_ki h, mon_hoc a, nam_hoc b);
void addlast_sv(ds_sinh_vien& mh, node_sv* add);
void nhap_sinh_vien(sinh_vien& a, int x, int y);
void nhap_ds_sinh_vien(ds_sinh_vien& l, int x, int y);
void xuat_ds_sinh_vien(ds_sinh_vien l);
void doc_ds_mon_hoc_tu_file(hoc_ki h,nam_hoc  b,ds_mon_hoc& l);
void xuat_ds_mon_hoc(ds_mon_hoc l, int x ,int y );
void xoa_dau_cach(char a[]);
void nhap_hoc_ki(hoc_ki& h, int x, int y);
void nhap_mon_hoc(mon_hoc& a, int x, int y);
void doc_ds_hoc_ki_tu_file(hoc_ki*& arr, nam_hoc a, int& sl);
void ghi_1_hoc_ki_vao_file(hoc_ki h, nam_hoc a);
void xuat_ds_hoc_ki(hoc_ki* a, int n, int x, int y);
void xuat_hoc_ki(hoc_ki h, int x , int y );
void make_link(char a[]);
void cap_phat_them_nam_hoc(nam_hoc*& a, int& sz);
void nd_nam_hoc(nam_hoc*& a, int sl, int x, int y);
bool kiem_tra_file_empty(char ten_file[]);
void nd_hoc_ki(hoc_ki*& a, int sl, int x, int y);
#endif 