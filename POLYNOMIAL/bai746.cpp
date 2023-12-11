#include <stdio.h>
#include <math.h>
float giaithua(int a){
	float giaithua=1;
	for (int i=a;i>=1;i--){
		giaithua*=i;
	}
	return giaithua;
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	float x;
	printf("\nNhap x:");
	scanf("%f",&x);
	float tong=1;
//	float mau=1;
	for (int i=2;i<=2*n;i+=2){
	//	mau*=(float)i;
		tong+=(pow(x,(float)i)/giaithua(i));
	}
	printf("%.2f",tong);
}