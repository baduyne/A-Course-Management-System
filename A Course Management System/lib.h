#pragma once
#include"lib1.h"
#include"lib2.h"
#include"all_struct.h"
#include"graphic.h"
#include<direct.h>
using namespace std;

void log_in(ds_tai_khoan& l, tai_khoan& infor, int x, int y);
void option_teacher(tai_khoan& temp, ds_tai_khoan l, int x, int y);
void option_student(tai_khoan temp, ds_tai_khoan l, int x, int y);
void  nd_sv(int x, int y, tai_khoan temp);
void nd_gv(int x, int y, tai_khoan temp);
void nd_hoc_ki(hoc_ki*& a, int sl, int x, int y);
void nd_khoa_hoc(int x, int y);
void nd_lop_hoc(int x, int y);
void nd_khoi_tao(int x, int y);
void nd_nhap_diem(int x, int y);
void nd_xem_diem_lop_hoc(int x, int y);
void nd_sua_khoa_hoc(int x, int y);
void noi_dung2(int x, int y);
void symbol_click(int x, int y, int w);
void remove_symbol_click(int x, int y, int w);
void noi_dung1(int x, int y);
void dk(int x, int y, char tf[]);
bool kt_trung_tai_khoan(ds_tai_khoan l, tai_khoan a);
void khoi_tao(ds_tai_khoan& l);
node* tao_node_log_in(tai_khoan a);
void addlast_log_in(ds_tai_khoan& l, node* p);
void xuat(tai_khoan a);
void xuat_ds(ds_tai_khoan l);
void doc_file(char ten_file[], ds_tai_khoan& l);
bool dn(ds_tai_khoan l, int x, int y, char tf[], tai_khoan& temp);
void xoa_xuong_dong(char a[]);
void xoa_dau_phay(char a[]);
void make_address(char a[]);
void delete_file(char ten_file[]);
void reset_key(ds_tai_khoan& l, tai_khoan& a, char ten_file[], int x, int y);
void xuat_so_node(ds_tai_khoan l);
void clearn(ds_tai_khoan& l);
int click(int x, int y, int sl, int w);
void infor(int x, int y, tai_khoan a);
void make_link(char a[]);
bool create_folder(char ten_file[]);
bool check_empty_file(char ten_file[]);
void func_khoi_tao(int x, int y, int  cl);
char* gender(int x, int y);
void in_hoa_chu_dau(char a[]);
char* ngay_hoc_trong_tuan(int x, int y);
char* ca_hoc_trong_ngay(int x, int y);
void ghi_file_tai_khoan(ds_tai_khoan l, char tf[]);