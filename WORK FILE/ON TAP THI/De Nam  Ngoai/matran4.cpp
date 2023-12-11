#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
void DocFile(int ***a,int &m,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file .");
		exit(0);
	}
	fscanf(f,"%d%d",&m,&n);
	// cap phat dong 
	(*a)= (int **) malloc (m*sizeof(int *));
	for(int i=0;i<m;i++){
		(*a)[i]=(int *) malloc (n*sizeof(int));
	}
	// doc ma tran tu tep 
	for(int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			fscanf(f,"%d",&(*a)[i][j]);
		}
	}
	printf("\nMa tran in dang bang la :\n");
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ",(*a)[i][j]);
		}
		printf("\n");
	}
}
void TichPhanTuLe (int **a,int m,int n){
	int tich=1;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(a[i][j] %2!=0){
				tich *=a[i][j];
			}
		}
	}
	printf("\nTich Cac phan tu le la :%d",tich);
}

int  main(){
	int n,m;
	int **a;
	char tentep[50]="matran4.txt";
	DocFile(&a,m,n,tentep);
	 TichPhanTuLe(a,m,n);
	return 0;
}