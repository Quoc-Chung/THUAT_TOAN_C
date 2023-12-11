#include <stdio.h>
#include <math.h>
void ucln(int a,int b){
   if(a==0 || b==0){
   	printf("%d",a+b);
   }
   while (a!=b){
   	if(a>b){
   		a=a-b;
	   }
	else{
		b=b-a;
	}
}
	printf("%d",a);
}
int main (){
	int a,b;
	scanf("%d%d",&a,&b);
	ucln(a,b);
	return 0;
	
}