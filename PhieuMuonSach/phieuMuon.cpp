#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// #include "../DocGia/docgia.h"
// #include "../DocGia/docgia.cpp"
#include "../Sach/sach.h"

#define MAX 200

// Thong Tin Phieu Muon
char maPhieuMuon[MAX][7];
char maDGMuon[MAX][7];
char maISBNMuon[MAX][5];
char soluongSachMuon[MAX][5];
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

    strncpy(soluongSachMuon[0], "2", sizeof(soluongSachMuon[0])-1);
    strncpy(soluongSachMuon[1], "5", sizeof(soluongSachMuon[1])-1);
    strncpy(soluongSachMuon[2], "6", sizeof(soluongSachMuon[2])-1);

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
        printf("%4s | %4s | %4s | %5s | %10s | %10d \n",
        maPhieuMuon[i], maDGMuon[i], maISBNMuon[i], soluongSachMuon[i], ngayMuonSach[i], ngayTraSachDuKien[i]);
    }
    printf("\n----------------------------------\n");
}

// In Thong tin toan bo Sach theo nguoi muon
void inThongTinSachTheoDocGia(char maDGCanTim[]){
    for(int i=0; i<tongPhieuMuon; i++){
        if(strstr(maDGMuon[i],maDGCanTim) != NULL){
            inThongTinSachv2(i);
        }
    }
}

// In thong tin toan bo nguoi muon dua theo ISBN

// Them thong phieu muon

// Thay doi thong tin


