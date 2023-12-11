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
 void  tongsole(int a[100][100],int m,int n){
	int sum1=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j]%2==1)
				sum1+=a[i][j];
		}
	}
  printf("\nTong ca so le ma tran la :%d",sum1);
}
void timmintungcot (int a[100][100],int m,int n){
	int min=a[0][0];
	int j=0;
	while (j<n){
		min=a[0][j];
		for (int i=0;i<m;i++){
			if(min>a[i][j]){
				min=a[i][j];
			}
		}
		printf("%d\n",min);
		j++;
	}
}
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	int a[100][100];
	nhapmang(a,m,n);
	printf("Ma tran la :\n");
	inmang(a,m,n);
	tongsole(a,m,n);
	printf("\nSo nho nhat tung cot la :\n");
	timmintungcot(a,m,n);
}