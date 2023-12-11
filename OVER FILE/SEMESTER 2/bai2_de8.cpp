#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void delete_newline(char c[]){
	size_t len =strlen(c);
	if(c[len-1]=='\n'){
		c[len-1]='\0';
	}
}
struct sach{
	char ten_sach[30];
	char tenTG[30];
	int nam_xb;
};
typedef struct sach SACH;
//void nhap_1_sach(SACH &s){
//	printf("\nNhap ten sach:");
//	fflush(stdin);
//	fgets(s.ten_sach,sizeof(s.ten_sach),stdin);
//	printf("\nNhap ten tac gia:");
//	fflush(stdin);
//	fgets(s.tenTG,sizeof(s.tenTG),stdin);
//	printf("\nNhap nam xuat ban:");
//	scanf("%d",&s.nam_xb);
//}
//void nhap_nhieu_sach(SACH s[],int &n){
//	printf("\nNhap so luong sach:");
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++){
//		nhap_1_sach(s[i]);
//	}
//}
void in_thuong(SACH s[],int &n){
	for (int i=1;i<=n;i++){
//			delete_newline(s[i].ten_sach);
//           delete_newline(s[i].tenTG);
		printf("%s",s[i].ten_sach);
		printf("%s",s[i].tenTG);
		printf("%d",s[i].nam_xb);
	}
}
void in_dang_bang(SACH s[],int &n){
 printf("\n\t\t\t\tBANG THONG TIN \n");
printf("+--------------------------------------------------------------------------------+\n");
printf("|%-5s | %-30s | %-27s | %-8s |\n","STT","TEN SACH","TEN TAC GIA","NAM XB");
printf("+--------------------------------------------------------------------------------+\n");
                          for (int i=1;i<=n;i++){
                          	delete_newline(s[i].ten_sach);
                            delete_newline(s[i].tenTG);
printf("|%-5d | %-30s | %-27s | %-8d |\n",
        i,s[i].ten_sach,s[i].tenTG,s[i].nam_xb);
}
printf("+-------------------------------------------------------------------------------+\n");
}
void ghi_vao_file(SACH s[],int n){
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\bai2_de8.txt";
	FILE *f;
	f=fopen(duong_dan,"w");
	if(f==NULL){
		printf("\nKhong ghi duoc ket qua vao file");
		exit(1);
	}
	fprintf(f,"%d\n",n);
	for (int i=1;i<=n;i++){
		fprintf(f,"\n%s ",s[i].ten_sach);
		fprintf(f,"\n%s ",s[i].tenTG);
		fprintf(f,"\n%d ",s[i].nam_xb);
	}
	fclose(f);
}
void doc_file(SACH s[],int &n){
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\bai2_de8.txt";
	FILE *f;
	f=fopen(duong_dan,"r");
	if(f==NULL){
		printf("\nKhong su dung duoc file ket qua.");
		exit(1);
	}
	fscanf(f,"%d",&n);
//	for (int i=1;i<=n;i++){
//		fgets(s[i].ten_sach,sizeof(s[i].ten_sach),f);
//        fgets(s[i].tenTG,sizeof(s[i].tenTG),f);
//        fread(&s[i].nam_xb,sizeof(s[i].nam_xb),1,f);
//	}
	
	for (int i = 1; i<=n; i++){
        
        fgets((*sv)[i].ten_sach, 50, f);
        fscanf(f, "%d", &sv[i].nam_xb);
        fgets((*sv)[i].tenTG, 50, f);
   }
	fclose(f);
}
void swap(SACH *a,SACH *b){
	SACH tam=*a;
	*a=*b;
	*b=tam;
}
void sapxepsach(SACH s[],int &n){
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\ket_qua_2_8.txt";
	FILE *f;
	f=fopen(duong_dan,"w");
	if(f==NULL){
		printf("\nKhong mo duoc file ghi ket qua.");
		exit(1);
	}
	for (int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++){
			if(s[i].nam_xb >s[j].nam_xb){
				swap(&s[i],&s[j]);
			}
		}
	}
	printf("\nSach duoc sap xep tam thoi:\n");
	for (int i=1;i<=n;i++){
		printf("\n%s",s[i].ten_sach);
	}
	for (int i=1;i<=n;i++){
		if(s[i].nam_xb>=2000){
		     fprintf(f,"%s",s[i].ten_sach);	
		}
	}
	//close file 
	fclose(f);
}
//int main (){
//	int n;
//	SACH s[100];
//	nhap_nhieu_sach(s,n);
//	in_dang_bang(s,n);
//	ghi_vao_file(s,n);
//	return 0;
//}
int main (){
	int n;
	SACH s[100];
	doc_file(s,n);
	in_dang_bang(s,n);
	sapxepsach(s,n);
//	in_thuong(s,n);
	return 0;
}
















