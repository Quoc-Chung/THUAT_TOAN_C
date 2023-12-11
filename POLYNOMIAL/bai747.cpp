#include <stdio.h>
#include <math.h>
int main (){
	int n;
	printf("\nNhap n:");
	scanf("%d",&n);
	for (int i=n-1;i>=1;i--){
		if( i%2==1 && n%i==0){
			printf("%d",i);
			break;
		}
	}
	return 0;
}