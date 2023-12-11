#include <stdio.h>
#include <math.h>
//Quy luật của dãy số Fibonacci: số tiếp theo bằng tổng của 2 số trước,
// 2 số đầu tiên của dãy số là 0, 1. Ví dụ: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
// tinh so fibonaci thu n.
//so thu 7 =8
int fibonaci(int n){
	int f1=0;
	int f2=1;
	int f=0;
	for (int i=2;i<=n;i++){
		f1=f2;
		f2=f;
		f=f1+f2;
	}
	return f;
}
int fibonaci1(int n){
	if(n==0 || n==1){
		return n;
	}
	return fibonaci(n-1)+fibonaci(n-2);
}
int main (){
	int n;
	scanf("%d",&n);
	int so1=fibonaci(n);
	printf("\nKhong dung de quy :%d",so1);
	int so2=fibonaci1(n);
	printf("\nDung de quy:%d",so2);
}