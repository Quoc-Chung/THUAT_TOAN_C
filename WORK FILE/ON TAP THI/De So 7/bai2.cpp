#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct  SinhVien{
	char  HoTen[50];
	float  diem;
	char Truong[2];
};
void DocFile(SinhVien **sv,int &n,char  *tentep ,FILE *f1=stdout){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*sv)=(SinhVien *) malloc (n*sizeof(SinhVien));
	for(int i=0;i<n;i++){
		fscanf(f," %[^\n]",(*sv)[i].HoTen);
		fscanf(f,"%f",&(*sv)[i].diem);
		fscanf(f," %[^\n]",(*sv)[i].Truong);
	}
	fprintf(f1,"\nDanh  sach  sinh  vien la :\n");
	for  (int i=0;i<n;i++){
		fprintf(f1," \n Ho Ten :%s   Diem: %.2f   Truong :%s",(*sv)[i].HoTen,(*sv)[i].diem,(*sv)[i].Truong);
	}
}
void TongDiem (SinhVien *sv ,int n, FILE *f=stdout){
	int dem1=0,dem2=0,dem3=0;
	float tong1=0,tong2=0,tong3=0;
	for  (int i=0;i<n;i++){
	   if(strcmp(sv[i].Truong,"A")==0){
	   	tong1+=sv[i].diem;dem1++;
	   }
	   else  if(strcmp(sv[i].Truong,"B")==0){
	   	tong2+=sv[i].diem;dem2++;
	   }	
	   else{
	   	tong3+=sv[i].diem;dem3++;
	   }
	}
	float DiemA =tong1/dem1,DiemB =tong2/dem2,DiemC =tong3/dem3;
	fprintf(f,"\nDiem  truong A :%.2f \nDiem  truong B :%.2f  \nDiem Truong C :%.2f",DiemA,DiemB,DiemC);
	if(DiemA <DiemB && DiemA <DiemC){
		 fprintf(f,"Truong  A  co diem  thap nhat");
	}
	else if(DiemB <DiemA && DiemB < DiemC){
		fprintf(f,"\nTruong B  co  diem  thap nhat.");
	}
	else{
		fprintf(f,"\nTruong  C  co  diem  thap nhat .");
	}
}
void DiemCaoNhat(SinhVien *sv,int n,FILE *f=stdout){
	for  (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(sv[i].diem > sv[j].diem){
				SinhVien tmp =sv[i];
				sv[i]=sv[j];
				sv[j]=tmp;
			}
		}
	}
	fprintf(f,"Ba thi  sinh co  diem  cao nhat  la  :\n");
	for(int i=0;i<3;i++){
		fprintf(f,"\n%s --- Diem:%.2f ---Truong :%s",sv[i].HoTen,sv[i].diem,sv[i].Truong);
	}
}
int  main (){
	int n;
	SinhVien *sv;
	char tentep[50]="input.txt";
		FILE *f=fopen("output.txt","w");
	if(f==NULL){
		printf("\nKhong the mo duoc  file .");
		exit(0);
	}
	DocFile(&sv,n,tentep,f);
	TongDiem (sv,n,f);
	DiemCaoNhat(sv,n,f);

}