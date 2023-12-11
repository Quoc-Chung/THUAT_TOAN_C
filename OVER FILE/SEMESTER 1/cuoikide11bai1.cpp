#include <stdio.h>
#include <math.h>
void nhapmang(float a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%f",&a[i]);
	}
}
void inmang(float a[],int n){
	printf("\nMang in ra la :\n");
	for (int i=1;i<=n;i++){
		printf("%.1f ",a[i]);
	}
}
void tbcongnhan(float a[],int n){
	float nhan=1,cong=0;
	int dem=0;
	for (int i=1;i<=n;i++){
		if(a[i]>=0 && a[i]<=100){
			nhan*=a[i];
			cong+=a[i];
			dem++;
		}
	}
	float tbnhan=nhan/(float)dem;
	float tbcong=cong/(float)dem;
	printf("\nTrung binh nhan la :%.2f",tbnhan);
	printf("\nTrung binh cong la :%.2f",tbcong);
}
int main (){
	int n;
	do{
		printf("Nhap n:");
		scanf("%d",&n);
		if(n<1){
			printf("\nVui long nhap lai:");
		}
	}while (n<1);
	float a[100];
	nhapmang(a,n);
	inmang(a,n);
	tbcongnhan(a,n);
	return 0;
}