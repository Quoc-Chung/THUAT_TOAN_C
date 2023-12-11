#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//  **a này là con trỏ trỏ tới địa chỉ của mảng  cấp  1 
void DocFile(int **a, int *n, char *NameFile){
    FILE *f;
    f = fopen(NameFile, "r");
    if (f == NULL) {
        printf("\nKhong the mo duoc file.");
        exit(0);
    }
    fscanf(f, "%d", n);
    
    *a = (int *)malloc(*n * sizeof(int));
    if (*a == NULL) {
        printf("\nKhong the cap phat bo nho.");
        exit(0);
    }
    for (int i = 0; i < *n; i++) {
        fscanf(f,"%d", *a+i);
    }
    printf("\nGia tri cua cac phan tu trong mang  la  :\n");
    for(int i=0;i<*n;i++){
    	printf("%d ",*(*a+i));
	}
    fclose(f);
}
void InFile(int *a,int n){
	for(int i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
}
int main(){
	int n,*a;
	char tentep[50];
	printf("\nNhap tep:");
	gets(tentep);
	DocFile(&a,&n,tentep);
	InFile(a,n);
	return 0;
}