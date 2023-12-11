#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
void DocFile(int  ***a,int &m,int  &n, char  *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file .");
		exit(0);
	}
	fscanf(f,"%d%d",&m,&n);
	(*a)=(int **) malloc (m *sizeof(int*));
	for(int i=0;i<m;i++){
		(*a)[i]=(int *) malloc(n*sizeof(int));
	}
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			fscanf(f,"%d",&(*a)[i][j]);
		}
	}
	printf("\nMa tran doc tu  tepp la :\n");
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ",(*a)[i][j]);
		}
		printf("\n");
	}
}
void TichPhanTuLe(int **a,int m,int n){
	for (int j=0;j<n;j++){
		int tich=1;
		for(int i=0;i<m;i++){
			if(a[i][j] %2!=0){
				tich*=a[i][j];
			}
		}
		printf("\nTich cot %d la :%d", j+1,tich);
	}
}
void  ChanMax(int **a,int m,int n){
	int max=0;
	int hang=0,cot=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
		  if(a[i][j] %2==0 && max <a[i][j]){
		  	max=a[i][j];
		  	hang=i,cot=j;
		  }	
		}
	}
	printf("\nPhan tu max la a[%d][%d]= %d", hang+1,cot+1,max);
}
int main(){
	int m,n;
	int **a;
	char tentep[50]="matran3.txt";
	DocFile(&a,m,n,tentep);
	TichPhanTuLe(a,m,n);
	ChanMax(a,m,n);
	return 0;
}
