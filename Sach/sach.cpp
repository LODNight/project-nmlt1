#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "sach.h"
// Khai báo biến toàn cục là MAX với kí tự tối đa là 200 đơn vị
#define MAX 200

// ------------------ Biến toàn cục ------------------
char ISBN[MAX][5];
char tenSach[MAX][100];
char tenTacGia[MAX][50];
char tenNhaXuatBan[MAX][100];
char namXuatBan[MAX][5];
char theLoai[MAX][50];
int giaSach[MAX];
// Quản lý số lượng Sách đang có
int soLuongSach[MAX];
int tongSach;

// -----------------------
// napDuLieuSachMau()
//  Chức năng: Nạp dữ liệu mẫu cho danh sách sách.
//  Tham số: null
//  Return: void
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

    giaSach[0] = 20000; 
    giaSach[1] = 15000; 
    giaSach[2] = 40000;

    soLuongSach[0] = 20; 
    soLuongSach[1] = 20; 
    soLuongSach[2] = 20; 
}

// -----------------------
// inThongTinToanBoSach()
//  Chức năng: In toàn bộ danh sách sách trong thư viện.
//  Tham số: null
//  Return: void
void inThongTinToanBoSach(){
    printf("\n----------------------------------\n");
    printf("\n====== DANH SACH [SACH] ======\n");
    if(tongSach == 0){
        printf("Chua co Sach");
        return;
    }
    for(int i=0; i < tongSach; i++){
        printf("%04s | %20s | %20s | %20s | %5s | %10s | %9d | %2d\n",
        ISBN[i], tenSach[i], tenTacGia[i], tenNhaXuatBan[i], namXuatBan[i], theLoai[i], giaSach[i],soLuongSach[i]);
    }
    printf("\n----------------------------------\n");
}

// -----------------------
// inThongTinSachv1()
//  Chức năng: In chi tiết thông tin 1 sách theo hàng dọc.
//  Tham số: i - vị trí sách trong danh sách.
//  Return: void
void inThongTinSachv1(int i){
    printf("\tMa ISBN:      | %s\n", ISBN[i]);
    printf("\tTen sach:     | %s\n", tenSach[i]);
    printf("\tTac gia:      | %s\n", tenTacGia[i]);
    printf("\tNha xuat Ban: | %s\n", tenNhaXuatBan[i]);
    printf("\tNam xuat ban: | %s\n", namXuatBan[i]);
    printf("\tThe loai:     | %s\n", theLoai[i]);
    printf("\tGia sach:     | %d\n", giaSach[i]);
    printf("\tSo luong:     | %d\n", soLuongSach[i]);
}

// -----------------------
// inThongTinSachv2()
//  Chức năng: In thông tin rút gọn của sách theo hàng ngang.
//  Tham số: i - vị trí sách trong danh sách.
//  Return: void
void inThongTinSachv2(int i){ 
    printf("%5s | %20s | %d | %d \n",
    ISBN[i], tenSach[i], giaSach[i], soLuongSach[i]);    
}

// -----------------------
// inThongTinSachv3()
//  Chức năng: In thông tin sách nhưng không kèm số lượng.
//  Tham số: i - vị trí sách.
//  Return: void
void inThongTinSachv3(int i){ 
    printf("%5s | %20s | %d\n",
    ISBN[i], tenSach[i], giaSach[i]);    
}

// -----------------------
// inTongSoLuongSach()
//  Chức năng: Thống kê tổng số lượng sách trong thư viện.
//  Tham số: null
//  Return: void
void inTongSoLuongSach(){
    printf("\n--------- THONG KE TOAN BO SO LUONG SACH ---------\n");
    printf("Tong so Sach la: %d\n", tongSach);
    printf("Sach cac loai hien co:\n");
    printf("\tmaSach |        ten Sach      | So luong  | The loai\n");
    for(int i = 0; i < tongSach; i++){
        printf("\t%6s | %20s | %9d | %s\n", ISBN[i],tenSach[i],soLuongSach[i], theLoai[i]);
    }
}

// -----------------------
// inTongSoLuongSachTheoTheLoai()
//  Chức năng: Thống kê số lượng sách theo thể loại nhập vào.
//  Tham số: null (người dùng nhập thể loại từ bàn phím).
//  Return: void
void inTongSoLuongSachTheoTheLoai(){
    printf("\n--------- THONG KE SO LUONG SACH THEO THE LOAI ---------\n");
    int dem = 0;
    int tong = 0;
    char theLoaiCanTim[50];

    getchar();
    printf("Nhap ten the loai: ");
    fgets(theLoaiCanTim,50,stdin);
    theLoaiCanTim[strcspn(theLoaiCanTim,"\n")] = '\0';

    // Kiem tra bien dem
    for(int i = 0; i < tongSach; i++){
        if(strstr(theLoai[i],theLoaiCanTim) != NULL){
            dem++;
            tong += soLuongSach[i];
        }
    }

    // Neu bien dem > 1
    if(dem >= 1){
        printf("------------------------------------------------\n");
        printf("\nSach theo the loai [%s] la: %d\n", theLoaiCanTim,dem);
        printf("Tong so luong sach la: %d\n", tong);
        printf("\nSach cac loai hien co:\n");
        printf("\tmaSach |        ten Sach      | So luong Sach\n");
        for(int i = 0; i < tongSach; i++){
            if(strstr(theLoai[i],theLoaiCanTim) != NULL){
                printf("\t%6s | %20s | %9d\n", ISBN[i],tenSach[i],soLuongSach[i]);
            }
        }
        printf("------------------------------------------------\n");
    } else {
        printf("\n>>> LOI: Khong tim thay sach. <<<\n");
        
    }
   
    
}


// -----------------------
// timSachTheoISBN()
//  Chức năng: Tìm sách theo mã ISBN.
//  Tham số: timISBN - mã ISBN cần tìm.
//  Return: vị trí sách (int) hoặc -1 nếu không tìm thấy.
int timSachTheoISBN(char timISBN[]){
    int vitriSach = -1;
    for(int i=0; i<tongSach; i++){
        if(strcmp(ISBN[i],timISBN) == 0){
            vitriSach = i;
            break;
        }
    }
    return vitriSach;
}

// -----------------------
// timSachTheoTen()
//  Chức năng: Tìm sách theo tên sách.
//  Tham số: timSach - chuỗi tên sách cần tìm.
//  Return: vị trí sách (int) hoặc -1 nếu không tìm thấy.
int timSachTheoTen(char timSach[]){
    int vitriSach = -1;
    for(int i=0; i<tongSach; i++){
        if(strstr(tenSach[i], timSach) != NULL){
            vitriSach = i;
        }
    }
    if(vitriSach < 0 )  printf("\n>>> Khong tim thay sach <<< \n");
    return vitriSach;
}

// -----------------------
// timSoLuongSachTheoISBN()
//  Chức năng: Lấy số lượng sách theo mã ISBN.
//  Tham số: timISBN - mã ISBN cần tìm.
//  Return: số lượng sách hoặc -1 nếu không tồn tại.
int timSoLuongSachTheoISBN(char timISBN[]){
    for(int i=0; i<tongSach; i++){
        if(strcmp(ISBN[i],timISBN) == 0){
            return soLuongSach[i];
        }
    }
    return -1;
}

// -----------------------
// timGiaSachSachTheoISBN()
//  Chức năng: Lấy giá sách theo mã ISBN.
//  Tham số: timISBN - mã ISBN cần tìm.
//  Return: giá sách hoặc -1 nếu không tồn tại.
int timGiaSachSachTheoISBN(char timISBN[]){
    for(int i=0; i<tongSach; i++){
        if(strcmp(ISBN[i],timISBN) == 0){
            return giaSach[i];
        }
    }
    return -1;
}

// -----------------------
// inThongTinSachSauKhiTimThayISBNv1()
//  Chức năng: In chi tiết thông tin sách (theo hàng dọc) khi tìm thấy ISBN.
//  Tham số: timISBN - mã ISBN cần tìm.
//  Return: void
void inThongTinSachSauKhiTimThayISBNv1(char timISBN[]){
    int vitriSach = timSachTheoISBN(timISBN);
    if(vitriSach >=0 ){
        printf("\n\n>>> Tim thay Sach voi cac thong tin la <<<\n");
        printf("------------------------------------------\n");
        inThongTinSachv1(vitriSach);
       printf("------------------------------------------\n");
    }
    if(vitriSach < 0)  
        printf("\n>>> Khong tim thay sach <<< \n");
}

// -----------------------
// inThongTinSachSauKhiTimThayISBNv2()
//  Chức năng: In thông tin sách (theo hàng ngang) khi tìm thấy ISBN.
//  Tham số: timISBN - mã ISBN cần tìm.
//  Return: void
void inThongTinSachSauKhiTimThayISBNv2(char timISBN[]){
    int vitriSach = timSachTheoISBN(timISBN);
    if(vitriSach >=0 ){
        printf("\n>>> Tim thay Sach voi cac thong tin la <<<\n");
        inThongTinSachv2(vitriSach);
    }
    if(vitriSach < 0)  
        printf("\n>>> Khong tim thay sach <<< \n");
}

// -----------------------
// inThongTinSachSauKhiTimThayTen()
//  Chức năng: In thông tin sách khi tìm theo tên sách.
//  Tham số: timSach - tên sách cần tìm.
//  Return: void
void inThongTinSachSauKhiTimThayTen(char timSach[]){
    int vitriSach = timSachTheoTen(timSach);
    if(vitriSach >=0 ){
        printf("\n\n>>> Tim thay Sach voi cac thong tin la <<<\n");
        printf("------------------------------------------\n");
        inThongTinSachv2(vitriSach);
        printf("------------------------------------------\n");
    }
    if(vitriSach < 0)  
        printf("\n>>> Khong tim thay sach <<< \n");
}

// -----------------------
// themThongTinSach()
//  Chức năng: Thêm thông tin sách mới vào hệ thống.
//  Tham số: null
//  Return: void
void themThongTinSach(){
    if(tongSach >= 0){
        printf("\n>>> Ban khong the them Sach <<<\n");
    }
    printf("\n===== Them thong tin Sach ===== \n");
    
    // Tên Sách
    themTenSach(tongSach);

    // Tên Tác Giả
    themTenTacGia(tongSach);

    // Tên nhà xuất bản
    themNhaXuatBan(tongSach);
    
    // Năm Xuất bản
    themNamXuatBan(tongSach);

    // The Loại
    themTheLoai(tongSach);

    // Giá Sách
    themGiaSach(tongSach);

    // Số lượng
    themSoLuongSach(tongSach);
    
    // Them Ma ISBN tang tu dong
    sprintf(ISBN[tongSach],"S%03d",tongSach+1);

    // THONG BAO
    printf(">> Them Sach Thanh Cong <<\n");
    tongSach++;
}

// -----------------------
// themTenSach()
//  Chức năng: Nhập tên sách mới.
//  Tham số: vitri - vị trí sách trong mảng.
//  Return: void
void themTenSach(int vitri){
    printf("Nhap ten Sach: ");
    getchar();
    fgets(tenSach[vitri],100,stdin);
    tenSach[vitri][strcspn(tenSach[vitri],"\n")] = '\0';
}

// -----------------------
// themTenTacGia()
//  Chức năng: Nhập tên tác giả.
//  Tham số: vitri - vị trí sách trong mảng.
//  Return: void
void themTenTacGia(int vitri){
    printf("Nhap ten Tac Gia: ");
    getchar();
    fgets(tenTacGia[vitri],50,stdin);
    tenTacGia[vitri][strcspn(tenTacGia[vitri],"\n")] = '\0';
}

// -----------------------
// themNhaXuatBan()
//  Chức năng: Nhập tên nhà xuất bản.
//  Tham số: vitri - vị trí sách.
//  Return: void
void themNhaXuatBan(int vitri){
    printf("Nhap ten nha xuat ban: ");
    getchar();
    fgets(tenNhaXuatBan[vitri],100,stdin);
    tenNhaXuatBan[vitri][strcspn(tenNhaXuatBan[vitri],"\n")] = '\0';
}

// -----------------------
// themNamXuatBan()
//  Chức năng: Nhập năm xuất bản và kiểm tra hợp lệ.
//  Tham số: vitri - vị trí sách.
//  Return: void
void themNamXuatBan(int vitri){
    int y;
    bool hopLe = false;

    do{
        printf("Nhap nam xuat ban (1000-2025): ");
        scanf("%d",&y);

        // Kiểm tra năm phải là 4 chữ số và không được bé hơn 1000
        if(y < 1000 || y > 2025){
            printf("\n>>> Nam khong hop le. Vui long nhap lai (1000-2025) <<<\n");
        } else {
            sprintf(namXuatBan[vitri], "%d", y); 
            hopLe = true;
        }
    } while(!hopLe);

}

// -----------------------
// themTheLoai()
//  Chức năng: Nhập thể loại sách.
//  Tham số: vitri - vị trí sách.
//  Return: void
void themTheLoai(int vitri){
    printf("Nhap ten the loai: ");
    getchar();
    fgets(theLoai[vitri],50,stdin);
    theLoai[vitri][strcspn(theLoai[vitri],"\n")] = '\0';
}

// -----------------------
// themGiaSach()
//  Chức năng: Nhập giá sách, kiểm tra trong khoảng hợp lệ.
//  Tham số: vitri - vị trí sách.
//  Return: void
void themGiaSach(int vitri){
    int m;
    bool hopLe = false;

    do{
        printf("Nhap gia tien: ");
        scanf("%d",&m);

        // Kiểm tra gias tiền phải từ 1000 tới 9000000000
        if(m < 1000 || m > 999999999){
            printf("\n>>> Gia tien khong hop le. Vui long nhap lai <<<\n");
        } else {
            giaSach[vitri] = m; 
            hopLe = true;
        }
    } while(!hopLe);

}

// -----------------------
// themSoLuongSach()
//  Chức năng: Nhập số lượng sách tồn kho.
//  Tham số: vitri - vị trí sách.
//  Return: void
void themSoLuongSach(int vitri){
    int soluong = 0;
    if(vitri > tongSach){
        printf("\n>>> Khong hop le <<<\n");
        return;
    }
    bool hopLe = false;
    
    do{        
        printf("Them so luong: ");
        scanf("%d",&soluong);

        if(soluong < 0){
            printf("\n>>> So luong khong hop le. Nhap lai so luong: ");
        }
        else{
            hopLe = true;
        }
    } while(!hopLe);
    if(hopLe){
        soLuongSach[vitri] = soluong;
    }

}

// -----------------------
// chinhSuaSach()
//  Chức năng: Chỉnh sửa thông tin sách theo ISBN.
//  Tham số: timISBN - mã ISBN của sách cần sửa.
//  Return: void
void chinhSuaSach(char timISBN[]){
    int vitriSach = timSachTheoISBN(timISBN);
    if(vitriSach == 0) return;
    else {
        printf("\n>> Bat dau sua thong tin Sach <<\n");
        int choice = -1;
        // nếu để khai báo int choice; thì sẽ có khả năng random là 0
        do{
            printf("---------------------------------------");
            printf("\n+++ CHINH SUA CAC THONG TIN SAU +++\n");
            printf("\t1. Ten Sach\n");
            printf("\t2. Tac Gia\n");
            printf("\t3. Nha xuat ban\n");
            printf("\t4. Nam xuat ban\n");
            printf("\t5. The loai\n");
            printf("\t6. Gia sach\n");
            printf("\t0. Thoat\n");
            printf("---------------------------------------\n");
            printf("Lua chon chinh sua: ");
            scanf("%d",&choice);
            getchar();
            
            // Kiểm tra case
            switch (choice)
            {
            case 1:
                // Ten Sach
                printf("Ten Sach: %s\n", tenSach[vitriSach]);
                themTenSach(vitriSach);
                break;
            case 2:
                // Tác giả
                printf("Tac gia: %s\n", tenTacGia[vitriSach]);
                themTenTacGia(vitriSach);
                break;
            case 3:
                // Nhà xuất bản
                printf("Nha xuat ban: %s\n", tenNhaXuatBan[vitriSach]);
                themNhaXuatBan(vitriSach);
                break;
            case 4:
                // Năm xuất bản
                printf("Nam xuat ban: %s\n", namXuatBan[vitriSach]);
                themNamXuatBan(vitriSach);
                break;
            case 5:
                // The loai
                printf("The loai: %s\n", theLoai[vitriSach]);
                themTheLoai(vitriSach);
                break;
            case 6:
                // Giá sách
                printf("Gia sach: %s\n", giaSach[vitriSach]);
                themGiaSach(vitriSach);
                break;
            case 0:
                printf("\n>> Thoat Chinh Sua <<\n");
                break;
            default:
                break;
            }

        } while(choice != 0); 
        
    }
    
}

// -----------------------
// thayDoiSoLuongSach()
//  Chức năng: Giảm số lượng sách khi mượn/trả.
//  Tham số: timISBN - mã ISBN, soLuong - số lượng cần thay đổi.
//  Return: void
void thayDoiSoLuongSach(char timISBN[], int soLuong){
    int vitriSach = timSachTheoISBN(timISBN);
    soLuongSach[vitriSach] -= soLuong;
}

// -----------------------
// xoaSach()
//  Chức năng: Xóa sách ra khỏi danh sách theo ISBN.
//  Tham số: timISBN - mã ISBN của sách cần xóa.
//  Return: void
void xoaSach(char timISBN[]){
    int vitriSach = timSachTheoISBN(timISBN);
    printf("\n >>>> Ban co muon xoa Sach  [%s - %s] khong <<<<\n",ISBN[vitriSach],tenSach[vitriSach]);
    char xacNhan;
    getchar();
    printf("Xac nhan (y/n): ");
    scanf("%c",&xacNhan);

    if(xacNhan == 'y' || xacNhan == 'Y'){
        for(int i = vitriSach; i < tongSach - 1; i++){
            strcpy(ISBN[i],ISBN[i+1]);
            strcpy(tenSach[i],tenSach[i+1]);
            strcpy(tenTacGia[i],tenTacGia[i+1]);
            strcpy(tenNhaXuatBan[i],tenNhaXuatBan[i+1]);
            strcpy(namXuatBan[i],namXuatBan[i+1]);
            strcpy(theLoai[i],theLoai[i+1]);
            // strcpy(giaSach[i],giaSach[i+1]);
            giaSach[i] = giaSach[i+1];
        }
        tongSach--;
        printf("\n >>> Da xoa Sach thanh cong <<<\n");
    } 
    else if(xacNhan == 'n' || xacNhan == 'N'){
        printf("\n >>> Huy xoa Sach <<<\n");
    }
    else{
        printf("\n >>> Sai cu phap <<<\n");
    }
}

