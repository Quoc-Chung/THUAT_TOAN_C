//Thêm một nhân viên vào đầu danh sách
//Thêm một nhân viên vào cuối danh sách
//Thêm một nhân viên vào vị trí k trong danh sách
//Xóa nhân viên ở đầu danh sách
//Xóa nhân viên ở cuối danh sách
//Xóa một nhân viên ở vị trí k trong danh sách
#include <stdio.h>
#include <math.h>
#include <string.h>
struct nhanvien {
	char ten[30];
     int ngay,thang,nam;
	float luong;
	char gioitinh[5];
	
};
//Xây dựng danh sách liên kết đơn, quản lý cấu trúc nhân viên. Biết rằng thông tin 
//của một nhân viên bao gồm: họ tên (30 ký tự), ngày sinh (30 kí tự), lương (số
//thực), giới tính (0. Nữ, 1.Nam).
void nhap(struct nhanvien nv[],int n){
	for (int i=1;i<=n;i++){
printf("\nNhap nhan vien thu %d:\n",i);
 printf("Nhap ho va ten :");
 fflush (stdin);
 fgets(nv[i].ten,sizeof(nv[i].ten),stdin);
 printf("\nNhap ngay sinh :");
 scanf("%d%d%d",&nv[i].ngay,&nv[i].thang,&nv[i].nam);
 printf("\nNhap luong :");
 scanf("%f",&nv[i].luong);
 printf("Nhap gioi tinh:");
 fflush (stdin);
 fgets(nv[i].gioitinh,sizeof(nv[i].gioitinh),stdin);	
}
}
void in (struct nhanvien nv[],int &n){
       printf("\n-----THONG TIN NHAN VIEN----\n");
	printf("So thu tu \t Ho va ten \t\t Gioi tinh \t Ngay sinh \t Luong\n");
	for (int i=1;i<=n;i++){
		printf("\nNhan vien thu %d:\n",i);
		printf("\nHo va ten :%s",nv[i].ten);
		printf("\nGioi tinh :%s",nv[i].gioitinh);
		printf("Ngay sinh: %d/%d/%d",nv[i].ngay,nv[i].thang,nv[i].nam);
		printf("\nLuong :%.0f trieu dong.",nv[i].luong);
	}
}
void indangbang(struct nhanvien nv[],int n){
	 printf("\n-----BANG THONG TIN NHAN VIEN----\n");
    printf("So thu tu \t Ho va ten \t Ngay Sinh \t Gioi tinh \t Luong \n");
    for (int i=1;i<=n;i++){
    	printf("%d \t %s \t %d/%d/%d \t %s \t %f \n",
		        i, nv[i].ten,nv[i].ngay,nv[i].thang,nv[i].nam,nv[i].gioitinh,nv[i].luong);
	}
}
void nhap1nv(struct nhanvien &nv){
 printf("\nNhap ho va ten :");
 fflush (stdin);
 fgets(nv.ten,sizeof(nv.ten),stdin);
 printf("\nNhap ngay sinh :");
 scanf("%d%d%d",&nv.ngay,&nv.thang,&nv.nam);
 printf("\nNhap luong :");
 scanf("%f",&nv.luong);
 printf("Nhap gioi tinh:");
 fflush (stdin);
 fgets(nv.gioitinh,sizeof(nv.gioitinh),stdin);
}
void themmoinhanvien(struct nhanvien nv[],int &n){// cần truyền tham chiếu vì số lượng sinh viên tăng lên 
  printf("\nNhap sinh vien them vao:\n");
  nhap1nv(nv[1]);
  n++;
}
//Tìm kiếm nhân viên theo họ tên
void timkiemnhanvien(struct nhanvien nv[],int n){
	char ten1[30];
	printf("\nNhap ten tim kiem :");
	fflush(stdin);
	fgets(ten1,sizeof(ten1),stdin);
	for (int i=1;i<=n;i++){
		if(strcmp(ten1,nv[i].ten)==0){
			in(nv,i);
			break;
			
		}
	}
}
//Sắp xếp nhân viên theo lương giảm dần
void sapxep (struct nhanvien nv[],int n){
	struct nhanvien tam;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if(nv[i].luong>nv[j].luong){
				tam=nv[i];
				nv[i]=nv[j];
				nv[j]=tam;
			}
		}
	}
	printf("\nDanh sach nhan vien giam dan la:\n");
	for (int i=1;i<=n;i++){
		printf("\n%d.%s",i,nv[i].ten);
	}
}
int main (){
	int n;
	do {
	printf("Nhap n:");
	scanf("%d",&n);
	if(n<1){
		printf("\nVui long nhap lai :\n");
	}
}while (n<1);
struct nhanvien nv[100];
nhap(nv,n);

indangbang(nv,n);
//themmoinhanvien(nv,n);
//in(nv,n);
//timkiemnhanvien(nv,n);
//sapxep(nv,n);
return 0;
}



















