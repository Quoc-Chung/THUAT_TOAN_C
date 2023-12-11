#include <stdio.h>
#include <math.h>
void nhapmang(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
void inso(int a[],int n,long long x){
	int so1=0;
	int so2=0;
	for (int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++)
	   	if(a[i]+a[j]==x && a[i]<=x &&a[j]<=x){
	   		so1=a[i];
	   		so2=a[j];
		   }
		   
	   }
	   if(so1<so2){
	   printf("\n%d %d",so1,so2);
}
else{
	printf("\n%d %d",so2,so1);
}
	}
int main (){
	int n;
	long long x;
	scanf("%d",&n);
	scanf("%lld",&x);
	int a[1000];
    nhapmang(a,n);
    inso(a,n,x);
    return 0;
    
}