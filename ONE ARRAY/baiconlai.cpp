
#include <stdio.h>
#include <math.h>
int nhapmang(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
int inmang(int a[],int n){
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
	}
}
int somax(int a[],int n){
	int max=0;
	for (int i=1;i<=n;i++){
		if(max<(a[i]/(n-i))){
			max=(a[i]/(n-i));
		}
		
	}
	return max;
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	nhapmang(a,n);
	printf("Mang in ra la :\n");
	inmang(a,n);
	printf("%d",somax(a,n));
	return 0;
		
	
}
