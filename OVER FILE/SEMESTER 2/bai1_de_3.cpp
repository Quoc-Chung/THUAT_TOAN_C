#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100
// co the nhap ma tran bang cach nay 
void nhapmangvip(int a[][MAX],int &hang,int &cot){
	printf("\nNhap kich thuoc :");
	scanf("%d%d",&hang,&cot);
	for(int i=0;i<hang*cot;i++){
		printf("\na[%d][%d]:",i/cot,i%cot);
		scanf("%d",&a[i/cot][i%cot]);
	}
}
void inmangvip (int a[][MAX],int hang ,int cot){
	for (int i=0;i<hang*cot;i++){
		printf("%d ",a[i/cot][i%cot]);
		if((i+1)%cot==0){
			printf("\n");
		}
	}
}
void nhapmang(int a[][MAX],int &hang ,int &cot){
	printf("\nNhap kich thuoc :");
	scanf("%d%d",&hang,&cot);
	for (int i=0;i<hang;i++){
	    for (int j=0;j<cot;j++){
	    	printf("\na[%d][%d]:",i,j);
	    	scanf("%d",&a[i][j]);
		   }
	 }
}
void inmang(int a[][MAX],int hang,int cot){
	printf("\nMa tran in ra la :\n");
    for (int i=0;i<hang;i++){
	    for (int j=0;j<cot;j++){
	       	printf("%d ",a[i][j]);
		   }
		   printf("\n");
	  }
}
// hamf tinh trung binh cong cac so chan va chia ba du 1 
void trung_binh_cong(int a[][MAX],int hang ,int cot){
    int dem=0;
    int tong=0;
	for  (int i=0;i<hang ;i++){
	      for (int j=0;j<cot;j++){
	      	if(a[i][j]%2==0 && a[i][j]%3==1){
	      		dem++;
	      		tong+=a[i][j];
			  }
		  }
	}
	float s=(float)tong/dem;
	printf("\nGia tri trung binh cong  :%.2f",s);
}
void tong_tung_hang(int a[][MAX],int hang ,int cot){
	int tong;
	for (int i=0;i<hang;i++){
		tong=0;
		for (int j=0;j<cot;j++){
			tong+=a[i][j];
		}
		printf("%d\n",tong);
	}
}
void in_matran_vao_file(int a[][MAX],int hang,int cot){
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\inmatrande3.txt";
	FILE *f;
	f=fopen(duong_dan,"w");
	if(f==NULL){
		printf("\nLoi khong tao duoc file.");
		exit(1);
	}
	// ghi file vao ma tran
	fprintf(f,"%s","Ma tran vua nhap la :\n");
	for (int i=0;i<hang;i++){
		for (int j=0;j<cot;j++){
			fprintf(f,"%d ",a[i][j]);
		}
		fprintf(f,"\n");
	}
	// dong file
	fclose(f);
}

// nghĩa  là  mày  không khai báo  tham chiếu m và  n thì lúc nó đọc  ấy m và  n nó chỉ có  
//giá trị là 2 3 (chẳng hạn )  và  khi hàm  này kết  thúc nó sẽ trở  về giá trị ban đầu (có thể  là giá trị rác  
// hoặc  bằng  0 vì lúc đầu m chưa  khai báo )  ==> khi m đọc sang hàm  in thì nó  sẽ  nhận n,m là các giá trị rác ấy 
//Truyền tham chiếu thì  lúc  m lấy m ,n ra từ  file thì cái giá trị m,n lấy ra  từ  file đó sẽ được lưu lại và đọc sang 
// hàm  in thì nó  sẽ  không bị lỗi 
void lay_matrantu_file(int a[][MAX],int &hang,int &cot ){
	char duong_dan[100]="C:\\Users\\Admin\\Documents\\THUATTOANC\\WORD FILEC\\inmatrande3.txt";
	FILE *f;
	f=fopen(duong_dan,"r");// file  để đọc 
	if(f==NULL){
		printf("\nKhong the mo duoc file doc.");
		exit(1);
	}
	// đọc kích thước 
	fscanf(f,"%d",&hang);
	fscanf(f,"%d",&cot);
	for (int i=0;i<hang;i++){
		for (int j=0;j<cot;j++){
			fscanf(f,"%d",&a[i][j]);
		}
	}
	fclose(f);
}
//int main (){
//	int m,n;
//	int a[MAX][MAX];
//	nhapmangvip(a,m,n);
//	inmangvip(a,m,n);
//	trung_binh_cong(a,m,n);
//	in_matran_vao_file(a,m,n);
//	return 0;
//}
int main (){
	int m,n;
	int a[MAX][MAX];
	 lay_matrantu_file(a,m,n);
	inmangvip(a,m,n);
	trung_binh_cong(a,m,n);
	 return 0;
	
}

