#include <stdio.h>
#include <math.h>
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	float tong=0;
	for (int i=0;i<=n;i++){
		//tong+=((2*i*1.0+1)/(2*i*1.0+2));
		tong +=(2*(float)i+1)/(2*(float)i+2);
		
	}
	printf("Tong la :%.3f",tong);
}
// ta thay i thuoc trong bieu thuc thuoc kieu int nen khi muon ra ket qua tong thi cac gia tri lam
// nen tong phai tuong thich kieu du lieu >> ep kieu trong c:*1.0 || (float )|| (int )
// thich ep kieu nao cung duoc 