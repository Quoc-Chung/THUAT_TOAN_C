#include <stdio.h>
#include <math.h>
struct toado{
	float x;
	float y;
};
// day la vi du ddien hinh cua nhap nhieu diem va tinh diem in ra ,no chang khac gi mot mang ca ta truyen vao mot mang vd nhu 
// truyen vao :"struct toado td[]...."
// luc nhap thi cho "&td[i].biencannhap"
// luc in thi "td[i].biencanin"
// luc goi ham thi ta khai bao mot bien struct ve mang vi du : "struct toado td[100]"(chi cho phep nhap 100 toa do );
// chang khac gi dung mot mâng ca

void nhapdiem(struct toado td[],int n){
 for (int i=1;i<=n;i++){
 	printf("Nhap toa do diem thu %d :",i);
 	scanf("%f%f",&td[i].x,&td[i].y);
 }
}
void indiem(struct toado td[],int n){
	for (int i=1;i<=n;i++){
		printf("\nToa do diem thu %d la :",i);
	    printf("%.2f %.2f",td[i].x,td[i].y);
	}
}
// dem so diem nam trong duong tron tam la goc toa do co ban kinh la 7.5(ta lay ban kinh bang 5 cho de thu 
// phuong trinh duong tron la :x^2+y^2=R^2
int  demdiem(struct toado td[],int n){
	int dem=0;
	for (int i=1;i<=n;i++){
		if((td[i].x*td[i].x+td[i].y*td[i].y)==25)
			dem++;
	}
	return dem ;
}
int main (){
	int n;
	printf("Nhap so diem :");
	scanf("%d",&n);
	struct toado td[100];
	nhapdiem(td,n);
	indiem(td,n);
	printf("\nSo diem nam tren duong tron la :%d",demdiem(td,n));
	return 0;
}