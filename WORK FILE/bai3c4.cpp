#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 100
void NhapMaTran(float a[][MAX],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("\na[%d][%d]:",i,j);
			scanf("%f",&a[i][j]);
		}
	}
}
void InMaTranVaoFileVanBan(float a[][MAX],int n,int m){
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\bai3c4.txt";
	FILE *f;
	f=fopen(duong_dan,"w");
	if(f==NULL){
		printf("\nKhong mo duoc file");
		exit(1);
	}
	fprintf(f,"%d %d\n",n,m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		   fprintf(f,"%.2f ",a[i][j]);
		}
		
		fprintf(f,"\n");
	}
	fclose(f);
}
// ghi ra file nhị phân
void InMaTranVaoFileNhiPhan(float a[][MAX],int n,int m){
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\bai3c4np.bin";
	FILE *f;
	f=fopen(duong_dan,"wb");
	if(f==NULL){
		printf("\nKhong mo duoc file");
		exit(1);
	}
	fwrite(&n, sizeof(int), 1, f);
    fwrite(&m, sizeof(int), 1, f);

    for (int i = 0;i<n; i++) {
      for (int j = 0; j < m; j++) {
        fwrite(&a[i][j], sizeof(float), 1, f);
    }  
   }
   fclose(f);
   printf("\nMa tran da duoc ghi vao file nhi phan.");
}
void DocMaTranVaoFileNhiPhan(float a[][MAX],int n,int m){
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\bai3c4np.bin";
	FILE *f;
	f=fopen(duong_dan,"rb");
	if(f==NULL){
		printf("\nKhong mo duoc file");
		exit(1);
	}
	fread(&n, sizeof(int), 1, f);
    fread(&m, sizeof(int), 1, f);
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        fread(&a[i][j], sizeof(float), 1, f);
            }
        }
    printf("\nMa tran duoc doc tu file nhi phan :\n");
    for(int i =0;i<n;i++) {
    for(int j =0;j<m;j++) {
        printf("%.2f ",a[i][j]);
            }
            printf("\n");
        }
        fclose(f);
}  
int main(){
	int n,m;
	printf("Nhap n*m:");
	scanf("%d%d",&n,&m);
	float a[MAX][MAX];
	NhapMaTran(a,n,m);
	InMaTranVaoFileVanBan(a,n,m);
	InMaTranVaoFileNhiPhan(a,n,m);
	DocMaTranVaoFileNhiPhan(a,n,m);
	return 0;
	
}
