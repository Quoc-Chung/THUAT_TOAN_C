#include <stdio.h>
#include <math.h>
void  nhapmang(int  a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap mang a[%d][%d]:",i,j);
		 scanf("%d",&a[i][j]);	
		}
	}
}
void inmang(int  a[100][100],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void timkiemphantu(int a[100][100],int m,int n,int x){
	int flag=0;
	int sotontai;
	int vitri1,vitri2;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(x==a[i][j]){
				flag=1;
				sotontai=x;
				vitri1=i;
				vitri2=j;
			printf("\nTon tai so %d o vi tri a[%d][%d]",sotontai,vitri1,vitri2);
			}
		}
	}
	if(flag==0){
		printf("Khong ton tai so %d trong ma tran",x);
	}
}
int somaxtrongmang(int a[100][100],int m,int n){
	int max=0;
	int vitri1,vitri2;
	for (int i=0;i<m;i++){
		for  (int j=0;j<n;j++){
			if(max<a[i][j]){
				max=a[i][j];
				vitri1=i;
				vitri2=j;
				
			}
		}
	}
	printf("\nSo max trong mang co gia tri %d vi tri a[%d][%d]",max,vitri1,vitri2);
}

int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	int a[100][100];
	nhapmang(a,m,n);
	printf("Ma tran la :\n");
	inmang(a,m,n);
	int x;
	printf("Nhap so kiem tra :");
	scanf("%d",&x);
	timkiemphantu(a,m,n,x);
	somaxtrongmang(a,m,n);
	return 0;
}