#include <stdio.h>
#include <math.h>
void nhapmang(int a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap mang a[%d][%d]:",i,j);
		 scanf("%d",&a[i][j]);	
		}
	}
}
void inmang(int a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
int tichduongcheochinh (int a[100][100],int m,int n){
	int tich=1;
	for (int i=0;i<=m;i++){
		for (int j=0;j<n;j++){
			if(i==j){
				tich *=a[i][j];
			}
		}
	}
	return tich;
}
int main (){
	int m,n;
	scanf("%d %d",&m,&n);
	int a[100][100];
	nhapmang (a,m,n);
	printf("%d",tichduongcheochinh(a,m,n));
	
	}
