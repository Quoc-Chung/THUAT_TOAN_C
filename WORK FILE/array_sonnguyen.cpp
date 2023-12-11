#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

void nhapmang(int a[],int n){
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
void inmang(int a[],int n){
	printf("\n");
	for (int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
void trich_xuat_file (int a[],int &n){
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\input.txt";
	FILE *f;
	f=fopen(duong_dan,"r");
	if(f==NULL){
		printf("\nKhong trich xuat duoc test.");
		exit(1);
	}
	// lấy số n từ file 
	fscanf(f,"%d",&n);
	// lay mang tu file 
	for (int i=0;i<n;i++){
		fscanf(f,"%d",&a[i]);
	}
	// đóng file
	fclose(f);
}

void max_mang_dem_chan_le(int a[],int n){
	char duong_dan1[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\ketqua_input.txt";
	FILE *f;
	f=fopen(duong_dan1,"w");
	if(f==NULL){
		printf("\nKhong the mo duoc file.");
		exit(1);
	}
	int max=INT_MIN;
	int dem_chan=0,dem_le=0;
	for (int i=0;i<n;i++){
		if(max<a[i]){
			max=a[i];
		}
		if(a[i]%2==0){
			dem_chan++;
		}
		if(a[i]%2!=0){
			dem_le++;
		}
	}
	fprintf(f,"\n %d ",max);
	fprintf(f,"\n %d ",dem_chan);
	fprintf(f,"\n %d ",dem_le);
}
void swap(int *a,int *b){
	int tam=*a;
	*a=*b;
	*b=tam;
}
void sapxep(int a[],int n){
	char duong_dan1[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\ketqua_input.txt";
	FILE *f;
	f=fopen(duong_dan1,"w");
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				swap(&a[i],&a[j]);
			}
		}
	}
	for (int i=0;i<n;i++){
		fprintf(f," %d ",a[i]);
	}
	// đóng file 
	fclose(f);
}
int main(){
	int n;
	// cấp phát động cho mảng không bị thừa memory 
	int *a;
	a=(int *) malloc (n*sizeof(int));
	trich_xuat_file(a,n);
	max_mang_dem_chan_le(a,n);
	sapxep(a,n);
	return 0;
}