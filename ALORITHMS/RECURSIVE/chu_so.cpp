//Viết hàm tính tổng các chữ số chẵn của số nguyên n.
//Viết hàm tính tổng các chữ số lẻ của số nguyên n.
// Viết hàm tính tích các chữ số của số nguyên n.
//Viết hàm đếm số lượng chữ số lẻ trong mảng.
 //Viết hàm tính tổng các số chẵn trong mảng
// Viết hàm tính tổng các chữ số lẻ trong mảng
#include <stdio.h>
#include <math.h>
//Kiểm tra xem số nguyên dương n có chứa toàn chữ số lẻ,đúng in ra 1,sai in ra 0.
// nguyen lí :Nếu ta cứ giảm dần số n và không thấy xuất hiện số chãn thì hàm cứ tiếp tục mà không in ra gì 
// và cứ tiếp tục giảm nếu không thấy chãn thì cả hàm sẽ mang giá trị true khi n==0 và hàm kết thúc .
bool kiemtrale(int n){
	if(n==0){
		return true;	
}
	if((n%10)%2==0){// nếu nó xuất hiện một số chãn thì bài trả về false 
	//câu lệnh này chỉ thưc hiện khi có xuất hiện số chãn 
		return false;
	}
	return kiemtrale(n/10);// giảm đi một chữ số 
}
//Kiểm tra xem số nguyên dương n có chứa toàn chữ số chẵn, nếu đúng in ra 1,nguoc lai in ra 0;
bool kiemtrachan(int n){
	// toàn chãn thi hàm sẽ trả về giá trị true khi 
	if((n%10)%2!=0){// xuat hiện số lẻ hàm mang giá trị false 
		return false;
	}
	return kiemtrachan(n/10);
}
//Viết hàm tính tổng các chữ số chẵn của số nguyên n.
int tongsochan(int n){
	int tong=0;
	while (n>0){
		if((n%10)%2==0){
			tong+=n%10;
		}
		n/=10;
	}
	return tong;
}
// dequy tong so chan
static int sum = 0;// khai bao bien truoc khi khoi tao mot ham 
int tinhtong(int n) {
 if (n == 0) {
    return sum;
    }
 if ((n%10) % 2 == 0) sum += (n%10);
 return tinhtong(n/10);
} 
int dequychan(int n){
     if (n==0)// nếu số n nhỏ hơn 10 và số n là so chan thi giá trị chinh bang n
        return n; 
    
     if((n%10)%2==0)
     	  return n%10;dequychan(n/10);	
	
  }
int main (){
	int n;
	printf("\nNhap n:");
	scanf("%d",&n);
//	if(kiemtrale(n)){
//		printf("1");
//	}
//	else {
//		printf("0");
//	}
printf("\nTong so chan :%d",tongsochan(n));
//printf("\nDe quy tong chan bang :%d",tinhtong(n));
//printf("\nDe quy tong chan bang :%d",dequychan(n));	
	return 0;
}

