#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
void nhapmang(int a[],int n){
	for (int i=1;i<=n;i++){
		printf("Nhap phan tu thu a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
void sapxep(int a[],int n){
	int tam;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if(a[i]<=a[j]){
				tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}
		}
	}
	printf("\nMang da sap xep la :\n");
	
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	} 
}
int cmp(const void *a,const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
	 return *x-*y;
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	int a[100];
	nhapmang(a,n);
//	sapxep(a,n);
qsort (a,n,sizeof(int ),cmp);
	
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	} 
	return 0;
}
