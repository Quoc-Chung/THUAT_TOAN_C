
// Cho biết các phần tử lớn nhất nằm ở vị trí nào.
#include <stdio.h>
#include <math.h>
void  nhapmang(float a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap mang a[%d][%d]:",i,j);
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
// gia tri max cua ma tran 
void  maxmatran(float a[100][100],int m,int n){
	float max=0;
	for (int i=0;i<=m;i++){
		for (int j=0;j<=n;j++){
			if (max<a[i][j]){
				max=a[i][j];
			}
		}
	}
}
void vitrimax(float a[100][100],int m,int n){
	int max=0;
	int vitrih;
	int vitric;
	printf("\nCac vi tri cua diem max la :\n");
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(max<a[i][j]){
				max=a[i][j];
			}
		}
	}
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			vitrih=0;
			vitric=0;
			if(a[i][j]==max){
				vitrih=i;
				vitric=j;	
				printf("\n%d %d",vitrih,vitric);
			}
		}
	}

	
}
int main(){
	int m,n;
	printf("Nhap kich thuoc m va n:");
	scanf("%d%d",&m,&n);
	float a[100][100];
	nhapmang(a,m,n);
	printf("Ma tran la :\n");
	inmang(a,m,n);
    //maxmatran(a,m,n);
    vitrimax(a,m,n);
    return 0;
}