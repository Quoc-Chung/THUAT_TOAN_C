// P(x) =an*x^n +... + a2*x^2+ a1*x + a0

#include <stdio.h>
#include <math.h>
int main(){	
// tinh bieu thuc
float f=0;
float f1=0;
// nhap n
  int n;
  float a[100];
  printf("Nhap n :");
  scanf("%d",&n);
 //nhap x	
  float x;
  printf("\nNhap gia tri x:");
  scanf("%f",&x);
//nhap he so
	for (int i=n;i>=0;i--){
		printf("\nNhap he so a[%d]:",i);
		scanf("%f",&a[i]);
	}
	// in he so 
	//printf("\nCac he so cua da thuc vua nhap la :\n");
	//for(int i=n;i>=0;i--){
	//	printf("%.2f ",a[i]);
	//}
	//tinh gia tri bieu thuc f(x)
	for (int i=n;i>=0;i--) {
		f+=a[i]*pow(x,i);
	}
	printf("Gia tri cua f(x)=%.2f",f);
	// tinh gia tri bieu thuc dao ham 
	for (int i=n;i>=0;i--){
			f1+=i*a[i]*pow(x,i-1);
		}
	printf("\nGia tri cua f''(x)=%.2f",f1);
	float s=sqrt (2021+f+f1);
	printf("\nGia tri cua bieu thuc la :%.2f",s);
}