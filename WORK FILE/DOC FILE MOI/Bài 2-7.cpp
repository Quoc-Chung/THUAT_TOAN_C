//7 Nhập danh sách n nhân viên của 1 công ty từ tệp input.txt Mỗi nhân viên là một 
//cấu trúc được lưu trữ trên 4 dòng của tệp gồm các trường : MNV (mã nhân viên), HT (Họ 
//tên NV), LUONG (Lương ), PHONG (phòng ban). Giả sử công ty có 3 phòng A, B, C, 
//Dòng dầu của tệp là số nguyên lưu trữ số lượng nhân viên
//1. Tính lương trung bình của từng phòng và cho biết phòng nào có lương trung bình thấp 
//nhất 
//2. In danh sách nhân viên ra mà hình theo thứ tự giảm cân của lưong 
//3. kết quái lưu vào tệp kq.txt bao gồm cả các thông tin về n nhân viên.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct  NhanVien {
	int Ma;
	char HoTen[50];
	float luong;
	char phong[2];
};
void  DocFile(NhanVien **nv,int &n,char *tentep){
	FILE *f;
	f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file .");
		exit(0);
	}
	fscanf(f,"%d",&n);
	*nv=(NhanVien *) malloc (n*sizeof(NhanVien));
	for(int i=0;i<n;i++){
		fscanf(f,"%d",&(*nv)[i].Ma);
		fscanf(f," %[^\n]",(*nv)[i].HoTen);
		fscanf(f,"%f",&(*nv)[i].luong);
		fscanf(f," %[^\n]",(*nv)[i].phong);
	}
	fclose(f);
}
void InFile(NhanVien *nv,int n,FILE *f=stdout){
	for(int i=0;i<n;i++){
		fprintf(f,"\n%d",(nv)[i].Ma);
		fprintf(f,"\n%s",(nv)[i].HoTen);
		fprintf(f,"\n%.2f",(nv)[i].luong);
		fprintf(f,"\n%s",(nv)[i].phong);
	}
}
void LuongTrungBinh (NhanVien *nv,int n,FILE *f=stdout){
	int dem1=0,dem2=0,dem3=0;
	float tong1=0,tong2=0,tong3=0;
	for (int  i=0;i<n;i++){
	 if(strcmp(nv[i].phong,"A")==0){
	 	dem1++;
	 	tong1+=nv[i].luong;
	 }
	  if(strcmp(nv[i].phong,"B")==0){
	 	dem2++;
	 	tong2+=nv[i].luong;
	 }
	  if(strcmp(nv[i].phong,"C")==0){
	 	dem3++;
	 	tong3+=nv[i].luong;
	 }
	}
	float phong1=tong1/dem1,phong2=tong2/dem2,phong3=tong3/dem3;
	fprintf(f,"\nLuong  trung binh phong  A la :%.2f",phong1);
	fprintf(f,"\nLuong  trung binh phong  B la :%.2f",phong2);
	fprintf(f,"\nLuong  trung binh phong  C la :%.2f",phong3);
			
	if(phong1<phong2 && phong1<phong3){
		fprintf(f,"\nPhong A co luong trung binh thap nhat");	
	}
	if(phong2<phong1 && phong2<phong3){
	    fprintf(f,"\nPhong B co luong trung binh thap nhat");	
	}
	else{
		fprintf(f,"\nPhong C  co  luong trung  binh thap nhat");
	}
}

void LuongGiamDan (NhanVien *nv,int n,FILE *f =stdout){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(nv[i].luong <nv[j].luong){
				NhanVien tmp=nv[i];
				nv[i]=nv[j];
				nv[j]=tmp;
			}
		}
	}
	fprintf(f,"\nDanh sach nhan vien theo luong giam dan la  :\n");
	for(int i=0;i<n;i++){
	    fprintf(f,"\n%d",(nv)[i].Ma);
		fprintf(f,"\n%s",(nv)[i].HoTen);
		fprintf(f,"\n%.2f",(nv)[i].luong);
		fprintf(f,"\n%s",(nv)[i].phong);
	}
}
int main (){
	int n;
	NhanVien *nv;
	char tentep[50]="NhanVien.txt";
	FILE *f=fopen("Ket_Qua_Nhan_Vien.txt","w");
	DocFile(&nv,n,tentep);
    InFile(nv,n,f);
	LuongTrungBinh (nv,n,f);
		LuongGiamDan (nv,n,f);
			fclose(f);
			return 0;
}



















