#include <stdio.h>
#include <math.h>
void nhapmang(float a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%f",&a[i]);
	}
}
void inmang(float a[],int n){
	printf("\nMang vua nhap la :\n");
	for (int i=1;i<=n;i++){
		printf("%.2f ",a[i]);
	}
}
void tong(float a[],int n){
	float tong=2022;
	for (int i=1;i<=n;i++){
		tong+=(a[i]+2*(float)i+1)/(2*(float)i+7);
	}
	printf("\nTong la :%.2f",tong);
}
int main(){
	int n;
	do{
		printf("Nhap n:");
		scanf("%d",&n);
		if(n<0){
			printf("Vui long nhap lai.");
		}
	}while(n<0);
	float a[n];
	nhapmang(a,n);
	//inmang(a,n);
	tong(a,n);
	return 0;
}


