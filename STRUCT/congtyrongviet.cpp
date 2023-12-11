#include <stdio.h> 
#include <string.h>
#include <math.h> 
#include <ctype.h>
#include <stdlib.h>
char ten1[30]="Hanh chinh";
char ten2[30]="Truong phong";
char ten3[30]="Tiep thi";
void xoaxuongdong(char c[]){
	size_t len =strlen(c);
	if(c[len-1]=='\n'){
		c[len-1]='\0';
	}
}
struct nhanvien {
	char ten[30];
	int maNV;
	char chucvu[30];
	int hanghoa;
	float luong;
};
void nhap (nhanvien *nv){
	printf("\nNhap ten nhan vien :");
	fflush(stdin);
	fgets(nv->ten,sizeof(nv->ten),stdin);
	printf("\nNhap ma nhan vien :");
	scanf("%d",&nv->maNV);
	printf("\nNhap chuc vu:");
	fflush(stdin);
	fgets(nv->chucvu,sizeof(nv->chucvu),stdin);
	if(stricmp(ten3,nv->chucvu)==0){
		printf("\nNhap so hang ban duoc:");
		scanf("%d",&nv->hanghoa);
	}
	printf("\nNhap tien luong:");
	scanf("%f",&nv->luong);
}
void  tinhtienluong(nhanvien nv[],int n){
	// truong phong co luong  bang luong hang thaang +5% *luong cua tong nhan vien cong ty 
	// nhan vien hanh chinh thi chi co luong thang 
	// tiep thi thi bang 1/2 so luong cua  thang cua cong nhan +75 so tien ban hang hoa(biet mot hang hoa gia 3 trieu
	//-->in ra bang ten nhan vien va luong cua nhan vien do 
}
void inputarray(nhanvien nv[],int n){
     for(int i=1;i<=n;i++){
     	printf("\nNhap Nhan vien %d:\n",i);
     	nhap((nv+i));
	 }
}
void output(nhanvien nv[],int n){
	printf("\n\t\t\tBANG THONG TIN \n");
    printf("\n%-20s %-8s %-20s %-10s\n","Ho va ten","Ma NV","Chuc vu","Tien luong");
    // bên trên dạng bang se đều in ra kí tự dạng chuỗi căn chỉnh lệch bên trái một so X
    for (int i=1;i<=n;i++){
 	xoaxuongdong(nv[i].ten);
 	xoaxuongdong(nv[i].chucvu);
 		char ten[30];
 	// bên duoi se in ra ket qua theo kieu dữ liệu của kết quả nhưng vẫn căn chỉnh lệch trái tương ứng phía trên
	printf("\n%-20s %-8d %-20s %-10.0f\n",nv[i].ten,nv[i].maNV,nv[i].chucvu,nv[i].luong); 	
 }	
}
int main(){
	int n;
	do {
		printf("\nNhap so nhan vien :");
		scanf("%d",&n);
        if(n<1){
        	printf("\nVui long nhap lai.");
		}
	}while (n<1);
	nhanvien nv[100];
	inputarray(nv,n);
	
}














