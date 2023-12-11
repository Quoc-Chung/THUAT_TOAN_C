#include <stdio.h>
#include <math.h>
// nhap phan so thi co the truyen con tro 
// cu muon lam thay doi mot ket qua gi do ma muon su thay doi duoc truyen ra khoi ham thi
struct phanso{
	int tu;
	int mau;
};
void nhap( struct phanso *ps){ //truyen con tro de nhap 
	printf("\nNhap tu so :");
	scanf("%d",&ps->tu);
	do {
		printf("\nNhap mau so :");
		scanf("%d",&ps->mau);
		if(ps->mau==0){
			printf("\nVui long nhap lai.");
		}
	}while(ps->mau==0);
}
// giai thich ham uoc chungg
// vi du 4 12==>4 la ket qua 
// thay a<b nen b=12-4=8 
// a<b tiep nen b= 8-4 =4 in ra so a
void rutgon ( struct phanso *ps){
	int a=ps->tu;
	int b=ps->mau;
	int ucln=1;
	if(a==0 || b==0){
		ucln=a+b;
	}
	else {
	while (a!=b){
		if(a>b){
			a=a-b;
		}
		else {
			b=b-a;
		}
	}
	ucln=a;
}
	a/=ucln;// ps->tu/=ucln;
	b/=ucln;// ps->mau/=ucln;

}
void doidau(struct phanso *ps){
	if(ps->mau<0){
		ps->tu*=-1;
		ps->mau*=-1;
	}
}
void in( struct phanso ps){// luu ý khi goi hàm struct con tr?
        doidau( &ps);
		rutgon(&ps);
		printf("%d/%d",ps.tu,ps.mau);
}
phanso congphanso( struct phanso ps1, struct phanso ps2){
	phanso ketqua;
	// a/b+c/d =>> quy dong mau
	ketqua.tu=ps1.tu*ps2.mau+ps2.tu*ps1.mau;
	ketqua.mau=ps1.mau *ps2.mau;
   return ketqua;
}
int main (){
	struct phanso ps1,ps2;
	nhap(&ps1);
	printf("\nPhan so thu nhat :");
	in(ps1);
	nhap(&ps2);
	printf("\nPhan so thu hai:");
	in(ps2);
	printf("\n");
 in(ps1); printf("+"); in(ps2); printf("=");in(congphanso(ps1,ps2));
	return 0;
	
}