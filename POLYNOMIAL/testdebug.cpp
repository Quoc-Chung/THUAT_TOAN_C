#include <stdio.h>
#include <math.h>
int demso(int n){
	int dem=0;
	while (n>0){
		dem++;
		n/=10;
	}
	return dem;
}
int main(){
	int n;
	printf("\nNhap so n:");
	scanf("%d",&n);
	int sogiua=0;
	int luong=demso(n);
	int dung=luong/2;
	//printf("%d",dung);
	while (luong!=dung){
		sogiua=n%10;
		n/=10;
		luong--;
	}
	printf("So o giua la :%d",sogiua);
}