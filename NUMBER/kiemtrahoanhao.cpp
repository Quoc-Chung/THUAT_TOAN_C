#include<stdio.h>
#include <math.h>
int nguyento(int n){
	if(n<2) {
	return 0;
	}
	else {
		for (int i=2;i<sqrt(n);i++){
			if(n%i==0){
	return 0;
}
			else {
				return 1;
			}
	}
	}
}
int hoanhaogiam(int n){
	int flag=1;
	int socuoi=n%10;
	n=n/10;
	while (n>0){
	  	int sogancuoi=n%10;
	  	n=n/10;
	  	if(socuoi > sogancuoi){// vi du 4321 thi so cuoi nho hon sogancuoi
	  		flag=0;
		  }
		  else{
		  	socuoi=sogancuoi;
		  }
	}
	if(flag==1){
		return 1;
	}
	else {
		return 0;
	}
	}
	int hoanhaotang(int n){
	int flag=1;
	int socuoi=n%10;
	n=n/10;
	while (n>0){
	  	int sogancuoi=n%10;
	  	n=n/10;
	  	if(socuoi < sogancuoi){//vi  du 1234 thi socuoi>sogancuoi
	  		flag=0;
		  }
		  else{
		  	socuoi=sogancuoi;
		  }
	}
	if(flag==1){
		return 1;
	}
	else {
		return 0;
	}
	}
	int main (){
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			if((hoanhaotang(i) || hoanhaogiam(i)) && nguyento(i)){
		printf("%d ",i);
			}
		}
	}
// ca so nguyen to nho hon 100:	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
