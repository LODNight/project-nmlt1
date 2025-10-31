#pragma once


#ifndef SACH_H
#define SACH_H

// ============================
//  FILE: sach.h
//  Mô tả: Khai báo các hàm xử lý thông tin sách
//  Bao gồm: thêm, sửa, xóa, tìm kiếm, thống kê
// ============================

// Nạp dữ liệu mẫu
void napDuLieuSachMau();

// In Thong Tin Sach
void inThongTinToanBoSach();
void inThongTinSachv1(int i);
void inThongTinSachv2(int i);
void inThongTinSachv3(int i);
void inTongSoLuongSach();
void inTongSoLuongSachTheoTheLoai();
void inThongTinSachSauKhiTimThayISBNv1(char timISBN[]);
void inThongTinSachSauKhiTimThayISBNv2(char timISBN[]);
void inThongTinSachSauKhiTimThayTen(char timSach[]);

// Them Sach
void themThongTinSach();
void themTenSach(int vitri);
void themTenTacGia(int vitri);
void themNhaXuatBan(int vitri);
void themNamXuatBan(int vitri);
void themTheLoai(int vitri);
void themGiaSach(int vitri);
void themSoLuongSach(int vitri);

// Chinh sua toan bo Sach
void chinhSuaSach(char timISBN[]);
void thayDoiSoLuongSach(char timISBN[], int soLuong);

// Xoa Sach
void xoaSach(char timISBN[]);

// Tim kiem Sach
int timSachTheoISBN(char timISBN[]);
int timSachTheoTen(char timSach[]);
int timGiaSachSachTheoISBN(char timISBN[]);
int timSoLuongSachTheoISBN(char timISBN[]);

#endif