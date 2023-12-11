#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include<conio.h>
// tao mot struct de luu tru 3 gia tri la ngay thang nam 
struct date {
	int ngay ;
	int thang ;
	int nam;
};
// lap mot struct de luu tru cac thong tin sinh vien 
struct SinhVien{
	int id;
	char ten[30];
	char malop[30];
	char gioitinh[5];
	date ngaysinh;//  tuc no se co 3 dac ta cho ngay thang nam voi kieu cau truc vua dinh nghia 
	float diemmon1;
	float diemmon2;
	float diemmon3;
	float DiemTB;
	char hocluc[10];
};
// ham nhap ta truyen bien tham chieu de co the thay doi gia tri da nhap trong ham khi ham ket thuc
// tuc la bien vua nhap trong ham co the su dung trong ham chinh luon
void NhapSV(struct SinhVien sv[],int n){
	for (int i=1;i<=n;i++){
		printf("\nNhap sinh vien thu :%d\n",i);
	printf("Nhap ID:");
	scanf("%d",&sv[i].id);
	//scanf("\n");// co dong lenh nay de tranh viec troi lenh cuar cac ham gets phia sau
	printf("\nNhap Ten Sinh Vien :\n");
    fflush(stdin);
    fgets(sv[i].ten,sizeof(sv[i].ten),stdin );
	printf("\nNhap Ten Lop :");
    fflush(stdin);
    fgets(sv[i].malop,sizeof(sv[i].malop),stdin );
	printf("\nNhap Gioi Tinh:");
	fflush(stdin);
	fgets(sv[i].gioitinh,sizeof(sv[i].gioitinh),stdin);
    printf("\nNhap ngay sinh:");
    scanf("%d%d%d",&sv[i].ngaysinh.ngay,&sv[i].ngaysinh.thang,&sv[i].ngaysinh.nam);
  	printf("\nNhap Diem mon 1,mon 2,mon 3:");
    scanf("%f %f %f",&sv[i].diemmon1,&sv[i].diemmon2,&sv[i].diemmon3);

}
}
void inSinhVien (struct SinhVien sv[],int n){
	for (int i=1;i<=n;i++){
	printf("ID:%d",sv[i].id);
	printf("\nTen Sinh Vien :%s",sv[i].ten);
	printf("\n Ma Lop :%s",sv[i].malop);
	printf("\n Gioi Tinh:%s",sv[i].gioitinh);
	printf("\n Diem mon 1:%f\nDiem mon2 :%f\nDiem mon 3:%f\n",sv[i].diemmon1,sv[i].diemmon2,sv[i].diemmon3);
}
}
void gioitinh(struct SinhVien sv[],int n,char gt[]){
	int flag=0;
	printf("Cac sinh vien thuoc gioi tinh vua nhap:");
 	for (int i=1;i<=n;i++){
 		if(strcmp(gt,sv[i].gioitinh)==0){
		 		printf("\n%s",sv[i].ten);
		 		flag++;
		 }
	 }
	 if(flag==0){
	 	printf("\nKhong co sinh vien.");
	 }
 }
void tinhtuoi (struct SinhVien sv[],int n){
	int tuoi;
	for (int i=1;i<=n;i++){
	tuoi=0;
	tuoi+=2022-sv[i].ngaysinh.nam;
	printf("\nTuoi cua %s la:%d",sv[i].ten,tuoi);
			}
}

void diemTB(struct SinhVien sv[],int n){
	float diem;
	for (int i=1;i<=n;i++){
		diem=0;
		diem+=(sv[i].diemmon1+sv[i].diemmon2
		   +sv[i].diemmon3)/3;
		printf("\nDiem TB cua %s :%.2f",sv[i].ten,diem);
	}
}
void maxTB(struct SinhVien sv[],int n){
	float max=0;
	for (int i=1;i<=n;i++){
		if (max<=((sv[i].diemmon1+sv[i].diemmon2
		   +sv[i].diemmon3)/3)){
		   	max=(sv[i].diemmon1+sv[i].diemmon2
		   +sv[i].diemmon3)/3;
		   }
	}
	printf("\nDiem trung binh lon nhat la :%.2f",max);
	
}
void tuoimax(struct SinhVien sv[],int n){
	int tuoimax=0;
	int vitri;
	for (int i=1;i<=n;i++){
		if(tuoimax<(2022-sv[i].ngaysinh.nam)){
			tuoimax=2022-sv[i].ngaysinh.nam;
			vitri=i;
		}
	}
	printf("\nSinh vien  %s co tuoi max la %d.",sv[vitri].ten,tuoimax);
}
//in danh sach sinh vien theo diem tang dan 
void sapxeptheodiemtb (struct SinhVien sv[],int n){
	struct SinhVien tam;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if(((sv[i].diemmon1+sv[i].diemmon2
		   +sv[i].diemmon3)/3)<((sv[j].diemmon1+sv[j].diemmon2
		   +sv[j].diemmon3)/3))
			{
				tam=sv[i];
				sv[i]=sv[j];
				sv[j]=tam;
			}
		}
	}
	printf("\nDanh sach sinh vien co diem TB tang dan la :");
	for (int i=1;i<=n;i++){
		printf("\n%s",sv[i].ten);
	}
}
void theomalop(struct SinhVien sv[],int n,char a[]){
	printf("\nCac sinh vien trong lop vua nhap :\n");
	for (int i=1;i<=n;i++){
		if (strcmp(a,sv[i].malop)==0){
			printf("%s\n",sv[i].ten);
		}
	}
}
// ta co the goi ham nhap nhung dac biet la phai nhap tham chieu,luc goi ham ta khong can goi ham tham chieu
void thongtinnhap(struct SinhVien sv[],int n,char ten1[]){
	for (int i=1;i<=n;i++){
	if(strcmp(sv[i].ten,ten1)==0){
	printf("ID:%d",sv[i].id);
	printf("\nTen Sinh Vien :%s",sv[i].ten);
	printf("\nMa Lop :%s",sv[i].malop);
	printf("\nGioi Tinh:%s",sv[i].gioitinh);
	printf("\nDiem mon 1:%f\nDiem mon2 :%f\nDiem mon 3:%f\n",sv[i].diemmon1,sv[i].diemmon2,sv[i].diemmon3);
	break;	
		}
	}
}
void xeploaihocsinh(struct SinhVien sv[],int n){
	float TB;
	int vitri;
	printf("\nDanh sach xep loai sinh vien la :\n");
	for(int i=1;i<=n;i++){
		TB=0;
		vitri=0;
		TB+=(sv[i].diemmon1+sv[i].diemmon2
		   +sv[i].diemmon3)/3;
		   vitri=i;
		   if(TB>=9){
		   	printf("\nSinh vien %s:GIOI!",sv[vitri].ten);
		   	continue;
		   }
		   if(TB>=6.5 && TB<9){
		   	printf("\nSinh vien %s:KHA!",sv[vitri].ten);
		   	continue;
		   	
		   }
		   else{
		   	printf("\nSinh Vien %s:TRUNG BINH!",sv[vitri].ten);
		   	continue;
		   }	
	}
}
void nhapPhimBatKy(){
		printf("\nNhap phim bat ky de tiep tuc!");
        getch();
    }
int main(){
	int n;
	struct SinhVien sv[100];
	int chon;
	do{
		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tMENU");
		printf("\n\t\t\t1-Nhap thong tin sinh vien .");
		printf("\n\t\t\t2-In thong tin sinh vien .");
		printf("\n\t\t\t3-In thong tin sinh vien theo ten nhap.");
		printf("\n\t\t\t4-Sinh vien cua lop vua nhap : .");
		printf("\n\t\t\t5-Tinh tuoi cac sinh vien .");
		printf("\n\t\t\t6-Tinh diem trung binh cac sinh vien.");
		printf("\n\t\t\t7-Danh sach sinh vien theo diem trung binh tang dan.");
		printf("\n\t\t\t8-Tim diem trung binh lon nhat.");
		printf("\n\t\t\t9-Tim tuoi lon nhat  .");
		printf("\n\t\t\t10-Danh sach xep loai học sinh .");
		printf("\n\t\t\t11-Danh sach sinh vien theo gioi tinh .");
		printf("\n\t\t\t12-Thoat .");
		printf("\nVui long nhap tuy chon:");
		scanf("%d",&chon);
	switch(chon){
		case 1:
		        printf("\n\t\tVui long nhap so luong sinh vien:");
		        scanf("%d",&n);
				NhapSV(sv,n);
				nhapPhimBatKy();
				break;
		case 2:
			    inSinhVien(sv,n);
		        nhapPhimBatKy();
		        break;
		case 3:
		        
		        char ten1[30];
	            printf("Nhap ten kiem tra:\n");
            	fflush(stdin);
                fgets(ten1,sizeof(ten1),stdin);
	            thongtinnhap(sv,n,ten1);
	            nhapPhimBatKy();
	            break;
	    case 4:
	    	    char lop[30];
                fflush(stdin);
          	    printf("\nNhap lop can in sinh vien :");
	            fgets(lop,sizeof(lop),stdin);
	            theomalop(sv,n,lop);
	            break;
	    case 5:
	    		tinhtuoi(sv,n);
	    		nhapPhimBatKy();
	    		break;
	    case 6:
	    		diemTB(sv,n);
	    		nhapPhimBatKy();
	    		break;
	    case 7:
	    	sapxeptheodiemtb(sv,n);
	    	nhapPhimBatKy();
	    	break;
	    case 8:
	    	maxTB(sv,n);
	    	nhapPhimBatKy();
	    	break;
	    case 9:
	    	tuoimax(sv,n);
	    	nhapPhimBatKy();
	    	break;
	    case 10:
	    	xeploaihocsinh(sv,n);
	    	nhapPhimBatKy();
	    	break;
	    case 11:
	    	xeploaihocsinh(sv,n);
	    	nhapPhimBatKy();
	    	break;
	    default :
	    	char gt[5];
            fflush(stdin);
            printf("\nNhap gioi tinh kiem tra:");
            fgets(gt,sizeof(gt),stdin);
            gioitinh(sv,n,gt);
  	    	nhapPhimBatKy();
  	    	break;
  	    }
	    	
	}  
	while (n!=0);
  return 0;
}






















