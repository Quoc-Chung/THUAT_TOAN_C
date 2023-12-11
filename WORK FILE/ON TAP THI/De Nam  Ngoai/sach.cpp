#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct Sach {
	int MaSach;
	char TenSach[50];
	char TacGia[30];
	int NamXB;
	int Gia;
};
void DocFile(Sach **s,int &n,char *tentep,FILE *f1=stdout){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file ");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*s)=(Sach*) malloc (n*sizeof(Sach));
	for (int i=0;i<n;i++){
		fscanf(f,"%d",&(*s)[i].MaSach);
		fscanf(f, " %[^\n]",(*s)[i].TenSach);
		fscanf(f," %[^\n]",(*s)[i].TacGia);
		fscanf(f,"%d",&(*s)[i].NamXB);
		fscanf(f,"%d",&(*s)[i].Gia);
	}
	printf("\nThong tin cuon sach la  :\n");
	for (int i=0;i<n;i++){
			printf("\nMa Sach:%d--Ten Sach :%s--Ten Tac Gia:%s--Nam Xuat Ban :%d--Gia:%d",
		  (*s)[i].MaSach,(*s)[i].TenSach,(*s)[i].TacGia,(*s)[i].NamXB,(*s)[i].Gia);
	}
	fprintf(f1,"\nThong tin  cua sach la :\n");
	for (int i=0;i<n;i++){
		fprintf(f1,"\nMa Sach:%d--Ten Sach :%s--Ten Tac Gia:%s--Nam Xuat Ban :%d--Gia:%d",
		  (*s)[i].MaSach,(*s)[i].TenSach,(*s)[i].TacGia,(*s)[i].NamXB,(*s)[i].Gia);
	}
}
void TimSach (Sach *s,int n,FILE  *f=stdout){
	int gia;
	char Ten[50];
	printf("\nNhap gia:");
	scanf("%d",&gia);
	printf("\nNhap  ten sach :");
	fflush(stdin);
	gets(Ten);
	bool check=false;
	for (int i=0;i<n;i++){
		if(strcmp(s[i].TenSach,Ten)==0 && s[i].Gia==gia){
			fprintf(f,"\nTim Thay Sach .\n");
			fprintf(f,"\nMa Sach:%d--Ten Sach :%s--Ten Tac Gia:%s--Nam Xuat Ban :%d--Gia:%d",
		  (s)[i].MaSach,(s)[i].TenSach,(s)[i].TacGia,(s)[i].NamXB,(s)[i].Gia);
		  check=true;
		  break;
		}
	}
	if(check==false){
		fprintf(f,"\nKhong tim thay sach");
	}
}
void ThuTu(Sach *s,int n,FILE *f=stdout){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(s[i].NamXB > s[j].NamXB){
				Sach tmp=s[i];
				s[i]=s[j];
				s[j]=tmp;
			}
		}
	}
	fprintf(f,"\nThu tu giam dan cua cuon sach la  :\n");
		for (int i=0;i<n;i++){
		fprintf(f,"\nMa Sach:%d--Ten Sach :%s--Ten Tac Gia:%s--Nam Xuat Ban :%d--Gia:%d",
		  (s)[i].MaSach,(s)[i].TenSach,(s)[i].TacGia,(s)[i].NamXB,(s)[i].Gia);
	}
}
int main(){
	int n;
	Sach *s;
	char tentep[50]="sach.txt";
	FILE *f=fopen("kqsach.txt","w");
	DocFile(&s,n,tentep,f);
	TimSach (s,n,f);
		ThuTu(s,n,f);
			return 0;
}
// giamr dan la dau > 4  > 3 
// tang dan la dau  3 < 4 