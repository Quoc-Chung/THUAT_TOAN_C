
//Thêm một nhân viên vào vị trí k trong danh sách
//Xóa nhân viên ở đầu danh sách
//Xóa nhân viên ở cuối danh sách
//Xóa một nhân viên ở vị trí k trong danh sách
//Sắp xếp nhân viên theo lương giảm dần
#include <stdio.h>
#include <math.h>
#include <string.h>
struct sinhvien {
	char ten[30];
	int sobaodanh;
	float luong;
	char gioitinh[7];
};
//kiểu unsigned int thay vì size_t, 
//nhưng sử dụng size_t là tốt hơn vì nó sẽ tự động chọn kiểu số nguyên tương ứng với
//hệ điều hành hoặc máy tính đang sử dụng, 
//tránh được các vấn đề liên quan đến việc chọn sai kiểu số nguyên.
void xoaxuongdong(char c[]){
	size_t len= strlen(c);
	// digit is one separator ,i used '' ,not used " "
	if(c[len-1]='\n'){
		c[len-1]='\0';
	}
}
void input(sinhvien *sv){
	printf("\nNhap ho va ten :");
	fflush(stdin);
	fgets(sv->ten,sizeof(sv->ten),stdin);
	printf("\nNhap so bao danh:");
	scanf("%d",&sv->sobaodanh);
	printf("\nNhap gioi tinh:");
	fflush (stdin);
	fgets(sv->gioitinh,sizeof(sv->gioitinh),stdin);
	printf("\nNhap luong :");
	scanf("%f",&sv->luong);
}
void output(sinhvien sv){
	printf("\nHo va ten :%s",sv.ten);
	printf("\nSo bao danh:%d",sv.sobaodanh);
	printf("\nGioi tinh :%s",sv.gioitinh);
	printf("\nTien luong :%.0f dong.",sv.luong);
}
void inputarray(sinhvien *sv,int n){
	for (int i=1;i<=n;i++){
		printf("\nNhap sinh vien thu :%d\n",i);
		input((sv+i));// &sv[i]; truyền con trỏ với con tro no cung giong nhu o nho dau trong mang  
	}
}
void outputarray(sinhvien sv[],int n){
	printf("\n\tTHONG TIN SINH VIEN:\n ");
	for (int i=1;i<=n;i++){
		printf("\nSinh vien thu %d:\n",i);
		output(sv[i]);
	}
}
void outputtable(sinhvien sv[],int n){
	printf("\n\t\t\tBANG THONG TIN \n");
    printf("\n%-20s %-13s %-10s %-10s\n","Ho va ten","So bao danh","Gioi tinh","Tien luong");
    // bên trên dạng bang se đều in ra kí tự dạng chuỗi căn chỉnh lệch bên trái một so X
    for (int i=1;i<=n;i++){
 	xoaxuongdong(sv[i].ten);
 	xoaxuongdong(sv[i].gioitinh);
 	// bên duoi se in ra ket qua theo kieu dữ liệu của kết quả nhưng vẫn căn chỉnh lệch trái tương ứng phía trên 
 	printf("\n%-20s %-13d %-10s %-10.0f\n",sv[i].ten,sv[i].sobaodanh,sv[i].gioitinh,sv[i].luong);
 }	
}
void innitial(sinhvien sv[],int &n){
	for (int i=n+1;i>=2;i--){
	sv[i]=sv[i-1];
	}
	n++;
    printf("\nNhap thong tin sinh vien them vao dau :\n");
    input(sv+1);
}
void finish (sinhvien sv[],int &n){
	n++;
	printf("\nNhap sinh vien cuoi danh sach:");
	input(sv+n);
}
void batki(sinhvien sv[],int &n,int &vitrithem){
	printf("\nNhap vi tri them :");
	scanf("%d",&vitrithem);
	for (int i=n+1;i>=vitrithem+1;i-- ){
		sv[i]=sv[i-1];
	}
	n++;
	printf("\nNhap sinh vien them :");
	input((sv+vitrithem));
}
void  xoabatki(sinhvien sv[],int &n,int &vitrixoa){
//	printf("\nNhap vi tri xoa :");
//	scanf("%d",&vitrixoa);
	for (int i=vitrixoa;i<=n-1;i++){
		sv[i]=sv[i+1];
	}
	n--;
}
void xoatheoSBD(sinhvien sv[],int &n,int &sobaodanh){
	int vitricanxoa;
	printf("\nNhap so bao danh can xoa :");
	scanf("%d",&sobaodanh);
	for (int i=1;i<=n;i++){
		if(sobaodanh==sv[i].sobaodanh){
			vitricanxoa=i;
			break;
		}
	}
	xoabatki(sv,n,vitricanxoa);
}
//Tìm kiếm nhân viên theo họ tên
void search (sinhvien sv[],int n){
	 char kiemten[30];
	printf("\nNhap nhan vien can tim kiem:\n");
	fflush(stdin);
	fgets(kiemten,sizeof(kiemten),stdin);
	for (int i=1;i<=n;i++){
		if(stricmp(kiemten,sv[i].ten)==0){
			output(sv[i]);
			break;
		}
	}
}
//Sắp xếp nhân viên theo lương giảm dần
void arrange (sinhvien sv[],int n){
	sinhvien tam;
	for (int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++){
			if(sv[i].luong<=sv[j].luong){ // luong nhan vien 1 nho hon luong nhan vien 2 thi doi cho 
			tam=sv[i];
			sv[i]=sv[j];
			sv[j]=tam;
			}
		}
	}
	printf("\nNhan vien theo luong giam dan :\n");
	for (int i=1;i<=n;i++){
		printf("\n%s",sv[i].ten);
	}
}

int main(){
	int n;
	do {
		printf("\nNhap n:");
		scanf("%d",&n);
		if(n<1){
			printf("\nVui long nhap lai .");
		}
	}while (n<1);
	int vitrithem,vitrixoa,sobaodanh;
	 sinhvien sv[100];
	 inputarray (sv,n);
//	 innitial(sv,n);
//	 finish(sv,n);
    outputtable(sv,n);
//	 outputarray(sv,n);
//	 search(sv,n);
//    arrange(sv,n);
     // batki(sv,n,vitrithem);
//     xoabatki(sv,n,vitrixoa);
//       outputarray(sv,n); 
      xoatheoSBD(sv,n,sobaodanh);
      outputtable(sv,n);
	 return 0;
}