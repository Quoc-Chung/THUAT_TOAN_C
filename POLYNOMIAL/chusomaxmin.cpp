#include <stdio.h>
#include <math.h>
int main(){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	int max=0,min=11;// đây là tim max min chu so
	int res=0;
	while (n>0){
		res=n%10;
		n/=10;
		if(max<res){
			max=res;
		}
		if(min>res){                                     
		}
	}
	printf("Chu so max la :%d",max);
	printf("\nChu so min la :%d",min);
}