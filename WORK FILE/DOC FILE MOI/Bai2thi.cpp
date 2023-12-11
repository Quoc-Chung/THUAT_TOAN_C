#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
void  DocFile(int ***a,int &n,char  *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	// cap phat dong  cho ma tran  
	*a=(int ** )malloc (n*sizeof(int*));
	for (int i=0;i<n;i++){
		(*a)[i]=(int *) malloc (n*sizeof(int));
	}
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			fscanf(f,"%d",&(*a)[i][j]);
		}
	}
	printf("\nMa tran duoc doc tu file  la  :\n");
	for (int  i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("%d ",(*a)[i][j]);
		}
		printf("\n");
	}
}
void  Max(int **a,int n){
	int max=INT_MIN;
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(max< a[i][j]){
				max=a[i][j];
			}
		}
	}
	printf("\nGia tri  lơn nhat cua  ma tran la:%d",max);
}
// hàm kiểm tra  ma trận có phải ma trận tam giác trên không  
void Tamgiactren(int **a,int n){
	bool flag=true;
	for(int i=0;i<n;i++){
		if(i>j && a[i][j]!=0){
			flag=false;
			break;
		}
	}
	if(flag){
		printf("\nMa tran la ma tran tam giac tren.");
	}
	else{
		printf("\nDeo phai .");
	}
	
	bool  flag2=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i<j && a[i][j] !=0){
				flag2=false;
				break;
			}
		}
	}
	if(flag2){
		printf("\nMa tran la ma tran  tam giac duoi.");
	}
	else {
		printf("\nDeo phai ma tran tam giac duoi ");
	}
}
// diều kiện nằm  phía trên đường chéo phụ   : i + j = n+1 
int  main (){
	int  n; 
	int **a; 
  	char tentep[50]="Bai2thi.txt";
	DocFile(&a,n,tentep);
	Max(a,n);
	Tamgiactren(a,n);
	
	return 0;
}