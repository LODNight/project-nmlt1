#pragma once

#ifndef MENU_H
#define MENU_H

// =================== MENU.H ===================
// Mô tả: Khai báo các hàm hiển thị menu chính của chương trình
// Gồm: menu chính, menu Độc Giả, menu Sách, menu Phiếu Mượn/Trả, Thống kê
// ==============================================

void menuChucNang();      // Menu chính của chương trình
void menuDocGia();        // Menu phụ (nếu có) cho Độc Giả
void chucNangDocGia();    // Xử lý chức năng độc giả
void chucNangSach();      // Xử lý chức năng sách
void chucNangPhieuMuon(); // Xử lý chức năng phiếu mượn
void chucNangPhieuTra();  // Xử lý chức năng phiếu trả
void chucNangThongKe();   // Xử lý thống kê
void napThongTin();       // Nạp dữ liệu mẫu ban đầu

#endif