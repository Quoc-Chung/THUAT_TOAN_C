#include <stdio.h>
#include <math.h>
void nhapmang(float a[],int n){
 for (int i=1;i<=n;i++){
 	printf("Nhap vao phan tu a[%d]:",i);
 	scanf("%f",&a[i]);
 }	
}
void inmang(float a[],int n){
	for (int i=1;i<=n;i++){
		printf("%.2f ",a[i]);
	}
}
// tim cap hai phan tu lien tiep co tich nho nhat 
void timcaptichmax(float a[],int n){
	float max1=0,max2=0;
	float max=0;
	for (int i=1;i<=(n-1);i++){
		for (int j=i+1;j<=n;j++){
			if(max<a[i]*a[j]){
				max=a[i]*a[j];
				max1=a[i];
				max2=a[j];
			}
		}
		
		
	}
		printf("\nHai so co cap tich max la %.2f va %.2f",max1,max2);
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	float a[n];
	nhapmang(a,n);
	printf("Mang la :\n");
	inmang(a,n);
timcaptichmax(a,n);
}