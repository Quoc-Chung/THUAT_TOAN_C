#include <stdio.h>
#include <math.h>
//   P(x)= a_0+ a_1x + a_2 x^2+ ….+ a_n x^n
//  Q(y)= b_0+ b_1x + b_2 x^2+ ….+ b_n x^n
// Nhập giá trị x, tìm P(x), Q(y)
// Tìm tổng P(x) + Q(y)
// Xuất tổng
void nhapheso(int a[],int n){
	for (int i=0;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
void inheso(int a[],int n){
	for (int i=0;i<=n;i++){
		printf("%d ",a[i]);
	}
}
float tong(int a[],int n,float x){
   int tong=0;
	for (int i=0;i<=n;i++){
		tong+=a[i]*pow(x,i);
	}
	//printf("\nTong la:%.2f",tong);
	return 1.0*tong;
}
int main(){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	int a[100];
	int b[100];
	printf("\nNhap he so mang a:\n");
	nhapheso(a,n);
	printf("\nHe so mang a la :\n");
	inheso(a,n);
	printf("\nNhap he so mang b:\n");
	nhapheso(b,n);
	printf("\nHe so mang b la :\n");
	inheso(b,n);
	float x;
	printf("\nNhap x:");
	scanf("%f",&x);
//	tong(a,n,x);
//	tong(b,n,x);
	float tonga=tong(a,n,x);
	float tongb=tong(b,n,x);
	printf("\nTong cua P(x)+Q(x):%.2f",tonga+tongb);
	return 0;
}
