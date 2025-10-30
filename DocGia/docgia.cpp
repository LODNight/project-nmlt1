#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "docGia.h"
// Khai báo biến toàn cục là MAX với kí tự tối đa là 200 đơn vị
#define MAX 200

char maDG[MAX][7];         // Không được trùng
char tenDG[MAX][40];        
char cmnd[MAX][12];         // Không được trùng
int gioiTinh[MAX];
char email[MAX][40];        // Không được trùng
char diachi[MAX][100];
char ngayLapThe[MAX][20];
char ngayHetHanThe[MAX][20];
int tongSoDG = 0;
int d, m, y;

// --------------------------
// Nap Du lieu
void napDuLieuDGMau() {
    tongSoDG = 3;
    // strncpy(): dùng để thêm chỉ định tối đa các ký tự vào danh sách và đảm bảo kết thúc bằng \0:
    strncpy(maDG[0], "DG001", sizeof(maDG[0]) - 1);
    strncpy(maDG[1], "DG002", sizeof(maDG[1]) - 1);
    strncpy(maDG[2], "DG003", sizeof(maDG[2]) - 1);

    strncpy(tenDG[0], "Nguyen Van A", sizeof(tenDG[0]) - 1);
    strncpy(tenDG[1], "Tran Thi B", sizeof(tenDG[1]) - 1);
    strncpy(tenDG[2], "Le Van C", sizeof(tenDG[2]) - 1);

    strncpy(cmnd[0], "111", sizeof(cmnd[0]) - 1);
    strncpy(cmnd[1], "987654321", sizeof(cmnd[1]) - 1);
    strncpy(cmnd[2], "01234", sizeof(cmnd[2]) - 1);

    gioiTinh[0] = 1;
    gioiTinh[1] = 0;
    gioiTinh[2] = 1;

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

// =======[THEM THONG TIN]=======
// --------------------------
// Thêm thong tin cua Doc Gia
void themThongTinDocGia(){
    int d,m,y;
    bool hopLe = false;
    if(tongSoDG >= MAX){
        printf(">> Thu vien da day, khong the them doc gia moi <<\n");
    }

    printf("\n====== THEM DOC GIA MOI ======\n");
    // Thêm tên DG
    printf("Them ho ten Doc Gia: ");
    fgets(tenDG[tongSoDG],40,stdin);
    tenDG[tongSoDG][strcspn(tenDG[tongSoDG],"\n")] = '\0';

    // Kiem tra CMND Doc Gia
    kiemTraCMNDDocGia();

    // Them Gioi Tinh
    int gt = 0;
    do{
        printf("Them Gioi tinh (0:Nam, 1:Nu, 2:Khac):  ");
        scanf("%d",&gt);
        if(gt >= 0 && gt <= 2){
            gioiTinh[tongSoDG] = gt;
            hopLe = true;
        }else{
            printf("\n>>> LOI: Lua chon khong hop le <<<\n");
        }
    } while(!hopLe);
    
    
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

// =======[IN THONG TIN]=======
// --------------------------
// In thong tin tat ca Doc Gia
void inThongTinToanBoDocGia(){
    printf("\n----------------------------------\n");
    printf("\n====== DANH SACH [DOC GIA] ======\n");
    if(tongSoDG == 0){
        printf("Chua co doc gia");
        return;
    }
    printf("Ma DG |    ho va ten    |    cmnd    |         email        | gioi tinh |     dia chi       |  ngay lap  | ngay het han" );
    for(int i=0; i < tongSoDG; i++){
        inThongTinDocGiav3(i);
    }
    printf("\n----------------------------------\n");
}

// In thong tin Doc Gia theo ten
// In 1 Doc Gia 
void inThongTinDocGiav1(int i){
    printf("\tMa DG:         | %s\n", maDG[i]);
    printf("\tTen DG:        | %s\n", tenDG[i]);
    printf("\tCMND:          | %s\n", cmnd[i]);

    if(gioiTinh[i] == 0) printf("| Nam ");
    else if(gioiTinh[i] == 1) printf("| Nu ");
    else if(gioiTinh[i] == 2) printf("| Khac "); 

    printf("\tEmail:         | %s\n", email[i]);
    printf("\tDia chi:       | %s\n", diachi[i]);
    printf("\tNgay Lap The:  | %s\n", ngayLapThe[i]);
    printf("\tNgay Het Han:  | %s\n", ngayHetHanThe[i]);  
}

// In nhieu Doc Gia 
void inThongTinDocGiav2(int i){
    printf("%05s | %20s | %12s | %20s \n", maDG[i], tenDG[i],cmnd[i],email[i]);    
}

// In nhieu Doc Gia voi day du thong tin 
void inThongTinDocGiav3(int i){
    printf("\n%05s ", maDG[i]);
    printf("| %15s ", tenDG[i]);
    printf("| %10s ", cmnd[i]);
    printf("| %20s ", email[i]);
    // Gioi tinh
    if(gioiTinh[i] == 0) printf("|    Nam    ");
    else if(gioiTinh[i] == 1) printf("|    Nu     ");
    else if(gioiTinh[i] == 2) printf("|    Khac  ");    
    
    printf("| %17s ", diachi[i]);
    printf("| %10s ", ngayLapThe[i]);
    printf("| %10s ", ngayHetHanThe[i]);
}


// IN tong so luong Doc Gia
void inTongSoLuongDocGia(){
    printf("\n--------- THONG KE SO LUONG DOC GIA ---------\n");
    if(tongSoDG < 1){
        printf("\n>>> Khong tim thay doc gia <<<\n");
        return;
    }
    printf("Tong so Doc Gia hien dang co la: %d\n", tongSoDG);
}

// IN tong so luong Doc Gia theo gioi tinh
void inTongSoLuongDocGiaTheoGioiTinh(){
    printf("\n--------- THONG KE SO LUONG DOC GIA ---------\n");
    if(tongSoDG < 1){
        printf("\n>>> Khong tim thay doc gia <<<\n");
        return;
    }
    int tongNam = 0;
    int tongNu = 0;
    int tongKhac = 0;
    for(int i = 0; i < tongSoDG; i++){
        if(gioiTinh[i] == 0) tongNu++;
        if(gioiTinh[i] == 1) tongNam++;
        if(gioiTinh[i] == 2) tongKhac++;
    }

    printf("Tong so Doc Gia hien dang co la: %d\n", tongSoDG);
    printf("\n------------------------------\n");
    printf("Trong do co\n");
    printf("- NAM: %d\n", tongNam);
    printf("- NU: %d\n", tongNu);
    printf("- KHAC: %d\n", tongKhac);
    printf("------------------------------\n");
}


// =======[TIM KIEM]=======
// --------------------------
// Tim Doc Gia theo CMND  return vi tri 
int timDocGiaTheoCMND(char timCMND[]){
    int vitriDocGia = -1;
    for(int i=0; i<tongSoDG; i++){
        if(strcmp(cmnd[i], timCMND) == 0){
            vitriDocGia = i;
            break;
        }
    }
    return vitriDocGia;
}

// Tim Doc gia theo ten  return vi tri
void timDocGiaTheoTen(char timTenDG[]){
    for(int i=0; i < tongSoDG; i++){
        if(strstr(tenDG[i],timTenDG) != NULL){
            inThongTinDocGiav3(i);
        }
    }
}

// Tim Ma doc Gia theo CMND  return vi tri 
void timMaDocGiaTheoCMND(char timCMND[], char ketqua[]){
    int vitri = timDocGiaTheoCMND(timCMND);
    if(vitri != -1){
        strcpy(ketqua,maDG[vitri]);
    } else{
        strcpy(ketqua,"NULL");
    }
}

// Tim Doc Gia theo ten   return vi tri 
int timDocGiaTheoMaDG(char maDGtim[]){
    int vitriDocGia = -1;
    for(int i=0; i<tongSoDG; i++){
        if(strstr(maDG[i], maDGtim) != NULL){
            vitriDocGia = i;
        }
    }
    return vitriDocGia;
}

// Tim CMND theo maDG   return CMND
void timCMNDDocGiaTheoMaDG(char maDGtim[], char ketqua[]){
    int vitriDocGia = -1;
    for(int i=0; i < tongSoDG; i++){
        if(strcmp(maDG[i], maDGtim) == 0){
            vitriDocGia = i;
            break;
        }
    }

    if(vitriDocGia != -1){
        strcpy(ketqua, cmnd[vitriDocGia]);
    } else {
        strcpy(ketqua, "NULL");
    }
}


// IN Thong tin Doc Gia sau khi tim theo CMND (theo hang doc)
void inThongTinDocGiaSauKhiTimTheoCMND(char timCMND[]){
    int vitriDocGia = timDocGiaTheoCMND(timCMND);
    if(vitriDocGia >= 0){
        printf("\n>> Tim Thay Doc Gia <<\n");
        printf("------------------------------------------\n");
        inThongTinDocGiav1(vitriDocGia);
        printf("------------------------------------------\n");
    }
    if(vitriDocGia < 0) 
        printf("\n>> Khong tim thay doc gia <<\n");
}

// IN Thong tin Doc Gia sau khi tim theo CMND (theo hang ngang)
void inThongTinDocGiaSauKhiTimTheoCMNDv2(char timCMND[]){
    int vitriDocGia = timDocGiaTheoCMND(timCMND);
    if(vitriDocGia >= 0){
        printf("\n>> Tim Thay Doc Gia <<\n");
        inThongTinDocGiav2(vitriDocGia);
    }
    if(vitriDocGia < 0) 
        printf("\n>> Khong tim thay doc gia <<\n");
}
// IN Thong tin Doc Gia sau khi tim theo ten
void inThongTinDocGiaSauKhiTimTheoTen(char maDGtim[]){
    int vitriDocGia = timDocGiaTheoMaDG(maDGtim);
    if(vitriDocGia >= 0){
        printf("\n>> Tim Thay Doc Gia <<\n");
        printf("------------------------------------------\n");
        inThongTinDocGiav2(vitriDocGia);
        printf("------------------------------------------\n");
    }
    if(vitriDocGia < 0) 
        printf("\n>> Khong tim thay doc gia <<\n");
}

// ========[CHINH SUA]========
// --------------------------
// Chinh sua thong tin Doc Gia
void suaThongTinDocGia(char timCMND[]){
    // Tìm Đọc Giả
    int vitriDG = timDocGiaTheoCMND(timCMND);
    int d,m,y;
    bool hopLe = false;
    if(vitriDG == -1) return;
    else{
        printf("\n>> Bat dau sua thong tin Doc Gia <<\n");
        // nếu để khai báo int choice; thì sẽ có khả năng random là 0
        int choice = -1;
        do{
            printf("---------------------------------------");
            printf("\n+++ CHINH SUA CAC THONG TIN SAU +++\n");
            printf("\t1. Ten DG\n");
            printf("\t2. CMND\n");
            printf("\t3. Gioi Tinh\n");
            printf("\t4. Email\n");
            printf("\t5. Dia chi\n");
            printf("\t6. Ngay Lap The\n");
            printf("\t7. Ngay Het Han The\n");
            printf("\t0. Thoat\n");
            printf("---------------------------------------\n");
            printf("Lua chon chinh sua: ");
            scanf("%d",&choice);
            getchar();
            
            switch (choice)
            {
            case 1:{
                char ten[MAX];
                do{
                    // Ten
                    printf("Ten: %s\n", tenDG[vitriDG]);
                    printf("Nhap ho ten moi: ");
                    fgets(ten,sizeof(ten), stdin);
                    // Xóa kí tự "\n"
                    ten[strcspn(ten,"\n")] = '\0';

                    if(ten != NULL){
                        strcpy(tenDG[vitriDG],ten);
                        hopLe = true;
                    }
                    else{
                        printf("\n>>> LOI: Khong hop le. Vui long thu lai <<<\n");
                    }
                } while(!hopLe);
                break;
            }
            case 2:{
                // CMND
                char c[MAX];
                do{
                    // Ten
                    printf("CMND: %s\n", cmnd[vitriDG]);
                    printf("Nhap CMND moi: ");
                    fgets(c,sizeof(c), stdin);
                    // Xóa kí tự "\n"
                    c[strcspn(c,"\n")] = '\0';

                    if(c != NULL){
                        strcpy(cmnd[vitriDG],c);
                        hopLe = true;
                    }
                    else{
                        printf("\n>>> LOI: Khong hop le. Vui long thu lai <<<\n");
                    }
                } while(!hopLe);
                break;
            }
            case 3:{
                // Gioi Tinh
                printf("Gioi tinh hien tai la: ");
                if(gioiTinh[vitriDG] == 0) 
                    printf("Nam\n");
                else if(gioiTinh[vitriDG] == 1) 
                    printf("Nu\n");
                else if(gioiTinh[vitriDG] == 2) 
                    printf("Khac\n");
                else printf("Chua co thong tin\n");

                int gt = 0;
                bool hopLe = false;
                do{
                    printf("Them Gioi tinh (0:Nam, 1:Nu, 2:Other):  ");
                    scanf("%d",&gt);
                    getchar();
                    if(gt >= 0 && gt <=2){
                        gioiTinh[vitriDG] = gt;
                        hopLe = true;
                    }
                    else{
                        printf("\n>>> LOI: Khong hop le. Vui long thu lai <<<\n");
                    }
                } while(!hopLe);
                break;
            }
            case 4:
                // Email
                printf("Emai: %s\n", email[vitriDG]);
                printf("Nhap email moi: ");
                fgets(email[vitriDG],sizeof(email[vitriDG]), stdin);
                // Xóa kí tự "\n"
                email[vitriDG][strcspn(email[vitriDG],"\n")] = '\0';
                break;
            case 5:
                // Dia chi
                printf("Dia chi: %s\n", diachi[vitriDG]);
                printf("Nhap dia chi moi: ");
                fgets(diachi[vitriDG],sizeof(diachi[vitriDG]), stdin);
                // Xóa kí tự "\n"
                diachi[vitriDG][strcspn(diachi[vitriDG],"\n")] = '\0';
                break;
            case 6:
                // Ngay lap the
                printf("Ngay lap the: %s\n", ngayLapThe[vitriDG]);
                printf("Nhap Ngay Lap The Moi (dd/mm/yyyy): ");
                scanf("%d/%d/%d",&d,&m,&y);
                kiemTraNgayHopLe(d, m, y);
                break;
            case 7:
                // Ngay het han the
                printf("Ngay het han the: %s\n", ngayHetHanThe[vitriDG]);
                printf("Nhap Ngay het han the moi (dd/mm/yyyy): ");
                scanf("%d/%d/%d",&d,&m,&y);
                kiemTraNgayHopLe(d, m, y);
                break;
            case 0:
                printf("\n>> Thoat Chinh Sua <<\n");
                break;
            default:
                break;
            }

        }while(choice != 0);
    }
}

// Xoa Thong tin Doc Gia
void xoaDGTheoCMND(char timCMND[]){
    int vitriDG = timDocGiaTheoCMND(timCMND);
    printf("\n >>>> Ban co muon xoa Doc Gia  [%s - %s] khong <<<<\n",maDG[vitriDG],tenDG[vitriDG]);
    char xacNhan;
    getchar();
    printf("Xac nhan (y/n): ");
    scanf("%c",&xacNhan);

    if(xacNhan == 'y' || xacNhan == 'Y'){
        for(int i = vitriDG; i < tongSoDG - 1; i++){
            strcpy(maDG[i],maDG[i+1]);
            strcpy(tenDG[i],tenDG[i+1]);
            gioiTinh[i]=gioiTinh[i+1];
            strcpy(email[i],email[i+1]);
            strcpy(diachi[i],diachi[i+1]);
            strcpy(ngayLapThe[i],ngayLapThe[i+1]);
            strcpy(ngayHetHanThe[i],ngayHetHanThe[i+1]);
        }
        tongSoDG--;
        printf("\n >>> Da xoa thanh cong <<<\n");
    } 
    else if(xacNhan == 'n' || xacNhan == 'N'){
        printf("\n >>> Huy xoa doc gia <<<\n");
    }
    else{
        printf("\n >>> Sai cu phap <<<\n");
    }
}


// =======[VALIDATION]=======
// --------------------------
// Kiem tra CMND Doc Gia
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

// Kiem tra Email
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

// Kiem tra Ngay Them va Tra
int timNamNhuan(int y){
    if((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)){
        return 29;
    } else {
        return 28;
    }
}

// Tim so ngay trong 1 thang
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

// Kiem tra ngay hop le
bool kiemTraNgayHopLe(int d, int m, int y){
    if(d <=0 || m <=0 || m > 12 || y <= 2003)
        return false;
    else if(d > timSoNgayTrongThang(m,y))
        return  false;
    else return true;
}

// Hop le khi nam tu 2003 tro di
void kiemTraNgayLapThe(){
    int d,m,y;
    bool hopLe = false;

    do{
        printf("Them Ngay Lap The (dd/mm/yyyy): ");
        scanf("%d/%d/%d",&d,&m,&y);
       
        hopLe = kiemTraNgayHopLe(d,m,y);
        
        if(!hopLe) 
            printf("\n>> Ngay ko hop le. Vui long nhap lai <<\n");
    } while(!hopLe);

    // Lưu chuỗi ngày hợp lệ
    sprintf(ngayLapThe[tongSoDG], "%02d/%02d/%04d", d, m, y);

    themNgayHetHanThe(d, m, y);

}

// Het han sau 48 thang ke tu ngay lap the
void themNgayHetHanThe(int d, int m, int y){
    m += 48;
    y += (m-1)/12;
    m = ((m-1) % 12) + 1;

    int dayMax = timSoNgayTrongThang(m,y);
    if(d > dayMax) d = dayMax;

    sprintf(ngayHetHanThe[tongSoDG],"%01d/%02d/%04d",d,m,y);
}

