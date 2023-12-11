#include <stdio.h>
#include <math.h>
int solvefibo(int n){
	if(n==1 || n==0){
		return 1;
		}
		int f1=0,f2=1;
		for (int i=3;i<=30;i++){
			int f=f1+f2;
			if(n==f){
				return 1;
				}
				f1=f2;
				f2=f;
				}
				return 0;// phai co return de reset lai truong hop,neu thieu cai nay thi nó se luon dung 
				}
int main (){
	int n;
	scanf("%d",&n);
	if(solvefibo(n)){
		printf("YES");
		}
		else{
			printf("NO");
			}
			}
