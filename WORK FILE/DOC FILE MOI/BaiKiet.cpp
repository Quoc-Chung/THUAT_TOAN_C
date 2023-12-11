#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"conio.h"
#include"string.h"
int i, j;
struct Sach
{
	char ten[100];
	char nxb[100];
	float gia;
};
void nhap(Sach** sa, int &n, char *tentep)
{
	FILE *f;
	f=fopen(tentep,"r");
	if (f == NULL)
	{
		printf("\nKhong mo dc file.");
		exit(0);
	}
	fscanf(f,"%d", &n);
	*sa = (Sach*) malloc(n* sizeof(Sach));
	if(*sa == NULL)
	{
		printf("\nKhong cap phat dc.");
		exit(0);
	}
	for (i=0; i<n; i++)
	{
		fscanf(f," %[^\n]", (*sa)[i].ten);
		fscanf(f," %[^\n]", (*sa)[i].nxb);
		fscanf(f,"%f", &(*sa)[i].gia);
	}
	fclose(f);
}
void xuat(Sach *sa, int n)
{
	printf("-Thong tin sach-");
	for (i=0;i<n;i++)
	{
		printf("\nTenSach: %s, NXB: %s, Gia: %.1f", sa[i].ten, sa[i].nxb, sa[i].gia);
	}
}
int main()
{
	int n;
	Sach *sa;
	char tentep[100];
	printf("\nNhap tep: ");
	gets(tentep);
	nhap(&sa,n,tentep);
	xuat(sa,n);
}
