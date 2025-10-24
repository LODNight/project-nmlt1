#pragma once

void napDuLieuDGMau();

// In dữ liệu
void xemThongTinToanBoDocGia();
void inThongTinDocGiav1(int i);
void inThongTinDocGiav2(int i);

// Kiểm tra bắt lỗi
void kiemTraCMNDDocGia();
void kiemTraEmail();
bool kiemTraNgayHopLe(int d, int m, int y);
void kiemTraNgayLapThe();
void themNgayHetHanThe(int d, int m, int y);
void suaThongTinDocGia(char timCMND[]);
void xoaDGTheoCMND(char timCMND[]);

// Tìm theo CMND 
int timDocGiaTheoCMND(char timCMND[]);
// Tìm theo tên 
int timDocGiaTheoTen(char tenDG[]);
// Tim MaDG theo CMND
void timMaDocGiaTheoCMND(char timCMND[], char ketqua[]);