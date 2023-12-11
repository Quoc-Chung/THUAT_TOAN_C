#include <stdio.h>
#include <math.h>
void input(float *a,int n){
	for (int i=1;i<=n;i++){
		scanf("%f",(a+i));//con tro tro den o nho dau tien trong mang
	}
}
void output(float *a,int n){
	printf("\nGIa tri cua mang la :\n");
	for (int i=1;i<=n;i++){
		printf("%.2f ",*(a+i));// gia tri cua o nho dau tien trong mang  
	}
}
int main (){
	int n;
	do {
		printf("\nNhap n:");
		scanf("%d",&n);
		if(n<1){
			printf("\nVui long nhap lai.\n");
		}
    }while (n<1);
    float a[n];
    input(a,n);
    output(a,n);
    return 0;
    
}
