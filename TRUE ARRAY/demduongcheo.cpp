#include <stdio.h>
#include <math.h>
void nhapmang(int a[100][100],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("Nhap a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void  inmang(int a[100][100],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
}
printf("\n");
}
}
void cheophu (int a[100][100],int n){
	int tong=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(i+j==n-1){
			tong+=a[i][j];
		}
		}
	}
	printf("\nTong cheo phu la :%d",tong);
}
int main (){
	int a[100][100];
	int n;
	printf("Nhap kich thuoc :");
	scanf("%d",&n);
	nhapmang(a,n);
	printf("\nMang ma tran la :\n");
	inmang(a,n);
	cheophu (a,n);
	
}
