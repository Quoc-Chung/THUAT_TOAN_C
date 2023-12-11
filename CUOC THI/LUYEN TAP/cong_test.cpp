#include <stdio.h>
#include <math.h>
int main (){
	int t;
	scanf("%d",&t);
	int *k=(int *) malloc (t*sizeof(int));
	int h=0;
	while (t--){
		int a,b;
		scanf("%d%d",&a,&b);
		int tam=a+b;
		k[h]=tam;
		h++;
		
	}
	for (int i=0;i<h;i++){
		printf("%d\n",k[i]);
	}
	free(k);
	
}