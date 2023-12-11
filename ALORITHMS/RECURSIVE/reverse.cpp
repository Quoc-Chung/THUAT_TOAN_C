#include <stdio.h>
#include <math.h>
int daonguoc(int n){
	int sodaonguoc=0;
	while (n>0){
		sodaonguoc=sodaonguoc*10+n%10;
		n/=10;
	}
	return sodaonguoc;
}
// 12345

int dequy(int n){
   int t=n%10;
     if(n>0){
     	printf("%d",t);
	 }
    return dequy(n/10);
}
int dequyduoi(int n, int x=0)// diều kiện dừng của bài này là n==0 thì kết quả x==0
{
	if (n == 0)
		return x;
	else
	{
		x = x*10 + n%10;
		return dequyduoi(n/10, x);
	}
}
int main (){
	int n;
	scanf("%d",&n);
	//printf("\nSo dao nguoc khong dung de quy la :%d",daonguoc(n));
	//printf("\nSo đao nguoc theo de quy duoi:%d",dequyduoi(n));
	printf("\nSo dao nguoc dung de quy thuong :%d",dequy(n));
	return 0;
	
}