#include <stdio.h>
#include <math.h>
int a[100][100];
int b[100*100];
void  nhapmang(int a[100][100],int m,int n){
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
void chuyendoimang (int a[100][100],int m,int n,int b[100*100],int &k){
	// taa phai truyen doi so cho kich thuoc cua mang gop la mot tham chieu de co the thay doi gia tri cua doi so k 
	int index=0;
    	k=m*n;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			b[index]=a[i][j];
			index++;
		}
	}
}
void inmangchuyendoi(int x[100*100],int c){
	for (int i=0;i<c;i++){
		printf("%d ",x[i]);
	}
}
int main (){
	int m,n;
	int k;
	int a[100][100];
    int b[100*100];
	scanf("%d %d",&m,&n);
	printf("Nhap mang:\n");
	nhapmang(a,m,n);
	printf("Ma tran la :\n");
	inmang(a,m,n);
	chuyendoimang(a,m,n,b,k);
	inmangchuyendoi(b,k);
}