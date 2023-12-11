#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100
bool nguyen_to(int n){
    if(n<2){
        return false;
    }
    else {
        for (int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
    }
    return true;
}
void nhap(int a[],int n){
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
int main (){
    int n;
    scanf("%d",&n);
    int a[MAX];
    nhap(a,n);
    for (int i=0;i<n;i++){
        if(nguyen_to(a[i])){
            printf("%d ",a[i]);
        }
    }
}