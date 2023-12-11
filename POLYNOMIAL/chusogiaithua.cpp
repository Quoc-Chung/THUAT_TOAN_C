#include <stdio.h>
#include <math.h>
int giaithua(int n){
	int gt=1;
	for (int i=1;i<=n;i++){
		gt*=i;
	}
	return gt;
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	int tong=0;
	int res=0;
	while (n>0){
		res=n%10;
		tong+=giaithua(res);
		n/=10;
	}
	printf("Tong la :%d",tong);
}