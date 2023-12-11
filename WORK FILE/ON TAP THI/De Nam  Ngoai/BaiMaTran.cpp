#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
void  DocFile(int ***a,int &n,char *tentep,FILE *f1=stdout){
	FILE *f=fopen (tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file .");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*a)=(int **)malloc (n*sizeof(int *));
	for(int i=0;i<n;i++){
		(*a)[i]=(int *) malloc (n*sizeof(int));
	}
	
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
		  	fscanf(f,"%d",&(*a)[i][j]);
		}
	}
	printf("\nMa tran  duoc doc ra  tu  tep  la :\n");
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
		  	printf("%d ",(*a)[i][j]);
		}
		printf("\n");
	}
	fprintf(f1,"\nMa tran nhap tu ban phim la :\n");
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
		  	fprintf(f1,"%d ",(*a)[i][j]);
		}
		fprintf(f1,"\n");
	}
}
void PhanTuLe(int **a,int n){
	int LeMax=INT_MIN;
	int dem=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(i==j  && a[i][j] %2 !=0 && LeMax <a[i][j]){
				LeMax=a[i][j];
				dem++;
			}
		}
	}
	if(dem==0){
		printf("\nKhong co phan tu le");
	}
	else {
		printf("\nPhan tu le nam tren duong cheo chinh lon nhat la :%d",LeMax);
	}
}
void TichChanHang(int **a,int n,FILE *f=stdout){
	for(int i=0;i<n;i++){
		int tich=1;
		for (int j=0;j<n;j++){
			tich*=a[i][j];
		}
		fprintf(f," \nTich Hang %d la %d",i,tich);
	}
}
int  main (){
	int n;
	int **a;
	char tentep[50];
	printf("\nNhap  ten  tep:");
	gets(tentep);
	FILE *f=fopen ("mt.txt","w");
	DocFile(&a,n,tentep,f);
	PhanTuLe(a,n);
	TichChanHang(a,n,f);
	return 0;
}