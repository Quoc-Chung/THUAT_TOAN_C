#include <stdio.h>
#include <math.h>
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	float tong=0;
	for (int i=1;i<=n;i++){
		tong+=(1.0*1)/(i*(i+1));
	}
	printf("%.2f",tong);
}