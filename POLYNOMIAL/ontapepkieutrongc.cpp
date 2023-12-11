//  on tap ep kieu voi viec tinh tong ,tìm giá trị biểu thức mảng 
// tôi thiểu của việc ép kiểu đối vơi những bài kiểu này là
//==> phải đưa được các phần tử mảng từ kiểu int sang kiểu số nguyên 
#include <stdio.h>
#include <math.h>
//Trong lập trình C, kết quả của phép cộng giữa một số thực và một số nguyên sẽ vẫn là một số thực.
// Trong C, kiểu dữ liệu của số thực là "float" hoặc "double", còn số nguyên là "int".
//  Nếu phép cộng diễn ra giữa hai biến có kiểu dữ liệu khác nhau, 
//biến có kiểu dữ liệu nhỏ hơn sẽ được ép sang kiểu dữ liệu lớn hơn trước khi phép cộng được thực hiện.
// ví dụ biến có kiểu dữ liệu int nhỏ hơn  được ép sang biến có kiểu dữ liệu lớn hơn 
void nhap(int a[],int n){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}
void inmang(int a[],int n){
	printf("\nMang ta vua nhap la :\n");
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}

void max1(int a[],int n){
	float max=-pow(10,5);
//	 biểu thức a[i] /i không được ép kiêu nên ket quả của hai sô nguyen này chia cho nhau sẽ là một  số nguyên 
//	 vi du :7/2 ra 3.5 nhưng vì là số nguyên nên kết quả sẽ trả về một số nguyên là ket qua la 3 
//	  muốn ra đúng bằng 3.5 thì phải tiến hành ép kieu ca hai so hoạc la ep kieu 1trong 2 số là đc
 //==>>> ưu tien ép kiểu cho các số  mang giá trị mảng 
	for (int i=1;i<=n;i++){
//		if(max<=((float)a[i]/i)){
//			max=(float)a[i]/i;
//		}
//	}



	// xét ví dụ duoi day van tra ve mot so nguyen vi no da tinh truoc trong ngoac hai sao nguyen rồi nên 
	// nên khi ta ép kieu nhu nay thi no chỉ chỉ ép từ số nguyên sang so thuc mà kết quả đúng nhất đã được làm 
	// tròn từ trong ngoặc rồi 
	// vi du :(float)(7/2)==(float)(3)==3.000000
//        if(max<=(float)(a[i]/i)){
//        	max=(float)(a[i]/i);
//		}
//	}



// sủa lai bên trên khi muon ep het tat ca :
         if(max<=((float)a[i]/(float)i)){
        	max=(float)a[i]/(float)i;
		}
	}
	
	
	printf("\nGia tri max cua bieu thuc la :%.2f",max);
}
void tinhtong1(int a[],int n){
	float tong =0;
	// dùng một biến trung gian bằng n để dùng bn đỡ bị sai 
	int d=n;
	d=(float)d;
	for (int i=1;i<=n;i++){
		tong+=((float)a[i]+d)/d;
		d--;
	}
	printf("\nTong vua tinh la :%.2f",tong);
}
// tinh tong so hai 
void tinhtong2(int a[],int n){
	float tong =0;
	for (int i=1;i<n;i++){
		tong+=((float)a[i]+(float)a[i+1])
	         /((float)a[i]-(float)a[i+1]);
	
	}
	printf("\nTong vua tinh la :%.2f",tong);
}

void giatrilonnhat (int a[],int n){
	float max=-pow(10,5);
	int d=n;
	// bai nay chung to chi can ep kieu của giá trị mảng 
	for (int i=1;i<=n;i++){
	     if(max<(float)a[i]/d){
	     	max=(float)a[i]/d;
		 }
		 d--;	
	}
	printf("\nGia tri lon nhat cua so can tinh la:%.2f",max);
}
// cach lam bai nay khac dung vong lap while 
void giatrilonnhat2(int a[],int n){
	float max=-pow(10,5);
    int d=n;
    printf("\n Gia tri cua d:%d",d);
    while (d>=1){
     for (int i=1;i<=n;i++){
			if(max<(float)a[i]/d){
				max=(float)a[i]/d;
			}
		d--;// phải dưa d vào trong vòng for và ở dưới lệnh ì thì bài mới ra kết quả dúng	
		}
		
	}
	printf("\nGia tri lon nhat can tim :%.2f",max);
}
void giatrilonnhat4(int a[],int n){
	int d=n;
	float max =-pow(10,5);
	for (int i=1;i<=n;i++){
	  if(max<((float)a[i]+i)/(d+i)){
	  	max=((float)a[i]+i)/(d+i);
	  }
	  d--;
	}
	printf("\nGia tri lon nhat can tim :%.2f",max);
}
// ket qua ma chia 0 thì sẽ ra một sô 1.#J
int main (){
	int n;
	scanf("%d",&n);
	int a[n];
	nhap(a,n);
	inmang(a,n);
//	max1(a,n);
//  tinhtong1(a,n);
//  tinhtong2(a,n);
    giatrilonnhat(a,n);
	giatrilonnhat2(a,n);
	giatrilonnhat4(a,n);
	return 0;
}