#include <stdio.h>
#include <math.h>
int nhap(int a[],int n){
	for (int i=1;i<=n;i++){
		printf("Nhap a[%d]",i);
		scanf("%d",&a[i]);
	}
}
void tich3lientiep(int a[],int n){
	int so1=0,so2=0,so3=0;
	int max=-pow(10,5);
	for (int i=1;i<=n-2;i++){
		if(max<a[i]*a[i+1]*a[i+2]){
			max=a[i]*a[i+1]*a[i+2];
			so1=a[i];
			so2=a[i+1];
			so3=a[i+2];
		}
	}
	printf("\n# so can tim la :%d %d %d",so1,so2,so3);
}
int main (){
	int n;
	scanf("%d",&n);
	int a[n];
	nhap(a,n);
	tich3lientiep(a,n);
	
	
}