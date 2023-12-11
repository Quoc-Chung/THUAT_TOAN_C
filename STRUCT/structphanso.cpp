#include <stdio.h>
#include <math.h>
struct Phanso{
int tuso;
int mauso;
};
int  UCLN (int a,int b){
	a=abs(a);
	b=abs(b);
	if(b==0){
		return a;
	}
	return UCLN(b,a%b);
}
void rutGon( struct PhanSo *ps){// truyen vao mot bien con tro de tro de tro toi gia tri cua tu so va phan so 
	// Tim USCLN
	int a = ps->tuSo;
	int b = ps->mauSo;
	a = abs(a);
	b = abs(b);
	int c=UCLN(a,b);
	ps->tuSo/=UCLN;
	ps->mauSo/=UCLN;
}

void nhapPhanSo(PhanSo *ps){// truyen con tro thi dung dia chi con tro 
	printf("\nNhap vao tu so: ");
	scanf("%d", &ps->tuSo);
	do{
		printf("\nNhap vao mau so: ");
		scanf("%d", &ps->mauSo);
	}while(ps->mauSo==0);
}

void inPhanSo(PhanSo ps){
	if(ps.mauSo<0){
		ps.tuSo*=-1;
		ps.mauSo*=-1;
	}
	rutGon(&ps);
	if(ps.mauSo==1){
		printf("%d",ps.tuSo);
	}else{
		printf("%d/%d", ps.tuSo, ps.mauSo);
	}

}

PhanSo congHaiPhanSo(PhanSo ps1, PhanSo ps2){
	PhanSo ketQua;
	// a/b + c/d => (a*d + c*b)/(b*d)
	ketQua.tuSo = ps1.tuSo*ps2.mauSo + ps2.tuSo*ps1.mauSo;
	ketQua.mauSo = ps1.mauSo*ps2.mauSo;
	return ketQua;
}

PhanSo truHaiPhanSo(PhanSo ps1, PhanSo ps2){
	PhanSo ketQua;
	// a/b + c/d => (a*d - c*b)/(b*d)
	ketQua.tuSo = ps1.tuSo*ps2.mauSo - ps2.tuSo*ps1.mauSo;
	ketQua.mauSo = ps1.mauSo*ps2.mauSo;
	return ketQua;
}

PhanSo nhanHaiPhanSo(PhanSo ps1, PhanSo ps2){
	PhanSo ketQua;
	// a/b + c/d => (a*c)/(b*d)
	ketQua.tuSo = ps1.tuSo*ps2.tuSo;
	ketQua.mauSo = ps1.mauSo*ps2.mauSo;
	return ketQua;
}

PhanSo chiaHaiPhanSo(PhanSo ps1, PhanSo ps2){
	PhanSo ketQua;
	// a/b + c/d => (a*d)/(b*c)
	ketQua.tuSo = ps1.tuSo*ps2.mauSo;
	ketQua.mauSo = ps1.mauSo*ps2.tuSo;
	return ketQua;
}

int main(){
 Phanso ps1,ps2;//co hai phan so 1 va 2
printf("Nhap vao phan so thu nhat :\n");
nhapPhanso(&ps1);
printf("\nNhap vap phan so thu hai :\n");
nhapPhanso(&ps2);
printf("\nPhan so vua nhap thu nhat la: ");
inPhanso(ps1);
printf("\nPhan so vua nhap thu hai la: ");
inPhanso(ps2);
printf("\nCong phep tinh: \n");
	inPhanSo(ps1); printf("+"); inPhanSo(ps2);
	 printf("="); inPhanSo(congHaiPhanSo(ps1, ps2));	
	   printf("\n");
	inPhanSo(ps1); printf("-"); inPhanSo(ps2); 
    	printf("="); inPhanSo(truHaiPhanSo(ps1, ps2));
	    printf("\n");	
	inPhanSo(ps1); printf("*"); inPhanSo(ps2);
	   printf("="); inPhanSo(nhanHaiPhanSo(ps1, ps2));	
	printf("\n");
	inPhanSo(ps1); printf(":"); inPhanSo(ps2); 
	printf("="); inPhanSo(chiaHaiPhanSo(ps1, ps2));	
}