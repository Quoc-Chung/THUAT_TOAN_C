/// Định nghĩa một cấu trúc Sinh viên gồm các thành phần: Mã SV, tên SV, năm sinh, điểm.
///Nhập, xuất n sinh viên.
// Tìm sinh viên lớn tuổi nhất trong lớp.
// Nhập vào mã sinh viên, in ra màn hình thông tin của sinh viên đó.
// Nhập vào điểm chuẩn, in ra màn hình những sinh viên trung tuyển.
#include <stdio.h>
#include <math.h>
struct sinhvien{
	unsigned int maSV;
	char ten[30];
	int namsinh ;
	float diem;
};
// %c là đặc tả của kiểu kí tự
// %s là đặc tả của chuỗi kí tư
void nhapdiem(struct sinhvien d[],int n){
	for (int i=1;i<=n;i++){
			printf("Nhap sinh vien thu %d:\n",i);
			printf("\nNhap ten :");
	        fflush(stdin); // Cái fflush(stdin) đúng là để xóa bộ đệm. 
			//Khi em nhập vào thì bao nhiêu ký tự cũng chui vào bộ đệm cho tới khi bộ đệm tràn.
			//co nghia la xoa bo nho cac ki tu da nhap tu truoc toi gio de tranhs tràn bộ nhớ đệm 
			   fgets(d[i].ten, sizeof(d[i].ten), stdin);
			printf("\nNhap ma sinh vien :");
			   scanf("%d",&d[i].maSV);
			printf("\nNhap nam sinh :");
			   scanf("%d",&d[i].namsinh);
			printf("\nNhap diem :");
			   scanf("%f",&d[i].diem);
			
		}
	}
void indiem (struct sinhvien d[],int n){
	for (int i=1;i<=n;i++){
		    printf("\nSinh vien thu %d:\n",i);
			printf("Ma sinh vien :%d",d[i].maSV);
			printf("\nTen :%s",d[i].ten);
			printf("\nNam sinh :%d",d[i].namsinh);
			printf("\nDiem :%.2f",d[i].diem);
	}
}

// tuoi max khi co nam sinh nho nhat 
void sinhvientuoimax(struct sinhvien d[],int n){
	int min =2100;
	int vitri=0;
	for (int i=1;i<=n;i++){
		if(min>d[i].namsinh){
			min=d[i].namsinh;
			vitri=i;
		}
	}
	printf("\nTen sinh vien co tuoi max la :%s",d[vitri].ten);
}
// Nhập vào mã sinh viên, in ra màn hình thông tin của sinh viên đó.
void inrasinhvien (struct sinhvien d[],int n,int m){
		for (int i=1;i<=n;i++){
			if(d[i].maSV==m){
			printf("Ma sinh vien :%d",d[i].maSV);
			printf("\nTen :%s",d[i].ten);
			printf("\nNam sinh :%d",d[i].namsinh);
			printf("\nDiem :%.2f",d[i].diem);
		}
	}
}
//Nhập vào điểm chuẩn, in ra màn hình những sinh viên trung tuyển
void kiemtratrungtuyen(struct sinhvien d[],int n,float diem){
	int vitri;
	for (int i=1;i<=n;i++){
		vitri=0;
	if(d[i].diem>=diem)
	vitri=i;
		printf("%s\n",d[i].ten);
		
	}
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	struct sinhvien sv[100];
	nhapdiem(sv,n);
	indiem(sv,n);
	sinhvientuoimax(sv,n);
	int ma;
	printf("\nNhap ma can in ra:");
	scanf("%d",&ma);
	inrasinhvien (sv,n,ma);
	int diemchuan;
	printf("\nNhap diem chuan :");
	
	scanf("%f",&diemchuan);
	printf("\nNhung sinh vien trung tuyen:\n ");
	kiemtratrungtuyen(sv, n, diemchuan);
	return 0;
}