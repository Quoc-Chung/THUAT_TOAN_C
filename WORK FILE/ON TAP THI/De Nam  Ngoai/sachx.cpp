#include "stdio.h"
#include "stdlib.h"
#include<math.h>
#include "string.h"
typedef struct {
	char ten[40];
	char nxb[40];
	unsigned int gia;
} sach;
void Read(sach **a, int *n, char *ten) {
	FILE *f=fopen(ten, "r");
	if(f==NULL){
		printf("Error opening file");
		exit(0);
	}
	fscanf(f, "%d\n", n);
	*a=(sach*)calloc(*n, sizeof(sach));
	for(int i=0; i<*n; i++) {
		fscanf(f, " %[^\n]", (*a)[i].ten);
		fscanf(f, " %[^\n]", (*a)[i].nxb);
		fscanf(f, "%u", &(*a)[i].gia);
	}
	fclose(f);
}

void Printf(sach *a, int n, FILE *f = stdout) {
    fprintf(f, "Thong tin sach:\n");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d. Sach thu %d:\n", i + 1, i + 1);
        fprintf(f, "Ten sach: %s\n", a[i].ten);
        fprintf(f, "Nha xuat ban: %s\n", a[i].nxb);
        fprintf(f, "Gia: %u\n", a[i].gia);
    }

    for (int i = 0; i < n; i++) {
        printf("%d. Sach thu %d:\n", i + 1, i + 1);
        printf("Ten sach: %s\n", a[i].ten);
        printf("Nha xuat ban: %s\n", a[i].nxb);
        printf("Gia: %u\n", a[i].gia);
    }
}

int Count(sach *a, int n,char *tg) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].nxb, tg) == 0) c++;
    }
    return c;
}
int main() {
    char ten[40] = "sachx.txt";
    int n;
    sach *a;

    Read(&a, &n, ten);
    FILE *f = fopen("output22.txt", "wt");
    Printf(a, n, f);
	char temp[40];
    fflush(stdin);
    printf("Input author name: ");
    gets(temp);
    printf("Co %d cuon sach boi nxb %s\n", Count(a, n,temp),temp);
  //  fprintf(f, "Co %d cuon sach boi nxb %s\n", Count(a, n, temp, &c));
    fclose(f);

    free(a);
    return 0;
}