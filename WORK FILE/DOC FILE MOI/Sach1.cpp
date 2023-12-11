#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct  Sach{
	char TenSach[50];
	char NhaXuatBan[50];
	int giaThanh;
};
void DocFile(Sach **s,int  &n, char *tentep){
	FILE *f;
	f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the mo duoc file .");
		exit(0);
	}
	fscanf(f,"%d",&n);
	*s=(Sach *) malloc (n*sizeof(Sach));
	for(int i=0;i<n;i++){
        fgets((*s)[i].TenSach,sizeof((*s)[i].TenSach),f);
        fgets((*s)[i].NhaXuatBan,sizeof((*s)[i].NhaXuatBan),f);
        fscanf(f,"%d",&((*s)[i].giaThanh));       
	}
}
void InFile(Sach *s,int n){
	printf("\nNoi dung trong  van ban la :\n");
	for(int i=0;i<n;i++){
		printf("\nSach thu %d:\n",i+1);
		printf("\nTen Sach :%s\n",s[i].TenSach);
		printf("\nNha xuat ban :%s\n",s[i].NhaXuatBan);
		printf("\nGia thanh :%d\n",s[i].giaThanh);
	}
}
int main(){
	int  n;
	Sach *s;
	char tentep[50]="Sach.txt";
	DocFile(&s,n,tentep);
	InFile(s,n);
	return 0;
}