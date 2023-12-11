#include <stdio.h>
#include <math.h>
// nhập xuất mảng  
void nhap_n(int &n){
	printf("\nNhap vao n:");
	scanf("%d",&n);
}
// nhập mảng(khởi tạo chỉ số )
void nhap_mang(int a[],int n,int i=0){
	if(i==n){
		return ;
	}
	printf("Nhap vao a[%d]:",i);
	scanf("%d",&a[i]);
	return nhap_mang(a,n,i+1);
}
void nhap_mang_khac(int a[],int n){
	if(n==0){
		return;
	}
	printf("\nNhap a[%d]:",n);
	scanf("%d",&a[n]);
	return nhap_mang_khac(a,n-1);
}
// xuất mảng 
void xuat_mang(int a[],int n,int i=0){
	if(i==n){
		return;
	}
	printf("%d ",a[i]);
	 return xuat_mang(a,n,i+1);
}
void xuat_mang_khac(int a[],int n){
	if(n==1){
		return;
	}
	printf("%d ",a[n]);
	return xuat_mang(a,n-1);
}
// tổng mảng 
int tong_mang(int a[],int n,int i=0,int tong = 0){
	if(i==n){
		return tong;
	}
	return  tong_mang(a,n,i+1,tong+=a[i]);
}
// tìm  max  mảng 
int min_mang(int a[] , int n,int i=0){
	int min=a[0];
	// 1  2  3  4  5 
	if(i>n){
		return min;
	}
	else {
		min>a[i]?a[i]:min;
		return min_mang(a,n,i+1);
	}
}
int  max_mang(int a[],int n,int i=1,int max=-100000){
	if(i>n){
		return max;
	}
	else {
		return max_mang(a,n,i+1,max<a[i]?a[i]:max);
	}
}
void sap_xep_tang_dan(int a[],int n){
	
}
void tim_kiem_nhi_phan(int a[],int n,int &x){
	printf("\nNhap gia tri x tim kiem :");
	scanf("%d",&x);
	int left =0,right=n-1;
	int mid;
	int vitri=0;
	int i=0;
	while (left<=right){
		mid=(left+right)/2;
		if(x==a[mid]){
			vitri=mid;
			break;
		}
		else if(x>a[mid]){
			left=mid+1;
		}
		else {
			right=mid-1;
		}
	}
	if(vitri==0){
		printf("\nGia tri x khong co trong mang ");
	}
	else{
			printf("\nX xuat hien o vi tri %d trong mang.",vitri+1);
	}

}
// đệ quy tìm kiếm nhị phân 
int binary_search(int a[],int n,int left,int right,int x){
//    if(left>right){
//    	return -1;// không tìm thấy x
//	}
//	else {
	int	mid=(left+right)/ 2;
		if(x > a[mid]){
			return binary_search(a,n,mid+1,right,x);
		}
		else {
			return binary_search(a,n,left,mid-1,x);
		}
//	}
}
int main (){
	int n;
	nhap_n(n);
	
	int x;
	printf("\nNhap gia tri x tim kiem:");
	scanf("%d",&x);
	
	int *a=(int *) malloc (n*sizeof(int));
	
 	nhap_mang(a,n);
//	nhap_mang_khac(a,n);


	xuat_mang(a,n);
	printf("\n");
	
	
   //xuat_mang_khac(a,n);
   int tong=tong_mang(a,n);
   printf("\nTong cua mang la :%d",tong);
   
   
   int min =min_mang(a,n);
   printf("\nGia tri min cua mang :%d",min);
   
   
   int max = max_mang(a,n);
    printf("\nGia tri max cua mang:%d",max);
    
    
   // tim_kiem_nhi_phan(a,n,x);
   
   
   int vitri=binary_search(a,n,0,n-1,x);
   	printf("\nX xuat hien tai vi tri :%d",vitri);
//   }
   
	free(a);
}