#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void input(int a[100][100],int m,int n){
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("\nNhap a[%d][%d]:",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}
void output (int  a[100][100],int m,int n){
    printf("\nMang  la :\n");
    for (int  i=0;i<m;i++){
        for (int j=0;j<n;j++){
           printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
int cmp(const void *a,const void *b){// hai con trỏ hàm có thể trỏ được vào hết loại con trỏ 
 int *x=(int *)a;
 int *y=(int *)b;
 return *x-*y;	
}
void arrange_rows(int a[100][100],int m,int n){
	printf("\nHang sap xep tang dan la : :\n");
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			qsort(a[i],n,sizeof(int),cmp);
		}
	}
	for (int  i=0;i<m;i++){
		for (int  j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void arrange_columns(int a[100][100],int m,int n){
	int  b[100][100];// tuc la kich thuoc cua hang bang kich thuoc cua cot  
	 int  hang=n,cot=m;
	 // chuyen vi ma tran tu ma tran a sang ma tran b
	  for (int i=0;i<hang;i++){
		for (int j=0;j<cot;j++){
			b[i][j]=a[j][i];
		}
	}
	printf("\nMa tran co cot sap xep tang dan  la :");
	arrange_rows(b,hang,cot);
	int c[100][100];
	int rows=m;
	int columns=n;
	for (int  i=0;i<rows;i++){
		for  (int  j=0;j<columns;j++){
			c[i][j]=b[j][i];
		}
	}
	for (int i=0;i<rows;i++){
		for (int  j=0;j<columns;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	 
}
int  main (){
	int  m,n;
	printf("\nNhap m va n:");
	scanf("%d%d",&m,&n);
	int a[100][100];
	input(a,m,n);
	output(a,m,n);
	arrange_rows(a,m,n);
	arrange_columns(a,m,n);
	return 0;
}



