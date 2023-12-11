#include <Stdio.h>
#include <math.h>
int tong_nomal(int n){
	int tong =0;
	for (int i=1;i<=n;i++){
		tong+=i;
	}
	return tong;
}
int recursive (int n){
	if(n==1){
		return n;
	}
	return n+recursive(n-1);
}
int recursive_tail(int n,int x=1){
      	if(n==1){
      		return x;
		  }
	// decreate so n đi cho 
	return recursive_tail(n-1,x+n);
}
// bài 740
int giaithua(int n){
	if(n==0){
		return 1;
	}
	return n*giaithua(n-1);
}
void tong_740(int n){
	int tong=0;
	while (n>=1){
		int tam=giaithua(n);
		tong+=tam;
		n--;
	}
	printf("%d",tong);
}
int recursive_749_tail(int n,int x=0){
	if(n==0){
		return x;
	}
	int gt=giaithua(n);
		return recursive_749_tail(n-1,x+=gt);;
}
// bài 746
float tinh_thuong(int n, int x) {
    float tong = 1;
    for (int i = 2; i <= 2 * n; i += 2) {
        tong += pow(x, i) / giaithua(i);
    }
    return tong;
}
//                   3     2       1
float de_quy_746(int n,int x,float y=1) {
    if (n==0){
        return y;
    }
    int gt=giaithua(2*n);
    y+=pow(x,2*n)/gt;
     return de_quy_746(n-1,x,y);
}
// tìm  ước lẻ lớn nhat của một số nguyên dương n 
void uoc_le_max(int n){
	int uoc_thoa_man=0;
	for (int i=n;i>=0;i--){
		if(n%i==0 && i%2!=0){
			uoc_thoa_man=i;
			break;
		}
	}
	printf("%d",uoc_thoa_man);
}
// dùng đệ quy
int uoc_le_max_1(int n){
	if(n%2!=0){
		return n;
	}
	else {
		return uoc_le_max_1(n/2);
	}
}
// de quy duoi 
float  de_quy_748(int n){
	if(n==1){
		return sqrt(2);
	}
	else {
		return sqrt(2+de_quy_748(n-1));
	}
}
// đệ quy và trả về 
//float de_quy_can(int n){
//	if(n==1){
//		return sqrt(n);
//	}
//	else {
//		return sqrt(n + de_quy_can(n-1));
//	}
//	
//}
float de_quy_can(int n){
    if(n==1){
        return sqrt(1);
    }
    else{
        float sum = sqrt(n + de_quy_can(n-1));
        for (int i = n-2; i >= 1; i--) {
            sum = sqrt(i + sum);
        }
        return sum;
    }
}
//float de_quy_can_tail(int n,float x=sqrt()){
//	if(n==1){
//		return 1;
//	}
//}
int main (){
//	int n;
//	scanf("%d",&n);
//	int tong=tong_nomal(n);
//	int tong_2=recursive(n);
//	int tong_3=recursive_tail(n);
//	printf("%d",tong);
//	printf("\n%d",tong_2);
//	printf("\n%d",tong_3);
//  tong_740(n);
//  int tong=recursive_749_tail(n);
//  printf("%d",tong);
//  tinh_thuong(3,2);
//  float tong=de_quy_746(3,2);
//  printf("\n%.2f",tong);
//    
//    int uoc=uoc_le_max_1(100);
//    printf("%d",uoc);

     float  dq= de_quy_can(4);
     printf("%.2f",dq);


    return 0;
	
}