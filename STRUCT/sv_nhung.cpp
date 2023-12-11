#include <stdio.h>
#include <math.h>
#include <string.h>
struct sinhvien {
	int maSV;
	char ten[30];
	char khoa[2];
	float diemTB;
};
// moi thong tin hie thi tren mot dong
void xoa(char c[]){
	size_t len=strlen(c);
	if(c[len-1]=='\n'){
		c[len-1]='\0';
	}
}
void nhap(sinhvien sv[],int n){
	for (int i=1;i<=n;i++){
		printf("\nSinh vien thu %d :\n",i);
//		printf("\nNhap MASV:");
//		scanf("%d",&sv[i].maSV);
		printf("\nNhap ho va ten:");
		fflush(stdin);
		fgets(sv[i].ten,sizeof(sv[i].ten),stdin);
		printf("\nNhap ten khoa:");
		fflush(stdin);
		fgets(sv[i].khoa,sizeof(sv[i].khoa),stdin);
//		printf("\nNhap diem trung binh :");
//		scanf("%f",&sv[i].diemTB);
	}
}

void in(sinhvien sv[],int n){
	printf("\nTHONG TIN SINH VIEN :\n");
	for (int i=1;i<=n;i++){
	//	printf("\nSinh vien thu %d:\n",i);
		xoa(sv[i].ten);// xóa kí tự xuống dòng \n
	//	printf("\nMa sinh vien:%d",sv[i].maSV);
		printf("\nHo va ten:%s",sv[i].ten);
		xoa(sv[i].khoa);// xóa kí tự xuống dòng \n
		printf("\tKhoa :%s",sv[i].khoa);
		//printf("\tDiem trung binh :%.2f",sv[i].diemTB);
	}
}
void information(sinhvien sv[],int n){
	char khoa1[2]="A",khoa2[2]="B",khoa3[2]="C";// so sanh hai chuoi nên ta phai dung dau ""
	int dem1=0,dem2=0,dem3=0;
	for (int i=1;i<=n;i++){
		if(strcmp(sv[i].khoa,khoa1)==0){
			dem1++;
		}
		if(strcmp(sv[i].khoa,khoa2)==0){
			dem2++;
		}
		if(strcmp(sv[i].khoa,khoa3)==0){
			dem3++;
		}
	}
	printf("\nThong tin sv moi khoa:");
	printf("\nKhoa A:%d",dem1);
	printf("\nKhoa B:%d",dem2);
	printf("\nKhoa C:%d",dem3);
	if(dem1<dem2 && dem1<dem3){
		printf("\nKhoa A it sinh vien nhat");
	}
	else if(dem2<dem1 && dem2<dem3){
		printf("\nKhoa B co it sinh vien nhat");
	}
	else {
		printf("\nKhoa C co it sinh vien nhat ");
	}
}
int main (){
	int n;
	printf("Nhap so sinh vien :");
	scanf("%d",&n);
	sinhvien sv[100];
	nhap(sv,n);
	in(sv,n);
    information(sv,n);
	return 0;
}