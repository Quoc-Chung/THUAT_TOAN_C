

//4. Xuất một dãy n tọa độ điểm ra file nhị phân có cấu trúc gồm một giá trị nguyên thể
//hiện số phần tử n và 3*n giá trị thực thể hiện các tọa độ dùng hàm fwrite
//5. Nhập một dãy n tọa độ điểm từ file nhị phân có cấu trúc như ý 4 dùng hàm fread
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct Diem{
	int x,y,z;
};
void Nhap1Diem(Diem &d){
	scanf("\n%d%d%d",&d.x,&d.y,&d.z);
}
void NhapNhieuDiem(Diem d[],int n){
	for(int i=0;i<n;i++){
		printf("\nDiem thu %d:",i+1);
		Nhap1Diem(d[i]);
	}
}
void GhiVaoFileVanBan(Diem d[],int n){
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\bai5c4.txt";
	FILE *f;
	f=fopen(duong_dan,"w");
	if(f==NULL){
		printf("\nKhong mo duoc file.");
		exit(1);
	}
	fprintf(f,"%d",n);
	for(int i=0;i<n;i++){
		fprintf(f,"\n %d  %d  %d ",d[i].x,d[i].y,d[i].z);
	}
	fclose(f);
}
void GhiVaoFileNhiPhan(Diem d[],int n){
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\bai5c4.bin";
	FILE *f;
	f=fopen(duong_dan,"wb");
	if(f==NULL){
		printf("\nKhong mo duoc file.");
		exit(1);
	}
	fwrite(&n, sizeof(int), 1, f);
  for (int i = 0; i < n; i++) {
    fwrite(&d[i], sizeof(Diem), 1, f);
    }
	printf("\nDa ghi duoc vao file nhi phan");
	fclose(f);
}
void DocVaoFileNhiPhan(Diem d[],int n){
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\bai5c4.bin";
	FILE *f;
	f=fopen(duong_dan,"rb");
	if(f==NULL){
		printf("\nKhong mo duoc file.");
		exit(1);
	}
	fread(&n, sizeof(int), 1, f);
  for (int i = 0; i < n; i++) {
    fread(&d[i], sizeof(Diem), 1, f);
    }
    printf("\bCac diem doc tu file nhi phan :\n");
    for(int i=0;i<n;i++){
    	printf("\n %d  %d  %d ",d[i].x,d[i].y,d[i].z);
	}
	fclose(f);
}
int main(){
	int n;
	printf("\nNhap so diem:");
	scanf("%d",&n);
	Diem d[100];
	NhapNhieuDiem(d,n);
	GhiVaoFileVanBan(d,n);
	GhiVaoFileNhiPhan(d,n);
	DocVaoFileNhiPhan(d,n);
	return 0;

}