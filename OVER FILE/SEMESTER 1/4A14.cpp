#include <stdio.h>
#include <math.h>
// doi voi so thuc thi cac kieu 
int nhapmang(float a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%f",&a[i]);
	}
}
int inmang (float a[],int n){
	for (int i=1;i<=n;i++){
		printf("%.1f ",a[i]);
}
}
int maxmang(float a[],int n){
	float max=0;
	for (int i=1;i<=n;i++){
		if(max<=a[i]){
			max=a[i];
		}
	}
	return max;
}
int minmang(float a[],int n){
	float min=a[0];
	for (int i=1;i<=n;i++){
		if(min>=a[i]){
			min =a[i];
		}
	}
	return min ;
}
// dieu kien la x-min>max-x,<=> x- min -max+x>0 <=> 2x-min-max>0
int demsothoaman(float a[],int n){
	int dem=0;
	float max1 = maxmang(a,n);
	float min1 = minmang(a,n);
	for(int i=1;i<=n;i++){
		if((2*(a[i])-max1-min1)>0){
			dem ++;
		}
	}
	return dem;
}
int main(){
	int n;
	scanf("%d",&n);
 float a[n];
 nhapmang(a,n);
 printf("In mang :\n");
 inmang(a,n);
 float m;
 scanf("%f",&m);
 printf("Cac so lon hon m la :\n");
for (int i=1;i<=n;i++){
	    if(a[i]>m){
			printf("%.1f ",a[i]);
}
}
printf("Cac gia tri  thoa man phan b la :%d",demsothoaman(a,n));
printf("Max:%f",minmang(a,n));
}
// vi du day 1 2 3 4 5 
// max la 5 min la 1 nen 2*x-5-1>0<=> 2x-6>0 <=> x>3 co hai  gia tri thoa man 
