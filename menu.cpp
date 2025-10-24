#include <stdio.h>
#include <stdbool.h>
#include "DocGia/docgia.h"
#include "DocGia/docgia.cpp"
#include "Sach/sach.h"
#include "Sach/sach.cpp"
#include "PhieuMuonSach/phieuMuon.h"
#include "PhieuMuonSach/phieuMuon.cpp"
#include "PhieuTraSach/phieuTra.h"
#include "PhieuTraSach/phieuTra.cpp"



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
    napMauThongTinPhieuMuon();
}

// Menu lựa chọn Đọc Giả
void chucNangDocGia(){
    int choice = -1;
    char timCMND[20];
    do{
        printf("\n\n===== QUAN LY DOC GIA =====\n");
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
            themThongTinDocGia(); 
            xemThongTinToanBoDocGia();
            break;
        case 3: 
            // Sửa Thông tin Đọc Giả
            xemThongTinToanBoDocGia();
            printf("Nhap So CMND: ");
            scanf("%s", timCMND);
            suaThongTinDocGia(timCMND);
            xemThongTinToanBoDocGia();
            break;
        case 4:
            // Xóa Đọc Giả
            xemThongTinToanBoDocGia();
            printf("Nhap So CMND: ");
            scanf("%s", timCMND);
            xoaDGTheoCMND(timCMND);
            xemThongTinToanBoDocGia();
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
    } while(choice != 0);
}


// Menu lựa chọn Đọc Giả
void chucNangSach(){
    int choice = -1;
    char timISBN[5];
    do{
        printf("\n\n===== QUAN LY SACH =====\n");
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
                inThongTinToanBoSach();;
                break;
            case 3: 
                // Sửa Thông tin Sách
                getchar();
                inThongTinToanBoSach();
                printf("\nNhap ISBN can tim: ");
                fgets(timISBN, 5, stdin);
                timISBN[strcspn(timISBN,"\n")] = '\0';

                chinhSuaSach(timISBN);
                inThongTinToanBoSach();
                choice = -1;
                break;
            case 4:
                // Xóa Sách
                getchar();
                inThongTinToanBoSach();
                printf("\nNhap ISBN can tim: ");
                fgets(timISBN, 5, stdin);
                timISBN[strcspn(timISBN,"\n")] = '\0';

                xoaSach(timISBN);
                inThongTinToanBoSach();
                choice = -1;
                break;
            case 5:
                // Tìm Kiếm Sách theo ISBN
                printf("\n>>> Tim sach theo ISBN <<<\n");
                getchar();
                printf("Nhap ISBN can tim: ");
                fgets(timISBN, 5, stdin);
                timISBN[strcspn(timISBN,"\n")] = '\0';
                
                timSachTheoISBN(timISBN);
                choice = -1;
                break;
            case 6:
                char timTenSach[100];

                // Tìm kiếm Sách theo tên Sách
                printf("\n>>> Tim sach theo Ten <<<\n");
                getchar();
                printf("Nhap ten Sach can tim: ");
                fgets(timTenSach, 100, stdin);
                timTenSach[strcspn(timTenSach,"\n")] = '\0';
                
                timSachTheoTen(timTenSach);
                choice = -1;
                break;
            case 0:
                printf("\n>> Quay ve Menu Chinh <<\n");
                menuChucNang();
                break;
            default:
                printf("\n>> Vui long chon lai <<\n"); 
                break;
        }
    }while(choice!=0);
}

// Menu Xu ly chuc nang Phieu Muon Sach
void chucNangPhieuMuon(){
    int choice = -1;
    char timISBN[5];
    do{
        printf("\n\n===== PHIEU MUON SACH =====\n");
        printf("1: Xem toan bo phieu muon\n");
        printf("2: Tim Sach theo ma Doc Gia\n");
        printf("3: Tim Doc Gia theo ISBN Sach\n");
        printf("0: Thoat\n");
        printf("=================================\n");
        printf("Chon chuc nang: ");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1:
                // Xem toàn bộ thông tin Phieu Muon
                inThongTinToanBoPhieuMuon();
                break;
            case 2: 
                // Tìm Sách theo mã Đọc Giả
                inThongTinSachTheoDocGia("DG001");
                break;
            case 3: 
                // Tìm Đọc Giả theo mã ISBN
                
                break;
            case 0:
                printf("\n>> Quay ve Menu Chinh <<\n");
                menuChucNang();
                break;
            default:
                printf("\n>> Vui long chon lai <<\n"); 
                break;
        }
    }while(choice!=0);
}

// Menu Xu ly chuc nang Phieu Tra Sach
void chucNangPhieuTra(){
    printf("\n===== PHIEU TRA SACH =====\n");
}

// Menu Xu ly chuc nang Thong Ke
void chucNangThongKe(){
    printf("\n===== THONG KE CO BAN =====\n");

}