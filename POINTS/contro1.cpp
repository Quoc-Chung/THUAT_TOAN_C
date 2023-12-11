#include <stdio.h>
#include <math.h>
void nhapn(int &n){
	printf("Nhap n:");
	scanf("%d",&n);
}
int main (){
	int n;
	printf("Nhap so n:");
	scanf("%d",&n);
	printf("\nSo n vua nhap la :%d",n);
	nhapn(n);
	printf("\nSo n trong ham la :%d",n);
//==>So n luc nay la da thay doi khi ham ket thuc 
// truyen tham chieu se lam thay doi duoc gia tri trong ham. 
	
	
	
	
}