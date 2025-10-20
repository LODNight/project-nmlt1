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
// Thêm thông tin của Độc Giả
void themThongTinDocGia(){
    if(tongSoDG >= MAX){
        printf(">> Thu vien da day, khong the them doc gia moi <<\n");
    }

    printf("\n====== THEM DOC GIA MOI ======\n");
    printf("Them ma Doc Gia: ");
    scanf("%s",maDG[tongSoDG]);
    printf("Them ho ten Doc Gia: ");
    getchar();
    fgets(tenDG[tongSoDG],40,stdin);
    tenDG[tongSoDG][strcspn(tenDG[tongSoDG],"\n")] = '\0';
    printf("Them CMND: ");
    scanf("%s",cmnd[tongSoDG]);
    printf("Them Gioi tinh (Male/Female/Other): ");
    scanf("%s",gioiTinh[tongSoDG]);
    printf("Them Email: ");
    scanf("%s",email[tongSoDG]);
    printf("Them Dia Chi: ");
    getchar();
    fgets(diachi[tongSoDG],100,stdin);
    diachi[tongSoDG][strcspn(diachi[tongSoDG], "\n")] == '\0';
    printf("Them Ngay Lap The: ");
    printf("Them Ngay Het Han: ");
    printf(">> Them Thanh Cong <<\n");

    tongSoDG++;
}

// ===========================
// Kiểm tra trùng Đọc Giả


// ===========================
// In tất cả Đọc Giả
void xemThongTinToanBoDocGia(){
    printf("\n====== DANH SACH DOC GIA ======\n");
    if(tongSoDG == 0){
        printf("Chua co doc gia");
        return;
    }
    for(int i=0; i < tongSoDG; i++){
        printf("%s | %s\n",maDG[i], tenDG[i]);
    }
}

// ===========================
// Tìm Đọc Giả theo CMND