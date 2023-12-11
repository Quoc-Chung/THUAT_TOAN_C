#include <stdio.h>
#include <math.h>

void nhapmang(float a[],int n){
	for (int i=1;i<=n;i++){
		printf("Nhap phan tu a[%d]:",i );
		scanf("%f",&a[i]);
	}
}
void inmang(float a[],int n){
	for (int i=1;i<=n;i++){
		printf("%.2f ",a[i]);
	}
}
float giatrimax(float a[],int n){
	float max=0;
	for (int i=1;i<=n;i++){
		if(max<((1.0*a[i])/i)){
			max=(1.0*a[i])/i;
		}
	}
	return max;
}
//Nhập vào số x, đếm và in ra màn hình các số có giá trị tuyệt đối lớn hơn x.
void thoaman(float a[],int n,float x){
	int dem =0;
	for (int i=1;i<=n;i++){
		if(fabs(a[i])>x){
			printf("%.2f ",a[i]);
			dem++;
		}
	}
	printf("\nSo luong cac so thoa ma la :%d",dem);
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	float a[n];
	nhapmang(a,n);
	printf("\nMang 1 chieu la :\n");
	inmang(a,n);
	printf("\nGia tri max trong day la :%.2f",giatrimax(a,n));
  float x;
 printf("\nNhap x :");
 scanf("%f",&x);
 thoaman(a,n,x);
}