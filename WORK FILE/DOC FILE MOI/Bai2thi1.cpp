#include<stdio.h>
#include<math.h>
void  DocFile(int a[][100],int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duuoc file .");
		exit(0);
	}
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(f,"%d",&a[i][j]);
		}
	}
	printf("\nMa tran doc tu tep ra  la :\n");
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	fclose(f);
}
void GhiFile(int a[][100],int n){
	printf("\nMA tran  duoc in ra trong  ham moi la  :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
int  main (){
	int  n; 
	int a[100][100];
  	char tentep[50]="Bai2thi.txt";
    DocFile(a,n,tentep);
	GhiFile(a,n);
	return 0;
}