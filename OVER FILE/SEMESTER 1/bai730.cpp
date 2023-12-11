#include <stdio.h>
#include <math.h>
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	int tong =0;
	for (int i=1;i<=n;i++){
		tong+=i;
	}
	printf("Tong la :%d",tong);
	return 0;
}