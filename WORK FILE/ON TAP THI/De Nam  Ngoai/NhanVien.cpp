#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct  NhanVien{
	int Ma;
	char HoTen[50];
	int HeSoLuong;
	int Phong;
};
void DocFile(NhanVien **nv,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*nv)=(NhanVien *) malloc (n*sizeof(NhanVien));
	for(int i=0;i<n;i++){
		fscanf(f,"%d",&(*nv)[i].Ma);
		fscanf(f," %[^\n]",(*nv)[i].HoTen);
		fscanf(f,"%d",&(*nv)[i].HeSoLuong);
		fscanf(f,"%d",&(*nv)[i].Phong);
	}
}

void HeSoLuong(NhanVien *nv,int n,int  luong){
   for (int  i=0;i<n;i++){
   	for  (int j =0;j<n;j++){
   		if(luong * nv[i].HeSoLuong <luong *nv[j].HeSoLuong){
   			NhanVien tmp=nv[i];
   			nv[i]=nv[j];
   			nv[j]=tmp;
		   }
	   }
   }
   printf("\nTHong tin nhan vien  giam dan  theo luong  :\n");
   for  (int i=0;i<n;i++){
	printf("\nMa :%d -- Ho Ten :%s -- He So Luong :%d --- Phong  :%d ",nv[i].Ma,nv[i].HoTen,nv[i].HeSoLuong,nv[i].Phong);	
	}	
}
void  LuongTrungBinh (NhanVien *nv,int  n,int  luong){
	int t1=0,t2=0,t3=0;
	int dem1=0,dem2=0,dem3=0;
	for  (int i=0;i<n;i++){
		if(nv[i].Phong==1){
			t1+=luong*nv[i].HeSoLuong;
			dem1++;
		}
	else	if(nv[i].Phong==2){
			t2+=luong*nv[i].HeSoLuong;
			dem2++;
		}
	else{
			t3+=luong*nv[i].HeSoLuong;
			dem3++;
		}
	}
	float tb1=0,tb2=0,tb3=0;
	if(dem1>0){
		 tb1= (float)t1/dem1;
	}
	if(dem2>0){
	
		 tb2= (float)t2/dem2;
	}
	if(dem3>0){
		 tb3= (float)t3/dem3;
	}
	
	
	if(tb1 >tb2 && tb1 >tb3){
		printf("\nPhong 1 cao nhat ");
	}
	else if(tb2>tb1 && tb2 >tb3){
		printf("\nPhong 2 cao nhat ");
	}
	else {
		printf("\nPhong 3 cao nhat ");
	}
}
void TimNhanVien(NhanVien* nv, int n, FILE* f = stdout) {
    int Phong;
    printf("\nNhap phong  :");
    scanf("%d",&Phong);
    char Ten[50];
    printf("\nNhap Ten :");
    fflush(stdin);
    gets(Ten);
    bool check = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(nv[i].HoTen, Ten) == 0 && Phong == nv[i].Phong) {
            fprintf(f, "Tìm Thấy:\n");
            fprintf(f, "Mã: %d -- Họ Tên: %s -- Hệ Số Lương: %d -- Phòng: %d\n", nv[i].Ma, nv[i].HoTen, nv[i].HeSoLuong, nv[i].Phong);
            check = true;
            break;
        }
    }
    if (!check) {
        printf("Không tìm thấy.\n");
    }
}
int  main (){
	int n;
	NhanVien *nv;
	char tentep[50]="input1.txt";
	printf("\nNhap Luong Co ban:");
	int luong;
	scanf("%d",&luong);
	DocFile (&nv,n,tentep);
	HeSoLuong(nv,n,luong);
	LuongTrungBinh (nv,n,luong);
	FILE *f=fopen("kqNhanVien.txt","w");
	TimNhanVien (nv,n,f);
	return 0;
}

