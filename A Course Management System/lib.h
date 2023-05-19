#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include"lib1.h"
#include"do_hoa.h"
using namespace std;
struct tai_khoan
{
	char ms[100];
	char ho_ten[100];
	char user[100];
	char key[100];
};
typedef struct tai_khoan tai_khoan;
struct node
{
	tai_khoan data;
	node* next;
};
struct list_log_in
{
	node* head;
};
void option_sinh_vien(tai_khoan temp, list_log_in l, int x , int y);
void option_giao_vien(tai_khoan& temp, list_log_in l, int x, int y);
void dk(int x, int y, char tf[]);
bool dn(list_log_in l, int x, int y, char tf[], tai_khoan& temp);
void noi_dung1(int x, int y);
void noi_dung2(int x , int y);
int click_dn_dk(int x, int y, int sl);
int click_sv_gv(int x, int y, int sl);
void bieu_tuong_click(int x, int y, int w);
void xoa_bieu_tuong_click(int x, int y, int w);
void khoi_tao(list_log_in& l);
node* tao_node_log_in(tai_khoan a);
void doc_file(char ten_file[], list_log_in& l);
void addlast_log_in(list_log_in& l, node* p);
void xuat(tai_khoan a);
void xuat_so_node(list_log_in l);
void clearn(list_log_in& l);
void log_in(list_log_in& l, tai_khoan& infor, int x, int y);
void reset_key(list_log_in& l, tai_khoan& a, char ten_file[], int x ,int y);
void nd_sv(int x, int y, tai_khoan temp);

void nd_gv(int x, int y, tai_khoan temp);
void ghi_file_tai_khoan(list_log_in l, char tf[]);
void xoa_xuong_dong(char a[]);
int click(int x, int y, int sl);