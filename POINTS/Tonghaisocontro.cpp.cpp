//cộng hai số sử dụng con trỏ 
#include <stdio.h>
#include <math.h>
int sum(int *&x,int *&y){// truyền vào hai con trỏ gọi phải gọi địa chỉ 
    int tong;
    tong=*x+*y;
   return tong;
}
int sum1(int *x,int *y){// chung ta phai hieu rang no se thay doi tren 
	int tong;
	tong=*x+*y;
	return tong;
}
int sum2(int &x,int &y){
	int tong =x+y;
	return tong;
}
int main (){
    int a=5;
    int b=5;
    int *p=&a;
    int *p1=&b;
    printf("\nTong la :%d",sum(p,p1));
    printf("\nTong la :%d",sum1(&a,&b));
    printf("\nTong la :%d",sum2(a,b));
    return 0;
}