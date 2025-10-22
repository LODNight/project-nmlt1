#pragma once

void themThongTinDocGia();
void xemThongTinToanBoDocGia();
void kiemTraCMNDDocGia();
void kiemTraEmail();
bool kiemTraNgayHopLe(int d, int m, int y);
void kiemTraNgayLapThe();
void themNgayHetHanThe(int d, int m, int y);
void suaThongTinDocGia(char timCMND[]);
void xoaDGTheoCMND(char timCMND[]);
// Tìm kiếm độc giả theo CMND 
int timDocGiaTheoCMND(char timCMND[]);
// Tìm kiếm sách theo họ tên 
int timSachTheoTenDocGia(char tenDG[]);