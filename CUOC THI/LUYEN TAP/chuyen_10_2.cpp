#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main (){
	int n;
	scanf("%d",&n);
	int h=0;
	int b[100];
	while (n>0){
	  b[h]=n%2;
	  h++;
	  n/=2;
	  }
	for (int i=h-1;i>=0;i--){
		printf("%d",b[i]);
	}
}