#include <stdio.h>
#include <math.h>
#include<string.h>
#include <stdlib.h>
int main (){
	float a,b;
	scanf("%f%f",&a,&b);
	char c[6];
	gets(c);
	printf("\nKet qua cua phep tinh a va b:");
	if(strcasecmp(cong,c)==0)
		printf("%d",a+b);
	if(strcasecmp(tru,c)==0)
		printf("%.2f",a-b);
	if(strcasecmp(nhan,c)==0)
		printf("%.2f",a*b);
	else 
		printf("%.2f",a/b);
}