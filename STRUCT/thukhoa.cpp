#include <stdio.h>
#include <math.h>
#include <string.h>
struct ngaysinh {
	int ngay;
	int thang ;
	int nam ;
};
struct diem {
	float mon1;
	float mon2;
	float mon3;      
};
struct thukhoa{
	int sbd;
	char ten[30];
    ngaysinh date;// định nghĩa kiểu dữ liệu ngày sinh 
    diem d;// định nghĩa kiểu dữ liệu điểm  
};
void nhap(thukhoa tk[],int n){
	for (int i=1;i<=n;i++){
		tk[i].sbd=i;
		fflush(stdin);
		fgets(tk[i].ten,sizeof(tk[i].ten),stdin);
		scanf("%d%d%d",&tk[i].date.ngay,&tk[i].date.thang,&tk[i].date.nam);
		scanf("%d%d%d",&tk[i].d.mon1,&tk[i].d.mon2,&tk[i].d.mon3);
	}
}
float tongdiem (float a,float b,float c){
	 float tong=a+b+c;
	return tong;
}
void information(thukhoa tk[],int n){
	thukhoa tam;
	for  (int i=1;i<=n;i++){
		for (int j=0;j<=n;j++){
			if(tongdiem(tk[i].d.mon1,tk[i].d.mon2,tk[i].d.mon3)
			<tongdiem (tk[j].d.mon1,tk[j].d.mon2,tk[j].d.mon3)){
				tam =tk[i];
				tk[i]=tk[j];
				tk[j]=tam;
			}
		}
	}
	for (int i=1;i<=n;i++){
		printf("\n%d %s %.1f",tk[i].sbd,tk[i].ten,tongdiem(tk[i].d.mon1,tk[i].d.mon2,tk[i].d.mon3));
	}
}
int main (){
	int n;
	scanf("%d",&n);
	thukhoa tk[100];
	nhap(tk,n);
	information(tk,n);
	return 0;
}