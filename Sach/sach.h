#pragma once

void napDuLieuSachMau();
void inThongTinToanBoSach();

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