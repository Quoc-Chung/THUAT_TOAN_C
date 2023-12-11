#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void nhapmang(int *a,int n){
	for (int i=1;i<=n;i++){
		printf("\na[%d]=",i);
		scanf("%d",(a+i));
	}
}
void inmang (int a,int n,int x){
		for (int i=1;i<=(n+x);i++){
		printf("%d ",*(a+i));
}
}
int main (){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
// int a[100] nhu nay goi la cap phat tinh 
	int *a;//gọi con trỏ hay chính là tên  mảng động tí nữa sẽ cấp phát 
	a=(int *)malloc(n*sizeof(int));// cáp phát động :ép kiểu con trỏ + malloc (soluong*sizeof(kiểu dữ liệu mảng)
	if(a==NULL){
		printf("\nCap phat dong bi loi");
		exit(1);// return ;
	}
   nhapmang(a,n);// sở dĩ ta truyền con trỏ mà lúc gọi khong gọi địa chỉ do ở đây ta đang làm với mảng 
	// in mang  
	printf("\nMang vua nhap khi chưa cấp phát thêm :\n");
	inmang(a,n);
	int x;
	printf("\nSo phan tu cap phat them :");
	scanf("%d",&x);
   int  *a =(int*)realloc(a,x*sizeof(int));// hàm cấp phát bộ nhớ thêm 
	printf("\nNhap mang vua cap phat :\n");
	for (int i=n+1;i<=(n+x);i++){
			printf("\na[%d]=",i);
		    scanf("%d",(a+i));
	}
		printf("\nMang ban dau voi mang vua duoc cap phat la :\n");
		//gop mang
	for (int i=1;i<=(n+x);i++){
		
		printf("%d ",*(a+i));
}

	free(a);
	// csp phat them bo  
}