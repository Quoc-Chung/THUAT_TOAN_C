#include <stdio.h>
#include <stdlib.h>
void doc(float ***a,int *m,int *n,char *t) {
	FILE *f;
	f = fopen(t,"r");
	fscanf(f,"%d%d",m,n);
	// Cấp phát cho từng hàng
	*a = (float **) malloc((*m)*sizeof(float *));
	for (int i = 0; i < *m; i++) {
		(*a)[i] = (float *) malloc((*n)*sizeof(float));
	}
	// Đọc dữ liệu từ file
	for (int i = 0; i <*m;i++) {
		for (int j = 0; j <*n; j++) {
			fscanf(f,"%f",&((*a)[i][j]));
		}
	}
	fclose(f);
}
void in(float **a,int m,int n) {
	printf("Ma tran la:\n");
	for (int i = 0; i <m; i++) {
		for (int j = 0; j <n; j++) {
			printf("%.1f ",a[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int n, m;
	float **a;
	char t[100];
	printf("Nhap ten tep:");
	fflush(stdin);
	gets(t);
	doc(&a,&m,&n,t);
	in(a,m,n);

	// Giải phóng bộ nhớ đã cấp phát
	for (int i = 0; i < m; i++) {
		free(a[i]);
	}
	free(a);
}
