//Nhập danh sách n thí sinh tham gia Hội khỏe sinh viên từ tệp input.txt, mỗi thí
//sinh là một ban ghi được lưu trữ trên 3 dỏng của tập tin các trường: HT (Họ tên), SD (Số
//điểm), Đơn vị, (giả thiết thiết có 3 đơn vị tham gia là A, B, C). Dòng đầu của tệp là số
//nguyên lưu trữ số lượng thí sinh. Yêu cầu:
//1. Tính tổng số điểm của môi đơn vị trên, và đơn vị nào có tổng điểm lớn nhất.
//2. Tìm 3 thí sinh có điểm cao nhất.
//3. Kết quả lưu vào tệp ketqua.txt bao gồm cả các thông tin về n thí sinh dự thi.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct SinhVien{
	char hoTen[30];
	float diem;
	char DonVi[2];
};
void DocTeptuFile(SinhVien** sv, int &n, char* tentep) {
    FILE* f;
    f = fopen(tentep, "r");
    if (f == NULL) {
        printf("\nKhong the mo duoc file.");
        exit(0);
    }
    fscanf(f, "%d", &n);

    *sv = (SinhVien*)malloc(n * sizeof(SinhVien));
    if (*sv == NULL) {
        printf("\nKhong the cap phat duoc.");
        exit(0);
    }

    for (int i = 0; i < n; i++) {
        fscanf(f," %[^\n]", (*sv)[i].hoTen);
        fscanf(f, "%f", &(*sv)[i].diem);
        fscanf(f," %[^\n]", (*sv)[i].DonVi);
    }

    fclose(f);
}
void InVanBan(SinhVien *sv,int n){
	printf("\nCac Thong tin tu file  la :\n");
	for(int i=0;i<n;i++){
		printf("\nThong tin cua nguoi thu %d:\n",i+1);
		printf("Ho va ten:%s",sv[i].hoTen);
		printf("\nDiem:%.2f",sv[i].diem);
		printf("\nDon vi :%s",sv[i].DonVi);
	}
}
int main(){
	int n;
	char tentep[50]="SinhVien1.txt";
//	printf("\nNhap ten tep:");
//	gets(tentep);
	SinhVien *sv;
	DocTeptuFile(&sv, n, tentep);
	InVanBan(sv,n);
	return 0;
}
