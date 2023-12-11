#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct Diem {
    int hoanh;
    int tung;
};

void LayMaTranTuFile(Diem **d, int* n) {
//    char tentep[100];
//    printf("Nhap ten tep: ");
//    scanf("%s", tentep);
      FILE* f;
//    char duong_dan[100] = "C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\Bai Tap\\";
//    strcat(duong_dan, tentep);
      char duong_dan[100] = "C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\Bai Tap\\Bai1-3.txt";
      f = fopen(duong_dan, "r");
    if (f == NULL) {
        printf("\nKhong the mo tep!");
        exit(1);
    }
    fscanf(f, "%d", n);
    *d = (Diem*)malloc(*n * sizeof(Diem));
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%d %d", &((*d)[i].hoanh), &((*d)[i].tung));
    }
    // Thử xem đã đọc được ma trận chưa 
    printf("\nDiem vua doc la:\n");
    for (int i = 0; i < *n; i++) {
        printf("%d %d\n", (*d)[i].hoanh, (*d)[i].tung);
    }
    fclose(f);
}
void KhoangCachX (Diem *d,int n){
	printf("\nKhoang cach tung  diem den truc hoanh :\n");
	for(int i=0;i<n;i++){
		printf("%d ",(d)[i].tung);
	}
}
void KhoangCachMax(Diem *d,int n){
	printf("\nKhoang cach max la :");
	float kcmax=0;
	for(int i=1;i<n;i++){
		if(sqrt(pow(d[i].hoanh-d[i-1].hoanh,2)+pow(d[i].tung-d[i].tung,2))){
			kcmax=sqrt(pow(d[i].hoanh-d[i-1].hoanh,2)+pow(d[i].tung-d[i].tung,2));
		}
	}
	printf("%.2f",kcmax);
} 
int main() {
    Diem* d;
    int n;
    LayMaTranTuFile(&d, &n);
    KhoangCachX (d,n);
    KhoangCachMax(d,n);
    free(d);
    return 0;
}
