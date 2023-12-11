#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct  Diem {
	float  hoanh;
	float tung;
};
void  DocFile(Diem **d,int &n,char *tentep){
	FILE  *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*d)=(Diem *) malloc (n*sizeof(Diem));
	for(int i=0;i<n;i++){
		fscanf(f,"%f%f",&(*d)[i].hoanh, &(*d)[i].tung);
	}
	printf("\n Day diem doc tu file  la  :\n");
	for (int i=0;i<n;i++){
		printf("\n %.2f %.2f ",(*d)[i].hoanh,(*d)[i].tung);
	}
	fclose(f);
}
int gt(int n){
	int gt=1;
	for(int i=1;i<=n;i++){
		gt*=i;
	}
	return gt;
}
void  DemDoanThang(Diem *d,int n){
	int dem=0;
	printf("\nNhap ban kinh :");
	 float R;
	 scanf("%f",&R);
	for (int i=0;i<n;i++){
		if(sqrt(d[i].hoanh *d[i].hoanh +d[i].tung*d[i].tung) < R){
			dem++;
		}
	}
	float sodoan=gt(dem)/(gt(dem-2)*gt(2));
	printf("\nSo Doan thang trong  duong tron la :%.0f",sodoan);
}
float TinhDienTich(Diem A, Diem B, Diem C){
    float AB = sqrt(pow(B.hoanh - A.hoanh, 2) + pow(B.tung - A.tung, 2));
    float BC = sqrt(pow(C.hoanh - B.hoanh, 2) + pow(C.tung - B.tung, 2));
    float AC = sqrt(pow(C.hoanh - A.hoanh, 2) + pow(C.tung - A.tung, 2));
    float p = (AB + BC + AC) / 2.0;
    return sqrt(p * (p - AB) * (p - BC) * (p - AC));
}
void SVuongMax(Diem* d, int n) {
    float Smax = 0;
    Diem maxA, maxB, maxC;
    bool check = false;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                float S = TinhDienTich(d[i], d[j], d[k]);
                if (Smax < S && pow(d[j].hoanh - d[i].hoanh, 2) + pow(d[j].tung - d[i].tung, 2) 
				   + pow(d[k].hoanh - d[j].hoanh, 2) + pow(d[k].tung - d[j].tung, 2) 
				       == pow(d[k].hoanh - d[i].hoanh, 2) + pow(d[k].tung - d[i].tung, 2)) {
                    Smax=S;
                    maxA = d[i];
                    maxB = d[j];
                    maxC = d[k];
                    check = true;
                }
            }
        }
    }
    if (check) {
        printf("\nTam giac vuong co dien tich lon nhat:\n");
        printf("A(%.2f, %.2f) - B(%.2f, %.2f) - C(%.2f, %.2f)\n", maxA.hoanh, maxA.tung, maxB.hoanh, maxB.tung, maxC.hoanh, maxC.tung);
        printf("Dien tich: %.2f", Smax);
    } else {
        printf("\nKhong co tam giac vuong trong day diem.");
    }
}
int main (){
	int n;
	Diem *d;
	char tentep[50]="diem.txt";
	DocFile(&d,n,tentep);
	DemDoanThang(d,n);
	SVuongMax(d,n);
	return 0;
}