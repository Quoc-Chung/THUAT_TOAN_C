#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//t?o m?t t?p ban d?u tru?c  
/*
XIN_CHAO_MOI_NGUOI_MINH_TEN_LA_CHUNG
18
*/
int main() {
    char tentep[100];
    printf("Nhap ten tep: ");
    scanf("%s",tentep);
    FILE *f;
    char duong_dan[100]="C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\";
     strcat(duong_dan,tentep); 
      f=fopen(duong_dan,"r");
    if (f == NULL){
        printf("\nKhong the mo tep!");
        exit(1);
    }
    char gioithieu[100];
    int tuoi;
    fscanf(f, "%s %d", gioithieu, &tuoi);
    fclose(f);
    printf("\n%s. Minh %d tuoi.", gioithieu, tuoi);
    return 0;
}
