#pragma once


#ifndef DOCGIA_H
#define DOCGIA_H
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

void themThongTinDocGia();
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

// Kiem tra Ngay Them va Tra
int timNamNhuan(int y);
// Tim so ngay trong 1 thang
int timSoNgayTrongThang(int m, int y);
// Kiem tra ngay hop le
bool kiemTraNgayHopLe(int d, int m, int y);

// Hop le khi nam tu 2003 tro di
void kiemTraNgayLapThe();

// Het han sau 48 thang ke tu ngay lap the
void themNgayHetHanThe(int d, int m, int y);
#endif