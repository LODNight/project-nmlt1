#pragma once

void napDuLieuSachMau();

// In Thong Tin Sach
void inThongTinToanBoSach();
// In Thong tin It Sach
void inThongTinSachv1(int i);
// In Thong tin Nhieu Sach
void inThongTinSachv2(int i);
// ===========================
// In Thon tin Sach sau khi tim thay ma ISBN
void inThongTinSachSauKhiTim(char timISBN[]);

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
// Chinh sua Sach
void chinhSuaSach(char timISBN[]);
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