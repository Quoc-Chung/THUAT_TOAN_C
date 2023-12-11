//BAI 1.1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void ReadFile(int **a, int **b, int *m ,int *n, char *tentep){
	FILE *f;
	f=fopen(tentep,"r");
	if(f==NULL){
		printf("Khong mo duoc tep!");
		exit(0);
	}
	fscanf(f,"%d%d",m,n);
	*a = (int *)malloc((*m+1) * sizeof(int));
	*b = (int *)malloc((*n+1) * sizeof(int));
	for(int i=0;i<=*m;i++) fscanf(f,"%d",(*a)+i);
	for(int i=0;i<=*n;i++) fscanf(f,"%d",(*b)+i);// chỗ này sửa lại thành *b+i
	fclose(f);
}
void Print(int *a,int m){
	printf("\nMang duoc doc tu File :\n");
	for(int i=0;i<=m;i++){
	 printf("%d ",a[i]);
}// tách ra  
	printf("\n");
}
int main(){
	int *a,*b;
	int m,n;
	char tentep[50];
	printf("Nhap ten du lieu:");gets(tentep);
	ReadFile(&a,&b,&m,&n,tentep);
	Print(a,m);
	Print(b,n);
}
