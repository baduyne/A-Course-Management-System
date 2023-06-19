#pragma once
#include<iostream>
using namespace std;
struct tai_khoan
{
	char ms[10]="\0";
	char ho_ten[50] = "\0";
	char ngay_sinh[20] = "\0";
	char gioitinh[20] = "\0";
	char cccd[20] = "\0";
	char user[50] = "\0";
	char key[50] = "\0";
};
//typedef struct tai_khoan tai_khoan;
struct node
{
	tai_khoan data;
	node* next;
};
struct list_log_in
{
	node* head;
};
struct hoc_ki
{
	char ten[50] = "\0";
	char nien_khoa[50] = "\0";
	char day_began[30] = "\0";
	char day_end[30] = "\0";
};
struct lop_hoc
{
	char ten[30] = "\0";
	char khoa[50] = "\0";
	char k[10];
	int so_luong;
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
	char ma_sinh_vien[20];
	char ho_ten[50];
	char gioi_tinh[20];
	char ngay_sinh[20];
	char cmnd[20];
	float diemgk = 0;
	float diemck = 0;
	float dqt = 0;
	float dtb = 0;
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