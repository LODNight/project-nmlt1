#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "lapPhieu.h"
#include "../DocGia/docGia.h"
#include "../Sach/sach.h"

#define MAX 200

// Thong Tin Phieu Muon
char maPhieuMuon[MAX][7];
char maDGMuon[MAX][7];
char maISBNMuon[MAX][5];
int soluongSachMuon[MAX][2];
char ngayMuonSach[MAX][20];
char ngayTraSachDuKien[MAX][20];
int tongPhieuMuon = 0;

char maPhieuTra[MAX][7];
char maDGTra[MAX][7];
char maISBNTra[MAX][5];
int soluongSachTra[MAX][2];
char ngayTraSachThucTe[MAX][20];
int tongPhieuTra = 0;

// ============= [PHIEU MUON SACH] =============
void napMauThongTinPhieuMuon(){
    tongPhieuMuon = 3;
    strncpy(maPhieuMuon[0], "PM0001", sizeof(maPhieuMuon[0])-1);
    strncpy(maPhieuMuon[1], "PM0002", sizeof(maPhieuMuon[1])-1);
    strncpy(maPhieuMuon[2], "PM0003", sizeof(maPhieuMuon[2])-1);

    strncpy(maDGMuon[0], "DG001", sizeof(maDGMuon[0])-1);
    strncpy(maDGMuon[1], "DG001", sizeof(maDGMuon[1])-1);
    strncpy(maDGMuon[2], "DG002", sizeof(maDGMuon[2])-1);

    strncpy(maISBNMuon[0], "S001", sizeof(maISBNMuon[0])-1);
    strncpy(maISBNMuon[1], "S003", sizeof(maISBNMuon[1])-1);
    strncpy(maISBNMuon[2], "S002", sizeof(maISBNMuon[2])-1);

    soluongSachMuon[0][1] = 1;
    soluongSachMuon[1][1] = 1;
    soluongSachMuon[2][1] = 2;

    strncpy(ngayMuonSach[0], "20/10/2024", sizeof(ngayMuonSach[0])-1);
    strncpy(ngayMuonSach[1], "20/10/2024", sizeof(ngayMuonSach[1])-1);
    strncpy(ngayMuonSach[2], "20/10/2024", sizeof(ngayMuonSach[2])-1);    
    
    strncpy(ngayTraSachDuKien[0], "24/10/2024", sizeof(ngayTraSachDuKien[0])-1);
    strncpy(ngayTraSachDuKien[1], "25/10/2024", sizeof(ngayTraSachDuKien[1])-1);
    strncpy(ngayTraSachDuKien[2], "25/10/2024", sizeof(ngayTraSachDuKien[2])-1);

    strncpy(ngayTraSachThucTe[2], "25/10/2024", sizeof(ngayTraSachThucTe[2])-1);
}

void napMauThongTinPhieuTra(){
    tongPhieuTra = 2;
    strncpy(maPhieuTra[0], "PT0001", sizeof(maPhieuTra[0])-1);
    strncpy(maPhieuTra[1], "PT0002", sizeof(maPhieuTra[1])-1);

    strncpy(maDGTra[0], "DG001", sizeof(maDGTra[0])-1);
    strncpy(maDGTra[1], "DG002", sizeof(maDGTra[1])-1);

    strncpy(maISBNTra[0], "S001", sizeof(maISBNTra[0])-1);
    strncpy(maISBNTra[1], "S003", sizeof(maISBNTra[1])-1);

    soluongSachTra[0][1] = 1;
    soluongSachTra[1][1] = 1;

    strncpy(ngayTraSachThucTe[0], "27/10/2024", sizeof(ngayTraSachThucTe[0])-1);
    strncpy(ngayTraSachThucTe[1], "29/10/2024", sizeof(ngayTraSachThucTe[1])-1);
    
}


// In Thong tin toan bo phieu muon
void inThongTinToanBoPhieuMuon(){
    printf("\n----------------------------------\n");
    printf("\n====== DANH SACH [PHIEU MUON] ======\n");
    if(tongPhieuMuon == 0){
        printf("\n>>> Chua co Phieu Muon <<<\n");
        return;
    }
    for(int i=0; i < tongPhieuMuon; i++){
        printf("%4s | %4s | %4s | %5d | %10s | %10s \n",
        maPhieuMuon[i], maDGMuon[i], maISBNMuon[i], soluongSachMuon[i][1], ngayMuonSach[i], ngayTraSachDuKien[i]);
    }
    printf("\n----------------------------------\n");
}

// In 1 Phieu Muon
void inThongTinPhieuMuonv1(int i){
    printf("\tMa Doc Gia:           | %s\n", maDGMuon[i]);
    printf("\tMa ISBN:              | %s\n", maISBNMuon[i]);
    printf("\tSo luong sach muon:   | %d\n", soluongSachMuon[i][1]);
    printf("\tNgay muon sach:       | %s\n", ngayMuonSach[i]);
    printf("\tNgay tra du kien:     | %s\n", ngayTraSachDuKien[i]);
    printf("\tNgay tra thuc te:     | %s\n", ngayTraSachThucTe[i]);
};

// In nhieu Phieu Muon
void inThongTinPhieuMuonv2(int i){
    printf("%5s | %5s | %3d | %12S | %12s | %12s",
    maDGMuon[i],maISBNMuon[i],soluongSachMuon[i][1],ngayMuonSach[i],ngayTraSachDuKien[i],ngayTraSachThucTe[i]);
}

// In Thong tin toan bo Sach theo nguoi muon
void inThongTinSachTheoDocGia(char maDGTim[]){
    // In thong tin Sach
    int slSach = 0;
    printf("\n+++ SACH +++\n");
    printf("\n----------------------------------\n");
    for(int i=0; i<tongPhieuMuon; i++){
        if(strstr(maDGMuon[i],maDGTim) != NULL){
            slSach++;
            inThongTinSachv2(i);
        }
    } 
    printf("\n----------------------------------\n");
    if(slSach <= 0){
        printf("\n>>> Khong tim thay sach <<<\n");
    }

}

// In thong tin toan bo nguoi muon dua theo ISBN
void inThongTinDocGiaTheoISBN(char maISBNTim[]){
    // In thong tin Sach
    int slDocGia = 0;
    printf("\n+++ THONG TIN DOC GIA MUON SACH +++\n");
    printf("\n----------------------------------\n");
    for(int i=0; i<tongPhieuMuon; i++){
        if(strstr(maISBNMuon[i],maISBNTim) != NULL){
            slDocGia++;
            inThongTinDocGiav2(i);
        }
    } 
    printf("\n----------------------------------\n");
    if(slDocGia <= 0){
        printf("\n>>> Khong tim thay Doc Gia muon <<<\n");
    }

}


// Them thong tin phieu muon
// maDG, ISBN, Sl Sach, Ngay muon, Ngay du kien tra, ngay tra thuc te
void themThongTinPhieuMuon(){
    if(tongPhieuMuon >= MAX){
        printf(">> Thu vien da day, khong the them phieu moi <<\n");
    }

    char timCMND[20];
    char timISBN[10];
    int vitriDocGia;
    int vitriSach;
    bool hopLe = false;
    printf("\n====== THEM PHIEU MUON SACH MOI ======\n");
    getchar();
    
    // Su dung CMND cua Doc Gia de them thong tin
    do{
        printf("Nhap CMND Doc Gia: ");
        fgets(timCMND, 20, stdin);
        timCMND[strcspn(timCMND,"\n")] = '\0';
        vitriDocGia = timDocGiaTheoCMND(timCMND);

        if(vitriDocGia >= 0){

            timMaDocGiaTheoCMND(timCMND,maDGMuon[tongPhieuMuon]);
            hopLe = true;
        }
        else
            printf("\n>>> Khong hop le. Vui long nhap lai <<<\n");
    } while(!hopLe);

    // Them ma ISBN
    hopLe = false;
    do{
        printf("Nhap ma sach(ISBN): ");
        fgets(timISBN, 10, stdin);
        timISBN[strcspn(timISBN,"\n")] = '\0';
        vitriSach = timSachTheoISBN(timISBN);
        if(vitriSach >= 0){
            strcpy(maISBNMuon[tongPhieuMuon],timISBN);
            hopLe = true;
        }
        else
            printf("\n>>> Khong hop le. Vui long nhap lai <<<\n");
    } while(!hopLe);
    
    // Them So luong Sach can muon
    int soLuong;
    int soluongSach = timSoLuongSachTheoISBN(timISBN); 
    hopLe = false;
    do {
        printf("Nhap so luong sach can muon: ");
        scanf("%d", &soLuong);
        if(soLuong < 0){
            printf(">>> So luong sach khong hop le <<<\n");
        } 
        else if(soLuong > soluongSach){
            printf(">>> Khong du sach <<<\n");
        } 
        else {
            if (soLuong > 0 && soLuong <= soluongSach) {
                soluongSachMuon[tongPhieuMuon][1]= soLuong;
                thayDoiSoLuongSach(timISBN, soLuong);
                break;
            }
        }
    } while (!hopLe);

    // Ngay muon - AUTO
    themNgayMuonSachTuDong();
    // Ngay tra du kien - AUTO

    
    // Them maPhieuMuon tang tu dong
    sprintf(maPhieuMuon[tongPhieuMuon],"PM%04d",tongPhieuMuon+1);
    
    // THONG BAO
    printf(">> Them Thanh Cong <<\n");
    tongPhieuMuon++;

}

// ------------------------------
// XU LY THOI GIAN

// Chuyen ten thang sang so
int chuyenThangSangSo(char *thang) {
    if (strcmp(thang, "Jan") == 0) return 1;
    if (strcmp(thang, "Feb") == 0) return 2;
    if (strcmp(thang, "Mar") == 0) return 3;
    if (strcmp(thang, "Apr") == 0) return 4;
    if (strcmp(thang, "May") == 0) return 5;
    if (strcmp(thang, "Jun") == 0) return 6;
    if (strcmp(thang, "Jul") == 0) return 7;
    if (strcmp(thang, "Aug") == 0) return 8;
    if (strcmp(thang, "Sep") == 0) return 9;
    if (strcmp(thang, "Oct") == 0) return 10;
    if (strcmp(thang, "Nov") == 0) return 11;
    if (strcmp(thang, "Dec") == 0) return 12;
    return 0;
}

// Them ngay muon tu dong
void themNgayMuonSachTuDong(){
    time_t now;
    // Lay ngya hien tai
    time(&now);
    char thoiGian[30];
    // chuyen thoi gian thanh chuoi
    strcpy(thoiGian,ctime(&now));

    char thang[4]; 
    char ngay[4];
    int d,y;

    sscanf(thoiGian,"%s %s %d %*s %d", ngay,thang,&d,&y);

    int m = chuyenThangSangSo(thang);

    if(!kiemTraNgayHopLe(d,m,y)){
        printf("\n>>> LOI: Ngay khong hop le <<<\n");
        return;
    }

    sprintf(ngayMuonSach[tongPhieuMuon], "%2d/%2d/%4d", d,m,y);
    themNgayTraDuKienTuDong(d,m,y);

}

// Them ngay tra du kien tu dong
void themNgayTraDuKienTuDong(int d, int m, int y){
    int d_new = d + 7;
    int m_new = m;
    int y_new = y;

    // Nếu vượt quá số ngày trong tháng
    int soNgayThang = timSoNgayTrongThang(m_new, y_new);
    if (d_new > soNgayThang) {
        d_new -= soNgayThang;
        m_new++;
        if (m_new > 12) {
            m_new = 1;
            y_new++;
        }
    }

    sprintf(ngayTraSachDuKien[tongPhieuMuon], "%2d/%2d/%4d", d_new,m_new,y_new);
}
// ------------------------------

// Thay doi thong tin
void suaThongTinPhieuMuon(char timPhieuMuon[]){
    int vitriPhieuMuon = timPhieuMuonTheoMa(timPhieuMuon);
    if(vitriPhieuMuon < 0)
        printf("\n>>> Khong tim thay Phieu Muon <<<\n");
    else{
        char timCMND[20];
        char cmndMuon[12];
        bool hopLe = false;
        
        int soLuong;
        int soluongSach = timSoLuongSachTheoISBN(maISBNMuon[vitriPhieuMuon]); 

        printf("\n====== CHINH SUA PHIEU MUON SACH ======\n");
        getchar();  

        // ---------------------
        // Kiem tra Doc Gia
        printf("\nMa Doc Gia hien tai: %s", maDGMuon[vitriPhieuMuon]);

        timCMNDDocGiaTheoMaDG(maDGMuon[vitriPhieuMuon], cmndMuon); 
        printf("\nCMND Doc Gia:  | %s", cmndMuon);
        printf("\nISBN:          | %s",maISBNMuon);
        printf("\nTen Sach:      | %s");
        printf("\nSo luong Sach: | %d",soluongSachMuon[vitriPhieuMuon][1]);
        printf("\nSo luong Sach con lai: %d",soluongSach);

        // ---------------------
        // Kiem Tra So Luong Sach

        printf("\n---- Chinh sua so luong Sach muon ----\n");

        hopLe = false;
        do {
            printf("Nhap so luong sach can muon: ");
            scanf("%d", &soLuong);
            if(soLuong < 0){
                printf(">>> So luong sach khong hop le <<<\n");
            } 
            else if(soLuong > soluongSach){
                printf(">>> Khong du sach <<<\n");
            } 
            else {
                if (soLuong > 0 && soLuong <= soluongSach) {
                    soluongSachMuon[vitriPhieuMuon][1] = soLuong;
                    thayDoiSoLuongSach(maISBNMuon[vitriPhieuMuon], soLuong);
                    hopLe = true;
                    break;
                }
            }
        } while (!hopLe);

        if(hopLe){
            printf("\n>>> Chinh sua so luong Sach thanh cong <<<\n");
        } 
        else {
            printf("\n>>> Chinh sua That bai <<<\n");
        }
    }
}

// Tim Phieu Muon theo MaPhieuMuon   return vitri
int timPhieuMuonTheoMa(char timPhieuMuon[]){
    int vitriPhieuMuon = -1;
    for(int i=0; i<tongPhieuMuon; i++){
        if(strcmp(maPhieuMuon[i],timPhieuMuon) == 0){
            return i;
        }
    }
    return -1;
}

// In thong tin Phieu Muon theo maPhieuMuon
void inThongTinPhieuMuonKhiTimThayMa(char timPhieuMuon[]){
    int vitriPhieuMuon = timDocGiaTheoCMND(timPhieuMuon);
    if(vitriPhieuMuon >= 0){
        printf("\n>> Tim Thay Phieu Muon <<\n");
        printf("------------------------------------------\n");
        inThongTinPhieuMuonv1(vitriPhieuMuon);
        printf("------------------------------------------\n");
    }
    if(vitriPhieuMuon < 0) 
        printf("\n>> Khong tim thay Phieu Muon <<\n");
}


// ============= [PHIEU TRA SACH] =============

// In nhieu Phieu Tra
void inThongTinPhieuTra(int i){
    printf("%5s | %5s | %3d | %12s\n",
    maDGTra[i],maISBNTra[i],soluongSachTra[i][1],ngayTraSachThucTe[i]);
}

// In toan bo thong tin Phieu Tra
void inToanBoThongTinPhieuTra(){
    printf("\n----------------------------------\n");
    printf("\n====== DANH SACH [PHIEU TRA] ======\n");
    if(tongPhieuTra == 0){
        printf("\n>>> Chua co Phieu Tra <<<\n");
        return;
    }
    for(int i=0; i<tongPhieuTra; i++){
        inThongTinPhieuTra(i);
    }
    printf("\n----------------------------------\n");

}

// Tim phieu muon theo CMND
void timPhieuMuonTheoCMND(char timCMND[]){
    // Chuyen doi tu CMND sang MaDG
    char maDGCanTim[10];
    timMaDocGiaTheoCMND(timCMND,maDGCanTim);

    if (strcmp(maDGCanTim, "NULL") == 0) {
        printf("\n>>> Khong tim thay doc gia <<<\n");
        return;
    }

    // tim Phieu Muon theo MaDG
    int dem = 0;
    for(int i=0; i<tongPhieuMuon; i++){
        if(strcmp(maDGMuon[i],maDGCanTim) == 0){
            inThongTinPhieuMuonv2(i);
            dem++;
        }
    }

    if(dem == 0)
        printf("\n>>> Doc gia chua co phieu <<<\n");
}

// them phieu Tra Sach thuc te
void themPhieuTraSach(){
    char maDGTra [20];
    int matSach;
    int hopLe = -1;
    printf("\nNhap CMND cua doc gia can tra sach:");
    scanf("%s",maDGTra);

    
    int i = 0; // timPhieuMuonTheoCMND

    do{
        printf("Sach co bi mat khong? (1:Co / 0:Khong): ");
        scanf("%d",&matSach);
        if(matSach == 1){
            printf(">>> Mat sach paht 200% <<<\n");
            hopLe = 1;
        } 
        else if (matSach == 0)
        {
            printf(">>> Khong mat sach <<<\n");
            hopLe = 1;
        }
        else {
            printf("\n>>> LOI: Khong hop le. Vui long thu lai <<<\n");
        }
        
    } while(hopLe < 0);
   


}
