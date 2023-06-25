#pragma once
#include<iostream>
#include"graphic.h"
#include"all_struct.h"
#include"lib.h"
#include<fstream>
#include<iomanip>
using namespace std;

void init_ds_kh(ds_khoa_hoc& mh);
node_khoa_hoc* tao_node_mh(khoa_hoc a);
void addfirst(ds_khoa_hoc& mh, node_khoa_hoc* add);
void addlast_mh(ds_khoa_hoc& mh, node_khoa_hoc* add);
void nhap_hoc_ki(hoc_ki& h, int x, int y, nam_hoc a);
bool kt_hoc_ki(hoc_ki* arr, int sl, hoc_ki a);
void nhap_khoa_hoc(khoa_hoc& a, int x, int y);
void init_ds_sinh_vien(ds_sinh_vien& sv);
node_sv* tao_node_sv(sinh_vien a);
void addfirst_sv(ds_sinh_vien& mh, node_sv* add);
void addlast_sv(ds_sinh_vien& mh, node_sv* add);
void remove_node_sv(ds_sinh_vien& l, int pos);
void nhap_sinh_vien(sinh_vien& a, int x, int y);
bool nhap_sinh_vien_tu_file(ds_sinh_vien& l, char ten_file[]);
void nhap_ds_sinh_vien(ds_sinh_vien& l, int x, int y);
void xuat_ds_sinh_vien_lop_hoc(ds_sinh_vien l, int x, int y);
void xuat_ds_sinh_vien_khoa_hoc(ds_sinh_vien l, int x, int y);
void ghi_1_sinh_vien_vao_khoa_hoc(nam_hoc a, hoc_ki b, khoa_hoc c, sinh_vien infor, int pos);
void ghi_ds_sinh_vien_vao_khoa_hoc(nam_hoc a, hoc_ki b, khoa_hoc c, ds_sinh_vien infor);
void ghi_1_sinh_vien_vao_lop_hoc(nam_hoc a, lop_hoc  c, sinh_vien infor, int pos);
void ghi_ds_sinh_vien_vao_lop_hoc(nam_hoc a, lop_hoc c, ds_sinh_vien infor);
void nhap_lop_hoc(lop_hoc& a, int x, int y);
void cap_phat_them_lop_hoc(lop_hoc*& a, int& size);
void doc_ds_lop_hoc_tu_file(lop_hoc*& a, nam_hoc b, int& sl);
void xuat_lop_hoc(lop_hoc* a, int sl, int  x, int y);
void ghi_1_lop_hoc_vao_file(lop_hoc a, nam_hoc b, int pos);
void ghi_1_hoc_ki_vao_file(hoc_ki h, nam_hoc a);
void doc_ds_hoc_ki_tu_file(hoc_ki*& arr, nam_hoc a, int& sl);
void xuat_hoc_ki(hoc_ki h, int x, int y);
void xuat_ds_hoc_ki(hoc_ki* a, int n, int x, int y);
void ghi_1_khoa_hoc(hoc_ki h, khoa_hoc a, nam_hoc b, int pos);
void ghi_ds_khoa_hoc(hoc_ki h, ds_khoa_hoc a, nam_hoc b);
void doc_ds_khoa_hoc_tu_file(hoc_ki h, nam_hoc b, ds_khoa_hoc& l);
int so_node_khoa_hoc(ds_khoa_hoc l);
khoa_hoc tim_khoa_hoc(ds_khoa_hoc l, int vt);
void xuat_ds_khoa_hoc(int x, int y, ds_khoa_hoc l);
void remove_khoa_hoc(ds_khoa_hoc& kh, int pos);
void nhap_nam_hoc(nam_hoc& nh, int x, int y);
bool kt_nam_hoc(nam_hoc* a, int size, nam_hoc b);
void ghi_1_nam_hoc_vao_file(nam_hoc a);
void cap_phat_them_nam_hoc(nam_hoc*& a, int& sz);
void doc_ds_nam_hoc_tu_file(nam_hoc*& arr, int& size);
int  so_node_ds_sinh_vien(ds_sinh_vien l);
void doc_ds_sinh_vien_khoa_hoc(nam_hoc a, hoc_ki b, khoa_hoc c, ds_sinh_vien& l);
void doc_ds_sinh_vien_lop_hoc(nam_hoc a, lop_hoc  c, ds_sinh_vien& l);
void xuat_ds_nam_hoc(nam_hoc* a, int n, int x, int y);
void xuat_nam_hoc(nam_hoc*& a, int sl, int x, int y);
bool kt_trung_ca_khoa_hoc(ds_khoa_hoc l, khoa_hoc a);
bool doc_file_diem(ds_sinh_vien& l, char tf[]);
void tao_file_nhap_diem(nam_hoc a, hoc_ki b, khoa_hoc c, ds_sinh_vien l);
void kt_khoa_hoc_thuoc_lop_hoc(nam_hoc a, hoc_ki b, lop_hoc c, ds_khoa_hoc& l, int x, int y);
void dk_khoa_hoc(int x, int y, tai_khoan temp);
bool check_ds_trong_lop(tai_khoan infor, nam_hoc a, hoc_ki b, khoa_hoc c);
void xem_khoa_hoc_da_dk(nam_hoc a, hoc_ki b, ds_khoa_hoc& l, int x, int y, tai_khoan t);
