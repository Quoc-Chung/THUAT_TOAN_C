#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void DocFile (int ***a,int &m,int &n, char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file ");
		exit(0);
	}
	fscanf(f,"%d%d",&m,&n);
	(*a)=(int**) malloc(m*sizeof(int*));
	for(int i=0;i<m;i++){
		(*a)[i]=(int *) malloc(n*sizeof(int));
	}
	// doc  ma tran  
	for  (int i=0;i<m;i++ ){
		for (int j=0;j<n;j++){
			fscanf(f,"%d",&(*a)[i][j]);
		}
	}
	fclose(f);
	
}
void TichLe (int  **a,int m,int n){
	int tich=1;
	int dem=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j] %2 !=0 && a[i][j] >211){
				tich *=a[i][j];
				dem++;
			}
		}
	}
	if(dem==0){
		printf("\nKhong co phan tu  thoa  man");
	}
	else{
		printf("\nTich can tim la  :%d ",tich);
	}
}
void LeMin(int **a,int m,int n){
    int min=INT_MAX;
	int h=0,c=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j] %2!=0 && min>a[i][j]){
				min=a[i][j];
				h=i,c=j;
			}
		}
	}
	printf("\n So can tim la  a[%d][%d]=%d",h,c,min);
}
void PhanTuNAmTrenCheoPhu(int **a,int m,int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
		
		}
	}
}
int  main (){
	int m,n; 
	int **a;
	char tentep[50];
	printf("\nNhap  ten tep:");
	gets(tentep);
	DocFile(&a,m,n,tentep);
	TichLe(a,m,n);
	LeMin(a,m,n);
	return 0;
}