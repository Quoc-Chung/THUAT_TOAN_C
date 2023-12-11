#include <stdio.h>
#include <math.h>

//X vnđ cho một ngày đối với K ngày đầu tiên
//Y vnđ cho một ngày từ ngày thứ K + 1 đến ngày cuối cùng.
int main (){
	int n,k,x,y;
	scanf("%d%d%d%d",&n,&k,&x,&y);
	int tien=0;
    if(k>=n){
    	tien=k*x;
	}
	else {
		tien=k*x+(n-k)*y;
	}
	printf("%d",tien);
}