#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
//#include <algorithm.>
struct PhanSo{
	int tu;
	int mau;
};
void DocFile(PhanSo **p,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the mo duoc file .");
		exit(0);
	}
	// cap phat dong
	fscanf(f,"%d",&n);
	(*p)=(PhanSo*) malloc(n*sizeof(PhanSo)); 
	for (int i=0;i<n;i++){
	  	fscanf(f,"%d%d",&(*p)[i].tu,&(*p)[i].mau);
	}
	printf("\nCac  phan so vua doc  la :\n");
	for(int i=0;i<n;i++){
		printf("\n%d / %d",(*p)[i].tu,(*p)[i].mau);
	}
}
void PhanSoMax(PhanSo *p, int n) {
    float max = 0.0;
    int tu = 0, mau = 0;  
    for (int i = 0; i < n; i++) {
        float giaTri = (float)p[i].tu / p[i].mau;
        if (max <giaTri) {
            max = giaTri;
            tu = p[i].tu;
            mau = p[i].mau;
        }
    }
    printf("\nPhan so lon nhat la: %d / %d", tu, mau);
}
int ucln(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return ucln(b, a % b);
    }
}
// rút gọn các  phân số  nếu mẫu âm  thì chuyển phân số lên tử 
void RutGonPhanSo(PhanSo *p, int n,FILE *f=stdout) {
    for (int i = 0;i<n;i++) {
        int gcd = abs(ucln(p[i].tu, p[i].mau)); // Tìm ước chung  lớn nhat cua hia  là  hàm có sẵn  trong thư viện stdlib.h
        p[i].tu /= gcd; // Rút gọn tử
        p[i].mau /= gcd; // Rút gọn mẫu
        if (p[i].mau < 0) { // Nếu mẫu âm, chuyển phân số lên tử và đổi dấu mẫu
            p[i].tu *= -1;
            p[i].mau *= -1;
        }
    }
    fprintf(f,"\nCac phan so sau khi  rut gon la :\n");
    for (int i=0;i<n;i++){
    	fprintf(f,"\n%d / %d",p[i].tu,p[i].mau);
	}
}
void TinhGiaTriPhanSoTong(PhanSo *p, int n) {
    PhanSo tong = {0, 1}; // Khởi tạo phân số tổng ban đầu
    for (int i = 0; i < n; i++) {
        // quy  đồng mẫu 
        int tuMoi = tong.tu * p[i].mau + p[i].tu * tong.mau;
        int mauMoi = tong.mau * p[i].mau;
        // Rút gọn phân số tổng (nếu cần)
        int gcd = abs(ucln(tuMoi, mauMoi));
        tuMoi /= gcd;
        mauMoi /= gcd;
        // Cập nhật giá trị phân số tổng
        tong.tu = tuMoi;
        tong.mau = mauMoi;
    }
    printf("\nTong cac  phan so  la  :%d / %d ",tong.tu,tong.mau);
}
int main(){
	int n;
	PhanSo *p;
	char tentep[50]="phanso.txt";
	DocFile(&p,n,tentep);
	PhanSoMax(p,n);
	FILE *f=fopen("psrutgon.txt","w");
	RutGonPhanSo(p,n,f);
	TinhGiaTriPhanSoTong(p,n);
	return 0;
}

