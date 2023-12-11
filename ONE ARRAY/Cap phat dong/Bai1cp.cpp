#include<stdio.h>
#include<math.h>
int n;
float *a;
int  nhap(float **a){//con trỏ cấp hai trỏ đến một con trỏ mảng  
	printf("\nNhap n:");
	scanf("%d",&n);
	*a=(float * )malloc(n*sizeof(float));
	  if (*a == NULL) {
        printf("Khong the cap phat bo nho!");
        return 0;
    }
	for(int i=0;i<n;i++){
		scanf("%f",(*a+i));
	}
	return n;
	
}
void in(float *a,int n){
	printf("\nMang in ra  la  :");
	for(int i=0;i<n;i++){
		printf("%.1f ",*(a+i));
	}
}
float MaxDuong(int n, float *a, float *max){
	for(int i=0;i<n;i++){
		if(*max < *(a+i)){
			*max=*(a+i);
		}
	}
	if(*max<0){
		return 0;
	}
	else{
		return *max;
	}	
}
int Fibo(int n, float *a){
	int flag=0;
	for(int i=2;i<=n-1;i++){
		if(a[i]!=(a[i-1]+a[i-2])){
			return 0;
			break;
		}
	}
	return 1;
}
// Viết hàm để tạo các mục lựa chọn (menu) sau đó tạo hàm main thực hiện các thao tác:
//- Mẫu hàm : int Menu();
//- Hàm trả về giá trị menu nếu được chọn trong [1…5]
//1. Nhập dãy
//2. Xuất dãy
//3. Tìm max dương
//4. Kiểm tra tính Fibonacci
//5. Thoát
int Menu(){
		int chon;
	do{

	printf("\n1. Nhap day");
	printf("\n2. Xuat day");
	printf("\n3. Tim max duong");
	printf("\n4. Kiem tra tinh Fibonacci");
	printf("\n5. Thoat");
	printf("\nChon:");	
	scanf("%d",&chon);
	  	switch(chon){
		case 1:{
			int size = nhap(&a);
			break;
		}
		case 2:{
			in(a,n);
			break;
		}
		case 3:{
			float max;	
	       printf("\nMAX LA:%.2f",MaxDuong(n,a,&max));
			break;
		}
		default:{
			printf("%d",Fibo(n,a));
			break;
		}
	}	
	}while(chon!=5);
}
int main(){
	Menu();
	
}

