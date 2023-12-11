#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
void LayMaTranTuFile(int***a, int &m, int &n){
    FILE* f;
//  	char tentep[100];
//    printf("Nhap ten tep: ");
//    scanf("%s",tentep);
//    char duong_dan[100]="C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\Bai Tap\\";
//     strcat(duong_dan,tentep); 
    char duong_dan[100] ="C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\Bai Tap\\Bai1-2.txt";
    f = fopen(duong_dan,"r");
    if (f == NULL) {
        printf("\nKhong the mo tep!");
        exit(1);
    }
    fscanf(f,"%d%d",&m,&n);

    // Cấp phát động bộ nhớ cho ma trận
    *a = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        (*a)[i] = (int*)malloc(n*sizeof(int));
    }
    for (int i = 0; i <m; i++) {
        for (int j = 0; j <n; j++) {
            fscanf(f,"%d",&(*a)[i][j]);
        }
    }
    fclose(f);
}
void TrungBinhCong(int **a, int m, int n) {
    int dem = 0;
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] < 0) {
                tong += a[i][j];
                dem += 1;
            }
        }
    }
    if (dem > 0) {
        float x = (float)tong/dem;
        printf("\nTBC so am la: %.2f", x);
    } else {
        printf("\nKhong co so am.");
    }
}
void TimPhanTuAmLonNhat(int** a, int m, int n) {
    int maxAm = INT_MIN;
    int vitrih = 0,vitric = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] < 0 && a[i][j] > maxAm) {
                maxAm = a[i][j];
                vitrih = i;
                vitric = j;
            }
        }
    }
    printf("\nPhan tu lon nhat vi tri a[%d][%d]=%d", vitrih, vitric, maxAm);
}
int main() {
    int m, n;
    int **a;
    LayMaTranTuFile(&a, m, n);
    TrungBinhCong(a, m, n);
    TimPhanTuAmLonNhat(a, m, n);
    // Giải phóng bộ nhớ
    for (int i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}
