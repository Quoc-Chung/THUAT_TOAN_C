#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//  mot  mang la  n  so  m^3  nước tiêu thụ  trong  n thang
void  DocFile(int  **a,int &n ,char *tentep){
	FILE *f=fopen (tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
   (*a)=(int * )malloc  (n*sizeof(int));
	for (int i=0;i<n;i++){
		fscanf(f,"%d",&(*a)[i]);
	}
	fclose(f);
	printf("\nThong tin  tien  dien la :\n");
	for(int i=0;i<n;i++){
		printf("%d ",(*a)[i]);
	}
}
void TongTien(int *a,int n){
	int TongNuoc=0;
	for (int i=0;i<n;i++){
		TongNuoc+=a[i];
	}
	int Tien=0;
	if(TongNuoc <=10){
		Tien =7000*TongNuoc;
	}
	else if(TongNuoc >10 && TongNuoc <=20){
		Tien =7000 *10 +(TongNuoc-10) *8200;
	}
	else if(TongNuoc>20 && TongNuoc <=30){
		Tien=7000*10 +8200*10 +10000*(TongNuoc -20);
	}
	else {
		Tien=7000*10 +8200*10+10000*10+18000*(TongNuoc-30);
	}
	
	printf("\nTien Nuoc cua  ho  gia dinh  la %d:",Tien);	
}
void Check (int *a,int  n){
	bool check=true;
	for (int i=0;i<n-1;i++){
		if(a[i]<a[i+1]){
			check=false;
			break;
		}
	}
	if(check){
		printf("\nGia  dinh ngay  cang dung it  nuoc");
	}
	else {
		printf("\nGia  dinh khong  ngay  cang dung  it  nuoc  ");
}
}
int  main (){
	int n ;
	int  *a;
	char tentep[50]="De1.txt";
	DocFile(&a,n,tentep);
	TongTien(a,n);
	Check(a,n);
	return 0;
}
