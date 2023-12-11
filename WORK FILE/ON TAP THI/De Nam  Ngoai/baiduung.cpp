#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct HS{
	char ht[100];
	int diem;
	char truong[3];
	
};
void read_file(struct HS **hs, int *n, FILE *f1){
	FILE *f=fopen("dung.txt", "r");
	if(f==NULL){
		printf("ERROR");
		exit(1);
	}
	fscanf(f, "%d", n);
	*hs=(HS*)malloc(*n*sizeof(HS));
	for(int i=0; i<*n; i++){
		fscanf(f, " %[^\n]", (*hs)[i].ht);
		fscanf(f, "%d", &(*hs)[i].diem);
		fscanf(f, " %[^\n]", (*hs)[i].truong);
	}

	for(int i=0; i<*n; i++){
	    fprintf(f1, "\n%s", (*hs)[i].ht);
	    fprintf(f1, "\n%d", (*hs)[i].diem);
	    fprintf(f1, "\n%s", (*hs)[i].truong);
    }
	fclose(f);
}
void tong(HS *hs, int n, FILE *f1){
	int A=0;
	int B=0;
	int C=0;
	for(int i=0; i<n; i++){
		if(strcmp(hs[i].truong, "A")==0){
			A+=hs[i].diem;
		}
	    if(strcmp(hs[i].truong, "B")==0){
			 B+=hs[i+1].diem;
		}
		if(strcmp(hs[i].truong, "C")==0){
			C+=hs[i].diem;
		}
	}
	fprintf(f1, "\n%d", A);
	fprintf(f1, "\n%d", B);
	fprintf(f1, "\n%d", C);
	
}
int main(){
	int n;
	struct HS *hs; 
	FILE *f1=fopen("kqdung.txt", "w");
	read_file(&hs, &n, f1);
	tong(hs, n, f1);
	
	
}
