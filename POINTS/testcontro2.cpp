#include <stdio.h>
#include <math.h>
void nhap (int a,int b){
    printf("\nGia tri cua a ban dau la :%d",a);
	printf("\nGia tri cua b ban dau la :%d",b);
    a++;
    b++;
//     printf("\nGia tri cua a ban dau la :%d",a);
// 	printf("\nGia tri cua b ban dau la :%d",b);
}
void nhapbangcontro(int *x,int *y){
    (*x)++;
    (*y)++;
    printf("\nDia chi cua a khi truyen con tro la :%d",x);
	printf("\nDia chi cua b khi truyen con tro la :%d",y);
	printf("\nGia tri cua a ban dau la :%d",*x);
	printf("\nGia tri cua b ban dau la :%d",*y);
}
void nhapbangthamchieu (int &a,int &b){
	printf("\nDia chi cua &a:%d",&a);
	printf("\nDia chi cua &b:%d",&b);
	a++;
	b++;
}
void controthamchieu(int*&x,int *&y){// nhu nay nó sẽ tham chiếu trục tiếp đến biến địa chỉ mà nó truyền vào chứ không thông qua bất khì một bản sao nào cẩ 
	printf("\ndia chi cua *&x:%d",*&x);
	printf("\ndia chi cua *&y:%d",*&y);
	
	(*x)++;
	(*y)++;
	printf("\nGia tri cua a khi truyen con tro tham chieu  la :%d",*x);
	printf("\nGia tri cua b khi truyen con tro tham chieu la :%d",*y);
}
int main (){
	int a=3;
	int b=3;
	int *pt=&a;// luc nay gia tri ma con tro pt dang tro toi chinh la a
	int *pt1=&b;// giá trị mà con trỏ pt1 dang tro toi chinh la b
 	printf("\nDia chi  cua a ban dau la :%d",&a);
 	printf("\nDia chi  cua b ban dau la :%d",&b);
// 	printf("\nGia tri cua a ban dau la :%d",a);
// 	printf("\nGia tri cua b ban dau la :%d",b);
	// câu hỏi đặt ra lúc này là làm thế  nao để thay doi gia tri cua a va b khi ham ket thuc 
//	nhap(a,b);
//	// bản chat nhu nay la truyen tham trị tức là cái thay doi ơ day la thay doi tren cai ban sao cua hai bien nay chhu khong phai la thay doi tren hai bien 
//	printf("\nGia tri cua a  khi truyen tham tri la :%d",a);
//	printf("\nGia tri cua b  khi truyen tham tri la :%d",b);
//	// muon thay doi thi ta phai lam thay doi trục tiếp với địa chỉ chứa giá trị hai biến này
//	nhapbangcontro(&a,&b);
//	printf("\nGia tri cua a khi truyen con tro la :%d",a);
//	printf("\nGia tri cua b khi truyen con tro la :%d",b);
  nhapbangthamchieu(a,b);
  //controthamchieu(pt,pt1);
     printf("\nGia tri cua a khi truyen con tro la :%d",a);
printf("\nGia tri cua b khi truyen con tro la :%d",b);
   
	
}
//hàm tăng giá trị số nguyên truyền vào
//void inc(int *x)
//{
//    (*x)++;
//}
// 
//int n = 5;
// 
////Để gọi hàm, ta có thể khai báo một con trỏ rồi truyền vào hàm
//int *p = &n;
//inc(p);
// 
////Hoặc truyền trực tiếp địa chỉ của biến
//inc(&n);