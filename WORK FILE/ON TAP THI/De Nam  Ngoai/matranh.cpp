#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void read(int **a,int *m,int *n,char *tentep,FILE *f1=stdout)
{
	FILE *f;
	f=fopen(tentep,"r");
	if(f==NULL)
	{
		printf("loi mo tep");
		exit(0);
	}
	fscanf(f,"%d%d",m,n);
	
		*a = (int *)malloc((*m) * (*n) * sizeof(int));
	for(int i=0;i<*m;i++)
	for(int j=0;j<*n;j++)
	{
		fscanf(f, "%d", &(*a)[*m * i + j]);
	}
	for(int i=0;i<*m;i++)
	{
	for(int j=0;j<*n;j++)
		fprintf(f1,"%d",(*a)[*m*i+j]);
		fprintf(f1,"\n");
    }

}
void tich(int*a,int m,int n)
{
	int tich=1;
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		if(a[m*i+j]%2==1)
		tich=tich*a[m*i+j];
	}
	printf("\nTich cac so le trong ma tran la:%d",tich);
}
int main()
{
	int *a, m, n;
	char tentep[100] = "matran3.txt";
	FILE *f1 = fopen("hunghoang.txt", "w");
	if (f1 == NULL)
	{
		printf("loi mo tep");
		exit(0);
	}
	read(&a, &m, &n, tentep, f1);
	tich(a, m, n);
	return 0;
}