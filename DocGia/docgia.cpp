#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Khai báo biến toàn cục là MAX với kí tự tối đa là 200 đơn vị
#define MAX 200

char maDG[MAX][20];         // Không được trùng
char tenDG[MAX][40];        
char cmnd[MAX][12];         // Không được trùng
char gioiTinh[MAX][10];
char email[MAX][40];        // Không được trùng
char diachi[MAX][100];
char ngayLapThe[MAX][20];
char ngayHetHanThe[MAX][20];
int tongSoDG = 0;

// ===========================
// Thêm mẫu Đọc Giả vào Thư viện
void napDuLieuMau() {
    tongSoDG = 3;
    // strncpy(): dùng để thêm chỉ định tối đa các ký tự vào danh sách và đảm bảo kết thúc bằng \0:
    strncpy(maDG[0], "DG001", sizeof(maDG[0]) - 1);
    strncpy(maDG[1], "DG002", sizeof(maDG[1]) - 1);
    strncpy(maDG[2], "DG003", sizeof(maDG[2]) - 1);

    strncpy(tenDG[0], "Nguyen Van A", sizeof(tenDG[0]) - 1);
    strncpy(tenDG[1], "Tran Thi B", sizeof(tenDG[1]) - 1);
    strncpy(tenDG[2], "Le Van C", sizeof(tenDG[2]) - 1);

    strncpy(cmnd[0], "123456789", sizeof(cmnd[0]) - 1);
    strncpy(cmnd[1], "987654321", sizeof(cmnd[1]) - 1);
    strncpy(cmnd[2], "01234", sizeof(cmnd[2]) - 1);

    strncpy(gioiTinh[0], "Male", sizeof(gioiTinh[0]) - 1);
    strncpy(gioiTinh[1], "Female", sizeof(gioiTinh[1]) - 1);
    strncpy(gioiTinh[2], "Male", sizeof(gioiTinh[2]) - 1);

    strncpy(email[0], "nguyenVanA@gmail.com", sizeof(email[0]) - 1);
    strncpy(email[1], "tranThiB@gmail.com", sizeof(email[1]) - 1);
    strncpy(email[2], "leVanC@gmail.com", sizeof(email[2]) - 1);

    strncpy(diachi[0], "123 Le Loi", sizeof(diachi[0]) - 1);
    strncpy(diachi[1], "456 Nguyen Trai", sizeof(diachi[1]) - 1);
    strncpy(diachi[2], "789 Tran Hung Dao", sizeof(diachi[2]) - 1);

    strncpy(ngayLapThe[0], "01/01/2023", sizeof(ngayLapThe[0]) - 1);
    strncpy(ngayLapThe[1], "15/03/2024", sizeof(ngayLapThe[1]) - 1);
    strncpy(ngayLapThe[2], "20/05/2024", sizeof(ngayLapThe[2]) - 1);

    strncpy(ngayHetHanThe[0], "01/01/2027", sizeof(ngayHetHanThe[0]) - 1);
    strncpy(ngayHetHanThe[1], "15/03/2028", sizeof(ngayHetHanThe[1]) - 1);
    strncpy(ngayHetHanThe[2], "20/05/2028", sizeof(ngayHetHanThe[2]) - 1);
}

// ===========================
// In thông tin tất cả Đọc Giả
void xemThongTinToanBoDocGia(){
    printf("\n====== DANH SACH DOC GIA ======\n");
    if(tongSoDG == 0){
        printf("Chua co doc gia");
        return;
    }
    for(int i=0; i < tongSoDG; i++){
        printf("%05s | %20s | %12s | %20s | %10s | %10s \n",maDG[i], tenDG[i],cmnd[i],email[i],ngayLapThe[i],ngayHetHanThe[i]);
    }
}

// ===========================
// Thêm thông tin của Độc Giả
void themThongTinDocGia(){
    int d,m,y;
    if(tongSoDG >= MAX){
        printf(">> Thu vien da day, khong the them doc gia moi <<\n");
    }

    printf("\n====== THEM DOC GIA MOI ======\n");
    // Thêm tên DG
    printf("Them ho ten Doc Gia: ");
    getchar();
    fgets(tenDG[tongSoDG],40,stdin);
    tenDG[tongSoDG][strcspn(tenDG[tongSoDG],"\n")] = '\0';

    // Kiem tra CMND Doc Gia
    kiemTraCMNDDocGia();

    // Them Gioi Tinh
    printf("Them Gioi tinh (Male/Female/Other):  ");
    scanf("%s",gioiTinh[tongSoDG]);
    
    // Them Email
    kiemTraEmail();

    // Them Dia Chi
    printf("Them Dia Chi: ");
    getchar();
    fgets(diachi[tongSoDG],100,stdin);
    diachi[tongSoDG][strcspn(diachi[tongSoDG], "\n")] = '\0';

    // Them Ngay Lap The va Het Han The
    kiemTraNgayLapThe();

    // Them MaDG tang tu dong
    sprintf(maDG[tongSoDG],"DG%03d",tongSoDG+1);
    
    // THONG BAO
    printf(">> Them Thanh Cong <<\n");
    tongSoDG++;
}

// ===========================
// Tìm Đọc Giả theo CMND
bool timDocGiaTheoCMND(char timCMND[]){
    bool tontaiDG = false;
    printf("\n====== TIM DOC GIA THEO TEN ======\n");
    for(int i=0; i<tongSoDG; i++){
        if(strcmp(cmnd[i], timCMND) ==0){
            tontaiDG = true;
            printf("\n>> Tim Thay Doc Gia <<\n");
            printf("--------------------------------\n");
            printf("Ma DG:      %s\n", maDG[i]);
            printf("Ten DG:     %s\n", tenDG[i]);
            printf("CMND:       %s\n", cmnd[i]);
            printf("Gioi tinh:  %s\n", gioiTinh[i]);
            printf("Email:      %s\n", email[i]);
            printf("Dia chi:    %s\n", diachi[i]);
            printf("Ngay Lap The:   %s\n", ngayLapThe[i]);
            printf("Ngay Het Han:   %s\n", ngayHetHanThe[i]);
            printf("--------------------------------\n");
            break;
        }
    }
    if(!tontaiDG) printf("\n>> Khong tim thay doc gia <<\n");
    return tontaiDG;
}

// ===========================
// Chỉnh sửa thông tin Đọc Giả
void suaThongTinDocGia(char timCMND[]){
    // Tìm Đọc Giả
    if(!timDocGiaTheoCMND(timCMND)) return;
    else{
        printf("\n>> Bat dau sua thong tin Doc Gia <<\n");
        int choice;
        do{
            printf("\n>> Nhap lua chon de chinh sua <<\n");
            scanf("%d",choice);
            
            switch (choice)
            {
            case 1:
                /* code */
                break;
            
            default:
                break;
            }


        }while(choice != 0);
    }
    // Chọn nội dung cần sửa

    
    // Sửa ĐỌc giả

}



// Nhóm xử lý bắt lỗi
// ===========================
#pragma region Validation

// Kiểm tra CMND Đọc Giả
void kiemTraCMNDDocGia(){
    char cmndNew[20]; // cmnd[kí tự]
    bool hopLe = false;

    do{
        hopLe = true;
        printf("Them CMND: ");
        scanf("%s",cmndNew);
        
        for(int i=0; i < tongSoDG; i++){
            if(strcmp(cmnd[i],cmndNew) == 0){
                printf("\n>> CMND da ton tai <<\n");
                hopLe = false;
                break;
            }
        }

        if(hopLe){
            strcpy(cmnd[tongSoDG],cmndNew);
        }
    }while(!hopLe);
}

// ===========================
// Kiểm tra Email
void kiemTraEmail(){
    char emailNew[20];
    bool hopLe = false;

    do{
        hopLe = true;
        printf("Them Email: ");
        scanf("%s",emailNew);

        for(int i=0; i < tongSoDG; i++){
            if(strcmp(email[i], emailNew) == 0){
                printf("\n>> Email da ton tai <<\n");
                hopLe = false;
            }
        }

        if(hopLe){
            strcpy(email[tongSoDG], emailNew);
        } else {
            printf(">> Luu Email That bai <<\n");
        }        
    } while(!hopLe);

}

// ===========================
// Kiểm tra Ngày Them va Tra
int timNamNhuan(int y){
    if((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)){
        return 29;
    } else {
        return 28;
    }
}

// Tìm số ngày trong 1 tháng
int timSoNgayTrongThang(int m, int y){
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
        return 31;
    } 
    if (m == 4 || m == 6 || m == 9 || m == 11){
        return 30;
    } else {
        return timNamNhuan(y);
    }
}

// Hợp lệ khi năm từ 2003 trở đi
void kiemTraNgayLapThe(){
    int d,m,y;
    bool hopLe = false;

    do{
        hopLe = true;

        printf("Them Ngay Lap The (dd/mm/yyyy): ");
        scanf("%d/%d/%d",&d,&m,&y);
        
        // Kiểm tra ngày hợp lệ
        if(d <=0 || m <=0 || m > 12 || y <= 2003)
            hopLe = false;
        if(d > timSoNgayTrongThang(m,y))
            hopLe = false;
        
        if(!hopLe) 
            printf("\n>> Ngay ko hop le. Vui long nhap lai <<\n");
    } while(!hopLe);

    // Lưu chuỗi ngày hợp lệ
    sprintf(ngayLapThe[tongSoDG], "%02d/%02d/%04d", d, m, y);

    themNgayHetHanThe(d, m, y);

}

// Het han sau 48 thang kể từ ngày lập thẻ
void themNgayHetHanThe(int d, int m, int y){
    m += 48;
    y += (m-1)/12;
    m = ((m-1) % 12) + 1;

    int dayMax = timSoNgayTrongThang(m,y);
    if(d > dayMax) d = dayMax;

    sprintf(ngayHetHanThe[tongSoDG],"%01d/%02d/%04d",d,m,y);
}

#pragma endregion



