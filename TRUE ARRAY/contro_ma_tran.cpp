#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void nhap_mang(int *a,int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			scanf("%d",(a+i*n+j));
		}
	}
}
void inmang(int *a,int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ",*(a+i*n+j));
		}
		printf("\n");
	}
}
int main(){
	int m,n;
    printf("\nKich thuoc:");
    scanf("%d%d",&m,&n);
	int *a=(int*) malloc(m*n*sizeof(int));
	nhap_mang(a,m,n);
	printf("Ma tran la :\n");
	inmang(a,m,n);
	free(a);
	return 0;
}
