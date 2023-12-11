#include <stdio.h>
#include <math.h>
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		int k;
		int n;
		scanf("%d%d",&n,&k);
		int a=k;
		int b=k+1;
	while (a==n||b==n){
			if(a==n)
				printf("\nntanh");
		    if(b==n)
				printf("\nnqson");
			else
				k++;
		}
	}
}