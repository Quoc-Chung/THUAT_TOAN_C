
#include <stdio.h>
#include <math.h>
// Viết thuật toán tìm UCLN của hai số nguyên dương.
void ucln(int a,int b){
   if(a==0 || b==0){
   	printf("%d",a+b);
   }
   while(a!=b){
   	if(a>b){
   		a=a-b;
	   }
	else{
		b=b-a;
	}
}
	printf("%d",a);
}
void nhapmang(int x[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
}
void inmang(int x[],int n){
	for (int i=1;i<=n;i++){
		printf("%d ",x[i]);
	}
}
// Đếm xem có bao nhiêu bộ 2 số liên tiếp(a_i, a_(i+1)) mà có cùng tính chất chẵn lẻ mà số sau lớn số trước.
void kiemtra(int x[],int n){
	int dem=0;
	for (int i=1;i<n;i++){
		if((x[i]%2==0 && x[i+1]%2==0 && x[i] < x[i+1])
		||(x[i]%2==1 && x[i+1]%2==1 && x[i]<x[i+1])){
			dem++;
			 }			    
	}
	if(dem==0){
		printf("\nKhong co bo so thoa man");
	}
	if(dem>0){
	printf("\nSo bo so thoa man la :%d",dem);
}
}
void doixung(int x[],int n){
	int flag=0;
	int k=n;// đặt k=n để khi tiến hành giảm k thì n khong bị thay đổi dẫn đến vòng lặp bị sai 
 for(int i=1;i<=((n-1)/2);i++){ // chay kiem tra 2 so trong mang cug mot luc nen chỉ can chay mot nua  
  	 if(x[i]!=x[k]){// kiểm tra số đầu và số cuối nếu mà sai thì dừng lại luôn. 
  	 	flag++;
  	 	break;
	   }
	else if(x[i]==x[k]){
	 	k--;// nếu mà đúng thì ta sẽ tiến hành giảm số  k đi de kiem tra a[2] với a[k-1]== a[4]
	 }
  }
  if(flag==0){
  	printf("\nDay so doi xung .");
  }
  else {
  	printf("\nDay khong doi xung .");
  }
}
void daygiamdan(int x[],int n){
	int flag=0;
	for (int i=1;i<n;i++){
		if(x[i]<=x[i+1]){
			flag++;
			break;
		}
	}
	if(flag==0){
		printf("\nDay thuc su giam dan.");
	}
	if(flag>0){
		printf("\nDay khong gism dan.");
	}
}
float trungbinhcong(int x[],int n){
	int tong=0;
	for (int i=1;i<=n;i++){
		tong+=x[i];
	}
	return 1.0*(tong/n); 
}
// Đếm các số lớn hơn trung bình cộng của dãy
void demsolon(int x[],int n){
	int dem=0;
	float tb=trungbinhcong(x,n);
	printf("\nGia tri trung binh cong la :%.2f",tb);
	for (int i=1;i<=n;i++){
		if(x[i]>tb){
			dem++;
		}
	}
	printf("\nSo lon hon trung binh cong la:%d",dem);
}
int main (){
	int a,b;
	int n;
		do {
		printf("Nhap n:");
		scanf("%d",&n);
		if(n<1){
			printf("\nVui long nhap lai.");
		}
	}while (n<1);
	int x[n];
	nhapmang(x,n);
	//kiemtra(x,n);
	//scanf("%d%d",&a,&b);
	//ucln(a,b);
	//doixung(x,n);
	//daygiamdan(x,n);
    demsolon(x,n);
	return 0;
	
}