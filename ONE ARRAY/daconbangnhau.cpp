#include <stdio.h>
#include <math.h>
void nhapmang(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
int main (){
	int t;
	scanf("%d",&t);
	int b[t];
	for (int k=0;k<t;k++){
		int n,dem=0;
     // d?t chir so dau tien trong day bang 0;
		printf("\nNhap n:");
		scanf("%d",&n);
		int a[n];
		nhapmang(a,n);
		for (int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				dem++;
			}
		
		}
		b[k]=dem;
	//	printf("\n%d",dem);
	}
	for (int i=0;i<t;i++){
		printf("\n%d",b[i]);
	}
}
