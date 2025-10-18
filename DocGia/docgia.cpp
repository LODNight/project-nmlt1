#include <stdio.h>
#include <stdbool.h>

// Khai báo biến toàn cục là MAX với kí tự tối đa là 200 đơn vị
#define MAX 200

char maDG[MAX][20];
char tenDG[MAX][40];
char cmnd[MAX][12];
char gioiTinh[MAX][10];
char email[MAX][40];
int tongSoDG = 0;

// Thêm thông tin của Độc Giả
void themThongTinDocGia(){
    printf("\n====== THEM DOC GIA MOI ======\n");
    printf("Them ten Doc Gia: ");
    scanf("%s",maDG[tongSoDG]);
    tongSoDG++;
}

// In tất cả Đọc Giả
void inThongTinToanBoDocGia(){
    for(int i=0; i < tongSoDG; i++){
        printf("%s\n", maDG[i]);
    }
}