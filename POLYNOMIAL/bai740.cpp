#include <stdio.h>
#include <math.h>
// ham tinh giai thua
int giaithua(int a){
	int giaithua=1;
	for (int i=a;i>=1;i--){
		giaithua*=i;
	}
	return giaithua;	
}
int main (){
	int n;
	printf("\nNhap n:");
	scanf("%d",&n);
	int tong=0;
	for (int i=1;i<=n;i++){
		tong +=giaithua(i);
		
	}
	printf("Tong la :%d",tong);
	return 0;
}