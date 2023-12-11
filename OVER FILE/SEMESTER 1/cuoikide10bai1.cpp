#include <stdio.h>
#include <math.h>
void nhapmang(float a[],int n){
	for(int i=1;i<=n;i++){
		scanf("%f",&a[i]);
	}
}
void inmang(float a[],int n){
	printf("\nMang vua nhap la :\n");
	for (int i=1;i<=n;i++){
		printf("%.2f ",a[i]);
	}
}
void bohaiso(float a[],int n){
	float so1=0;
	float so2=0;
	float max=-pow(10,5);
	for (int i=1;i<n;i++){
		if(max<a[i]*a[i+1]){
			max=a[i]*a[i+1];
			so1=a[i];
			so2=a[i+1];
		}
	}
	printf("\nHai bo so can tim la :%.1f %.1f",so1,so2);
}
int main (){
	int n;
	do {
		 printf("Nhap n:");
		 scanf("%d",&n);
		 if(n<1){
		 	printf("\nVui long nhap lai:\n");
		 }
	}while (n<1);
	float a[n];
	nhapmang(a,n);
	inmang(a,n);
	bohaiso(a,n);
	return 0;
}
