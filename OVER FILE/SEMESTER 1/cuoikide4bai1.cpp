#include <stdio.h>
#include <math.h>
struct toado {
	int h;
	int t;
};
void nhap(toado d[],int n){
	for (int i=1;i<=n;i++){
		printf("\nDiem %d:",i);
		scanf("%d%d",&d[i].h,&d[i].t);
	}
}
void in(toado d[],int n){
	printf("\n\t\t\tTOA DO CAC DIEM:\n");
	for (int i=1;i<=n;i++){
		printf("\nToa do %d:%d %d",i,d[i].h,d[i].t);
	}
}
void duongtron (toado d[],int n){
	int dem=0;
	for (int i=1;i<=n;i++){
		if(d[i].h*d[i].h+d[i].t*d[i].t<25){
			dem++;
		}
	}
	printf("\nSo diem nam trong duong tron :%d",dem);
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	struct toado d[100];
	nhap(d,n);
	in(d,n);
	duongtron(d,n);
	return 0;
}