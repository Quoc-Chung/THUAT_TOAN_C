#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void nhap_mang(int *a,int &n){
	printf("\nNhap so n:");
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",(a+i));
		// toán tử tăng của con trỏ ,mỗi lần tăng con trỏ lên một đơn vị là mỗi lần con trỏ sẽ nhảy 1 ô địa chỉ 
	}
}
void in_mang(int *a,int n){
	printf("\nMang vua nhap la :\n");
	for (int i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
}
int main(){
	int n;
	int *a;
	a=(int *) malloc (n*sizeof(int));
	// a là địa chỉ đầu tiên của mảng vừa cấp phát 
	nhap_mang(a,n);
	in_mang(a,n);
	// giải phóng bộ nhớ 
	free(a);
	return 0;
}