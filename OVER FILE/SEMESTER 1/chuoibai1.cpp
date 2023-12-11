#include <stdio.h>
#include <math.h>
void nhapday(float a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%f",&a[i]);
	}
}
void tongbai1(float a[],int n){
	float tong=0;
	int d=n;
	for (int i=1;i<=n;i++){
		tong+=a[i]/(float)d;
		d-=1;
	}
	printf("\nTong la:%.3f",sqrt(tong));
}
int main (){
	int n;
	do{
		printf("Nhap n:");
		scanf("%d",&n);
		if(n<1){
			printf("\nVui long nhap lai:\n");
		}
	}while (n<1);
	float a[100];
	nhapday(a,n);
	tongbai1(a,n);
}