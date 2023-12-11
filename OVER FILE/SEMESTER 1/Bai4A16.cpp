// nghien cuu ham sort sap xep mang 

#include <stdio.h>
#include <math.h>
int nhapmang (float a[],int n){
	for (int i=1;i<=n;i++){
		scanf(" %f",&a[i]);
	}
}
int inmangduong(float  a[],int n){
	for (int i=1;i<=n;i++){
		if(a[i]>=0){
		printf(" %.2f ",a[i]);
		}
}

}
int inmangam(float  a[],int n){
	printf("\n");
	for (int i=1;i<=n;i++){
		if(a[i]<0){
			printf("%.2f",a[i]);
		}
}
}
int maxmang(float a[],int n){
	float max=0;
	for (int i=1;i<=n;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	return max;
}
int minmang(float a[],int n){
	float min =a[0];
	for (int i=1;i<=n;i++){
		if(min > a[i]){
			min=a[i];
		}
	}
	return min ;
}
int main (){
	int n;
	scanf("%d",&n);
	float a[n];
	nhapmang(a,n);
	inmangduong(a,n);
	inmangam(a,n);
	float hieu=maxmang(a,n)- minmang(a,n);
    printf("Hieu can tim la :%.2f",hieu);
}
