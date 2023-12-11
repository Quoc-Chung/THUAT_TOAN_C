//Bài 2-1 Nhập danh sách n thí sinh tham gia Hội khỏe sinh viên từ tệp input.txt, mỗi thí 
//sinh là một ban ghi được lưu trữ trên 3 dỏng của tập tin các trường: HT (Họ tên), SD (Số 
//điểm), Đơn vị, (giả thiết thiết có 3 đơn vị tham gia là A, B, C). Dòng đầu của tệp là số 
//nguyên lưu trữ số lượng thí sinh. Yêu cầu: 
//1. Tính tổng số điểm của môi đơn vị trên, và đơn vị nào có tổng điểm lớn nhất.
//2. Tìm 3 thí sinh có điểm cao nhất. 
//3. Kết quả lưu vào tệp ketqua.txt bao gồm cả các thông tin về n thí sinh dự thi.
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct  SinhVien {
	char  HoTen[30];
	float Diem;
	char DonVi[2];
};
void  DocFile(SinhVien **sv,int &n,char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  doc duoc file");exit(0);
	}
	fscanf(f,"%d",&n);
	(*sv)=(SinhVien *)malloc(n*sizeof(SinhVien));
	for(int i=0;i<n;i++){
		fscanf(f," %[^\n]",(*sv)[i].HoTen);
		fscanf(f,"%f",&(*sv)[i].Diem);
		fscanf(f," %[^\n]",(*sv)[i].DonVi);
	}
	//  in thong tin sinh vien  ra  man  hinh 
	printf("\nThong tin  sinh vien la  :\n");
	for (int i=0;i<n;i++){
		printf("\nHo Ten :%s  ---- Diem :%.2f ---- Don Vi :%s",(*sv)[i].HoTen,(*sv)[i].Diem,(*sv)[i].DonVi);
	}
}
// ham in thong tin  sinh vien vao  file  
void InVaoFile (SinhVien *sv,int n,FILE *f=stdout){
	fprintf(f,"\nThong tin  sinh vien la  :\n");
	for (int i=0;i<n;i++){
		fprintf(f,"\nHo Ten :%s  ---- Diem :%.2f ---- Don Vi :%s",sv[i].HoTen,sv[i].Diem,sv[i].DonVi);
	}
}
void TongDiem(SinhVien *sv, int n, FILE *f = stdout) {
    int diem1 =0,diem2 = 0,diem3 = 0;
    float tong1 = 0, tong2 = 0, tong3 = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(sv[i].DonVi, "A") == 0) {
            diem1++;
            tong1+= sv[i].Diem;
        } else if(strcmp(sv[i].DonVi, "B") == 0) {
            diem2++;
            tong2 += sv[i].Diem;
        } else {
            diem3++;
            tong3 += sv[i].Diem;
        }
    }
   float diemA = 0, diemB = 0, diemC = 0;
if(diem1 != 0) {
    diemA = tong1 / diem1;
}
if(diem2 != 0) {
    diemB = tong2 / diem2;
}
if(diem3 != 0) {
    diemC = tong3 / diem3;
}
    fprintf(f, "\nDiem cua don vi A la: %.2f\nDiem cua truong B la: %.2f\nDiem cua truong C la: %.2f", diemA, diemB, diemC);
}
void  ThiSinhCaoDiem (SinhVien *sv,int n,FILE *f=stdout){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(sv[i].Diem >sv[j].Diem){
				SinhVien tmp=sv[i];
				sv[i]=sv[j];
				sv[j]=tmp;
			}
		}
	}
	fprintf(f,"\nThong tin  3 thi  sinh  co diem cao nhat  la  :\n");
	for (int i=0;i<3;i++){
		 fprintf(f,"\nHo Ten :%s  ---- Diem :%.2f ---- Don Vi :%s",sv[i].HoTen,sv[i].Diem,sv[i].DonVi);
	}
}
int main(){
	int n;
	SinhVien *sv;
	char tentep[50]="SinhVien1.txt";
	FILE *f=fopen("ketqua1.txt","w");
	if(f==NULL) {
		printf("\nKhong the  mo duoc file ");
		exit(0);
	}
	DocFile(&sv,n,tentep);
	TongDiem(sv,n,f);
	InVaoFile (sv,n,f);
	ThiSinhCaoDiem (sv,n,f);
	return 0;
}