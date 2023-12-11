#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct NhanVien{
	int  Ma;
	char HoTen[50];
	float HeSo;
	int Phong;
};
void DocFile(NhanVien **nv,int &n,char *tentep){
	FILE  *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc  file");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*nv)=(NhanVien *)malloc (n*sizeof(NhanVien));
	for (int i=0;i<n;i++){
	fscanf(f,"%d",&(*nv)[i].Ma);
	fscanf(f," %[^\n]",(*nv)[i].HoTen);
	fscanf(f,"%f",&(*nv)[i].HeSo);
	fscanf(f,"%d",&(*nv)[i].Phong);	
	}
	fclose(f);
}
void InFile(NhanVien *nv,int n){
	for  (int i=0;i<n;i++){
		printf("\nHo gia dinh thu %d:\n",i+1);
    printf("Ma Nhan Vien: %d -- Ho Ten: %s -- He So Luong: %.2f -- Phong: %d", nv[i].Ma, nv[i].HoTen, nv[i].HeSo, nv[i].Phong);

}
}
void LuongCoBan(NhanVien *nv,int n,int Luong){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(Luong*nv[i].HeSo <Luong*nv[j].HeSo){
				NhanVien tmp =nv[i];
				nv[i]=nv[j];
				nv[j]=tmp;
			}
		}
	}
	for  (int i=0;i<n;i++){
		printf("\nHo gia dinh thu %d:\n",i+1);
    	printf("Ma Nhan Vien :%d --Ho Ten :%s --He So Luong :%s --Phong :%d ",(nv)[i].Ma,(nv)[i].HoTen,nv[i].HeSo,nv[i].Phong);
	}
	
}

void LuongTheoPhongBan (NhanVien *nv,int n,int Luong){
	float p1=0,p2=0,p3=0;
	int dem1=0,dem2=0,dem3=0;
	for (int i=0;i<n;i++){
		if (nv[i].Phong == 1) {
            p1 += nv[i].HeSo * Luong;
            dem1++;
       }     
   else if (nv[i].Phong == 2) {
            p2 += nv[i].HeSo * Luong;
            dem2++;
       } 
  else {
    p3 += nv[i].HeSo * Luong;
    dem3++;
       }
   }
	float T1=p1/dem1,T2=p2/dem2,T3=p3/dem3;
	printf("\nLuong trung  binh phong  ban  thu nhat  la :%.2f",T1);
	printf("\nLuong trung  binh phong  ban  thu hai  la :%.2f",T2);
	printf("\nLuong trung  binh phong  ban  thu ba  la :%.2f",T3);
	
	if(T1 >T2 && T1>T3){
		printf("\n Phong  1 co luong trung  binh cao nhat .");
	}
	else if(T2 >T3 && T2 >T1){
		printf("\nPhong  2  co luong trung  binh  cao nhat ");
	}
	else {
		printf("\nPhong 3  co luong trung  binh cao nhat");
	}
}
void TimKiemNhanVien (NhanVien *nv ,int n,  FILE  *f=stdout){
	char HoTen[50];
	int Phong;

	printf("\nNhap Ten Phong :");
	scanf("%d",&Phong);
	printf("\nNhap Ten Nhan Vien :");
	fflush(stdin);
	gets(HoTen);
    int dem=0;
for (int i = 0; i < n; i++) {
    if (strcmp(nv[i].HoTen, HoTen) == 0 && nv[i].Phong == Phong) {
        
      printf("Ma Nhan Vien: %d -- Ho Ten: %s -- He So Luong: %.2f -- Phong: %d\n", nv[i].Ma, nv[i].HoTen, nv[i].HeSo, nv[i].Phong);  
       
     fprintf(f, "Ma Nhan Vien: %d -- Ho Ten: %s -- He So Luong: %.2f -- Phong: %d\n", nv[i].Ma, nv[i].HoTen, nv[i].HeSo, nv[i].Phong);
        
        dem=1;
        break;
    }
}
if (dem==0) {
    printf("Khong The Tim Thay Nhan Vien.\n");
  }
}
int  main (){
	int n;
	NhanVien *nv;
	char tentep[50]="input1.txt";
	DocFile(&nv,n,tentep);
	InFile(nv,n);
	int  Luong;
	printf("\nNhap luong  co  ban :");
	scanf("%d",&Luong);
	LuongTheoPhongBan (nv,n,Luong);
	FILE  *f=fopen("kqNhanVien.txt","w");
	if(f==NULL){
		printf("\nKhong the  mo duoc file .");
		exit(0);
	}
	TimKiemNhanVien (nv,n,f);
}
