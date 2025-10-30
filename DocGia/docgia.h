#pragma once


#ifndef DOCGIA_H
#define DOCGIA_H

void napDuLieuDGMau();

// =========================
// In du lieu
void inThongTinToanBoDocGia();
// In 1 Doc gia theo hang doc
void inThongTinDocGiav1(int i);
// In nhieu Doc Gia theo hang ngang (madg, tendg, cmnd, email)
void inThongTinDocGiav2(int i);
// In nhieu Doc Gia voi toan bo thong tin theo hang ngang 
void inThongTinDocGiav3(int i);
// IN Thong tin Doc Gia sau khi tim theo ten
void inThongTinDocGiaSauKhiTimTheoTen(char maDGtim[]);
// IN Thong tin Doc Gia sau khi tim theo CMND
void inThongTinDocGiaSauKhiTimTheoCMND(char maDGtim[]);
// IN tong so luong Doc Gia
void inTongSoLuongDocGia();
// IN tong so luong Doc Gia theo gioi tinh
void inTongSoLuongDocGiaTheoGioiTinh();

// ====================
// Tim theo CMND
// return vi tri
int timDocGiaTheoCMND(char timCMND[]);
// ====================
// Tim theo ten 
// return vi tri
void timDocGiaTheoTen(char tenDG[]);
// ====================
// Tim MaDG theo CMND
// return maDG
void timMaDocGiaTheoCMND(char timCMND[], char ketqua[]);
// Tim CMND theo maDG  
// return CMND
void timCMNDDocGiaTheoMaDG(char maDGtim[], char ketqua[]);


// =========================
// Them thong tin Doc Gia
void themThongTinDocGia();
// Them ngay het han the
void themNgayHetHanThe(int d, int m, int y);

// =========================
// Sua thong tin Doc Gia
void suaThongTinDocGia(char timCMND[]);
// =========================
// Xoa Doc Gia
void xoaDGTheoCMND(char timCMND[]);


// =========================
// Kiểm tra CMND
void kiemTraCMNDDocGia();
// Kiểm tra Email
void kiemTraEmail();
// Kiểm tra Ngay hop le
bool kiemTraNgayHopLe(int d, int m, int y);
// Kiểm tra Ngay lap the
void kiemTraNgayLapThe();
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