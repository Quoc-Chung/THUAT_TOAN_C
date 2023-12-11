#include <stdio.h>
#include <math.h>
int main (){
	int n;
	scanf("%d",&n);
	int a[n];
		for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int max=0;
	int min=pow(10,6);
	int dem;
	for (int i=1;i<=n;i++){
		if(max<a[i]){
			max=a[i];
		}
		if(min>a[i]){
			min=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(max==min){
			dem=n;
			break;
		}
	    if(max==a[i]|| min==a[i]){
		dem++;
		}		
	}
	printf("%d",dem);
}