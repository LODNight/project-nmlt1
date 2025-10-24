#pragma once

void napDuLieuSachMau();

// In Thong Tin Sach
void inThongTinToanBoSach();
void inThongTinSachv1(int i);
void inThongTinSachv2(int i);

// Them Sach
void themThongTinSach();
void themTenSach(int vitri);
void themTenTacGia(int vitri);
void themNhaXuatBan(int vitri);
void themNamXuatBan(int vitri);
void themTheLoai(int vitri);
void themGiaSach(int vitri);
void themSoLuongSach(int vitri);

// Chinh sua Sach
void chinhSuaSach(char timISBN[]);
// Xoa Sach
void xoaSach(char timISBN[]);

// Tim kiem Sach
int timSachTheoISBN(char timISBN[]);
int timSachTheoTen(char timSach[]);