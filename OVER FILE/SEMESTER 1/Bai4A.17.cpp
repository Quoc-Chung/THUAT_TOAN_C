#include <stdio.h>
#include <math.h>
int nhapmang(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		}
	}
// in ra so chia het cho 2 va cho 3 lon nhat mang 
int check(int n){
	for (int i=1;i<=n;i++){
		if(n%2==0 && n%3==0){
			return 1;
			}
		else {
			return 0;
			}
			}
			}
int thoaman1(int a[],int n){
	for (int i=1;i<=n;i++){
		if(check(a[i])){
			if(a[i]>a[i+1]){
				printf("%d ",a[i]);
				break;
				}
			}
			}
	}
	int thoaman2(int a[],int n ){
		int max=thoaman1(a,n);//=18
		for (int i=1;i<=n;i++){
			if(check(a[i])){
				if(max<a[i]){
					printf("%d ",a[i]);
					break;
					}
				}
			}
	}
	
	
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	nhapmang(a,n);
    thoaman2(a,n);
	return 0;
	}
	

