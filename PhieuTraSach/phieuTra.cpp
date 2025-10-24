#include <stdio.h>
#include <stdbool.h>

#define MAX 200

// Lưu thông tin Đọc Giả mượn sách nào
// Lưu thông tin Đọc Giả
char maDG[MAX][7];
char tenDG[MAX][40];        
char cmnd[MAX][12];

// Lưu thông tin Sách
char ISBN[MAX][5];
char tenSach[MAX][100];
char soluongSach[MAX][2];

// Biết số lần mượn sách
// Ngày mượn sách / Ngày trả sách dự kiến
// Số lần đã trả sách