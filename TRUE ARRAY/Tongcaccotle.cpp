#include <stdio.h>
#include  <math.h>
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
// tinh tich cac cot le 
void cotle (int a[100][100],int m,int n){
	int tich;
	int flag;
	for (int j=1;j<n;j++){
		 tich=1;
		 flag=0;
		 for (int i=0;i<m;i++){
		 	if(j%2!=0){
		 		flag=1;
		 	tich *=a[i][j];
		 }
		    
		 }
		 if(flag==1){
		printf("%d\n",tich);
	}
	}
}
int main(){
	int m,n;
	printf("Nhap kich thuoc mang :\n");
	scanf("%d %d",&m,&n);
	int a[100][100];
	nhapmang(a,m,n);
	printf("Ma tran la :\n");
	inmang(a,m,n);
	cotle(a,m,n);
}