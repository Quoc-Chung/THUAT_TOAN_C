//1-3 Cho tệp văn bản (tên tệp nhập từ bàn phím) chứa toạ độ của một dãy n điểm. Tệp
//có cấu trúc như sau: Dòng đầu chứa số nguyên n, n dòng tiếp theo mỗi dòng chứa toạ độ
//x, y của một điểm (giữa các giá trị có ít nhất một dấu cách). Hãy xây dựng các hàm để
//thực hiện các việc sau đây:
//1. Đọc tọa độ dãy điểm từ tệp.
//2. Tính khoảng cách của các điểm đến trục hoành.
//3. Trong số các đoạn thẳng có dầu mút là các điểm nói trên, tìm một đoạn thăng có độ dai
//lớn nhất.
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct Diem{
	int hoanh;
	int tung;
};
void DocFile (Diem **d,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKHong the mo duoc file.");
		exit(0);
	}
	//cap phat dong
	fscanf(f,"%d",&n);
	(*d)=(Diem *) malloc(n*sizeof(Diem));
	for (int i=0;i<n;i++){
		fscanf(f,"%d%d",&(*d)[i].hoanh,&(*d)[i].tung);
	}
	printf("\nCac diem duoc doc tu tep la  :\n");
	for (int i=0;i<n;i++){
		printf("\n%d %d",(*d)[i].hoanh,(*d)[i].tung);
	}
}
void  KhoangCachDenTrucHoanh (Diem *d,int n){
	for(int i=0;i<n;i++){
		printf("\nKhoang cach diem (%d %d) den truc hoanh la :%d ",d[i].hoanh,d[i].tung,d[i].tung);
	}
}
float TinhKhoangCach(Diem A, Diem B) {
    return sqrt(pow(B.hoanh - A.hoanh, 2) + pow(B.tung - A.tung, 2));
}

// doan thang co  do dai lon nhat  như  nào 
void DoanThangMax(Diem *d,int n){
	int max=INT_MIN;
	Diem maxA,maxB;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			float kc =TinhKhoangCach(d[i],d[j]);
			if(max < kc){
				max=kc;
				maxA=d[i];
				maxB=d[j];
			}
		}
	}
	printf("\nDoan thang co do  dai max  duoc tao tu diem (%d %d) va (%d %d).",maxA.hoanh,maxA.tung,maxB.hoanh,maxB.tung);
}
int main(){
	int n;
	Diem *d;
	char tentep[50]="khoangcachmax.txt";
	DocFile(&d,n,tentep);
	KhoangCachDenTrucHoanh (d,n);
	DoanThangMax(d,n);
	return 0;
}