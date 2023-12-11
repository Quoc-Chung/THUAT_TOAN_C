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
	do{
	printf("\nNhap so n:");
	scanf("%d",&n);
	if(demso(n)<3 || demso(n)%2==0){
		printf("Vui long nhap lai.");
		break;
	}
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
}while (demso(n)<3 && demso(n)%2==0);
}