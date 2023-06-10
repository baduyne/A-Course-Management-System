#pragma once
#include"lib1.h"
#include"lib2.h"
#include"all_struct.h"
#include"graphic.h"
#include<direct.h>
using namespace std;

void option_student(tai_khoan temp, list_log_in l, int x , int y);
void option_teacher(tai_khoan& temp, list_log_in l, int x, int y);
void dk(int x, int y, char tf[]);
bool dn(list_log_in l, int x, int y, char tf[], tai_khoan& temp);
void noi_dung1(int x, int y);
void noi_dung2(int x , int y);
void symbol_click(int x, int y, int w);
void remove_symbol_click(int x, int y, int w);
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
void box(int x, int y, int sl, int w);
void nd_gv(int x, int y, tai_khoan temp);
void ghi_file_tai_khoan(list_log_in l, char tf[]);
void xoa_xuong_dong(char a[]);
int click(int x, int y, int sl, int w);
void infor(int x, int y, tai_khoan a);
bool create_folder(char ten_file[]);
void make_link(char a[]);
bool check_empty_file(char ten_file[]);
void xoa_dau_cach(char a[]);
void dk_khoa_hoc(int x, int y, tai_khoan temp);
bool check_ds_trong_lop(tai_khoan infor, nam_hoc a, hoc_ki b, khoa_hoc c);
void xem_khoa_hoc(ds_khoa_hoc& l, int x, int y, tai_khoan t);
void init_sinh_vien(sinh_vien& a);