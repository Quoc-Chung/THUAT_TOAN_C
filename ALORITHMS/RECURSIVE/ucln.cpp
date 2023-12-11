#include <stdio.h>
#include <math.h>
// khong dung de quy 
int ucln1(int a,int b){
	if(a==0 || b==0){
		return a+b;
	}
	while (a!=b){//day la dieu kien de dung tuc la hai so bang nhau in ra mot trong hai so 
		if(a>b){
			a=a-b;
		}
		else {
			b=b-a;
		}
	}
	return a;
}
// dùng đệ quy 

int ucln2(int a,int b){
	if(b==0){
		return a;// tuc la ta phai lam sao de ham nay co the dung lai 
	}
	return ucln2(b,a%b);
}
// ucln2(4,12)==> in ra hai so 4
// ucln2(12,8 )
// ucln(8,4)
// ucln(4,0) return a;
 
int main (){
	int a,b;
	scanf("%d%d",&a,&b);
	int c=ucln1(a,b);
	printf("%d",c);
	int d=ucln2(a,b);
	printf("\ndung de quy :%d",d);
	return 0;
}