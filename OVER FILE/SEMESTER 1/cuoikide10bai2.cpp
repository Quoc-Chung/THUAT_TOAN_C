#include <stdio.h>
#include <math.h>
void nhapmang(float  a[100][100],int &m,int &n){
	do{
		printf("Nhap kich thuoc :");
		scanf("%d%d",&m,&n);
		if(m<1 || n<1){
			printf("\nVui lòng nhập lại :");
		}
	}while (m<1 || n<1);
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			printf("Nhap gia tri a[%d][%d]:",i,j);
			scanf("%f",&a[i][j]);
		}
	}
}
void inmang(float a[100][100],int m,int n){
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			printf("%.1f ",a[i][j]);
		}
		printf("\n");
	}
}
// tính và in ra màn hình b[j] với b[j] là giá trị lớn nhất của cột thứ j
void maxcotnhap(float a[100][100],int m,int n,int &cot){
	do{
		printf("\nNhap cot :");
		scanf("%d",&cot);
		if(cot <1 || cot >n){
			printf("\nVui long nhap lai cot.");
		}
	} while (cot <1 || cot >n);
	float max=a[1][cot];
	for (int i=1;i<=m;i++){
		if(max<a[i][cot]){
			max=a[i][cot];
		}
	}
	printf("\n Gia tri max cua cot vua nhap la :%.2f",max);
}	
int main (){
	int m,n;
	int cot;
	float a[100][100];
	nhapmang(a,m,n);
	inmang(a,m,n);
//	timmaxtunghang(a,m,n);
//	timmintungcot(a,m,n);
    maxcotnhap(a,m,n,cot);
	return 0;	
	}