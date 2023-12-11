//Viết chương trình nhập thông tin cho n ô tô vận tải từ tệp oto.txt. Mỗi ô tô là một 
//cấu trúc và được lưu trữ trên 3 dòng của tệp gồm: BKS (Số biển kiểm soát: là một số 
//nguyên), TT (Trọng tải: là một số thực), CTy (Công ty chủ quản: là một ký tự). Cho biết: 
//chỉ có 3 công ty chủ quản là : A. B, C. Yêu cầu: 
//1. Đếm xem có bao nhiêu ô tô của công ty B có BKS chia hết cho 3. 
//2. In ra màn hình 3 ô tô có trọng tại nhỏ nhất. 
//3. Kết quả lưu vào tệp Output.txt bao gồm cả các thông tin về n ô tô vận tải
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
struct VanTai{
	int bien;
	float TrongTai;
	char Cty;
};
void DocFile(VanTai **vt,int &n,char *tentep){
	FILE *f;
	f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the no duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	*vt=(VanTai*) malloc (n*sizeof(VanTai));
	if(*vt==NULL){
		printf("\nKhong the cap phat bo nho.");
		exit(0);
	}
	for(int i=0;i<n;i++){
		fscanf(f,"%d",&(*vt)[i].bien);
		fscanf(f,"%f",&(*vt)[i].TrongTai);
		fscanf(f," %c",&(*vt)[i].Cty);
	}
}
void GhiTepTuFile(VanTai*vt,int n,FILE *f=stdout){
	fprintf(f,"\n----------Thong tin van tai ----------");
	for (int i=0;i<n;i++){
		fprintf(f,"\nTen bien so : %d",vt[i].bien);
		fprintf(f,"\nTrong Tai : %f",vt[i].TrongTai);
		fprintf(f,"\nTen Cong Ty : %c",vt[i].Cty);
	}
}
void DemOTo(VanTai *vt,int n,FILE *f=stdout){
	int dem=0;
	for (int i=0;i<n;i++){
		if( vt[i].bien % 3==0  && vt[i].Cty=='B'){
			dem++;
		}
	}
	fprintf(f,"O to cua cong ty co bien kiem soat chia het cho 3 la:%d",dem);
}
void  SapXepTrongTai(VanTai *vt,int n,FILE *f=stdout){
	for(int  i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(vt[i].TrongTai >vt[j].TrongTai){
				VanTai tmp=vt[i]; vt[i]=vt[j] ;vt[j]=tmp;
			}
		}
	}
	fprintf(f,"\nThong tin ba xe co trong tai nho nhat  la  :\n");
	for (int i=0;i<3;i++){
		fprintf(f,"\nTen bien so : %d",vt[i].bien);
		fprintf(f,"\nTrong Tai : %f",vt[i].TrongTai);
		fprintf(f,"\nTen Cong Ty : %c",vt[i].Cty);
	}
}

int  main(){
	int n;
	VanTai *vt;
	char tentep[50]="VanTai.txt";
	DocFile(&vt,n,tentep);
	FILE *f=fopen("Ket_Qua_Van_Tai.txt","w");
	GhiTepTuFile(vt,n,f);
	DemOTo(vt,n,f);
	SapXepTrongTai(vt,n,f);
	return 0;
}