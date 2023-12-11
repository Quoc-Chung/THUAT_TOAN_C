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
		tong+=a[i]/d;
		d--;
	}
	
}
void tongbai12(float a[],int n,float x){
	float tong=2005;
	for (int i=1;i<=n;i++){
		tong+=(x+2*i)/(2*i+7);
	}
	printf("Tong la :%.2f",tong);
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
	//nhapday(a,n);
	//tongbai1(a,n);
	float x;
	printf("\nNhap so x:");
	scanf("%f",&x);
	tongbai12(a,n,x);
}