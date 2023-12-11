#include <stdio.h>
#include <math.h>
int main (){
	int n;
	scanf("%d",&n);
	int tien=0;
	if( n>0 && n<50){
		tien=100*n;
	}
	else if(n>=50 && n<1000){
		tien=500*n;
	}
	else if(n>=1000 && n<10000){
		tien=1000*n;
	}
	else if(n>=10000){
		tien=1200*n;
	}
	printf("%d",tien);
}