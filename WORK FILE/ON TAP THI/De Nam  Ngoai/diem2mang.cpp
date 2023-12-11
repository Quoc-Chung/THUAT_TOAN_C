#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void DocFile(float **a,float **b,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the mo duoc file");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*a)=(float*) malloc(n*sizeof(float));
	(*b)=(float *) malloc (n*sizeof(float));
	for(int i=0;i<n;i++){
		fscanf(f,"%f",&(*a)[i]);
	}
	for(int i=0;i<n;i++){
		fscanf(f,"%f",&(*b)[i]);
	}		
}
void DemDiemTrongGoc2(float *a,float *b,int n){
    	int dem=0;
    	for(int i=0;i<n;i++){
    		if(a[i] <0 && b[i] >0){
    			dem++;
			}
		}
		printf("\nSo diem o goc phan tu thu hai la :%d",dem);
}
void HaiDiemGoc1XaNhat(float *a, float *b, int n) {
    int maxD1= -1; // Chỉ số của điểm xa nhất đầu tiên
    int maxD2 = -1; // Chỉ số của điểm xa nhất thứ hai
    float max= 0; // Khoảng cách lớn nhất giữa hai điểm
    for (int i = 0; i < n; i++) {
        if (a[i] > 0 && b[i] > 0) { // Kiểm tra xem điểm có nằm trong góc phần tư thứ nhất không
            for (int j = i + 1; j < n; j++) {
                if (a[j] > 0 && b[j] > 0) { // Kiểm tra xem điểm thứ hai có nằm trong góc phần tư thứ nhất không
                    float distance = sqrt((a[j] - a[i]) * (a[j] - a[i]) + (b[j] - b[i]) * (b[j] - b[i])); // tinh toan hóng cach giua hai diem
                    if (max <distance) {
                        max = distance;
                        maxD1 = i;
                        maxD2 = j;
                    }
                }
            }
        }
    }
    if (maxD1 != -1 && maxD1 != -1) {
        printf("\nHai diem xa nhau nhat trong goc phan tu thu nhat la:\n");
        printf("Diem 1: (%.2f, %.2f)\n", a[maxD1], b[maxD1]);
        printf("Diem 2: (%.2f, %.2f)\n", a[maxD2], b[maxD2]);
    } else {
        printf("\nKhong tim thay hai diem trong goc phan tu thu nhat.\n");
    }
}
void TinhDoDaiDuongGapKhuc(float *a, float *b, int n) {
    float length = 0.0; // Total length of the polygonal path
    for (int i = 1; i < n; i += 2) {
        if (i + 1 < n) {
            float dx = a[i + 1] - a[i];
            float dy = b[i + 1] - b[i];
            length += sqrt(dx * dx + dy * dy);
        }
    }
    printf("\nDo dai duong gap khuc  la :%.2f",length);
}
int main(){
	int n;
	float *a,*b;
	char tentep[50]="diem2mang.txt";
	DocFile(&a,&b,n,tentep);
	DemDiemTrongGoc2(a,b,n);
	HaiDiemGoc1XaNhat(a,b,n);
	TinhDoDaiDuongGapKhuc(a,b,n);
	return 0;
}




