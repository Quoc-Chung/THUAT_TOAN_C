#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// yêu cầu lấy kết quả từ file  tổng hợp 1 chiều 
// lưu kết quả của bài vào file kết quả tổng hợp một chiều 
// kiem tra nguyen to 
int nguyento(int n){
	if(n<2){
		return 0;
	}
	else{
	for (int i=2;i<=sqrt(n);i++){
		if(n%i==0)
		return 0;
	}
}
	return 1;
}
void nhapmang(int a[],int &n){
	printf("\nNhap so n:");
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
// không can nhap n=mang nua vi bay gio ta phai lam sao de lay duoc test ra tu file 
void inmang(int a[],int n){
printf("Mang in ra la :\n");
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}
void tongmang(int a[],int &n){
	int tong =0;
	for (int i=1;i<=n;i++){
		tong+=a[i];
	}
	printf("\n%d",tong);
}
void maxmang(int a[],int &n){
	int max=0;
	for (int i=1;i<=n;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	printf("\n%d",max);
}
void minmang(int a[],int &n){
	int min=a[0];
	for (int i=1;i<=n;i++){
		if(min>a[i]){
			min=a[i];
		}
	}
	printf("\n%d",min);
}
void tongsochan (int a[],int &n){
	int tong=0;
	for (int i=1;i<=n;i++){
		tong+=a[i];
	}
	printf("\n%d",tong);
}
void sapxeptang (int a[],int &n){
	int sapxep;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if(a[i]<a[j]){
				sapxep=a[i];
				a[i]=a[j];
				a[j]=sapxep;
				}
			}
	}
	printf("\n");
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}
void ghi_ket_qua_vao_file_doc(int a[],int n,char duongdan[]){
	    nhapmang(a,n);
    	FILE *f;
    	f = fopen(duongdan,"w");// file funcstion read result
    	if(f==NULL){
    		printf("\nKhong trich xuat duoc ket qua");
    		exit(1);
		  }
		// đọc sô n
		fprintf(f,"%d",n);
		fprintf(f,"\n");
		// đọc mảng 
		for (int i=1;i<=n;i++){
			fprintf(f,"%d ",a[i]);
	        	}
		// close file
		fclose(f);
}
void lay_ket_qua_tu_file_doc(int a[],int &n,char duongdan[]){
    	FILE *f;
    	f = fopen(duongdan,"r");// file funcstion read result
    	if(f==NULL){
    		printf("\nKhong trich xuat duoc ket qua");
    		exit(1);
		  }
		// đọc sô n
		fscanf(f,"%d",&n);
		// đọc mảng 
		for (int i=1;i<=n;i++){
			fscanf(f,"%d",&a[i]);
	        	}
		// close file
		fclose(f);
}
int main(){
	int n;
	int *a=(int*) malloc (n*sizeof(int));// phải cấp phát bộ nhớ độngcho mảng 1 chiều thì mới có thể truyền file test vào  đúng  
    char duongdan[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\tonghop1chieu.txt";// trích xuất test
    //ghi_ket_qua_vao_file_doc(a,n,duongdan);
    lay_ket_qua_tu_file_doc(a,n,duongdan);
    //char duongdan1[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\ketqua_tonghop1chieu.txt";
    inmang(a,n);
    tongmang(a,n);
    maxmang(a,n);
    minmang(a,n);
    tongsochan(a,n);
    sapxeptang(a,n);
	return 0;
}
