#include <stdio.h>
#include <math.h>
// S=x^2+x^4+x^6+.. x^2*n;
float dequy(float x,int n){
	if(n==1){
		return x*x;
	}
	return dequy(x,n-1)+pow(x,2*n);
	
}
// S=x^2+x^4+x^6+.. x^2n;
float dequyduoi(float x,int n,float y = 0 ){
	if(n==1){
		return y;
	}
	return (x,n-1,y+pow(x,2*n));
}
float khudequy(int x,int n){
	float tong=x*x;
	for (int i=2;i<=n;i++){
		tong +=pow(x,2*i);
	}
	return tong;
}
int main (){
	int x=3;
	int n=4;
	printf("De quy la:%f",dequy(x,n));
	printf("\nDe quy duoi :%f",dequyduoi(x,n));
	printf("\nKhu de quy :%f",khudequy(x,n));
	return 0;
}