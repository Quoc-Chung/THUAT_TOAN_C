#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct  ThiSinh{
	char HoTen[50];
	float Diem;
	char Truong[2];
};
void DocFile(ThiSinh **sv,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file .");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*sv)= (ThiSinh *) malloc  (n*sizeof(ThiSinh));
	for(int i=0;i<n;i++){
		fscanf(f," %[^\n]",(*sv)[i].HoTen);
		fscanf(f,"%f",&(*sv)[i].Diem);
		fscanf(f," %[^\n]",(*sv)[i].Truong);
	}
}
void  TongDiem(ThiSinh *sv,int n){
	int dem1=0,dem2=0,dem3=0;
	float tong1=0,tong2=0,tong3=0;
	for(int i=0;i<n;i++){
		if(strcmp(sv[i].Truong,"A")==0){
			tong1+=sv[i].Diem;
			dem1++;
		}
    	else if(strcmp(sv[i].Truong,"B")==0){
			tong2+=sv[i].Diem;
			dem2++;
		}
		else{
			tong3+=sv[i].Diem;
			dem3++;
		}
	}
	float tb1=tong1/dem1,tb2=tong2/dem2,tb3=tong3/dem3;
	printf("\nTong diem cua truong  A  la  :%.2f",tb1);
	printf("\nTong diem cua truong  B la  :%.2f",tb2);
	printf("\nTong diem cua truong  C  la  :%.2f",tb3);
	if(tb1 <tb2 &&tb1 <tb3){
		printf("\nTruong A  co diem trung  binh thap nhat  .");
	}
	else if(tb2<tb1 &&tb2 <tb3){
		printf("\nTruong B co diem  tb thap nhat.");
	}
	else{
		printf("\nTruong C co diem trung  binh  thap nhat .");
	}
}
void  NhapHo (ThiSinh *sv,int n){
	float tong=0;
	int dem=0;
	char ho[30];
	printf("\nNhap Ho:");
	gets(ho);
	for (int i=0;i<n;i++){
	  if(strncmp(ho,sv[i].HoTen,strlen(ho))==0){
	  	tong+=sv[i].Diem;dem++;
	  }
	}
	if(dem>0){
		float tb= tong/dem;
		printf("\nDiem Trung binh  cua cac thi sinh mang  ho %s la:%.2f",ho,tb);
	}
}
int main (){
	int n;
	ThiSinh *sv;
	char tentep[50]="thisinh.txt";
	DocFile(&sv,n,tentep);
	TongDiem(sv,n);
	NhapHo(sv,n);
	return 0;
}