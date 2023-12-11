#include <stdio.h>

void nhapmang(int *&a, int &m, int &n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void inmang(int *&a, int &m, int &n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
	printf("\n");	
	}
}

int main(){
	int m,n;
	scanf("%d%d", &m, &n);
	int a[100][100];
	nhapmang(a,m,n);
	inmang(a,m,n);
}
