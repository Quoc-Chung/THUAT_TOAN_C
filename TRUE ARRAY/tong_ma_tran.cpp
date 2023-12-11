#include <stdio.h>
#include <stdlib.h>
int main(){
	int m, n,p;

	scanf("%d%d%d",&m,&n,&p);
	 int **a =(int **)malloc(m * sizeof(int *));
    for(int i = 0; i < m; i++){
        a[i] = (int *)malloc(n * sizeof(int));
    }
    int **b = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){
        b[i] = (int *)malloc(p * sizeof(int));
    }
    int **c = (int **)malloc(m * sizeof(int *));
    for(int i = 0; i < m; i++){
        c[i] = (int *)malloc(p * sizeof(int));
    }
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<p;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            c[i][j] = 0;
            for(int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
	for (int i=0;i<m;i++){
		for (int j=0;j<p;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	for(int i = 0; i < m; i++){
        free(a[i]);
	}
    free(a);

    for(int i = 0; i < n; i++){
        free(b[i]);
    }
    free(b);
    for(int i = 0; i < m; i++){
        free(c[i]);
    }
    free(c);
	return 0;
}