#pragma once


#ifndef DOCGIA_H
#define DOCGIA_H

// ============================
//  FILE: docGia.h
//  Mô tả: Khai báo các hàm xử lý thông tin độc giả
//  Bao gồm: thêm, xóa, sửa, tìm kiếm, thống kê và kiểm tra dữ liệu
// ============================

// --- Nạp dữ liệu mẫu ---
void napDuLieuDGMau();

// --- In dữ liệu ---
void inThongTinToanBoDocGia();
void inThongTinDocGiav1(int i);
void inThongTinDocGiav2(int i);
void inThongTinDocGiav3(int i);
void inThongTinDocGiaSauKhiTimTheoMaDG(char maDGtim[]);
void inThongTinDocGiaSauKhiTimTheoCMND(char timCMND[]);
void inThongTinDocGiaSauKhiTimTheoCMNDv2(char timCMND[]);
void inTongSoLuongDocGia();
void inTongSoLuongDocGiaTheoGioiTinh();

// --- Tìm kiếm ---
int timDocGiaTheoCMND(char timCMND[]);
void timDocGiaTheoTen(char tenDG[]);
void timMaDocGiaTheoCMND(char timCMND[], char ketqua[]);
void timCMNDDocGiaTheoMaDG(char maDGtim[], char ketqua[]);

// --- Thêm/Sửa/Xóa độc giả ---
void themThongTinDocGia();
void suaThongTinDocGia(char timCMND[]);
void xoaDGTheoCMND(char timCMND[]);

// --- Kiểm tra dữ liệu ---
void kiemTraCMNDDocGia();
void kiemTraEmail();
bool kiemTraNgayHopLe(int d, int m, int y);
void kiemTraNgayLapThe();
int timNamNhuan(int y);
int timSoNgayTrongThang(int m, int y);
bool kiemTraNgayHopLe(int d, int m, int y);
void kiemTraNgayLapThe();
void themNgayHetHanThe(int d, int m, int y);
#endif