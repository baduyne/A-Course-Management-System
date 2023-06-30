#pragma once
#include"lib.h"
#include"lib1.h"
#include"all_struct.h"
void xu_ly_lop_hoc(int x, int y);
void xu_ly_khoa_hoc( int x, int y);
bool nhap_diem_tu_file(ds_sinh_vien& ds_sv_kh, char ten_file[]);
void xem_diem(tai_khoan infor, int x, int y);
void sua_khoa_hoc(khoa_hoc &a, int x, int y, int cl);
void xem_diem_lop_hoc(nam_hoc a, hoc_ki b, lop_hoc c, int x, int y, int cl);