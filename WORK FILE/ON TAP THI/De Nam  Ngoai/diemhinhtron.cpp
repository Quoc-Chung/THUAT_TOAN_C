#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct Diem{
	int h;
	int t;
};
void DocFile(Diem **d,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the mo duoc file .");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*d)=(Diem *) malloc(n*sizeof(Diem));
	for(int i=0;i<n;i++){
		fscanf(f,"%d%d",&(*d)[i].h,&(*d)[i].t);
	}
	printf("\nDiem duoc doc ra tu  file  la :\n");
	for(int i=0;i<n;i++){
		printf("\n%d %d ",(*d)[i].h,(*d)[i].t);
	}
}
//xac dinh do dai duong gap khuc di qua hai diem (1,2,...n) va (2 3 ...n)
void dodaigapkhuc(Diem *d,int n){
	float tong =0;
	for (int i=1;i<n;i++){
		tong+= sqrt(pow(d[i+1].h-d[i].h,2)+pow(d[i+1].t-d[i].t,2));
	}
	printf("\nDo dai duong gap khuc :%.2f",tong);
}
//tinh do  dai duong gap khuc di qua cac diem 
void TinhDoDaiGapKhuc(Diem *d, int n) {
    float tong = 0;
    for (int i = 0; i < n - 1; i++) {
        tong += sqrt(pow(d[i + 1].h - d[i].h, 2) + pow(d[i + 1].t - d[i].t, 2));
    }
    printf("\nDo dai duong gap khuc: %.2f", tong);
}
// cách tìm tâm của các điểm chính là trung bình cộng của hoành và trung bình cộng của tung 
//>> tâm duong tron la (x,y)
// tiếp theo tìm bán kính bằng cách tìm khoảng cách lớn nhất giữa các điểm với tâm x,y vừa tìm được 
//>> khoảng cách nào lớn nhất  thì đây chính là bán kinh 
void DienTich (Diem *d,int n){
	int tonghoanh=0,tongtung=0;
	float r=0;
	for (int i=0;i<n;i++){
		tonghoanh+=d[i].h;
		tongtung +=d[i].t;
	}
	float x_center=(float)tonghoanh/n;
	float y_center=(float)tongtung/n;
	for (int i=0;i<n;i++){
		float tam=1.0*sqrt(pow(d[i].h-x_center,2)+pow(d[i].t-y_center,2));
		if(r<tam){
			r=tam;
		}
	}	
	float dientich=3.14*r*r;
	printf("\nDien tich nho nhat chua tat ca cac diem la :%.2f",dientich);
}
int gt(int n){
	int tich=1;
	for (int i=1;i<=n;i++){
		tich*=i;
	}
	return tich;
}
void  DemDoanThangGoc3(Diem *d,int n){
	int dem=0;
	for(int i=0;i<n;i++){
		if(d[i].h < 0 && d[i].t <0){
			dem++;
		}
	}
	if(dem==0){
		printf("\nKhong co doan thang nao thuoc goc phan tu thu 3");
	}
	else{
		printf("\nSo doan thang  thuoc goc phan tu thu 3  la  :%d .",gt(dem)/(gt(dem-2)*gt(2)));
	}
}
// Cac  diem nam ngoai  duong trong  
void DiemNgoaiDuongTron(Diem *d,int n){
	float r;
	printf("\nNhap  ban kinh:");
	scanf("%f",&r);
	printf("\nCac diem nam ngoai duong tron  la  :\n");
	for(int i=0;i<n;i++){
		if(sqrt(d[i].h*d[i].h +d[i].t*d[i].t ) > r){
			printf("\n%d %d",d[i].h,d[i].t);
		}
	}
}
// Tìm diện tích hình chữ nhật nhỏ nhất, có các cạnh song song với hệ trục tọa độ nhỏ
//nhất, chứa tất cả các điểm
void DienTichMin(Diem *d, int n) {
   int max_hoanh =INT_MIN;
   int max_tung = INT_MIN;
    // Tìm giá trị hoành độ lớn nhất và tung độ lớn nhất
    for (int i = 1; i < n; i++) {
        if (max_hoanh <abs(d[i].h)) max_hoanh = abs(d[i].h);
        if (max_tung <abs(d[i].t)) max_tung = abs(d[i].t);
    }
    // Tính cạnh của hình chữ nhật
    int dai= 2 * max_hoanh;
    int rong = 2 * max_tung;
    // Tính diện tích
    int dien_tich = dai *rong;
    printf("\nDien tich hinh chu nhat nho nhat: %d", dien_tich);
}
int  main(){
	int n;
	Diem *d;
	char tentep[50]="diemhinhtron.txt";
	DocFile(&d,n,tentep);
	TinhDoDaiGapKhuc(d,n);
	DienTich(d,n);
	DemDoanThangGoc3(d,n);
	DiemNgoaiDuongTron(d,n);
	DienTichMin(d,n);
	return 0;
}
