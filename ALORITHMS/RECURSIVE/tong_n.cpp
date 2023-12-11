// tinh tong n so co su dung de quy 
//s=1+2+3...+n;
#include <stdio.h>
#include <math.h>
int tong(int n){
	int tong=0;
	for (int i=1;i<=n;i++){
		tong +=i;
	}
	return tong;
}
// su dung de quy thuong 
int tong1(int n){
	if(n==1){
		return 1;
	}
	return n+tong(n-1);
}
// su dung de quy duoi tuc la return ta se trả về một giá trị kết quả chứ nó khong tra ve ham goi lai 
//(nó không tinh toán với hàm mà nó gọi lại mà nó tính toán với một biến kết quả mà ta vừa truyền vào hàm  
int  dequyduoi(int n,int x=1){
	if(n==1){
		return x;
	}
	return dequyduoi (n-1,x+n);
}
//vi du (1+2+3=6)
// tuc luc nay ta se truyen vao ham (3,x=1)==> neu pass by value bị lỗi thì ta có thể gán giá trị ra trong mảng 
// (2,1+3)
// (1,1+3+2)
// rồi ỉn ra gia tri cua x 
int main (){
	int n;
	scanf("%d",&n);
	printf("\n Tong la :%d",tong(n));
	printf("\nTong dung de quy :%d",tong1(n));
	printf("\ntong dung de quy duoi la:%d",dequyduoi(n));
	
	
}