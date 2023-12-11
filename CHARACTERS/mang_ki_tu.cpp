#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
 // mang co 4 dong va 7 ki tu 
//*****X**
//*****XX*
//*XXX****
//****X***
int main (){
	int m,n;
	scanf("%d%d",&m,&n);
	char c[100][100];
	for (int i=0;i<m;i++){// duyt qua tung hang cua ma tran xau 
		for (int  j=0;j<n;j++){// duyt qua tung ki tu trong mot hang cua xau 
			scanf("%c",&c[i][j]);
		}
	}
	printf("\nMang ki tu vua nhap la :\n");
	for (int i=0;i<m;i++){
	for (int j=0;j<n;j++){
		printf("%c ",c[i][j]);// ki tu o dong i và ở vi tri thu j trong dong đó
	}
}
	printf("\n");
}