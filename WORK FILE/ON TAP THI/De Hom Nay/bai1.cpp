#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
void  DocFile (float  ***a,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file .");
		exit(0);
	}
	fscanf(f,"%d",&n);
	//Cap phat dong  
	(*a)=(float  **) malloc  (n*sizeof(float *));
	for (int i=0;i<n;i++){
		(*a)[i]=(float  *) malloc  (n*sizeof(int));
	}
   for(int i=0;i<n;i++){
   	for(int j=0;j<n;j++){
   		fscanf(f,"%f", &(*a)[i][j]);
	   }
   }
   printf("\nMa tran duoc doc tu  file  la  :\n");
   for  (int i=0;i<n;i++){
   	for  (int j=0;j<n;j++){
   		printf("%.2f ",(*a)[i][j]);
	   }
	   printf("\n");
   }
}

void InMaTran(float **a,int n){
	printf("\nHAm in  ma  tran  :\n");
	for  (int  i=0;i<n;i++){
		for  (int  j=0;j<n;j++){
			printf("%.2f ",a[i][j]);
		}
		printf("\n");
	}
}
void  TinhTrungBinhCong(float  **a,int n){
	float tong  =0;
	for  (int i=0;i<n;i++){
		for  (int j=0;j<n;j++){
			if(i+j==n-1){
					tong+=a[i][j];
			}
		
		}
	}
	printf("\nTong duong  cheo  phu  ma tran :%.2f",tong);
}
int main(){
	int  n;
	float  **a;
	char  tentep[50]="Matran1.txt";
	DocFile (&a,n,tentep);
	InMaTran (a,n);
	TinhTrungBinhCong(a,n);
	return 0;
	
}