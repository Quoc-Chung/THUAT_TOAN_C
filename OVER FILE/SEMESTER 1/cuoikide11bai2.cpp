#include <stdio.h>
#include <math.h>
void nhap(int a[100][100],int &m,int &n){
	do{
		printf("Nhap kich thuoc :");
		scanf("%d%d",&m,&n);
		if(m<0 || n<0){
			printf("\nVui long nhap lai :\n");
		}
	}while (m<0 || n<0);
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Nhap a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void in (int a[100][100],int m,int n){
	printf("\nMang in ra la :\n");
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void sochanmax(int a[100][100],int m,int n){
	int max=a[0][0];
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j]%2==0 && max<a[i][j]){
				max=a[i][j];
			}
		}
	}
	printf("\nSo thoa man la :%d",max);
}
void tim(int a[100][100],int m,int n,int x){
	int vitri1=0;
	int vitri2=0;
	int flag=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j]==x){
				vitri1=i;
				vitri2=j;
				flag++;
			}
		}
	}
	if(flag==0){
		printf("\nKhong co so nao trong ma tran bang x.");
	}
	else{
	printf("\nTon tai so bang x tai vi tri a[%d][%d]=%d",vitri1,vitri2,x);
}
}
int main (){
	int m,n;
	int a[100][100];
	nhap(a,m,n);
	in(a,m,n);
//	sochanmax(a,m,n);
	int x;
	printf("Nhap x:");
	scanf("%d",&x);
	tim(a,m,n,x);
	return 0;
}