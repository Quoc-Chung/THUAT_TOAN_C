#include <stdio.h>
#include <math.h>
int main(){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	int flag=0;
	int res=0;
	while (n>0){
	res=n%10;
	if(res%2==0){
		flag++;
		break;
	}
	n/=10;	
	}
	if(flag==0){
		printf("So chua toan chu so le .");
	}
	if(flag>0){
		printf("So chua ca so chan.");
	}
}