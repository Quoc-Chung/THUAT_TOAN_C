#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void nhapmang(int *a,int n,int i=1){// con trỏ thực chất cũng là một mảng 
	if(i==n+1){// phai chay den luc i vi phạm thì mới kết thức hàm nhập 
		return ;
	}
	printf("\na[%d]:",i);
	scanf("%d",(a+i));
	nhapmang(a,n,i+1);
}
void xuatmang(int *a,int n,int i=1){
	if(n==n+1){
		return ;
		
	}
	printf("%d ",*(a+i));
	xuatmang(a,n,i+1);
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
//	printf("Nhap n:");
//	scanf("%d",&n);
//	int *a = (int*)malloc(n* sizeof (int));
	int  *a =(int*)malloc(n * sizeof(int));
	nhapmang(a,n);
	xuatmang(a,n);
	free(a);

	
}