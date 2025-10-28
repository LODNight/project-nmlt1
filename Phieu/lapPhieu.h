#pragma once

#ifndef LAPPHIEU_H
#define LAPPHIEU_H
// ============= [PHIEU MUON SACH] =============
// --------------------------
// Nạp dữ liệu mẫu
void napMauThongTinPhieuMuon();
// --------------------------
// In thông tin Sách theo Mã Đọc Giả
void inThongTinSachTheoDocGia(char maDGCanTim[]);
// In Thong tin toan bo phieu muon
void inThongTinToanBoPhieuMuon();
// In 1
void inThongTinPhieuMuonv1(int i);
// In nhieu
void inThongTinPhieuMuonv2(int i);
// In Thong tin toan bo Sach theo maDG
void inThongTinSachTheoDocGia(char maDGTim[]);
// In thong tin toan bo nguoi muon theo ISBN
void inThongTinDocGiaTheoISBN(char maISBNTim[]);

// ----------------------------
// Thêm Phiếu Mượn
void themThongTinPhieuMuon();
// --------------------------
// Tim Phieu Muon theo MaPhieuMuon   return vitri
int timPhieuMuonTheoMa(char timPhieuMuon[]);
// --------------------------
// Thay doi thong tin Phieu Muon
void suaThongTinPhieuMuon(char timPhieuMuon[]);


// --------------------------
// Chuyen ten thang sang so
int chuyenThangSangSo(char *thang);
// Them ngay muon tu dong
void themNgayMuonSachTuDong();

// Them ngay tra du kien tu dong (7 days)
void themNgayTraDuKienTuDong(int d, int m, int y);
// --------------------------


// ============= [PHIEU TRA SACH] =============
// In thong tin

// Nhap CMND de kiem tra co muon sach chua tra khong => ngayTraSachThucTe = NULL

// Hien thi cac phieu muon dang con han

// Nhap ngay tra thuc te

// Tim so ngay nop tre -> phat 5000 1 ngay

// Kiem tra sach co mat hay khong => co: phat 200% tien sach

// Cap nhat du lieu

#endif