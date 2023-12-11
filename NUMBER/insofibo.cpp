// in ra cac so fibonacci
#include <stdio.h>
#include <math.h>
int solve (int n){
	printf("0 1 ");
	int f1=0,f2=1;
	for (int i=3;i<=n;i++){
		int f=f1+f2;
		printf("%d ",f);
		f1=f2;
		f2=f;
		}
		}
int main (){
	int n;
	scanf("%d",&n);
	solve (n);
	}
	
