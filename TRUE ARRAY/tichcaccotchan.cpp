#include <stdio.h>
#include <math.h>
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
void caccotchan(int a[100][100],int m,int n){
	for (int j=0;j<n;j+=2){// duyt tung chi so cot 
	  int tich=1;	 
		for (int i=0;i<m;i++){// duyt cac chi so hang tu hang 1 den hang cuoi
			tich*=a[i][j];
		}
		printf("%d\n",tich);	
	}
}
void  giatrimincot (int a[100][100],int m,int n){
	for (int j=0;j<n;j++){
		int min=a[0][0];
		for (int i=0;i<m;i++){
			if(min >= a[i][j])
				min=a[i][j];
		}
		printf("%d\n",min);
	}
}

int main (){
	int m,n;
	scanf("%d%d",&m,&n);
	int a[100][100];
	nhapmang(a,m,n);
	printf("Mang vua nhap la :\n");
	inmang (a,m,n);
	caccotchan(a,m,n);
	printf("Cac gia tri nho nhat cua cac hang la :\n");
	giatrimincot(a,m,n);
	
}
