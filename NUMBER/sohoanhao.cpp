// kiem tra so hoan hao vi du 28
#include <stdio.h>
#include <math.h>
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		int n;
		scanf("%d",&n);
		int tong=0;
		for (int i=1;i<n;i++){
			if(n%i==0){
				tong=tong +i;
			}
		}
			if(tong==n){
				printf("YES ");
			}
			else {
				printf(" N0 ");
			}
			
}
}
