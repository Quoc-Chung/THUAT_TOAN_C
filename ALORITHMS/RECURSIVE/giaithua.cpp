#include <stdio.h>
#include <math.h>
// ham de quy luon tra ve gia tri return 
// bat ki bai de quy nao cung co dieu kien de no dung ,thường khi đó  nó sẽ trả về return 1;
// khong dung de quy 
unsigned long long giaithua (int n){
	int gt=1;
	for (int i=1;i<=n;i++){
		gt*=i;
	}
	return gt;
}
// dung de quy 
unsigned long long giaithua1(int n){
	if(n==1 ||  n==0){
		return 1;
	}
	return  n*giaithua(n-1);// khi minh tra ve nhu nay tuc la vong tiep theo khi thuc hien  
	// lenh thi doi truyen vao luc nay la luc nay se la  n-1 chu khong  phai la so n nũa
}
// giai thich: lúc dau truyen n vao la 5 vao 
// kiem tra dieu kien dung thay khong thoa man 
//return 5*giaithua(4) xu nhu vay cho den khi n==1 thi ham trả vè 1 va cuoi cung tra ve giai thua da tinh o phia truoc 
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	long long  gt1=giaithua(n);
	printf("\nKhong dung de quy ra :%lld",gt1);
	long long gt2=giaithua1(n);
	printf("\nDung de quy no se ra :%lld",gt2);
	return 0;
}