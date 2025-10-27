#pragma once

void napDuLieuDGMau();

// In du lieu
void inThongTinToanBoDocGia();
// In 1
void inThongTinDocGiav1(int i);
// In nhieu
void inThongTinDocGiav2(int i);

// =========================
// IN Thong tin Doc Gia sau khi tim theo ten
void inThongTinDocGiaSauKhiTimTheoTen(char maDGtim[]);
// =========================
// IN Thong tin Doc Gia sau khi tim theo CMND
void inThongTinDocGiaSauKhiTimTheoCMND(char maDGtim[]);


// Kiểm tra bắt lỗi
void kiemTraCMNDDocGia();
void kiemTraEmail();
bool kiemTraNgayHopLe(int d, int m, int y);
void kiemTraNgayLapThe();
void themNgayHetHanThe(int d, int m, int y);
void suaThongTinDocGia(char timCMND[]);
void xoaDGTheoCMND(char timCMND[]);

// ====================
// Tim theo CMND
// return vi tri
int timDocGiaTheoCMND(char timCMND[]);

// ====================
// Tim theo ten 
// return vi tri
int timDocGiaTheoTen(char tenDG[]);

// ====================
// Tim MaDG theo CMND
// return maDG
void timMaDocGiaTheoCMND(char timCMND[], char ketqua[]);

// Tim CMND theo maDG  
// return CMND
void timCMNDDocGiaTheoMaDG(char maDGtim[], char ketqua[]);
