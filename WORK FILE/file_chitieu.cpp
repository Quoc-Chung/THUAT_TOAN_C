#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
// 1. ID khoản mục chi tiêu là số nguyên tự động 
//tăng từ 1; 2. loại khoản mục: 1 là thu và 2 là chi; 3. tên khoản mục; 4. số tiền
void delete_newline(char c[]){
	size_t len =strlen (c);
	if(c[len-1]=='\n'){
		c[len-1]='\0';
	}
}
struct chitieu{
	int id;
	char khoanmuc[4];
	char tenkhoan[20];
	float sotien;
};
void nhap(chitieu ct[],int &n){
	for (int i=1;i<=n;i++){
		ct[i].id=i;
		printf("\nNhap khoan muc :");
	  fflush(stdin);
	  fgets(ct[i].khoanmuc,sizeof(ct[i].khoanmuc),stdin);
	  printf("\nNhap ten khoan muc :");
	  fflush(stdin);
	  fgets(ct[i].tenkhoan,sizeof(ct[i].tenkhoan),stdin);
	  printf("\nNhap so tien:");
	  scanf("%f",&ct[i].sotien);
    }
}
void in(chitieu ct[],int n){
	printf("\n%-2s \t %-10s \t %-10s \t %-10s","ID","KHOAN MUC","TEN KHOAN","SO TIEN");
	for (int i=1;i<=n;i++){
		delete_newline(ct[i].khoanmuc);delete_newline(ct[i].tenkhoan);
	printf("\n%-2d \t %-10s \t %-10s \t %-10.0f",ct[i].id,ct[i].khoanmuc,ct[i].tenkhoan,ct[i].sotien);
	}
}
void ghi_vao_file (chitieu ct[],int n,char diachifile[]){
	// mo file 
	FILE *f;
	// open file 
	f=fopen(diachifile,"wb");// file  have function write result 
	if(f==NULL){
		printf("\nFile khong ghi duoc ket qua");
		exit(1);
	}
	fwrite(&n,sizeof(n),1,f);// chi ghi mot so n duy nhat vao file;
	for (int i=1;i<=n;i++){
		fwrite(&ct[i],sizeof(struct chitieu),1,f);
	}      
	// close file 
	fclose(f);
}
void lay_test_tu_file(chitieu ct[],int &n,char diachifile[]){
	FILE *f;
	// open file 
	f=fopen(diachifile,"rb");// file  have function read result 
	if(f==NULL){
		printf("\nKhong mo duoc file chua ket qua");
		exit(1);
	}
	fread(&n,sizeof(n),1,f);// chi ghi mot so n duy nhat vao file;
	for (int i=1;i<=n;i++){
		fread(&ct[i],sizeof(struct chitieu),1,f);
	}
	// close file 
	fclose(f);
}
// hàm ghi dùng struct chi tieu 1,hàm doc dung struct chi tieu 2
int main(){
	int n=3;
	char duongdan[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\chitieu.bin";
	chitieu ct1[100],ct2[100];
//	nhap(ct1,n);
	lay_test_tu_file(ct2,n,duongdan);
//	in(ct,n);
    in(ct2,n);
//	ghi_vao_file(ct1,n,duongdan);
	return 0;
}
