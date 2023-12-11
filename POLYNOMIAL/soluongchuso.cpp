#include <stdio.h>
#include <math.h>
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	int dem=0;
	while (n>0){
		dem++;
		n/=10;
	}
	printf("%d",dem);
}