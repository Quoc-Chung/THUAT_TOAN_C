

// Tìm diện tích hình chữ nhật nhỏ nhất, có các cạnh song song với hệ trục tọa độ nhỏ
//nhất, chứa tất cả các điểm.
#include <stdio.h>
#include <math.h>
struct diem{
 int h;
 int t;	

};
//Nhập, xuất vào một dãy có n điểm, thực hiện các yêu cầu sau:
void nhapdiem(struct diem d[],int n){
	for (int i=1;i<=n;i++){
		printf("Nhap diem thu %d:",i);
		scanf("%d %d",&d[i].h,&d[i].t);
	}
}
void indiem(struct diem d[],int n){
	printf("\nCac diem vua nhap la :\n ");
	for (int i=1;i<=n;i++){
		printf("%d %d\n",d[i].h,d[i].t);
	}
}
// Đếm số đoạn thẳng thuộc góc phần tư thứ 3.
void sodoanthanggoc3(struct diem d[],int n){
	int dem=0;
	for (int i=1;i<=n;i++){
		if(d[i].h*d[i].t<0){
			dem++;
		}
	}
	if(dem==0 || dem ==1){
		printf("\nKhong co doan thang nao o goc phan tu thu 3.");
	}
	if(dem>1){
		printf("\nSo doan thang trong goc phan tu thu 3 la :%d",dem);
	}
}
//Nhập bán kính R, đếm và in ra màn hình các điểm nằm ngoài đường tròn tâm O, bán 
//kính R.
void kiemtradiem(struct diem d[],int n,float r){
  int dem=0;
	for (int i=1;i<=n;i++ ){
	   if((1.0*sqrt (d[i].h*d[i].h+d[i].t*d[i].t))>r){
	   	  printf("%d %d\n",d[i].h,d[i].t);
		   dem ++;
	   }	
	}
	if(dem==0){
		printf("\nKhong co diem nao nam ngoai duong tron.");
		
	}
	if(dem>=1){
		printf("Vay co tong %d diem nam ngoai duong tron.",dem);
	}
}
 //Tìm diện tích hình chữ nhật nhỏ nhất, có các cạnh song song với hệ trục tọa độ nhỏ
//nhất, chứa tất cả các điểm.
void hinhchunhatmin(struct diem d[],int n){
     int  dai=0,rong=0;
     int minh=100,mint=100,maxh=0,maxt=0;
     if(n>=3){
	for (int i=1;i<=n;i++){
		if(minh>d[i].h){
			minh=d[i].h;
		}
		if(mint>d[i].t){
			mint=d[i].t;
		}
		if(maxh<d[i].h){
			maxh=d[i].h;
		}
		if(maxt<d[i].t){
			maxt=d[i].t;
		}
	}	
	// kiem tra dieu kien;
	//printf("\n min h:%d   mint: %d maxh:   %d maxt:   %d",minh,mint,maxh,maxt);
	dai=maxh-minh;
	rong=maxt-mint;
	int s=dai*rong;
	printf("\nDien tich hinh chu nhat thoa man la :%d",s);
}
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	struct diem d[100];
	nhapdiem(d,n);
    //float r;
	//printf("\nNhap ban kinh r:");
	//scanf("%f",&r);
	indiem(d,n);
	//sodoanthanggoc3(d,n);
	//printf("\nCac diem nam ngoai duong tron :\n");
	//kiemtradiem(d,n,r);
	 hinhchunhatmin(d,n);
	return 0;
}