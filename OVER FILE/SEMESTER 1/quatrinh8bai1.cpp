
#include <stdio.h>
#include <math.h>
// struct hoanh va tung
struct toado{
	int h;
	int t;
};
// dem so diem nam trong duong tron tam 0 ban kinh r:hoanh *hoanh +tung *tung <r*r thi tang bien dem ;
void nhaptoado(struct toado d[],int n){
	for (int i=1;i<=n;i++){
		printf("Nhap toa do diem thu %d:",i);
		scanf("%d%d",&d[i].h,&d[i].t);
	}
}
void intoado(struct toado d[],int n){
	printf("\nToa do vua nhap la:\n");
	for (int i=1;i<=n;i++){
		printf("%d %d\n",d[i].h,d[i].t);
	}
}

// dem so doan thang cat truc hoanh
void demcathoanh (struct toado d[],int n){
	int dem1=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if(d[i].t*d[j].t<0){
				dem1++;
			}
		}
	}
	printf("\nSo doan thang cat truc hoanh la :%d",dem1);
}
// Đếm số điểm nằm phía trên đường phân giác của góc phần tư thứ nhất và in kết quả
//ra màn hình.
void dem(struct toado d[],int n){
	int dem=0;
	for (int i=1;i<=n;i++){
		if((d[i].h>0 )&&(d[i].t>=0)&& (d[i].h== d[i].t)){
			dem++;
		}
	}
	printf("\nSo diem thoa man la :%d",dem);
}
// Tìm diện tích hình chữ nhật nhỏ nhất có 4 cạnh của chiều dài và chiều rộng song 
//song với trục tọa độ chứa tất cả các điểm

int main (){
	int n;
    printf("Nhap n:");
    scanf("%d",&n);
    struct toado d[100];
    nhaptoado(d,n);
   // intoado(d,n);
   //dem(d,n);
   demcathoanh(d,n);
    return 0;
}
