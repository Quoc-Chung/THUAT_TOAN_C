#include <stdio.h>
#include <math.h>
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	int tich=1;
	while (n>0){
		int a=n%10;
		if(a%2==1){
			tich*=a;
		}
		n/=10;
	}
	printf("%d",tich);
}