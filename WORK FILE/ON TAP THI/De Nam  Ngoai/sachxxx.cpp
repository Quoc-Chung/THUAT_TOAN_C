#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
typedef struct {
	char ten[40];
	char nxb[40];
	unsigned int gia;
} sach;

void Read(sach **a, int *n, char *ten) {
	FILE *f=fopen(ten, "r");
	if(f==NULL) {
		printf("Error opening file");
		getch();
		exit(0);
	}
	fscanf(f, "%d\n", n);
	*a=(sach*)calloc(*n, sizeof(sach));
	for(int i=0; i<*n; i++) {
		fscanf(f, " %[^\n]\n", (*a)[i].ten);
		fscanf(f, " %[^\n]\n", (*a)[i].nxb);
		fscanf(f, "%u\n", &(*a)[i].gia);
	}
	fclose(f);
}

void Printf(sach *a, int n, FILE *f=stdout) {
	fprintf(f, "Thong tin sach:\n");
	for(int i=0; i<n; i++) {
		fprintf(f, "%d. Sach thu %d:\n", i+1, i+1);
		fprintf(f, "Ten sach: %s\n", a[i].ten);
		fprintf(f, "Nha xuat ban: %s\n", a[i].nxb);
		fprintf(f, "Gia: %u\n", a[i].gia);
	}
	
	for(int i=0; i<n; i++) {
		printf("%d. Sach thu %d:\n", i+1, i+1);
		printf( "Ten sach: %s\n", a[i].ten);
		printf("Nha xuat ban: %s\n", a[i].nxb);
		printf("Gia: %u\n", a[i].gia);
	}
}

int Count(sach *a, int n, char *t, int *c) {
	for(int i=0; i<n; i++) {
		if(stricmp(a[i].nxb, t)==1) c++;
	}
	return *c;
}

main() {
	char ten[40]="sachx.txt";
	int n;
	sach *a;
//	printf("Input file name: ");
//	gets(ten);
	Read(&a, &n, ten);
	FILE *f=fopen("output22.txt", "wt");
	Printf(a, n, f);
	char temp[40];
	fflush(stdin);
	printf("Input author name: ");
	gets(temp);
//	printf("\\\\%s/////", temp);
	int c=0;
	printf("Co %d cuon sach boi nxb %s\n", Count(a, n, temp, &c));
	fprintf(f, "Co %d cuon sach boi nxb %s\n", Count(a, n, temp, &c));
	fclose(f);
}