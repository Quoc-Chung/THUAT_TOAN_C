#include <stdio.h>
#include <stdlib.h>
void nhapmang(int A[100][100],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("A[%d][%d]=",i,j);
			scanf("%d",&A[i][j]);
		}
	}
	printf("Ma tran vua nhap:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
}
int tong(int A[100][100],int n)// tong duong cheo phu
{
	int i,j,tong=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==n-1-i || i==n-1-j)
			{
				tong+=A[i][j];
			}
		}
	}
	return tong;
}
int main(int argc, char *argv[]) 
{
	int A[100][100],n;
	printf("Nhap so bac cua mang:");
	scanf("%d",&n);
	nhapmang(A,n);
	printf("Tong duong cheo phu:%d",tong(A,n));
	return 0;
}