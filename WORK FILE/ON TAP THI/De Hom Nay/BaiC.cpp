#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct thisinh{
	char hoten[60];
	float diem;
	char donvi[2];
};
void readfile(thisinh **ts, int *n, char *tentep){
	FILE *f;
	f=fopen(tentep,"r");
	if(f==NULL){
		printf("KHong mo duoc tep");
		exit(0);
	}
	fscanf(f,"%d",n);
	*ts=(thisinh*)malloc(*n * sizeof(thisinh));
	for(int i=0;i<*n;i++){
		fscanf(f," %[^\n]",(*ts)[i].hoten);
		fscanf(f,"%f",&(*ts)[i].diem);
		fscanf(f," %[^\n]",(*ts)[i].donvi);
	}
	printf("\nThong tin thi sinh la:\n");
	for(int i=0;i<*n;i++){
		printf("\nHoTen: %s --- SoDiem: %.2f--- Donvi: %s",(*ts)[i].hoten,(*ts)[i].diem,(*ts)[i].donvi);
	}
}
void tong(thisinh *ts, int n,FILE *f =stdout){
	float tong1=0 , tong2=0 , tong3=0;
	for(int i=0;i<n;i++){
		if(strcmp(ts[i].donvi,"A")==0){
			tong1+=ts[i].diem;
		}
		if(strcmp(ts[i].donvi,"B")==0){
			tong2+=ts[i].diem;
		}
		if(strcmp(ts[i].donvi,"C")==0){
			tong3+=ts[i].diem;
		}
	}
	fprintf(f,"\nTong diem cua don vi A B C lan luot la: %.2f  %.2f  %.2f",tong1,tong2,tong3);
	if(tong1>tong2 && tong1>tong3) fprintf(f,"\nDon vi 1 co tong diem lon nhat");
	if(tong2>tong1 && tong2>tong3) fprintf(f,"\nDon vi 2 co tong diem lon nhat");
	if(tong3>tong2 && tong3>tong1) fprintf(f,"\nDon vi 3 co tong diem lon nhat");
}

int main(){
	thisinh *ts;
	int n;
	char tentep[50]="BaiC.txt";
	FILE *f=fopen("2.1.kq.txt","w");
	readfile(&ts,&n,tentep);
	tong(ts,n,f);
//x		thisinhcao(ts,n,f);
}