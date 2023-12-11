#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100
void nhap(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
void cap_so_cong(int a[],int n){
	if(n<3){
		return;
	}
	else {
	int flag=0;
	int k=0;
	for (int i=1;i<=n-3;i++){
		if(a[i+1]-a[i]!=a[i+2]-a[i+1]){
			flag++;
			i++;
		}
	}
	for (int i=1;i<=n-3;i++){
	if(a[i+1]-a[i]!=a[i+2]-a[i+1]){
			k=i+2;
			break;
		}
	}
	if(flag==0){
		printf("\nDay la day cap so cong");
	}
    else if(flag==1){
		printf("\nDay la gan cap so cong tai vi tri %d",k);
	}
	else{
		printf("\nDay khong la day gan cap so cong");
	}
}
}
int main (){
    int n;
    scanf("%d",&n);
    int a[MAX];
    nhap(a,n);
    cap_so_cong(a,n);
    
}