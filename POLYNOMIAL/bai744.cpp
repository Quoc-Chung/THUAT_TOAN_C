#include <stdio.h>
#include <math.h>
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	float tong=0;
	float mau=0;
	for (int i=1;i<=n;i++){
		mau+=(float)i;
		tong+=1/mau;
	}
	printf("\nTong la :%.2f",tong);
}