#include <stdio.h>
#include <math.h>

struct connguoi {
	char ten[10];
	int tuoi;
	float chieucao ;
	float vong_mot;
};
void nhapbonhi (connguoi *bonhi){
	// có thể viết (*bonhi). cũng được 
	printf("\nNhap ten :");
	fflush(stdin);
	fgets(bonhi->ten,sizeof(bonhi->ten),stdin);
	printf("\nNhap tuoi cua bo :");
	scanf("%d",&bonhi->tuoi);
	printf("\nNhap chieu cao :");
	scanf("%f",&bonhi->chieucao);
	printf("\nNhap vong mot :");
	scanf("%f",&bonhi->vong_mot);
}
void inbonhi(connguoi bonhi){
	printf("\nTen cua bo:");printf("%s",bonhi.ten);
	printf("\nTuoi :");printf("%d",bonhi.tuoi);
	printf("\nChieu cao :");printf("%.2f",bonhi.chieucao);
	printf("\nVong mot :");printf("%.2f",bonhi.vong_mot);
}
void nhapnhieubo(connguoi bo[],int n){
	for (int i=1;i<=n;i++){
		printf("\nNhap bo nhi thu %d:\n",i);
	nhapbonhi(&bo[i]);	// truyen dia chi cua ham mang kieu cau truc :&bo[i];
	}
}
void innhieubo(connguoi bo[],int &n){
	for (int i=1;i<=n;i++){
		printf("\nBo thu %d:\n",i);
		inbonhi(bo[i]);// truyền luôn mảng vào :bo[i] 
	}
}
// them danh sach bo vao n[n+1]
void themmotconbovaocuoi(connguoi bo[],int &n){
	printf("\nNhap sinh vien moi can them vao :");
	nhapbonhi(&bo[n+1]);
	n++;
}
void themmotconbobatki(connguoi bo[],int &n,int vitrithem){
	for (int i=n+1;i>=vitrithem+1;i--){
		bo[i]=bo[i-1];// cac côn bo se dich chuyen lui mot o 
	}
    n++;
    nhapbonhi(&bo[vitrithem]);
} 
void xoamotvitribatki(connguoi bo[],int &n,int vitrixoa){
	for (int i=vitrixoa;i<=n-1;i++){
		bo[i]=bo[i+1];
	}
	n--;
}
int main (){
	int n;
	int vitri;
	int vitrixoa;
	printf("Nhap so con bo :");
	scanf("%d",&n);
    connguoi bonhi[100];
    nhapnhieubo(bonhi,n);
   //	printf("\nNhap vi tri them:");scanf("%d",&vitri);
   printf("\nNhap vi tri xoa:");scanf("%d",&vitrixoa);
  // innhieubo(bonhi,n);
//themmotconbovaocuoi(bonhi,n);
//themmotconbobatki(bonhi,n,vitri);
xoamotvitribatki(bonhi,n,vitrixoa);
   innhieubo(bonhi,n);
   return 0;
	
}