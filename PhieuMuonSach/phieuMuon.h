#pragma once


// =======================
// Nạp dữ liệu mẫu
void napMauThongTinPhieuMuon();

// =======================
// In thông tin Sách theo Mã Đọc Giả
void inThongTinSachTheoDocGia(char maDGCanTim[]);

// In 1
void inThongTinPhieuMuonv1(int i);
// In nhieu
void inThongTinPhieuMuonv2(int i);

// In Thong tin toan bo Sach theo maDG
void inThongTinSachTheoDocGia(char maDGTim[]);
// In thong tin toan bo nguoi muon theo ISBN
void inThongTinDocGiaTheoISBN(char maISBNTim[]);

// =======================
// Thêm Phiếu Mượn
void themThongTinPhieuMuon();


// =======================
// Tim Phieu Muon theo MaPhieuMuon   return vitri
int timPhieuMuonTheoMa(char timPhieuMuon[]);


// =======================
// Thay doi thong tin Phieu Muon
void suaThongTinPhieuMuon(char timPhieuMuon[]);