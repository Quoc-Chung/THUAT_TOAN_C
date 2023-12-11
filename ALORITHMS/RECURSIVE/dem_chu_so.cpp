#include <stdio.h>
#include <math.h>
int countdigit(int n){
	int dem=0;
	while (n>0){
		dem++;
		n/=10;
	}
	return dem;
}
// su dung de quy thuong 
int dequy(int n){
	if(n<10){ // neu mot so nho hon 10 thi 
		return 1;
	}
	return 1+dequy(n/10);
}
int dequyduoi (int n ,int x=0){
	if(n==0){
		return x;
	}

	return dequyduoi(n/10,x+1); 
}
// de quy duoi tu sang tac 
int dequyduoithantrieu(int n,int x=1){
	if(n<10){
		return x;
	}
	return dequyduoithantrieu(n/10,x+=1);
}
int main (){
	int n;
	scanf("%d",&n);
	printf("\nSo luong chu so :%d",countdigit(n));
	printf("\nSo luong chu so theo de quy :%d",dequy(n));
	printf("\nSo luong chu so theo de quy duoi:%d",dequyduoi(n));
	printf("\nSo luong chu so theo de quy duoi than trieu :%d",dequyduoithantrieu(n));
	return 0;
}