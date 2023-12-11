#include <stdio.h>
#include <math.h>
int daoso(int n){
	int sodao=0;
	while (n>0){
		sodao=sodao*10+n%10;
		n=n/10;
	}
	return sodao;
}
int main (){
	int t;
	scanf("%d",&t);
	while (t--){
		int n;
		scanf("%d",&n);
		if(daoso(n)==n){
		printf("YES");	
		}
		else{
			printf("NO");
		} 
		}
		
	}
