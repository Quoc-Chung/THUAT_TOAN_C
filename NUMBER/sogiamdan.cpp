// vi du so 4321 laf so giam daan va co so cuoi <so gan cuoi
#include <stdio.h>
#include <math.h>
int kiemtrasogiam(int n){
	int flag=1;//ta coi nhu so ban dau dung
	int x=n;//gan x=n de de khi su  dung gia tri x thi nos khonng lam thay doi gia tri x
	int socuoi=x%10;//dung x de gia tri cua n khong thay doi
	while (x>0){
		int sogancuoi=x%10;
		x=x/10;
		if(socuoi < sogancuoi){
			flag=0;
		
	}
	else {
	socuoi=sogancuoi;
	}
	}
	if(flag==1){
		printf("So do sap xep giam dan");
		}
		else {
			printf("So do khong sap xep giam dan");
			}
	 
}
int main (){
	int n;
	scanf("%d",&n);
	kiemtrasogiam(n);
	return 0;
	}
