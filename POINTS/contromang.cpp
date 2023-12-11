#include <stdio.h>
#include <math.h>
void nhapmang(int x[],int &n){
	do{
		printf("Nhap n:");
		scanf("%d",&n);
		if(n<1){
			printf("\nVui long nhap lai.");
		}
	}while (n<1);
	for (int i=1;i<=n;i++){
		printf("\na[%d]:",i);
		scanf("%d",&x[i]);
	}
}
void inmang(int x[],int n){
	for (int i=1;i<=n;i++){
		printf("%d ",x[i]);
	}
}
void nhap(int *a,int &n){
		do{
		printf("Nhap n:");
		scanf("%d",&n);
		if(n<1){
			printf("\nVui long nhap lai.");
		}
	}while (n<1);
	for (int i=1;i<=n;i++){
		printf("\na[%d]: ",i);
		scanf("%d",a+i);
	}
}
void in(int *a,int n){
	for (int i=1;i<=n;i++){
		printf("%d ",*(a+i));
	}
}
int main (){
	int n;
	int* a =(int*)calloc(n,sizeof(int));// cap phat dong vua du dung trong mang 
	nhap(a,n);
	in(a,n);
//	int a[100];
//	nhapmang(a,n);
//	inmang(a,n);
	return 0;
}