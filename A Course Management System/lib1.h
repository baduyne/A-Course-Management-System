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
	char ten[50];
	char nien_khoa[50];
	char day_began[30];
	char day_end[30];
};
struct khoa_hoc
{
	char ma_khoa[20];
	char ten_khoa_hoc[50];
	char ten_lop_hoc[50];
	char ten_giao_vien[50];
	int so_tin_chi;
	int so_luong = 50;
	char ngay[30];
	char ca_hoc[30];
};
struct node_khoa_hoc
{
	khoa_hoc data;
	node_khoa_hoc* next;
};
struct ds_khoa_hoc
{
	node_khoa_hoc* head;
};
struct sinh_vien
{
	char ma_sinh_vien[10];
	char ho_ten[50];
	char gioi_tinh[10];
	char ngay_sinh[20];
	char cmnd[20];
	int diem=0;
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
	char ten[30];
};
void nhap_nam_hoc(nam_hoc& nh,int x, int y);
void ghi_1_nam_hoc_vao_file(nam_hoc a);
void cap_phat_them_nam_hoc(nam_hoc*& a, int& sz);
void doc_ds_nam_hoc_tu_file(nam_hoc*& arr, int& sl);
void init_ds_mh(ds_khoa_hoc& mh);
node_khoa_hoc* tao_node_mh(khoa_hoc a);
void addfirst(ds_khoa_hoc& mh, node_khoa_hoc* add);
void addlast_mh(ds_khoa_hoc& mh, node_khoa_hoc* add);
void init_ds_sinh_vien(ds_sinh_vien& mh);
node_sv* tao_node_sv(sinh_vien a);
bool nhap_sinh_vien_tu_file(ds_sinh_vien& l, char ten_file[]);
void make_address(char a[]);
void xoa_dau_phay(char a[]);
void addfirst_sv(ds_sinh_vien& mh, node_sv* add);
void ghi_ds_khoa_hoc(hoc_ki h, khoa_hoc a, nam_hoc b);
void addlast_sv(ds_sinh_vien& mh, node_sv* add);
void nhap_sinh_vien(sinh_vien& a, int x, int y);
void nhap_ds_sinh_vien(ds_sinh_vien& l, int x, int y);
void xuat_ds_sinh_vien(ds_sinh_vien l, int x, int y);
void doc_ds_khoa_hoc_tu_file(hoc_ki h,nam_hoc  b,ds_khoa_hoc& l);
void xoa_dau_cach(char a[]);
void nhap_hoc_ki(hoc_ki& h, int x, int y, nam_hoc a);
void nhap_khoa_hoc(khoa_hoc& a, int x, int y);
void doc_ds_hoc_ki_tu_file(hoc_ki*& arr, nam_hoc a, int& sl);
void ghi_1_hoc_ki_vao_file(hoc_ki h, nam_hoc a);
void xuat_ds_hoc_ki(hoc_ki* a, int n, int x, int y);
void xuat_hoc_ki(hoc_ki h, int x , int y );
void make_link(char a[]);
void cap_phat_them_nam_hoc(nam_hoc*& a, int& sz);
void nd_nam_hoc(nam_hoc*& a, int sl, int x, int y);
bool check_empty_file(char ten_file[]);
void nd_hoc_ki(hoc_ki*& a, int sl, int x, int y);
void nd_lop_hoc(int x, int y);
void ghi_1_sinh_vien_vao_file(nam_hoc a, hoc_ki b, khoa_hoc c, sinh_vien infor);
void xuat_ds_khoa_hoc(int x, int y, ds_khoa_hoc l);
int so_node_khoa_hoc(ds_khoa_hoc l);
void xuat_khoa_hoc_them_sv(int  x, int y, ds_khoa_hoc l);
khoa_hoc tim_khoa_hoc(ds_khoa_hoc l, int vt);
void draw_load(int x, int y, int w);
void doc_ds_sinh_vien(nam_hoc a, hoc_ki b, khoa_hoc c, ds_sinh_vien& l);
int  so_node_ds_sinh_vien(ds_sinh_vien l);
#endif 