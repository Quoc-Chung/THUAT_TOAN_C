#include <stdio.h>
#include <math.h>
int nhapmang(float a[],int n){
for (int i=1;i<=n;i++){
	scanf("%f",&a[i]);
	}
}
int inmang (float a[],int n){
	for (int i=1;i<=n;i++){
		printf("%.2f ",a[i]);
		}
		}
int calculate(float a[],int n){
	float max=a[1]/n;
	for (int i=1;i<=n;i++){
		if( max <= (a[1+i]/(n-i))){
			max=a[i+1]/(n-i);
			}
			}
		return max;
		}
int sosanhgiatri(float a[],int n,float x){
	for (int i=1;i<=n;i++){
		if (abs(a[i])>x){
			printf("%.1f ",a[i]);
			}
			}
			}
int main (){
	int n;
	int x;
	scanf("%d",&n);
	float a[n];
	nhapmang (a,n);
	printf("In mang :\n");
	inmang (a,n);
	printf("\nNhap x:\n");
	scanf("%.1f",&x);
	printf("Cac gia tri lon hon tri tuyet doi:\n");
	sosanhgiatri(a,n,x);
	return 0;
	}
	
	
	
	
