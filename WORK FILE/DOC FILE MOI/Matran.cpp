#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void DocFile(int ***a,int *n,char *tentep){
	FILE *f;
	f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong  mo duoc file de doc");
		exit(0);
	}
	// doc n va cap phat dong
   fscanf(f,"%d",n);
   *a=(int **)malloc (*n*sizeof(int*));
   for(int i=0;i<*n;i++){
   	(*a)[i]=(int*) malloc(*n*sizeof(int));
   }
   for(int i=0;i<*n;i++){
   	for(int j=0;j<*n;j++){
   		fscanf(f,"%d",&((*a)[i][j]));
	   }
   }
}
void InFile(int **a,int n){
	printf("\nMa tran doc tu file la :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
			printf("\n");
	}

}
int main(){
	int n;
	int **a;
	char tentep[50];
	printf("\nNhap ten file :");
	gets(tentep);
	DocFile(&a,&n,tentep);
	InFile(a,n);
	return 0;
	
}