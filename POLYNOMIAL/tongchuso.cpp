#include <stdio.h>
#include <math.h>
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	int tong=0;
	while (n>0){
		tong+=n%10;
		n/=10;
	}
	printf("%d",tong);
}