#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "../DocGia/docgia.h"
#include "../Sach/sach.h"

#define MAX 200

// Thong Tin Phieu Muon
char maPhieuMuon[MAX][7];
char maDGMuon[MAX][7];
char maISBNMuon[MAX][5];
int soluongSachMuon[MAX][5];
char ngayMuonSach[MAX][20];
char ngayTraSachDuKien[MAX][20];
char ngayTraSachThucTe[MAX][20];
int tongPhieuMuon = 0;

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

// In Thong tin toan bo phieu muon
void inThongTinToanBoPhieuMuon(){
    printf("\n----------------------------------\n");
    printf("\n====== DANH SACH [PHIEU MUON] ======\n");
    if(tongPhieuMuon == 0){
        printf("\n>>> Chua co Phieu Muon <<<\n");
        return;
    }
    for(int i=0; i < tongPhieuMuon; i++){
        printf("%4s | %4s | %4s | %5s | %10s | %10s \n",
        maPhieuMuon[i], maDGMuon[i], maISBNMuon[i], soluongSachMuon[i], ngayMuonSach[i], ngayTraSachDuKien[i]);
    }
    printf("\n----------------------------------\n");
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
    bool hopLe = false;
    printf("\n====== THEM PHIEU MUON SACH MOI ======\n");
    getchar();
    
    // Su dung CMND cua Doc Gia de them thong tin
    do{
        printf("Nhap CMND Doc Gia: ");
        fgets(timCMND, 20, stdin);
        timCMND[strcspn(timCMND,"\n")] = '\0';
        int vitriDocGia = timDocGiaTheoCMND(timCMND);

        if(vitriDocGia >= 0){

            timMaDocGiaTheoCMND(timCMND,maDGMuon[tongPhieuMuon]);
            hopLe = true;
        }
        else
            printf("\n>>> Khong hop le. Vui long nhap lai <<<\n");
    } while(!hopLe);
    hopLe = false;
    do{
        printf("Nhap ma sach(ISBN): ");
        fgets(timISBN, 10, stdin);
        timISBN[strcspn(timISBN,"\n")] = '\0';
        int vitriSach = timSachTheoISBN(timISBN);
        if(vitriSach >= 0){
            strcpy(maISBNMuon[tongPhieuMuon],timISBN);
            hopLe = true;
        }
        else
            printf("\n>>> Khong hop le. Vui long nhap lai <<<\n");
    } while(!hopLe);
    
    
    printf("\n----- ma DG: %s --- ma ISBN: %s -----\n", maDGMuon[tongPhieuMuon],maISBNMuon[tongPhieuMuon]);
    printf("Nhap SL Sach can muonL: ");
    // Ngay muon - AUTO
    // Ngay tra du kien - AUTO

}


// Thay doi thong tin


