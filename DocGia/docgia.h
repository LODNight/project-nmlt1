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

// Tìm kiếm Đoc giả theo CMND 
int timDocGiaTheoCMND(char timCMND[]);
// Tìm kiếm Đọc Giả theo tên 
int timDocGiaTheoTen(char tenDG[]);