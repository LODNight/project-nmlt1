#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Khai báo biến toàn cục là MAX với kí tự tối đa là 200 đơn vị
#define MAX 200

char ISBN[MAX][7];
char tenSach[MAX][100];
char tenTacGia[MAX][50];
char tenNhaXuatBan[MAX][100];
char namXuatBan[MAX][4];
char theLoai[MAX][50];
char giaSach[MAX][9];
int tongSach;

// ==========================
// Nap du lieu Sách
void napDuLieuSachMau(){
    tongSach = 3;
    strncpy(ISBN[0], "S001", sizeof(ISBN[0]) - 1);
    strncpy(ISBN[1], "S002", sizeof(ISBN[1]) - 1);
    strncpy(ISBN[2], "S003", sizeof(ISBN[2]) - 1);

    strncpy(tenSach[0], "Lap trinh C co ban", sizeof(tenSach[0]) - 1);
    strncpy(tenSach[1], "Giai tich 1", sizeof(tenSach[1]) - 1);
    strncpy(tenSach[2], "Nhap mon SQL", sizeof(tenSach[2]) - 1);

    strncpy(tenTacGia[0], "Nguyen Van A", sizeof(tenTacGia[0]) - 1);
    strncpy(tenTacGia[1], "Tran Thi B", sizeof(tenTacGia[1]) - 1);
    strncpy(tenTacGia[2], "Le Van C", sizeof(tenTacGia[2]) - 1);

    strncpy(tenNhaXuatBan[0], "NXB Tre", sizeof(tenNhaXuatBan[0]) - 1);
    strncpy(tenNhaXuatBan[1], "NXB Giao Duc", sizeof(tenNhaXuatBan[1]) - 1);
    strncpy(tenNhaXuatBan[2], "NXB Lao Dong", sizeof(tenNhaXuatBan[2]) - 1);

    strncpy(namXuatBan[0], "2022", sizeof(namXuatBan[0]) - 1);
    strncpy(namXuatBan[1], "2023", sizeof(namXuatBan[1]) - 1);
    strncpy(namXuatBan[2], "2020", sizeof(namXuatBan[2]) - 1);

    strncpy(theLoai[0], "Lap trinh", sizeof(theLoai[0]) - 1);
    strncpy(theLoai[1], "Toan hoc", sizeof(theLoai[1]) - 1);
    strncpy(theLoai[2], "CSDL", sizeof(theLoai[2]) - 1);

    strncpy(giaSach[0], "120000", sizeof(giaSach[0]) - 1);
    strncpy(giaSach[1], "95000", sizeof(giaSach[1]) - 1);
    strncpy(giaSach[2], "150000", sizeof(giaSach[2]) - 1);
}


// ==========================
// In Thông tin toàn bộ Sách
void inThongTinToanBoSach(){
printf("\n====== DANH SACH [SACH] ======\n");
    if(tongSach == 0){
        printf("Chua co Sach");
        return;
    }
    for(int i=0; i < tongSach; i++){
        printf("%04s | %20s | %20s | %20s | %5s | %10s | %9s \n",
        ISBN[i], tenSach[i], tenTacGia[i], tenNhaXuatBan[i], namXuatBan[i], theLoai[i], giaSach[i]);
    }
}


// ==========================
// Thêm Sách
void themThongTinSach(){
    if(tongSach >= 0){
        printf("\n>>> Ban khong the them Sach <<<\n");
    }
    printf("\n===== Them thong tin Sach ===== \n");
    
    // Tên Sách
    themTenSach();

    // Tên Tác Giả
    themTenTacGia();

    // Tên nhà xuất bản
    themNhaXuatBan();
    
    // Năm Xuất bản
    themNamXuatBan();

    // The Loại
    themTheLoai();

    // Giá Sách
    themGiaSach();
    
    // Them Ma ISBN tang tu dong
    sprintf(ISBN[tongSach],"S%03d",tongSach+1);

    // THONG BAO
    printf(">> Them Sach Thanh Cong <<\n");
    tongSach++;
}


// Tên Sách
void themTenSach(){
    printf("Nhap ten Sach: ");
    getchar();
    fgets(tenSach[tongSach],100,stdin);
    tenSach[tongSach][strcspn(tenSach[tongSach],"\n")] = '\0';
}

// Tên Tác Giả
void themTenTacGia(){
    printf("Nhap ten Tac Gia: ");
    getchar();
    fgets(tenTacGia[tongSach],50,stdin);
    tenTacGia[tongSach][strcspn(tenTacGia[tongSach],"\n")] = '\0';
}

// Tên nhà xuất bản
void themNhaXuatBan(){
    printf("Nhap ten nha xuat ban: ");
    getchar();
    fgets(tenNhaXuatBan[tongSach],100,stdin);
    tenNhaXuatBan[tongSach][strcspn(tenNhaXuatBan[tongSach],"\n")] = '\0';
}

// Năm Xuất bản
void themNamXuatBan(){
    int y;
    bool hopLe = false;

    do{
        printf("Nhap nam xuat ban (1000-2025): ");
        scanf("%d",&y);

        // Kiểm tra năm phải là 4 chữ số và không được bé hơn 1000
        if(y < 1000 || y > 2025){
            printf("\n>>> Nam khong hop le. Vui long nhap lai (1000-2025) <<<\n");
        } else {
            sprintf(namXuatBan[tongSach], "%d", y); 
            hopLe = true;
        }
    } while(!hopLe);

}

// The Loại
void themTheLoai(){
    printf("Nhap ten the loai: ");
    getchar();
    fgets(theLoai[tongSach],50,stdin);
    theLoai[tongSach][strcspn(theLoai[tongSach],"\n")] = '\0';
}

// Giá Sách
void themGiaSach(){
    int m;
    bool hopLe = false;

    do{
        printf("Nhap gia tien: ");
        scanf("%d",&m);

        // Kiểm tra gias tiền phải từ 1000 tới 9000000000
        if(m < 1000 || m > 999999999){
            printf("\n>>> Gia tien khong hop le. Vui long nhap lai <<<\n");
        } else {
            sprintf(giaSach[tongSach], "%d", m); 
            hopLe = true;
        }
    } while(!hopLe);

}


// ==========================
// Chinh sua Sách
void chinhSuaSach(){

}

// ==========================
// Xoa Sach


// ==========================
// Tim sach theo ISBN


// ==========================
// Tim sach theo ten Sach

