#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
 struct HangHoa{
    char TenHang[30];
    int SoLuong;
    char LoaiHang[20];
};
// Ham nhap mot hang hoa tu ban phim
void Nhap1(HangHoa &hang) {
    printf("Nhap ten hang hoa: ");
    fflush(stdin);
    gets(hang.TenHang);
    printf("Nhap so luong: ");
    scanf("%d",&hang.SoLuong);
    printf("Nhap loai hang: ");
    fflush(stdin);
    gets(hang.LoaiHang);
}
// Ham nhap mot danh sach n hang hoa tu ban phim
void NhapDanhSachHangHoa(HangHoa ds[], int n) {
    for (int i =0;i<n;i++) {
        printf("Nhap hang hoa thu %d:\n",i + 1);
        Nhap1(ds[i]);
    }
}
// Ham xuat mot hang hoa ra file van ban
void XuatHangHoa(HangHoa ds[],int n){
	FILE *f;
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\bai2c4.txt";
	f=fopen(duong_dan,"w");
	
	if(f==NULL){
		printf("\nKhong mo duoc file.");
		exit(1);
	}
	for(int i=0;i<n;i++){
    fprintf(f,"%s %d %s\n",ds[i].TenHang,ds[i].SoLuong,ds[i].LoaiHang);
}
}
void TinhTongSoLuong(HangHoa  ds[],int n) {
    int tong =0;
    for (int i =0;i< n;i++) {
        tong += ds[i].SoLuong;
    }
   printf("\nTong so luong  la  :%d",tong);
}
void TimKiemTenHang(HangHoa ds[], int n){
	char ten_hang[100];
	printf("\nNhap ten tim kiem:");
	gets(ten_hang);
	int flag=0;
    for (int i = 0;i<n;i++) {
        if (strcmp(ds[i].TenHang,ten_hang)==0) {
            printf("\nTim thay:");
            flag=1;
            break;
        }
    }
    if(flag==0){
    	printf("\nKhong tim thay.");
	}
   
}
void sap_xep(HangHoa ds[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(ds[i].TenHang, ds[j].TenHang) > 0) {
                HangHoa tmp = ds[i];
                ds[i] = ds[j];
                ds[j] = tmp;
            }
        }
    }
    FILE *f1;
    
    f1 = fopen("C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\HangHoa.bin", "wb");
    if (f1 == NULL) {
        printf("\nKhong mo duoc file.");
        exit(1);
    }
    fwrite(&n, sizeof(int), 1, f1); 
    for (int i = 0; i < n; i++) {
        if (fwrite(&ds[i], sizeof(HangHoa), 1, f1) != 1) {
            printf("\nKhong ghi duoc du lieu vao file.");
            exit(1);
        }
    }
    fclose(f1);
    printf("\nDa xuat danh sach hang hoa vao file thanh cong!");
}
void DocTuFile(HangHoa ds[], int *n) {
    FILE *f = fopen("C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\HangHoa.bin", "rb");
    if (f == NULL) {
        printf("\nKhong mo duoc file.");
        exit(1);
    }
    fread(n, sizeof(int), 1, f);
    for (int i = 0; i < *n; i++) {
        fread(&ds[i], sizeof(HangHoa), 1, f);
    }
    fclose(f);
    printf("Danh sach hang hoa vua doc tu file:\n");
    for (int i = 0; i < *n; i++) {
        printf("Ten hang: %s - So luong: %d - Loai hang: %s\n", ds[i].TenHang, ds[i].SoLuong,ds[i].LoaiHang);
    }
}

int  main (){
	int n;
	printf("\nNhap n:");
	scanf("%d",&n);
	HangHoa ds[100];
	NhapDanhSachHangHoa(ds, n);
	XuatHangHoa(ds,n);
	TinhTongSoLuong(ds, n);
	TimKiemTenHang(ds, n);
	sap_xep(ds,n);
	DocTuFile(ds,&n);
	return 0;	
}

