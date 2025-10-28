#pragma once


#ifndef SACH_H
#define SACH_H
void napDuLieuSachMau();

// In Thong Tin Sach
void inThongTinToanBoSach();
// In Thong tin It Sach
void inThongTinSachv1(int i);
// In Thong tin Nhieu Sach
void inThongTinSachv2(int i);
// ===========================
// In Thon tin Sach sau khi tim thay ma ISBN
void inThongTinSachSauKhiTimThayISBN(char timISBN[]);
void inThongTinSachSauKhiTimThayTen(char timSach[]);

// ==========================
// Them Sach
void themThongTinSach();
void themTenSach(int vitri);
void themTenTacGia(int vitri);
void themNhaXuatBan(int vitri);
void themNamXuatBan(int vitri);
void themTheLoai(int vitri);
void themGiaSach(int vitri);
void themSoLuongSach(int vitri);

// ==========================
// Chinh sua toan bo Sach
void chinhSuaSach(char timISBN[]);

// Chinh sua So luong Sach
void thayDoiSoLuongSach(char timISBN[], int soLuong);
// ==========================
// Xoa Sach
void xoaSach(char timISBN[]);

// ==========================
// Tim kiem Sach
// return vị trí sách
int timSachTheoISBN(char timISBN[]);

// ==========================
// Tim kiem Sach theo Tên Sách
// return vị trí sách
int timSachTheoTen(char timSach[]);

// ==========================
// Tim SL theo ISBN
// return slSach
int timSoLuongSachTheoISBN(char timISBN[]);

#endif