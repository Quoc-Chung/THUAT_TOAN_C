#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct ThiSinh{
	char HoTen[50];
	float SoDiem;
	char Truong[2];
};
void DocFile(ThiSinh **sv,int &n, char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*sv)=(ThiSinh *)malloc (n*sizeof(ThiSinh));
	for(int i=0;i<n;i++){
		fscanf(f," %[^\n]",(*sv)[i].HoTen);
		fscanf(f,"%f",&(*sv)[i].SoDiem);
		fscanf(f," %[^\n]",(*sv)[i].Truong);
	}
}
// Ham chi ghi  thong  tin vao  tep 
void GhiThongTin (ThiSinh *sv,int n,FILE *f=stdout){
	fprintf(f,"\nThong tin thi  sinh la :\n");
	for (int i=0;i<n;i++){
		fprintf(f,"\nHo ten :%s -- So Diem :%.2f --Truong :%s",sv[i].HoTen,sv[i].SoDiem,sv[i].Truong);
	}	
} 

void  TongDiem(ThiSinh *sv,int n,FILE *f=stdout){
	int dem1=0,dem2=0,dem3=0;
	float tong1=0,tong2=0,tong3=0;
	for(int i=0;i<n;i++){
		if(strcmp(sv[i].Truong,"A")==0){
			tong1+=sv[i].SoDiem;
			dem1++;
		}
    	else if(strcmp(sv[i].Truong,"B")==0){
			tong2+=sv[i].SoDiem;
			dem2++;
		}
		else{
			tong3+=sv[i].SoDiem;
			dem3++;
		}
	}
	float tb1=tong1/dem1,tb2=tong2/dem2,tb3=tong3/dem3;
	fprintf(f,"\nTong diem cua truong  A  la  :%.2f",tb1);
	fprintf(f,"\nTong diem cua truong  B la  :%.2f",tb2);
	fprintf(f,"\nTong diem cua truong  C  la  :%.2f",tb3);
	if(tb1 <tb2 &&tb1 <tb3){
		fprintf(f,"\nTruong A  co diem trung  binh thap nhat  .");
	}
	else if(tb2<tb1 &&tb2 <tb3){
		fprintf(f,"\nTruong B co diem  tb thap nhat.");
	}
	else{
		fprintf(f,"\nTruong C co diem trung  binh  thap nhat .");
	}
}
void  ThiSinhDiemCao(ThiSinh *sv,int n,FILE *f=stdout){
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(sv[i].SoDiem >sv[j].SoDiem){
				ThiSinh tmp =sv[i];
				sv[i]=sv[j];
				sv[j]=tmp;
			}
		}
	}
	fprintf(f,"\nThong tin  3 sinh  vien diem cao nhat :\n");
	for (int i=0;i<3;i++){
			fprintf(f,"\nHo ten :%s -- So Diem :%.2f --Truong :%s",(sv)[i].HoTen,(sv)[i].SoDiem,(sv)[i].Truong);
	}
}
int main(){
	int n;
	ThiSinh *sv;
	char tentep[50]="ts.txt";
	FILE *f=fopen("kqThiSinh.txt","w");
	DocFile(&sv,n,tentep);
	GhiThongTin (sv,n,f);
	TongDiem(sv,n,f);
	ThiSinhDiemCao(sv,n,f);
	
}