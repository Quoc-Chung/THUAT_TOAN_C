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
 struct   date ngaysinh;//  tuc no se co 3 dac ta cho ngay thang nam voi kieu cau truc vua dinh nghia 
	float diemmon1;
	float diemmon2;
	float diemmon3;
	float DiemTB;
	char hocluc[10];
};
void  xoaxuongdong(char c[]){
	size_t len =strlen(c);
	if(c[len-1]='\n'){
		c[len-1]='\t';
	}
}
void input(struct  SinhVien sv){
	printf("Nhap ID:");
	scanf("%d",&sv.id);
	//scanf("\n");// co dong lenh nay de tranh viec troi lenh cua cac ham gets phia sau
	printf("\nNhap Ten Sinh Vien :");
    fflush(stdin);
    fgets(sv.ten,sizeof(sv.ten),stdin );
	printf("\nNhap Ten Lop :");
    fflush(stdin);
    fgets(sv.malop,sizeof(sv.malop),stdin );
	printf("\nNhap Gioi Tinh:");
	fflush(stdin);
	fgets(sv.gioitinh,sizeof(sv.gioitinh),stdin);
    printf("\nNhap ngay sinh:");
    scanf("%d%d%d",&sv.ngaysinh.ngay,&sv.ngaysinh.thang,&sv.ngaysinh.nam);
  	printf("\nNhap Diem mon 1,mon 2,mon 3:");
    scanf("%f %f %f",&sv.diemmon1,&sv.diemmon2,&sv.diemmon3);
}
void NhapSV(struct SinhVien sv[],int n){
	for (int i=1;i<=n;i++){
	input(sv[i]);
}
}
void  output(struct SinhVien sv){
	printf("ID:%d",sv.id);
	printf("\nTen Sinh Vien :%s",sv.ten);
	printf("\n Ma Lop :%s",sv.malop);
	printf("\n Gioi Tinh:%s",sv.gioitinh);
	printf("\n Diem mon 1:%f\nDiem mon2 :%f\nDiem mon 3:%f\n",sv.diemmon1,sv.diemmon2,sv.diemmon3);

}
void inSinhVien (struct SinhVien sv[],int n){
	for (int i=1;i<=n;i++){
	printf("\nSinh vien thu nhat la :%d",i);
    output(sv[i]);
}
}
void indangbang (struct SinhVien sv[],int &n){
	printf("\n\t\t\tBANG THONG TIN SINH VIEN \n");
	printf("\n%-3s %-20s %-6s %-8s %-8s %-8s %-8s\n ","ID","Ten Sinh VIen","Ma lop","Gioi Tinh","Diem mon 1","Diem mon 2","Diem mon 3");
	for (int i=1;i<=n;i++){
		xoaxuongdong(sv[i].ten);xoaxuongdong (sv[i].malop);xoaxuongdong(sv[i].gioitinh);
		printf("\n%-3d %-20s %-6s %-8s %-8.2f %-8.2f %-8.2f",sv[i].id,sv[i].ten,sv[i].malop,sv[i].gioitinh,sv[i].diemmon1,sv[i].diemmon2,sv[i].diemmon3);
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
void themsv(struct SinhVien sv[],int &n,int vitrithem){
    for (int i=n+1;i>=vitrithem+1;i--){
        sv[i]=sv[i-1];
    }
    input(sv[vitrithem]);
	 n++;
}
void xoabatki(struct SinhVien sv[],int &n,int vitrixoa){
	for (int i=vitrixoa;i<=n;i++){
		sv[i]=sv[i+1];
	}
	n--;
}
void nhapPhimBatKy(){
		printf("\nNhap phim bat ky de tiep tuc!");
        getch();
    }
int main(){
	int n;
    int vitrithem,vitrixoa;
     char ten1[30];
     char gt[5];
     char lop[30];
	struct SinhVien sv[100];
	int chon;
	do{
        printf("\n\t\t\t_____________________________________________");
		printf("\n\t\t\t|1-Nhap thong tin sinh vien .                |");
		printf("\n\t\t\t|2.In thong tin dang bang .                  |");
		printf("\n\t\t\t|3-In thong tin sinh vien theo ten nhap.     |");
		printf("\n\t\t\t|5-Tinh tuoi cac sinh vien .                 |");
		printf("\n\t\t\t|6-Tinh diem trung binh cac sinh vien.       |");
		printf("\n\t\t\t|7-Danh sach  theo diem tb tang dan.         |");
		printf("\n\t\t\t|8-Tim diem trung binh lon nhat.             |");
		printf("\n\t\t\t|9-Tim tuoi lon nhat  .                      |");
		printf("\n\t\t\t|10-Danh sach xep loai hoc sinh .            |");
		printf("\n\t\t\t|11-Danh sach sinh vien theo gioi tinh .     |");
		printf("\n\t\t\t|12-Them sinh vien bat ki .                  |");
		printf("\n\t\t\t|13-Xoa sinh vien bat ki .                   |");
		printf("\n\t\t\t|12-Thoat .                                  |");
        printf("\n\t\t\t|____________________________________________|");
		printf("\nVui long nhap tuy chon: ");
		scanf("%d",&chon);
	switch(chon){
		case 1:
		        printf("\n\t\tVui long nhap so luong sinh vien:");
		        scanf("%d",&n);
				NhapSV(sv,n);
				indangbang (sv,n);
				nhapPhimBatKy();
				break;
		case 2:
			    inSinhVien(sv,n);
		        nhapPhimBatKy();
		        break;
		case 3:  
		       
	            printf("Nhap ten kiem tra:\n");
            	fflush(stdin);
                fgets(ten1,sizeof(ten1),stdin);
	            thongtinnhap(sv,n,ten1);
	            nhapPhimBatKy();
	            break;
	    case 4:
	    	    
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
		case 12:
		    printf("\nNhap vi tri them :");
		    scanf("\n%d",&vitrithem);
		    themsv(sv,n,vitrithem);
		    nhapPhimBatKy();
		    break;
		case 13:
		    printf("\nNhap vi tri xoa sinh vien :");
		    scanf("\n%d",&vitrixoa);
		    xoabatki(sv,n,vitrixoa);
			nhapPhimBatKy();
			break;
	    default :
	    	
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






















