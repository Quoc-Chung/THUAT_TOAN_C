#include <stdio.h>
#include <math.h>
//M?t s? du?c g?i l� �l?c ph�t� n?u ch? c� c�c ch? s? 0,6,8. Nh?p v�o m?t s?
//nguy�n duong kh�ng qu� 9 ch? s?, h�y ki?m tra xem d� c� ph?i s? l?c ph�t hay
//kh�ng. N?u d�ng in ra 1, sai in ra 0.

int locphat(int n){
	int flag=0;
	while (n>0){
		int t=n%10;
		if(t==0 || t==6 || t==8){
			flag=1;
		}
			else{
			flag=0;
		}
	
		n/=10;
	}
	if(flag==1){
		return 1;
	}
	else{
		return 0;
	}
	
}
int main (){
	int n;
	scanf("%d",&n);
	if(locphat(n)==1){
		printf("1");
	}
	else{
		printf("0");
	}
	}
