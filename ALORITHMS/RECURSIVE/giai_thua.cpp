#include <stdio.h>
#include <math.h>
int giaithua(int n){
	if(n==1){
		return 1;
	}
	return giaithua(n-1)*n;
}
float  dequy(float x,int n){
	if(n==1){
		return x;
	}
	return dequy(x,n-1)+pow(x,n)/giaithua(n);
	}
int main (){
	float x=3;
	int n=3;
	printf("tong de quy luc nay la :%f",dequy(x,n));
}