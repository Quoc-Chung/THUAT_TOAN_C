#include <stdio.h>
#include <math.h>
#include <string.h>
struct sach {
	int maS;
	char tenS[30];
	char tenTG[30];
	char loaiS[10];
	int namSB;
	int giatien;
	int soluong;
};
// function delete digit \n
void xoakituxuongdong(char x[]){
	// TITI\n\0=>> TITI\0\0
	size_t length=strlen(x);// Size_t 
	if(x[length-1]=='\n'){
		x[length-1]='\0';
	}
}
// input one book 
void nhap1cuonsach ( sach &s){
	printf("\nNhap ma sach :");
	scanf("%d",&s.maS);
	printf("\nNhap ten sach :");
	fflush(stdin);
	fgets(s.tenS,sizeof(s.tenS),stdin);
	printf("\nNhap ten tac gia :");
	fflush(stdin);
	fgets(s.tenTG,sizeof(s.tenTG),stdin);
	printf("\nNhap loai sach :");
	fflush(stdin);
	fgets(s.loaiS,sizeof(s.loaiS),stdin);
	printf("\nNam xuat ban :");
	scanf("%d",&s.namSB);
	printf("\nGia tien :");
	scanf("%d",&s.giatien);
	printf("\nSo luong sach :");
	scanf("%d",&s.soluong);
}
// in ra mot cuon sach 
void in1loaisach (sach s){
	printf("\nMa sach la :%d",s.maS);
	printf("\nTen cuon sach :%s",s.tenS);
	printf("\nTac gia :%s",s.tenTG);
	printf("\nLoai sach :%s",s.loaiS);
	printf("\nNam xuat ban :%d",s.namSB);
	printf("\nGia tien :%d",s.giatien);
	printf("\nSo luong sach nay :%d",s.soluong);
}
// ham nhap nhieu cuon sach 
void nhapnhieucuonsach(sach s[],int n){
	printf("\n\t\tNHAP CAC LOAI SACH BAN DAU \n");
	for (int i=1;i<=n;i++){
		printf("\nNhap cuon sach thu %d:\n",i);
		nhap1cuonsach(s[i]);
	}
}
// hàm in danh sach sinh vien duoi dang board  
void inbang(sach s[],int n){
	printf("\n\t\t\t\tDANH SACH CAC LOAI SACH BAN DAU \n");
	printf("Masach \t Tencuonsach \t Tentacgia \t Loaisach \t Namxuatban \t Gia tien \t\t Soluong\n");
	for (int i=1;i<=n;i++){
		 xoakituxuongdong(s[i].tenS);xoakituxuongdong(s[i].tenTG);xoakituxuongdong(s[i].loaiS);
		printf("%d \t %s \t %s \t %s \t %d \t\t %d \t\t %d\n",
		s[i].maS,
		s[i].tenS,
		s[i].tenTG,
		s[i].loaiS,
		s[i].namSB,
		s[i].giatien,
		s[i].soluong);
	}
}
// ham  nhap nhieu  cuon sach 
void innhieucuonsach(sach s[],int n){
	printf("\n\tt\t\t\tDANH SACH CAC LOAI SACH BAN DAU \n");
	for (int i=1;i<=n;i++){
		printf("\nCuon sach thu %d:\n",i);
		in1loaisach(s[i]);
	}
}
// add one book to initial array
void themvaodau(sach s[],int &n){
	printf("\nNhap quyen sach can them :\n");
	for (int i=n+1;i>=2;i--){
		s[i]=s[i-1];
	}
	n++;
	nhap1cuonsach(s[1]);
}
// add one book to finish array
void themvaocuoi (sach s[],int &n){
	printf("\nNhap thong tin quyen sach can them:\n");
     nhap1cuonsach(s[n+1]);
     n++;
}
// add one book any location to board array
void addanylocation (sach s[],int &n,int vitrithem){
	printf("\nThem mot cuon sach vao vi tri bat ki.");
	for (int i=n+1;i>=vitrithem+1;i--){
		s[i]=s[i-1];
	}
	nhap1cuonsach(s[vitrithem]);
}
//delete one book initial array
void xoadau(sach s[],int &n) {
	for (int i=1;i<=n-1;i++){
		s[i]=s[i+1];
	}
	n--;
}
//  delete one book final array 
void xoacuoi (sach s[],int &n){
	n--;
}
// delete any location array
void xoabatki(sach s[],int &n,int vitrixoa){
	for(int i=vitrixoa;i<=n-1;i++){
		s[i]=s[i+1];
	}
	n--;
}
// delete book publish(xuat ban ) before 2000
void xoasach(sach s[],int &n){
	int vitrixoa;
	for (int i=1;i<=n;i++){
		vitrixoa=0;
		if(s[i].namSB<2000){
		 vitrixoa=i;
		 xoabatki(s,n,vitrixoa);	
		}
	}
}
// count book have to price (gias tien less( nho hon ) 50000 and information its
void information(sach s[],int n){
	int count=0;
	int location;
	printf("The book under 50000 :\n");
	for (int i=1;i<=n;i++){
		location =0;
		if(s[i].giatien<50000){
			count++;
			 location =i;
			 printf("\n%s",s[location].tenS);
		}
		
	}
	printf("\nVay co tat ca %d sach co gia duoi 50000.",count);
}
// sum book money 
void sum(sach s[],int n){
	int tong=0;
	for (int i=1;i<=n;i++){
		tong+=s[i].giatien;
	}
	printf("\nSum book :%d",tong);
}
// there type book have price min 
void hienthi (sach s[],int n){
	printf("Ba loai sach co gia nho nhat la :");
	struct sach tam;
	for(int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++){
			if(s[i].giatien<s[j].giatien){
			 tam=s[i];
			 s[i]=s[j];
			 s[j]=tam;
			}
		}
	}
	for (int i=1;i<=3;i++){
		printf("%s\n",s[i].tenS);
	}
}
// arrange book theo monney ascending
void arrange (sach s[],int n){
	struct sach tam;
		for(int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++){
			if(s[i].giatien<s[j].giatien){
			 tam=s[i];
			 s[i]=s[j];
			 s[j]=tam;
			}
		}
	}
	printf("\nDanh sach sinh vien tang dan theo chieu :\n");
	for (int i=1;i<=n;i++){
		printf("\n%s",s[i].tenS);
	}
}
// search book by author(tac gia)
void search(sach s[],int n,char ten[]){
	int location;
	for (int i=1;i<=n;i++){
		location =0;
		if(stricmp(ten,s[i].tenTG)==0){// sao chi co mot phep
			location=i;
			printf("%s\n",s[location]);
		}
	}
}
//output type book the same type 
void hienthiloai(sach s[],int n){
	char d[10]="tu nhien";
	char e[10]="xa hoi";
	int vitri1,vitri2;
	printf("\nTen cac loai sach thuoc loai tu nhien :\n");
	for (int i=1;i<=n;i++){
		vitri1=0;
		if (stricmp(s[i].loaiS,d)==0){
			vitri1=i;
			printf("\n%s",s[i].loaiS);
		}
	}
	printf("\nTen cac loai sach thuoc loai xa hoi");
	for (int i=1;i<=n;i++){
		vitri2=0;
		if (stricmp(s[i].loaiS,e)==0){
			vitri2=i;
			printf("\n%s",s[i].loaiS);
		}
	}
}
void nhapPhimBatKy(){
		printf("\nNhap phim bat ky de tiep tuc!");
      getchar();// getch();
   }
int main (){
	int n,chon,vitrithem,vitrixoa;
	do {
	printf("Nhap n:");
	scanf("%d",&n);
	if(n<1){
		printf("\nVui long nhap lai \n");
	}
}while (n<1);
	sach s[100];
	nhapnhieucuonsach(s,n);
	do{
	printf("\n\t\t BANG CHUC NANG \n");
	printf("\n1--In ra bang danh sach ban dau.");
	printf("\n2--Them mot cuon sach vao dau danh sach va danh sach cap nhat .");
	printf("\n3--Them mot cuon sach vao cuoi danh sach va danh sach cap nhat ");
	printf("\n4--Them mot danh sach vao vi tri bat ki va danh sach cap nhat ");
	printf("\n5--Xoa quyen sach ban dau va cap nhat danh sach");
	printf("\n6--Xoa quyen sach o vi tri cuoi va danh sach cap nhat");
	printf("\n7--Xoa quyen sach o vi tri bat ki va cap nhat danh sach ");
	printf("\n8--Xoa cac cuon sach xuat ban truoc nam 2000");
	printf("\n9--Dem so luong sach co gia lon hon 50 nghin va in ra thong tin cua sach do");
	printf("\n10--Xuat cac loai sach theo loai");
	printf("\n11--Ba loai sach re nhat.");
	printf("\n12--Tim kiem sach theo tac gia ");
    printf("\n13--Sap xep sach tang dan theo gia tien");
    printf("\n14--Tong tat ca tien sach .");
	printf("\n15--Thoat.");
	printf("\nDai ca chon giup em mot con so :");
	scanf("%d",&chon);
		switch (chon){
			case 1:
			      inbang(s,n);
				  	nhapPhimBatKy();   break;
			case 2:
		       	themvaodau(s,n);
			    inbang(s,n);nhapPhimBatKy();
					            break;
			case 3:
			   themvaocuoi(s,n);
			   inbang(s,n);
			   	nhapPhimBatKy();    break;
			case 4:
			
			   printf("\nNhap vi tri them cuon sach");
               scanf("%d",&vitrithem);
	           addanylocation(s,n,vitrithem);
	           inbang(s,n); nhapPhimBatKy();
			                    break;
			case 5:
				xoadau(s,n);
				nhapPhimBatKy();break;
			case 6:
			    xoacuoi(s,n);
				nhapPhimBatKy();break;
			case 7:
		       printf("\nnhap vao vi tri xoa :");
	           scanf("%d",&vitrixoa);
               xoabatki(s,n,vitrixoa);
               inbang(s,n);    
			   	nhapPhimBatKy(); break;
			case 8:
				xoasach (s,n);
				inbang(s,n); 
				nhapPhimBatKy();break;
			case 9:
				information(s,n);
				nhapPhimBatKy();
				break;
			case 10:
			 hienthiloai(s,n);
			 	nhapPhimBatKy();
				 break;
			case 11:
				hienthi(s,n); break;
			case 12:
			char tacgia[30];
			fflush(stdin);
			fgets(tacgia,sizeof(tacgia),stdin);
			search(s,n,tacgia);     
				nhapPhimBatKy(); break;
			case 13:
				arrange(s,n); 
					nhapPhimBatKy();
					break;
		    case 14:
		    	sum(s,n); 
					nhapPhimBatKy();  
					break;
		    default:
		    	exit(1);
		    	break;
		    }				    
		}while (n!=0);
	}
	

