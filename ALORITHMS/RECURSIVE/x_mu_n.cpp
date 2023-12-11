#include <stdio.h>
#include <math.h>
// s=x+x^2 +x^3 +x^4 +... +x^n
float  dequy(float x,int n){
	if(n==1){
		return x;
	}
	return dequy(x,n-1)+pow(x,n);
}
// doi voi de quy duoi thi ta phai khai bao một biến y trong doi so 

// đồng thoi tìm ra dieu ken dunng cua de quy 
float dequyduoi(float x,int n,float y=0){
	if(n==0){
		return y;
	}
	return  dequyduoi(x,n-1,y+pow(x,n));
}
float khudequy(float x, int n){
	float tong=x;
	for (int i=2;i<=n;i++){
		tong+=pow(x,i);
	}
	return tong;
}
int main (){
	float x=3;
	int n=4;
	printf("gia tri de quy :%f",dequy(x,n));
	printf("\nGia tri de quy duoi :%f",dequyduoi(x,n));
	printf("\nGia tri khu de quy la :%f",khudequy(x,n));
	return 0;
}