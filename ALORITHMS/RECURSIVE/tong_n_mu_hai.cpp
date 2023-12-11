// 1^2+2^2+3^2+4^2+...+n^2;
#include <stdio.h>
#include <math.h>
int tongthuong (int n){
	int tong=0;
	for (int i=1;i<=n;i++){
		tong+=pow(i,2);
	}
	return tong;
}
int tongdequy (int n){
	if(n==1){
		return 1;
	}
	return tongdequy(n-1)+pow(n,2);
}
int dequyduoi(int n,int x=1){
	if(n==1){
		return x;
	}
	return dequyduoi(n-1,x+pow(n,2));
}
int main (){
	int n;
	scanf("%d",&n);
	printf("\nKhong dung de quy ra:%d",tongthuong(n));
	printf("\nDung de quy thuong ra:%d",tongdequy(n));
	printf("\ndung de quy duoi ra :%d",dequyduoi(n));
	return 0;
	
}
