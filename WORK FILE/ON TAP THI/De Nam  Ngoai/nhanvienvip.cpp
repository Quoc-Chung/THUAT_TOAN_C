//Nhập danh sách n nhân viên của 1 công ty từ tệp input.txt Mỗi nhân viên là một
//cấu trúc được lưu trữ trên 3 dòng của tệp gồm các trường : MNV (mã nhân viên), HT (Họ
//tên NV), LUONG (Lương ), PHONG (phòng ban). Giả sử công ty có 3 phòng A, B, C,
//Dòng dầu của tệp là số nguyên lưu trữ số lượng nhân viên
//1. Tính lương trung bình của từng phòng và cho biết phòng nào có lương trung bình thấp
//nhất
//2. In danh sách nhân viên ra mà hình theo thứ tự giảm cân của lưong
//3. kết quái lưu vào tệp kq.txt bao gồm cả các thông tin về n nhân viên.
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct NhanVien {
	int Ma;
	char HoTen[50];
	int Luong;
	char Phong[2];
};
void DocFile(NhanVien **nv,int &n ,char *tentep,FILE *f1=stdout){
 FILE *f=fopen(tentep,"r");
 if(f==NULL){
 	printf("\nKhong the  mo duoc file ");
 	exit(0);
 }
 fscanf(f,"%d",&n);
 (*nv )=(NhanVien *) malloc  (n*sizeof(NhanVien));
 for(int i=0;i<n;i++){
 	fscanf(f,"%d",&(*nv)[i].Ma);
 	fscanf(f," %[^\n]",(*nv)[i].HoTen);
 	fscanf(f,"%d",&(*nv)[i].Luong);
 	fscanf(f," %[^\n]",(*nv)[i].Phong);
 }
 fprintf(f1,"\nThong tin nhan vien doc tu  file  la :\n");
 for  (int i=0;i<n;i++){
 	fprintf(f1,"\nMa nhan vien :%d \nHo va Ten :%s \nLuong :%d \nPhong :%s",(*nv)[i].Ma,(*nv)[i].HoTen,(*nv)[i].Luong,(*nv)[i].Phong);
 }
}
void LuongTrungBinh(NhanVien *nv,int n,FILE *f=stdout){
	int t1=0,t2=0,t3=0;
	int dem1=0,dem2=0,dem3=0;
	for(int i=0;i<n;i++){
		if(strcmp(nv[i].Phong,"A")==0){
			t1+=nv[i].Luong;dem1++;
		}
		else if(strcmp(nv[i].Phong,"B")==0){
			t2+=nv[i].Luong;dem2++;
		}
		else{
			t3+=nv[i].Luong;dem3++;
		}
	}
	float tb1=(float)t1/dem1,tb2=(float)t2/dem2,tb3=(float)t3/dem3;
     	fprintf(f,"\nLuong trung binh phong A la :%.2f",tb1);
		fprintf(f,"\nLuong trung binh phong B la :%.2f",tb2);
		fprintf(f,"\nLuong trung binh phong C la :%.2f",tb3);
	if(tb1 >tb2 && tb1 >tb3){
		fprintf(f,"\nPhong A  co luong trung  binh cao nhat.");
	}
	else if(tb2 >tb1  && tb2 >tb3){
		fprintf(f,"\nPhong B co luong trung binh cao nhat.");
	}
	else{
		fprintf(f,"\nPhong C co luong trung binh cao nhat.");
	}
}
void GiamDanLuong(NhanVien *nv,int n,FILE *f=stdout){
	for  (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(nv[i].Luong > nv[j].Luong){
			   NhanVien tmp =nv[i];
			   nv[i]=nv[j];
			   nv[j]=tmp;	
			}
		}
	}
	fprintf(f,"\nDanh  sach sinh  vien giam  dan theo luong la  :\n");
	for (int i=0;i<n;i++){
	fprintf(f,"\nMa nhan vien :%d \nHo va Ten :%s \nLuong :%d \nPhong :%s",(nv)[i].Ma,(nv)[i].HoTen,(nv)[i].Luong,(nv)[i].Phong);	
	}
}

int main (){
	int n;
	NhanVien *nv;
	FILE *f=fopen("nhanviensieucap.txt","w");
	char tentep[50]="nhanvienvip.txt";
	DocFile(&nv,n,tentep,f);
	LuongTrungBinh(nv,n,f);
	GiamDanLuong(nv,n,f);
	return 0;
}