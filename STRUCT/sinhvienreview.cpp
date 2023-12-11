#include <stdio.h>
#include <math.h>
#include <string.h>
struct sinhvien {
	char ten[30];
	float toan,li,hoa;
};
void xoaxuongdong(char c[]){
	size_t len=strlen(c);
	if(c[len-1]=='\n'){
		c[len-1]='\0';
	}
}
void nhap(sinhvien sv[],int n){
	for (int i=1;i<=n;i++){
		printf("\nNhap sinh vien thu %d:\n",i);
		printf("\nNhap ho ten:");
		fflush(stdin);
		fgets(sv[i].ten,sizeof(sv[i].ten),stdin);
		printf("\nNhap diem toan -li -hoa :");
		scanf("%f%f%f",&sv[i].toan,&sv[i].li,&sv[i].hoa);
	}
}
void in(sinhvien sv[],int n){
	for (int i=1;i<=n;i++){
	//	xoaxuongdong(sv[i].ten);
		printf("\nHo va ten :%s",sv[i].ten);
		printf("\tDiem toan:%.2f",sv[i].toan);
		printf("\tDiem li:%.2f",sv[i].li);
		printf("\tDiem hoa :%.2f",sv[i].hoa);
}
}
void satisfy(sinhvien sv[],int n){
	printf("\nDanh sach sinh vien co diem thoa man :\n");
	for (int i=1;i<=n;i++){
		if(sv[i].toan>=9 || sv[i].li>=9 || sv[i].hoa>=9){
			printf("%s",sv[i].ten);
		}
	}
}
void information(sinhvien sv[],int n,char c[]){
	for (int i=1;i<=n;i++){
		if(strcmp(sv[i].ten,c)==0){
		printf("\nHo va ten:%s",sv[i].ten);
		printf("\tDiem toan:%.2f",sv[i].toan);
		printf("\tDiem li:%.2f",sv[i].li);
		printf("\tDiem hoa :%.2f",sv[i].hoa);
		}
	}
}
void sapxep(sinhvien sv[],int n){
	for (int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++){
			if(sv[i].toan<sv[j].toan){
			sinhvien tam=sv[i];
				sv[i]=sv[j];
				sv[j]=tam;
			}
		}
		
	}
	printf("\nSinh vien theo diem toan tang dan la :\n");
	for (int i=1;i<=n;i++){
		printf("%s\n",sv[i].ten);
	}
}
int main(){
	int n;
	printf("Nhap so sinh vien :");
	scanf("%d",&n);
	sinhvien sv[100];
	nhap(sv,n);
	in(sv,n);
	satisfy(sv,n);
	char ten[30];
	printf("\nNhap ten kiem tra:");
	fflush(stdin);
	fgets(ten,sizeof(ten),stdin);
	information(sv,n,ten);
	sapxep(sv,n);
	return 0;
}