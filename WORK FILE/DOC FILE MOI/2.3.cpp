#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sach {
    char TenSach[50];
    int nam;
    float gia;
};

void DocFile(Sach **s, int& n, char* tentep) {
    FILE* f;
    f = fopen(tentep, "r");
    if (f == NULL) {
        printf("\nKhong the doc duoc file.");
        exit(0);
    }
    fscanf(f, "%d", &n);
    *s = (Sach*)malloc(n * sizeof(Sach));
    for (int i = 0; i < n; i++) {
        fscanf(f, " %[^\n]", (*s)[i].TenSach);
        fscanf(f, "%d", &(*s)[i].nam);
        fscanf(f, "%f", &(*s)[i].gia);
    }
    fclose(f);
}

void InFile(Sach* s, int n, char* ketqua) {
    FILE* f;
    f = fopen(ketqua, "w");
    if (f == NULL) {
        printf("\nKhong the  mo duoc file ghi.");
        exit(0);
    }
    fprintf(f, "Sach duoc doc tu file la : \n");
    for (int i = 0; i < n; i++) {
        fprintf(f, "\nTen Sach :%s    Nam xuat ban:%d    Gia thanh :%.3f dong\n", s[i].TenSach, s[i].nam, s[i].gia);
    }
    fclose(f);
}

void TimKiemSach(Sach* s, int n, char* ketqua) {
    FILE* f;
    f = fopen(ketqua, "w");
    if (f == NULL) {
        printf("\nKhong the  mo file  ghi  .");
        exit(0);
    }
    char TenKiem[50];
    printf("\nNhap ten sach can kiem:");
    fgets(TenKiem, 50, stdin);
    int len = strlen(TenKiem);
    if (TenKiem[len - 1] == '\n') {
        TenKiem[len - 1] = '\0';  // Remove newline character
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(s[i].TenSach, TenKiem) == 0) {
            fprintf(f, "\n-------Sach duoc tim thay ------\n");
            fprintf(f, "\nTen Sach :%s", s[i].TenSach);
            fprintf(f, "\nNam xuat ban:%d", s[i].nam);
            fprintf(f, "\nGia thanh :%.3f dong.", s[i].gia);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        fprintf(f, "\nSach vua nhap khong duoc tim thay.");
    }
    fclose(f);
}

void TrungBinhCong(Sach* s, int n, char* ketqua) {
    FILE* f;
    f = fopen(ketqua, "w");
    if (f == NULL) {
        printf("\nKhong the  mo duoc file.");
        exit(0);
    }
    int dem = 0;
    float tong = 0;
    for (int i = 0; i < n; i++) {
        if (s[i].nam >= 2011 && s[i].nam < 2013) {
            dem++;
            tong += s[i].gia;
        }
    }
    fprintf(f,"TB gia cua cac cuon sach  tu nam  2011 -2013:%.3f\n", tong / dem);
    fclose(f);
}

int main() {
    int n;
    Sach* s;
    char tentep[40] = "Bai2-3.txt";
    char ketqua[40] = "Bai2-3_ketqua.txt";
    DocFile(&s, n, tentep);
    InFile(s, n, ketqua);
    TrungBinhCong(s, n, ketqua);
    TimKiemSach(s, n, ketqua);
    return 0;
}
