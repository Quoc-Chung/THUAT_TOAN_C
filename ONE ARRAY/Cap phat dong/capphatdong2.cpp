#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
	int n;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	int *a;// khai báo mảng a
	//int* ptr = (int*)malloc(n*sizeof(int));
   a	= (int*)calloc(n, sizeof(int));// cấp phát động cho mảng a
	if(a==NULL){
		printf("\nError: Khong cap phat duoc vung nho");
		exit(1);
	}
	
	for(int i=0;i<n;i++){
		printf("a[%d]=",i);
		scanf("%d",a+i);// tuong dduong vói &(a[i])
	}
	
	// Xuat mang
//	for(int i=0; i<n; i++){
//		printf("%d ", *(a+i));
//	}
//	
	int x;
	printf("\nKich co mang muon thay doi la: ");
	scanf("%d", &x);
	// kiểu realloc trả về là một kiểu void ==>ép sang kiểu int
	int *tam =(int *)realloc(a, x * sizeof(int));// cấp phát thêm bộ nhớ cho mảng và lưu trữ nó vào mảng mới
	// kiểm tra có cấp phất được mảng mới không  
	if(tam==NULL){
		printf("\nxay ra loi khi cap phat bo nho them");
		exit(1);
	}
	else{
		a=tam;// reset adress array a
	}
// giúp đảm bảo rằng mảng a sẽ trỏ tới địa chỉ mới được cấp phát bởi hàm realloc().
	//nhập mảng cáp phát thêm
	for(int i=n;i<x; i++){
		printf("a[%d]=",i);
		scanf("%d",a+i);
	}
	// Xuat mang
	printf("\n");
	for(int i=0; i<x; i++){
		printf("%d ", *(a+i));
	}
	// giải phóng bộ nhớ 
	free(a);
}