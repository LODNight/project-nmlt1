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
// In nhieu Sach khong co so luong sach
void inThongTinSachv3(int i);
// Tong so luong Sach
void inTongSoLuongSach();
// Tong so luong Sach theo the loai Sach
void inTongSoLuongSachTheoTheLoai();
// ===========================
// In Thong tin Sach sau khi tim thay ma ISBN v1 (theo hang doc)
void inThongTinSachSauKhiTimThayISBNv1(char timISBN[]);
// In Thon tin Sach sau khi tim thay ma ISBN v2 (theo hang ngang)
void inThongTinSachSauKhiTimThayISBNv2(char timISBN[]);
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
// return vi tri sach
int timSachTheoISBN(char timISBN[]);

// ==========================
// Tim kiem Sach theo Ten Sach
// return vị tri ssch
int timSachTheoTen(char timSach[]);

// Tim gia Sach theo maSach
// return giaSach
int timGiaSachSachTheoISBN(char timISBN[]);

// ==========================
// Tim SL theo ISBN
// return slSach
int timSoLuongSachTheoISBN(char timISBN[]);

#endif