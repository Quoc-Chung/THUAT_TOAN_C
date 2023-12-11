#include <stdio.h>
#include <math.h>
void nhapmang(float a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap phan tu a[%d][%d]:",i,j);
			scanf("%f",&a[i][j]);
		}
	}
}
void inmang(float a[100][100],int m,int n){
		for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%.2f ",a[i][j]);
		}
		printf("\n");
}
}
// gia tri va vi tri cua phan tu max
void caculate1(float a[100][100],int m,int n){
	float max=0;
	int vitrihang;
	int vitricot;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(max<a[i][j]){
				max=a[i][j];
				vitrihang=i;
				vitricot=j;
			}
		}
	}
		printf("\nGia tri max la :%.2f",max);
		printf("\nVi tri cua gia tri max la a[%d][%d].",vitrihang,vitricot);
	
}
// tich cac cot le cua ma tran (duyet tung cot ---- kiem tra co phai cot le khong -----sau do duyet tu hang 1 den hang cuoi)
void tichcotle(float a[100][100],int m,int n){
	float tich;
	for (int j=1;j<=n;j++){
		  tich=1;
		 for (int i=0;i<m;i++){
		 	tich*=a[i][j];
		 }
 	printf("\nTich cot le la:%.2f",tich);
 	   j++;
 	   if(j+2>n)
 		break;
	}
}
int main (){
	int m,n;
	printf("Nhap kich thuoc ma tran :");
	scanf("%d%d",&m,&n);
	float a[100][100];
	nhapmang(a,m,n);
	printf("Mang duoc in ra la :\n");
	inmang(a,m,n);
	caculate1(a,m,n);
	tichcotle(a,m,n);
	return 0;
}