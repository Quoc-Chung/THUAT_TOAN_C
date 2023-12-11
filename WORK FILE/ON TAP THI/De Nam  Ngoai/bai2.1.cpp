#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct  Diem {
	int hoanh;
	int tung;
};
void DocFile(Diem **d,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*d) =(Diem *) malloc(n*sizeof(Diem));
	for (int i=0;i<n;i++){
		fscanf(f,"%d%d",&(*d)[i].hoanh,&(*d)[i].tung);
	}
	
}
void DiemXaNhat (Diem *d,int n){
	float max =INT_MIN;
	int h=0,t=0;
	for (int i=0;i<n;i++){
		if(max < sqrt(d[i].hoanh *d[i].hoanh +d[i].tung *d[i].tung)){
			max =sqrt(d[i].hoanh *d[i].hoanh +d[i].tung *d[i].tung);
			h=d[i].hoanh;
			t=d[i].tung;
		}
	}
	printf("\nDiem o xa toa do nhat :(%d  %d)",h,t);	
}
int gt(int n){
	int tich=1;
	for (int i=1;i<=n;i++){
		tich*=i;
	}
	return  tich;
}
void DoanThangTrongGoc3(Diem *d,int n){
	int dem=0;
	for (int i=0;i<n;i++){
		if(d[i].hoanh <0  && d[i].tung <0){
			dem++;
		}
	}
printf("\nDoan thang nam  trong goc  phan tu thu  3 la :%d",gt(dem)/(gt(dem-2))*gt(2));
}
int main(){
	int n;
	Diem *d;
    char tentep[50]="diem1.txt";
    DocFile(&d,n,tentep);
    DoanThangTrongGoc3(d,n);
     DiemXaNhat (d,n);
     return 0;
} 