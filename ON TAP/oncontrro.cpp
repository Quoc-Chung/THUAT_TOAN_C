#include <stdio.h>
#include <math.h>
void  nhapmang (int *a,int &n){
	printf("\nNhap n:");
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",(a+i));// con tro mang cua phan tu thu i;
	}
}
void inmang  (int *a,int n){
	for (int i=1;i<=n;i++){
		printf("%d ",*(a+i));
	}
}
int main (){
	int a=100;
	int n;
	printf("\nNhap n:");
	scanf("%d",&n);
	printf("\nDia chi cua bien a la :%d",&a);
	printf("\nGia tri cua bien a la :%d",a);
	char c[]="chung";
	int a[n];
	nhapmang(a,n);
	inmang(a,n);
	printf(" Chuoi vua nhap mang dia chi :%d",&c);
	printf("\nChuoi vua nhap mang gia tri :%s",c);
	int *p;
	p=&a;// con trỏ  trỏ đến giá trị của  biến a  
	printf("\nDia chi cua con tro p dang tro den:%d ",p);
	printf("\nGia tri con tro p đang tro den a la :%d",*p);
	void *pt;
	// con trỏ lúc này không mang kiểu giá trị nào hết nên khi ta để đặc tả bất kì thì nó sẽ
	// báo lỗi là điều đương nhiên .
	//==> cách giải quyết lúc này là ép kiểu cho con trỏ void sang kiểu mà nó đang trỏ tới 
	// nó có thể trỏ tới một biến khác hoặc  đến chính biên mà 
//	pt=&a;
    pt=p;// tức là con trỏ kiểu void đang cùng với con trỏ p thực hiện chung một nhiệm vụ là trỏ đến biến a
	printf("\n\t con tro P dang tro toi a ");
	printf("\nGía trị của con tro pt(con tro kieu void):%d",*((int*)pt));
	printf("\nGia tri cua con tro p:%d",*p);
	int **ptt;//khai bao con tro cap 2 tuc la con tro tro den con tro 
	ptt=&p;
	printf("\nDia chi cua ptt la :%d",ptt);
	printf("\nGia tri cua *ptt luc nay la :%d",*ptt);
	*p+=1;// tăng gia tri cua con tro len 1 đồng nghĩa với việc đia chỉ của
	printf("\nDia chi cua con tro p+1: %d", p);
	printf("\nGia tri cua con tro p+1:%d",*p);
	printf("\nGia tri cua bien a la :%d",a);
	
}