#include<stdio.h>
#include <math.h>
void nhapmang(float x[],int *n){
	for (int i=1;i<=*n;i++){
		scanf("%f",&x[i]);
		
	}
}
void inmang(float x[],int n){
	for(int i=1;i<=n;i++){
		printf("%.2f ",x[i]);
	}
}
float tinhtoan(float  x[],int n,int a,int b){
	int dem=0;
	float tong=0;
	for (int i=1;i<=n;i++){
		if(x[i]>=a && x[i]<=b){
			tong+=x[i];
			dem++;
		}
	}
	return tong/(dem*1.0);
}
void sapxep(float x[],int n){
	float sapxep;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if(x[i]<=x[j]){
			
			sapxep=x[i];
			x[i]=x[j];
			x[j]=sapxep;
		}
	}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	float x[n];
	float a,b;
	printf("\nNhap vao hai so a va  b:");
	scanf("%f %f",&a,&b);
	nhapmang (x,&n);
	printf("Mang in ra la :\n");
	inmang(x,n);
	printf("\n trung binh cong trong doan la  :%.2f",tinhtoan(x,n,a,b));
     sapxep(x,n);
     printf("\nMang da sap xep la :");
	for (int i=1;i<=n;i++){
		printf("%.2f",x[i]);
	}
	return 0;
	
}