#include <stdio.h>
#include <math.h>
void nhapmang(int a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap chi so a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void inmang (int a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	
}
void matrantamgiac(int a[100][100],int m,int n){      
	int flag=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(i>j && a[i][j]==0){
				flag=1;
			}
			}       
		}
	if(flag==1){
		printf("Ma tran tam giac duoi.");
	}
	else {
		printf("Khong la ma tran tam giac duoi.");
	}
	}
void mincheochinh (int a[100][100],int m,int n){
	int min=a[0][0];
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(i==j){
				if(min>a[i][j]){
					min=a[i][j];
				}
			}
		}
	}
	printf("\nGia tri nho nhat duong cheo chinh la %d ",min);
}
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	int a[100][100];
	nhapmang(a,m,n);
	printf("Mang ma tran la :\n");
	inmang(a,m,n);
	matrantamgiac(a,m,n);
	mincheochinh(a,m,n);
	
}