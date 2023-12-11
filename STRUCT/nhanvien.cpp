#include <stdio.h>
#include <math.h>
#include <string.h>
struct ngaysinh{
	int ngay;
	int thang;
	int nam;
};
struct nhanvien {
	char ten[30];
    ngaysinh date;// date luc nay thuoc ca cấu trúc nhân viên lẫn cấu truc ngày sinh :nv[i].date.ngay...
	float luong;
	char gioitinh[5];
	
};
//Xây dựng danh sách liên kết đơn, quản lý cấu trúc nhân viên. Biết rằng thông tin 
//của một nhân viên bao gồm: họ tên (30 ký tự), ngày sinh (30 kí tự), lương (số
//thực), giới tính (0. Nữ, 1.Nam).
void nhap1nv(struct nhanvien &nv){
 printf("\nNhap ho va ten :");
 fflush (stdin);
 fgets(nv.ten,sizeof(nv.ten),stdin);
// printf("\nNhap ngay sinh :");
// scanf("%d%d%d",&nv.date.ngay,&nv.date.thang,&nv.date.nam);
// printf("\nNhap luong :");
// scanf("%f",&nv.luong);
// printf("Nhap gioi tinh:");
// fflush (stdin);
// fgets(nv.gioitinh,sizeof(nv.gioitinh),stdin);
}
void nhap(struct nhanvien nv[],int n){
   for (int i=1;i<=n;i++){
   	printf("\nNhap nhan vien thu %d:\n",i);
   	nhap1nv(nv[i]);
}
}
void in1nv(struct nhanvien nv){// có dấu truyền tham chiếu vì tí n sẽ có sự thay đổi 
		printf("\nHo va ten :%s",nv.ten);
		
		
		
		
		

}
void in(struct nhanvien nv[],int &n){
	printf("\n\tTHONG TIN NHAN VIEN\n");
	for (int i=1;i<=n;i++){
		printf("\nNhan vien thu :%d",i);
		in1nv(nv[i]);
	}	
}
//Thêm một nhân viên vào đầu danh sách
void themnhanviendaudanhsach (nhanvien nv[],int &n){
	for (int i=n+1;i>=2;i--){
		nv[i]=nv[i-1];
	}
	n++;
	printf("\nThong tin nhan vien dau danh sach :\n");
	nhap1nv(nv[1]);	
}
//Thêm một nhân viên vào cuối danh sách
void themnhanviencuoidanhsach(nhanvien nv[],int &n){
	printf("\nNhap nhan vien them vao cuosi danh sach :\n");
	nhap1nv(nv[n+1]);// don giản ở day la vì ở cuối nên không cần vòng for nào để dịch các chỗ để có chỗ trống nhét 
	// nhân viên cần thêm vào mà chỉ cần tăng số lượng nhân viên lên 1
	n++;
}
//Thêm một nhân viên vào vị trí k trong danh sách
void thembatki (struct nhanvien nv[],int &n,int vitrik){
	for(int i=n+1;i>=vitrik+1;i--){
		nv[i]=nv[i-1];
	}
	n++;
	nhap1nv(nv[vitrik]);
}
//Xóa nhân viên ở đầu danh sách
void xoanhanviendau (struct nhanvien nv[],int &n){
	for (int i=1;i<=n-1;i++){
		nv[i]=nv[i+1];// a ở vị trí trước lúc này là vị trí sau dó ,túc là dịch lùi lại một ô 
	}
	n--;
}
//Xóa nhân viên ở cuối danh sách
void xoanhanviencuoi(struct nhanvien nv[],int &n){
	n--;
}
void xoanhanvienvitrik(struct nhanvien nv[],int &n,int vitrik){
	for (int i=vitrik;i<=n-1;i++){
		nv[i]=nv[i+1];
	}
	n--;
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
	int vitrik1,vitrik2;
	do {
	printf("Nhap n:");
	scanf("%d",&n);
	if(n<1){
		printf("\nVui long nhap lai :\n");
	}
}while (n<1);
struct nhanvien nv[100];
nhap(nv,n);
printf("\nNhap vi tri them :");
scanf("%d",&vitrik1);
printf("\nNhap vi tri xoa :");
scanf("%d",&vitrik2);
themnhanviendaudanhsach (nv,n);
themnhanviencuoidanhsach(nv,n);
thembatki(nv,n,vitrik1);
xoanhanviendau(nv,n);
xoanhanviencuoi(nv,n);
xoanhanvienvitrik(nv,n,vitrik2);
in(nv,n);
timkiemnhanvien(nv,n);
sapxep(nv,n);
return 0;
}



















