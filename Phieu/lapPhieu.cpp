#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "lapPhieu.h"
#include "../DocGia/docGia.h"
#include "../Sach/sach.h"

#define MAX 200

// ------------------ Biến toàn cục ------------------
// ------- [Phiếu Mượn] -------
char maPhieuMuon[MAX][7];
char maDGMuon[MAX][7];
char maISBNMuon[MAX][5];
int soluongSachMuon[MAX];
char ngayMuonSach[MAX][20];
char ngayTraSachDuKien[MAX][20];
int tongPhieuMuon = 0;

// ------- [Phiếu Trả] -------
char maPhieuTra[MAX][7];
char maDGTra[MAX][7];
char maISBNTra[MAX][5];
int soluongSachTra[MAX];
char ngayTraSachThucTe[MAX][20];
int sachBiMat[MAX];
int tongPhieuTra = 0;

// ============= [PHIEU MUON SACH] =============

// ------------------------------
// napMauThongTinPhieuMuon()
//  Chức năng: Nạp dữ liệu mẫu cho danh sách Phiếu mượn.
//  Tham số: null
//  Return: void
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

    soluongSachMuon[0] = 1;
    soluongSachMuon[1] = 1;
    soluongSachMuon[2] = 2;

    strncpy(ngayMuonSach[0], "20/9/2025", sizeof(ngayMuonSach[0])-1);
    strncpy(ngayMuonSach[1], "16/5/2025", sizeof(ngayMuonSach[1])-1);
    strncpy(ngayMuonSach[2], "04/10/2025", sizeof(ngayMuonSach[2])-1);    
    
    strncpy(ngayTraSachDuKien[0], "27/9/2025", sizeof(ngayTraSachDuKien[0])-1);
    strncpy(ngayTraSachDuKien[1], "23/5/2025", sizeof(ngayTraSachDuKien[1])-1);
    strncpy(ngayTraSachDuKien[2], "13/10/2025", sizeof(ngayTraSachDuKien[2])-1);

    strncpy(ngayTraSachThucTe[2], "25/10/2025", sizeof(ngayTraSachThucTe[2])-1);
}

// ------------------------------
// napMauThongTinPhieuTra()
//  Chức năng: Nạp dữ liệu mẫu cho danh sách Phiếu trả.
//  Tham số: null
//  Return: void
void napMauThongTinPhieuTra(){
    tongPhieuTra = 2;
    strncpy(maPhieuTra[0], "PT0001", sizeof(maPhieuTra[0])-1);
    strncpy(maPhieuTra[1], "PT0002", sizeof(maPhieuTra[1])-1);

    strncpy(maDGTra[0], "DG001", sizeof(maDGTra[0])-1);
    strncpy(maDGTra[1], "DG002", sizeof(maDGTra[1])-1);

    strncpy(maISBNTra[0], "S001", sizeof(maISBNTra[0])-1);
    strncpy(maISBNTra[1], "S003", sizeof(maISBNTra[1])-1);

    soluongSachTra[0] = 1;
    soluongSachTra[1] = 1;    
}

// ------------------------------
// inThongTinToanBoPhieuMuon()
//  Chức năng: In toàn bộ danh sách phiếu mượn sách.
//  Tham số: null
//  Return: void
void inThongTinToanBoPhieuMuon(){
    printf("\n----------------------------------\n");
    printf("\n====== DANH SACH [PHIEU MUON] ======\n");
    if(tongPhieuMuon == 0){
        printf("\n>>> Chua co Phieu Muon <<<\n");
        return;
    }
    printf("  ma   | ma DG | ma Sach |  SL   | Ngay muon | Ngay tra du kien | Ngay tra thuc te\n");
    for(int i=0; i < tongPhieuMuon; i++){
        printf("%6s | %5s | %5s   | %5d | %10s | %13s | %13s \n",
        maPhieuMuon[i], maDGMuon[i], maISBNMuon[i], soluongSachMuon[i], ngayMuonSach[i], ngayTraSachDuKien[i],ngayTraSachThucTe[i]);
    }
    printf("\n----------------------------------\n");
}

// ------------------------------
// inThongTinPhieuMuonv1()
//  Chức năng: In chi tiết thông tin 1 phiếu mượn theo dạng cột.
//  Tham số: i - vị trí phiếu trong danh sách.
//  Return: void
void inThongTinPhieuMuonv1(int i){
    printf("\tMa Doc Gia:           | %s\n", maDGMuon[i]);
    printf("\tMa ISBN:              | %s\n", maISBNMuon[i]);
    printf("\tSo luong sach muon:   | %d\n", soluongSachMuon[i]);
    printf("\tNgay muon sach:       | %s\n", ngayMuonSach[i]);
    printf("\tNgay tra du kien:     | %s\n", ngayTraSachDuKien[i]);
    printf("\tNgay tra thuc te:     | %s\n", ngayTraSachThucTe[i]);
};

// ------------------------------
// inThongTinPhieuMuonv2()
//  Chức năng: In rút gọn thông tin phiếu mượn theo dạng hàng ngang.
//  Tham số: i - vị trí phiếu trong danh sách.
//  Return: void
void inThongTinPhieuMuonv2(int i){
    printf("\n%5s | %5s | %5s | %3d | %12s | %12s | %12s",
    maPhieuMuon[i],maDGMuon[i],maISBNMuon[i],soluongSachMuon[i],ngayMuonSach[i],ngayTraSachDuKien[i],ngayTraSachThucTe[i]);
}

// ------------------------------
// inThongTinSachTheoDocGia()
//  Chức năng: In danh sách sách mà một độc giả đã mượn.
//  Tham số: maDGTim - mã độc giả cần tìm.
//  Return: void
void inThongTinSachTheoDocGia(char maDGTim[]){
    // In thong tin Sach
    int slSach = 0;
    printf("\n+++ SACH +++\n");
    printf("\n----------------------------------\n");
    for(int i=0; i<tongPhieuMuon; i++){
        if(strstr(maDGMuon[i],maDGTim) != NULL){
            slSach++;
            inThongTinSachv3(i);
        }
    } 
    printf("\n----------------------------------\n");
    if(slSach <= 0){
        printf("\n>>> Khong tim thay sach <<<\n");
    }

}

// ------------------------------
// inThongTinDocGiaTheoISBN()
//  Chức năng: In danh sách độc giả đang mượn sách theo ISBN.
//  Tham số: maISBNTim - mã ISBN cần tìm.
//  Return: void
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

// ------------------------------
// inSoLuongSachMuon()
//  Chức năng: Thống kê số lượng sách đang được mượn (chưa trả).
//  Tham số: null
//  Return: void
void inSoLuongSachMuon(){
    int tongsm = 0; // Tong sach muon
    int tongst = 0; // Tong sach tra
    printf("\n--------- THONG KE SO LUONG SACH DANG DUOC MUON ---------\n");

    for(int i = 0; i < tongPhieuMuon; i++){
        tongsm += soluongSachMuon[i];
    }
    for(int i = 0; i < tongPhieuTra; i++){
        tongst += soluongSachTra[i];
    }
    
    if(tongsm <= 0){
        printf("\n>>> Khong co sach nao dang duoc muon <<<\n");
        return;
    }
    printf("\n------------------------------------------------\n");
    printf("So luong sach dang duoc muon la: %d\n",tongsm-tongst);
    printf("------------------------------------------------\n");

}

// ------------------------------
// themThongTinPhieuMuon()
//  Chức năng: Thêm phiếu mượn mới (nhập CMND, ISBN, SL, auto ngày mượn).
//  Tham số: null
//  Return: void
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
                soluongSachMuon[tongPhieuMuon]= soLuong;
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


// ===================== [XỬ LÝ THỜI GIAN] =====================

// ------------------------------
// chuyenThangSangSo()
//  Chức năng: Chuyển tên tháng tiếng Anh sang số tương ứng.
//  Tham số: thang - chuỗi tháng (Jan, Feb, ...)
//  Return: số tháng (int)
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

// ------------------------------
// themNgayMuonSachTuDong()
//  Chức năng: Tự động lấy ngày hiện tại làm ngày mượn.
//  Tham số: null
//  Return: void
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

// ------------------------------
// themNgayTraDuKienTuDong()
//  Chức năng: Tự động tính ngày trả dự kiến sau 7 ngày kể từ ngày mượn.
//  Tham số: d, m, y - ngày, tháng, năm mượn.
//  Return: void
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
// themNgayTraThucTeTuDong()
//  Chức năng: Ghi nhận ngày trả thực tế bằng thời gian hệ thống.
//  Tham số: i - vị trí phiếu trong danh sách.
//  Return: void
void themNgayTraThucTeTuDong(int i){    
    time_t now;
    // Lay ngya hien tai
    time(&now);
    char thoiGian[30];
    // chuyen thoi gian thanh chuoi
    strcpy(thoiGian,ctime(&now));
    char thang[4]; 
    char ngay[4];
    int d,y;

    sscanf(thoiGian, "%s %s %d %*s %d", ngay, thang, &d, &y);

    int m = chuyenThangSangSo(thang);

    sprintf(ngayTraSachThucTe[i], "%02d/%02d/%04d", d, m, y);
}

// ------------------------------
// themNgayTraThucTeThuCong()
//  Chức năng: Cho phép nhập thủ công ngày trả thực tế.
//  Tham số: i - vị trí phiếu trong danh sách.
//  Return: void
void themNgayTraThucTeThuCong(int i){
    int d,m,y;
    bool hopLe = false;

    do{
        printf("Them ngay tra sach thuc te (dd/mm/yyyy): ");
        scanf("%d/%d/%d",&d,&m,&y);
       
        hopLe = kiemTraNgayHopLe(d,m,y);
        
        if(!hopLe) 
            printf("\n>> Ngay ko hop le. Vui long nhap lai <<\n");
    } while(!hopLe);

    // Lưu chuỗi ngày hợp lệ
    sprintf(ngayTraSachThucTe[i], "%02d/%02d/%04d", d, m, y);
}


// ===================== [CHỈNH SỬA / TRA CỨU PHIẾU MƯỢN] =====================

// ------------------------------
// suaThongTinPhieuMuon()
//  Chức năng: Chỉnh sửa thông tin phiếu mượn theo mã phiếu.
//  Tham số: timPhieuMuon - mã phiếu cần chỉnh sửa.
//  Return: void
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
        printf("\nSo luong Sach: | %d",soluongSachMuon[vitriPhieuMuon]);
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
                    soluongSachMuon[vitriPhieuMuon] = soLuong;
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

// ------------------------------
// timPhieuMuonTheoMa()
//  Chức năng: Tìm vị trí phiếu mượn theo mã phiếu mượn.
//  Tham số: timPhieuMuon - mã phiếu cần tìm.
//  Return: vị trí phiếu (int), -1 nếu không tìm thấy.
int timPhieuMuonTheoMa(char timPhieuMuon[]){
    int vitriPhieuMuon = -1;
    for(int i=0; i<tongPhieuMuon; i++){
        if(strcmp(maPhieuMuon[i],timPhieuMuon) == 0){
            return i;
        }
    }
    return -1;
}

// ------------------------------
// inThongTinPhieuMuonKhiTimThayMa()
//  Chức năng: In thông tin chi tiết khi tìm thấy phiếu mượn.
//  Tham số: timPhieuMuon - mã phiếu cần tìm.
//  Return: void
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


// ===================== [PHIEU TRA SACH] =====================

// ------------------------------
// inThongTinPhieuTra()
//  Chức năng: In thông tin 1 phiếu trả.
//  Tham số: i - vị trí phiếu trả trong danh sách.
//  Return: void
void inThongTinPhieuTra(int i){
    printf("%5s | %5s | %5s | %3d | %12s\n",
    maPhieuTra[i],maDGTra[i],maISBNTra[i],soluongSachTra[i],ngayTraSachThucTe[i]);
}

// ------------------------------
// inToanBoThongTinPhieuTra()
//  Chức năng: In toàn bộ danh sách phiếu trả.
//  Tham số: null
//  Return: void
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

// ------------------------------
// timPhieuMuonTheoCMND()
//  Chức năng: Tìm và in các phiếu mượn của độc giả theo CMND.
//  Tham số: timCMND - số CMND độc giả.
//  Return: void
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
    else
        printf("\n++++ Doc Gia %s co %d phieu muon ++++\n",maDGMuon,dem);
        
}

// ------------------------------
// themPhieuTraSach()
//  Chức năng: Lập phiếu trả sách, kiểm tra trễ hạn, mất sách, tính tiền phạt.
//  Tham số: null
//  Return: void
void themPhieuTraSach(){
    char timCMND [20];
    char maPhieuMuonCanTim[5];
    int matSach;
    int hopLe = -1;

    // tim Phieu Muon theo CMND Doc Gia
    printf("\nNhap CMND cua doc gia can tra sach:");
    scanf("%s",timCMND);

    // Kiem tra co ton tai ma Phieu Muon theo CMND khong
    timPhieuMuonTheoCMND(timCMND);

    // Nhap Ma Phieu Muon
    printf("\nNhap ma phieu muon ban muon thay doi: ");
    scanf("%s",maPhieuMuonCanTim);

    // Tim vi tri cua Phieu muon theo Ma Phieu Muon
    int vitriPhieuMuon = timPhieuMuonTheoMa(maPhieuMuonCanTim);
    if(vitriPhieuMuon == -1){
        printf("\n>>> Khong tim thay Phieu muon <<<\n");
        return;
    }

    // Gia tien 1 quyen Sach
    int giaTien = timGiaSachSachTheoISBN(maISBNMuon[vitriPhieuMuon]);
    int phat = 0;
    int tre = 0;

    // themNgayTraThucTeTuDong(vitriPhieuMuon);
    themNgayTraThucTeThuCong(vitriPhieuMuon);

    do{
        printf("Sach co bi mat khong? (1:Co / 0:Khong): ");
        scanf("%d",&matSach);
        if(matSach == 1){
            sachBiMat[vitriPhieuMuon] = matSach;
            phat = giaTien*2.0;
            hopLe = 1;
        } 
        else if (matSach == 0)
        {
            tre = tinhSoNgayTre(ngayTraSachDuKien[vitriPhieuMuon],ngayTraSachThucTe[vitriPhieuMuon]);
            phat = giaTien * tre;
            hopLe = 1;
        }
        else {
            printf("\n>>> LOI: Khong hop le. Vui long thu lai <<<\n");
        }
    } while(hopLe < 0);
    
    printf("\nNgay du kien tra Sach: %s | Ngay Tra Sach thuc te: %s\n",ngayTraSachDuKien[vitriPhieuMuon],ngayTraSachThucTe[vitriPhieuMuon]);
    printf("Phat: %d | Tre: %d ngay\n",phat,tre);
    printf("\n\t>>> Tien phat phai dong: %d VND <<<\n",phat);

}


// ===================== [XỬ LÝ NGÀY THÁNG & THỐNG KÊ] =====================

// ------------------------------
// tachNgay()
//  Chức năng: Tách ngày/tháng/năm từ chuỗi "dd/mm/yyyy".
//  Tham số: s - chuỗi ngày, d/m/y - tham chiếu lưu kết quả.
//  Return: void
void tachNgay(char s[], int &d, int &m, int &y){
    sscanf(s, "%d/%d/%d", &d, &m, &y);
}

// ------------------------------
// tinhKhoangNgayDuKienVaThucTe()
//  Chức năng: Tính số ngày chênh lệch giữa 2 mốc thời gian (d1/m1/y1 → d2/m2/y2).
//  Tham số: d1, m1, y1, d2, m2, y2.
//  Return: số ngày chênh lệch (int)
int tinhKhoangNgayDuKienVaThucTe(int d1,int m1,int y1,int d2,int m2,int y2){
    int ngay = 0;
    while(y1 < y2 || m1 < m2 || d1 < d2){
        d1++;
        ngay++;
        if(d1 > timSoNgayTrongThang(m1,y1)){
            d1 = 1; 
            m1++;
            if(m1 > 12){ 
                m1 = 1; 
                y1++; 
            }
        }
        if(y1 == y2 && m1 == m2 && d1 == d2) break;
    }
    return ngay;
}

// ------------------------------
// tinhSoNgayTre()
//  Chức năng: Tính số ngày trả trễ giữa ngày dự kiến và ngày thực tế.
//  Tham số: duKien - ngày dự kiến, thucTe - ngày thực tế.
//  Return: số ngày trễ (int)
int tinhSoNgayTre(char duKien[], char thucTe[]){
    int d1,m1,y1,d2,m2,y2;
    tachNgay(duKien, d1,m1,y1);
    tachNgay(thucTe, d2,m2,y2);

    if(y2 < y1 || (y2 == y1&& m2<m1) || (y2 == y1 && m2 == m1 && d2 <= d1))
        return 0; 
    return tinhKhoangNgayDuKienVaThucTe(d1,m1,y1,d2,m2,y2);
}

// ------------------------------
// thongKeDanhSachDocGiaTreHan()
//  Chức năng: Thống kê danh sách độc giả bị trễ hạn (chưa trả & quá ngày).
//  Tham số: null
//  Return: void
void thongKeDanhSachDocGiaTreHan(){
    int d1,m1,y1,d2,m2,y2;
    bool hopLe = false;
    char cmndTim[MAX];
    int vitriDocGia;
    int dem=0;
    printf("\n--------- THONG KE SO LUONG SACH DANG DUOC MUON ---------\n");
     do{
        printf("Them ngay hien tai (dd/mm/yyyy): ");
        scanf("%d/%d/%d",&d1,&m1,&y1);
        hopLe = kiemTraNgayHopLe(d1,m1,y1);
        if(!hopLe) 
            printf("\n>> Ngay ko hop le. Vui long nhap lai <<\n");
    } while(!hopLe);

    // Check co so luong doc gia nop tre hay ko
    // Neu ngay tra sach thuc te = NULL va ngay tre >= 1 
    for(int i=0; i < tongPhieuMuon; i++){
        tachNgay(ngayTraSachDuKien[i],d2,m2,y2);
        int tre = tinhKhoangNgayDuKienVaThucTe(d1,m1,y1,d2,m2,y2);
        if(tre >= 1 && (strcmp(ngayTraSachThucTe[i], "NULL") == 0 || strcmp(ngayTraSachThucTe[i], "") == 0)){
            dem++;
        }
    }
    // In du lieu neu ngay tra sach thuc te = NULL va ngay tre >= 1 
    if(dem>0){
        printf("Co %d dang bi tre han",dem);
        for(int i=0; i < tongPhieuMuon; i++){
            tachNgay(ngayTraSachDuKien[i],d2,m2,y2);
            int tre = tinhKhoangNgayDuKienVaThucTe(d1,m1,y1,d2,m2,y2);
            if(tre >= 1 && (strcmp(ngayTraSachThucTe[i], "NULL") == 0 || strcmp(ngayTraSachThucTe[i], "") == 0)){
                timCMNDDocGiaTheoMaDG(maDGMuon[i],cmndTim);
                inThongTinDocGiaSauKhiTimTheoCMNDv2(cmndTim);
                inThongTinSachSauKhiTimThayISBNv2(maISBNMuon[i]);
                printf("\n=====================================\n");
            }
        }
    } else {
        printf("\n Khong tim thay Doc gia tre han \n");
    }

}