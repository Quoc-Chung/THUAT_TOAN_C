#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
void DocFile(int ***a,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*a)=(int **) malloc(n*sizeof(int *));
	for (int i=0;i<n;i++){
		(*a)[i]=(int *)malloc (n*sizeof(int));
	}
	//  doc  ma tran  
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			fscanf(f,"%d",&(*a)[i][j]);
		}
	}
}
void InFile (int  **a,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",(a)[i][j]);
		}
		printf("\n");
	}
}
void MatranCheoPhu(int **a,int n){
	printf("\nCac  phan  tu nam  tren duong cheo phu :\n");
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(i+j==n+1){
				printf("%d ",(a)[i][j]);
			}
		}
	}
}
// max tung  hang cua  ma tran 
void MaxTungHang(int **a,int n){
	for (int i=0;i<n;i++){
		int max=0;
		for (int j=0;j<n;j++){
			if(max <a[i][j]){
				max=a[i][j];
			}
			printf("\nMax hang %d  la :%d",i+1,max);
		}
	}
} 
int main(){
	int n;
	int **a;
	char tentep[50]="matranvuong.txt";
	DocFile(&a,n,tentep);
	InFile (a,n);
	MatranCheoPhu(a,n);
	MaxTungHang(a,n);
	return 0;
	
}