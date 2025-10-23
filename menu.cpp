#include <stdio.h>
#include <stdbool.h>
#include "DocGia/docgia.h"
#include "DocGia/docgia.cpp"
#include "Sach/sach.h"
#include "Sach/sach.cpp"



// Menu ChucNang
void menuChucNang(){
    int choice;
    while(choice != 0){
        printf("\n===== MENU CHUC NANG =====\n");
        printf("1: Quan li Doc Gia\n");
        printf("2: Quan li Sach\n");
        printf("3: Lap phieu muon sach\n");
        printf("4: Lap phieu tra sach\n");
        printf("5: Thong ke\n");
        printf("0: Thoat\n");
        printf("=================================\n");
        printf("Chon chuc nang: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: 
            printf("\n>> Ban da chon: Quan li Doc Gia <<\n"); 
            chucNangDocGia();
            break;
        case 2: 
            printf("\n>> Ban da chon: Quan li Sach <<\n"); 
            chucNangSach();
            break;
        case 3: 
            printf("\n>> Ban da chon: Lap phieu muon sach <<\n"); 
            chucNangPhieuMuon();
            break;
        case 4: 
            printf("\n>> Ban da chon: Lap phieu tra sach <<\n"); 
            chucNangPhieuTra();
            break;
        case 5: 
            printf("\n>> Ban da chon: Thong ke co ban <<\n"); 
            chucNangThongKe();
            break;
        case 0:
            printf("\n>> Ban da chon thoat chuong trinh <<\n");
            break;
        default:
            printf("\n>> Lua chon khong hop le. Vui long nhap lai <<\n");
            break;
        }
    }
    
}

// Nạp thông tin
void napThongTin(){
    napDuLieuDGMau();
    napDuLieuSachMau();
}

// Menu lựa chọn Đọc Giả
void chucNangDocGia(){
    int choice;
    char timCMND[20];

    napDuLieuDGMau();

    while(choice != 0){
        printf("\n===== MENU QUAN LY DOC GIA =====\n");
        printf("1: Xem danh sach Doc Gia\n");
        printf("2: Them Doc Gia\n");
        printf("3: Chinh sua thong tin Doc Gia\n");
        printf("4: Xoa thong tin Doc Gia\n");
        printf("5: Tim kiem Doc Gia theo CMND\n");
        printf("6: Tim kiem Doc Gia theo ho ten\n");
        printf("0: Thoat\n");
        printf("=================================\n");
        printf("Chon chuc nang: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            // Xem Toàn bộ thông tin Đọc Giả
            xemThongTinToanBoDocGia(); break;
        case 2: 
            // Thêm Thông tin Đọc Giả
            themThongTinDocGia(); break;
        case 3: 
            // Sửa Thông tin Đọc Giả
            printf("Nhap So CMND: ");
            scanf("%s", timCMND);
            suaThongTinDocGia(timCMND);
            break;
        case 4:
            // Xóa Đọc Giả
            printf("Nhap So CMND: ");
            scanf("%s", timCMND);
            xoaDGTheoCMND(timCMND);
            break;
        case 5:
            // Tìm Kiếm Đọc Giả theo CMND
            printf("Nhap So CMND: ");
            scanf("%s", timCMND);
            timDocGiaTheoCMND(timCMND);
            break;
        case 6:
        case 0:
            printf("\n>> Quay ve Menu Chinh <<\n");
            menuChucNang();
            break;
        default:
            printf("\n>> Vui long chon lai <<\n"); break;
        }
    }    
}


// Menu lựa chọn Đọc Giả
void chucNangSach(){
    int choice;
    while(choice != 0){
        printf("\n===== MENU QUAN LY SACH =====\n");
        printf("1: Xem danh sach Sach\n");
        printf("2: Them Sach\n");
        printf("3: Chinh sua thong tin Sach\n");
        printf("4: Xoa thong tin Sach\n");
        printf("5: Tim kiem Sach theo ISBN\n");
        printf("6: Tim kiem Sach theo ten sach\n");
        printf("0: Thoat\n");
        printf("=================================\n");
        printf("Chon chuc nang: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                // Xem Toàn bộ thông tin Sách
                inThongTinToanBoSach();
                break;
            case 2: 
                // Thêm Thông tin Sách
                themThongTinSach();
                break;
            case 3: 
                // Sửa Thông tin Sách
                printf("Nhap ISBN: ");
                
                break;
            case 4:
                // Xóa Sách
                printf("Nhap ISBN: ");
                
                break;
            case 5:
                // Tìm Kiếm Sách theo ISBN
                printf("Nhap ISBN: ");
                
                break;
            case 6:
                // Tìm kiếm theo tên Sách
                printf("Nhap ISBN");

                break;
            case 0:
                printf("\n>> Quay ve Menu Chinh <<\n");
                break;
            default:
                printf("\n>> Vui long chon lai <<\n"); 
                break;
        }
    }
}

// Menu Xu ly chuc nang Phieu Muon Sach
void chucNangPhieuMuon(){
    printf("\n===== PHIEU MUON SACH =====\n");
}

// Menu Xu ly chuc nang Phieu Tra Sach
void chucNangPhieuTra(){
    printf("\n===== PHIEU TRA SACH =====\n");
}

// Menu Xu ly chuc nang Thong Ke
void chucNangThongKe(){
    printf("\n===== THONG KE CO BAN =====\n");

}