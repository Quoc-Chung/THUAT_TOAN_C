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
void  tichcotle(float a[100][100],int m,int n){
    float tich;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			 tich = 1;
			if(j%2==1){
				tich=tich*a[i][j];
			}
		}
	}
	printf("Tich cot le :%f",tich);
}
void  maxmang(float a[100][100],int m,int n){
	float max=0;
	int x,y;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(max<a[i][j]){
				max=a[i][j];
				x=i;
				y=j;
			}
		}
	}
		printf("phan tu a[%d][%d] lon nhat la :%.2f",x,y,max);
}

int main (){
	int m,n;
	printf("Nhap kich thuoc :\n");
	scanf("%d %d",&m,&n);
	float a[100][100];
	printf("Nhap mang:\n");
	nhapmang (a,m,n);
	printf("Mang in ra la :\n");
	inmang (a,m,n);
	tichcotle(a,m,n);
    maxmang(a,m,n);
	
}