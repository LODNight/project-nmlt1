#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "menu.h"
#include "DocGia/docGia.h"
#include "Sach/sach.h"
#include "Phieu/lapPhieu.h"

// Menu ChucNang
void menuChucNang(){
    int choice = -1;
    do{
        printf("\n----------------------------\n");
        printf("\n\n===== MENU CHUC NANG =====\n");
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
    }while(choice != 0);
    
}

// Nạp thông tin
void napThongTin(){
    napDuLieuDGMau();
    napDuLieuSachMau();
    napMauThongTinPhieuMuon();
    napMauThongTinPhieuTra();
}

// Menu lựa chọn Đọc Giả
void chucNangDocGia(){
    int choice = -1;
    char timCMND[20];
    char timTenDG[40];
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
            inThongTinToanBoDocGia(); break;
        case 2: 
            // Thêm Thông tin Đọc Giả
            themThongTinDocGia(); 
            
            inThongTinToanBoDocGia();
            break;
        case 3: 
            // Sửa Thông tin Đọc Giả
            inThongTinToanBoDocGia();
            printf("Nhap So CMND: ");
            scanf("%s", timCMND);
            suaThongTinDocGia(timCMND);
            inThongTinToanBoDocGia();
            break;
        case 4:
            // Xóa Đọc Giả
            inThongTinToanBoDocGia();
            printf("Nhap So CMND: ");
            scanf("%s", timCMND);
            xoaDGTheoCMND(timCMND);
            inThongTinToanBoDocGia();
            break;
        case 5:
            // Tìm Kiếm Đọc Giả theo CMND
            printf("Nhap So CMND: ");
            scanf("%s", timCMND);
            inThongTinDocGiaSauKhiTimTheoCMND(timCMND);
            break;
        case 6:
            // Tim Doc Gia theo ten Doc Gia
            printf("Nhap ten Doc Gia: ");
            scanf("%s", timTenDG);
            printf("Ma DG |    ho va ten    |    cmnd    |         email        | gioi tinh |     dia chi       |  ngay lap  | ngay het han" );
            timDocGiaTheoTen(timTenDG);
            break;

        case 0:
            printf("\n>>> Quay ve Menu Chinh <<<\n\n");
            return;
        default:
            printf("\n>>> LOI: Vui long chon lai <<<\n"); break;
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
                
                inThongTinSachSauKhiTimThayISBNv1(timISBN);
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
                
                inThongTinSachSauKhiTimThayTen(timTenSach);
                choice = -1;
                break;
            case 0:
                printf("\n>>> Quay ve Menu Chinh <<<\n\n");
                return;
            default:
                printf("\n>>> LOI: Vui long chon lai <<<\n"); 
                break;
        }
    }while(choice!=0);
}

// Menu Xu ly chuc nang Phieu Muon Sach
void chucNangPhieuMuon(){
    int choice = -1;
    char maPhieuMuon[7];
    char timISBN[5];
    char timCMND[20];
    char timMaDG[20];
    do{
        printf("\n\n===== PHIEU MUON SACH =====\n");
        printf("1: Xem toan bo phieu muon\n");
        printf("2: Tim Sach theo ma Doc Gia\n");
        printf("3: Tim Doc Gia theo ISBN Sach\n");
        printf("4: Them phieu muon\n");
        printf("5: Chinh sua phieu muon\n");
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
                // Tìm Sách theo CMND Đọc Giả
                printf("Nhap So CMND: ");
                scanf("%s", timCMND);
                timMaDocGiaTheoCMND(timCMND,timMaDG);
                if(strcmp(timMaDG,"NULL") != 0)
                    inThongTinSachTheoDocGia(timMaDG);
                choice = -1;
                break;
            case 3: 
                // Tìm Đọc Giả theo mã ISBN
                printf("Nhap ma ISBN: ");
                getchar();
                fgets(timISBN,20, stdin);
                timISBN[strcspn(timISBN,"\n")] = '\0';
                inThongTinDocGiaTheoISBN(timISBN);
                choice = -1;
                break;

            case 4: 
                // Thêm Phiếu mượn
                printf("\n++++ Them Phieu muon ++++\n");
                themThongTinPhieuMuon();
                break;

            case 5:
                // Chỉnh sửa Phiếu mượn
                printf("\n++++ Chinh sua Phieu muon ++++\n");
                
                inThongTinToanBoPhieuMuon();

                printf("\nNhap ma Phieu muon: ");
                getchar();
                fgets(maPhieuMuon,7,stdin);
                
                suaThongTinPhieuMuon(maPhieuMuon);
                
                choice = -1;

                break;
            case 0:
                printf("\n>>> Quay ve Menu Chinh <<<\n\n");
                return;
            default:
                printf("\n>>> LOI: Vui long chon lai <<<\n"); 
                break;
        }
    }while(choice!=0);
}

// Menu Xu ly chuc nang Phieu Tra Sach
void chucNangPhieuTra(){
    int choice = -1;
    char timCMND[20];
    do{
        printf("\n\n===== PHIEU TRA SACH =====\n");
        printf("1: Them phieu tra Sach\n");
        printf("2: Xem toan bo phieu tra Sach\n");
        printf("3: Xem thong tin phieu tra Sach\n");
        printf("0: Thoat\n");
        printf("=================================\n");
        printf("Chon chuc nang: ");
        scanf("%d",&choice);
        
         switch (choice)
        {
            case 1:
                // them Thong tin Phieu Tra Sach
                themPhieuTraSach();

                break;
            case 2:
                inToanBoThongTinPhieuTra();
                break;
            case 3:
                // Tim phieu muon theo CMND
                printf("Nhap CMND: ");
                scanf("%s",timCMND);

                timPhieuMuonTheoCMND(timCMND);
                break;
            default:
                break;
        }
    } while(choice!=0);
    
}

// Menu Xu ly chuc nang Thong Ke
void chucNangThongKe(){
    int choice = -1;
    char timCMND[20];
    do{
        printf("\n\n===== THONG KE CO BAN =====\n");
        printf("1: Thong ke so luong sach trong thu vien\n");
        printf("2: Thong ke so luong sach theo the loai\n");
        printf("3: Thong ke so luong doc gia\n");
        printf("4: Thong ke so luong doc gia theo gioi tinh\n");
        printf("5: Thong ke so sach dang duoc muon\n");
        printf("6: Thong ke danh sach doc gia bi tre han\n");
        printf("0: Thoat\n");
        printf("=================================\n");
        printf("Chon chuc nang: ");
        scanf("%d",&choice);
        
         switch (choice)
        {
            case 1:
                // Thong ke so luong sach trong thu vien
                inTongSoLuongSach();
                break;
            case 2:
                // Thong ke so luong sach theo the loai
                inTongSoLuongSachTheoTheLoai();
                break;
            case 3:
                // Thong ke so luong doc gia
                inTongSoLuongDocGia();
                break;
            case 4:
                // Thong ke so luong doc gia theo gioi tinh
                inTongSoLuongDocGiaTheoGioiTinh();
                break;
            case 5:
                // Thong ke so sach dang duoc muon
                inSoLuongSachMuon();
                break;
            case 6:
                // Thong ke danh sach doc gia bi tre han
                thongKeDanhSachDocGiaTreHan();
                break;
            default:
                break;
        }
    }while(choice != 0);
}

