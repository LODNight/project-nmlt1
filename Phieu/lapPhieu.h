#pragma once

#ifndef LAPPHIEU_H
#define LAPPHIEU_H
// ===============================================
//   MODULE: Quản lý Phiếu Mượn / Phiếu Trả Sách
//   Mục đích: xử lý thao tác mượn - trả, ngày tháng,
//   thống kê, và phạt trễ hạn.
// ===============================================


// ====== [PHIẾU MƯỢN SÁCH] ======

// --- Nạp dữ liệu mẫu (demo)
void napMauThongTinPhieuMuon();
void napMauThongTinPhieuTra();

// --- In thông tin Phiếu mượn
void inThongTinToanBoPhieuMuon();     // In toàn bộ danh sách
void inThongTinPhieuMuonv1(int i);    // In chi tiết 1 phiếu
void inThongTinPhieuMuonv2(int i);    // In ngắn gọn 1 phiếu

// --- In thông tin theo người mượn hoặc ISBN
void inThongTinSachTheoDocGia(char maDGTim[]);
void inThongTinDocGiaTheoISBN(char maISBNTim[]);

// --- Thống kê số lượng sách đang được mượn
void inSoLuongSachMuon();

// --- Thêm, tìm, sửa Phiếu mượn
void themThongTinPhieuMuon();
int timPhieuMuonTheoMa(char timPhieuMuon[]);
void suaThongTinPhieuMuon(char timPhieuMuon[]);


// ====== [XỬ LÝ NGÀY THÁNG] ======
int chuyenThangSangSo(char *thang);                 // Chuyển "Jan" → 1
void themNgayMuonSachTuDong();                      // Auto ngày mượn
void themNgayTraDuKienTuDong(int d, int m, int y);  // Auto +7 ngày
void themNgayTraThucTeTuDong(int i);
void themNgayTraThucTeThuCong(int i);


// ====== [PHIẾU TRẢ SÁCH] ======
void inThongTinPhieuTra(int i);
void inToanBoThongTinPhieuTra();
void timPhieuMuonTheoCMND(char timCMND[]);
void themPhieuTraSach();


// ====== [XỬ LÝ HỖ TRỢ & THỐNG KÊ] ======
void tachNgay(char s[], int &d, int &m, int &y);
int tinhKhoangNgayDuKienVaThucTe(int d1,int m1,int y1,int d2,int m2,int y2);
int tinhSoNgayTre(char duKien[], char thucTe[]);
void thongKeDanhSachDocGiaTreHan();
#endif