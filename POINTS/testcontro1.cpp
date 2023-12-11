#include <stdio.h>
#include <math.h>
// lam nhu nay se khong thay doi duocc gia tri cua con trỏ
void swap(char *&x,char *&y){
	char *tmp;
    tmp =x;
    x=y;
    y=tmp;
}
void hoanvi(int *&a,int *&b){// nhu nay duoc gọ la truyentham chieu tuc la no se lam thay doi truc tiep 
// dia chi ma ta truyen vao ham 
// sau khi dia chi bi hoa doi thi gia tri tai dia chi do cung bi thay doi theo 
//    printf("\ndia chi a :%d",a);
//	printf("\ndia chi b:%d",b);
//	printf("\ndia chi &a:%d ",&a);// day chinh la dia chi moi cua con tro 
//	printf("\ndia chi &b:%d",&b);// day chinh la dia chi moi cua con tro 
	int tam=*a;
	*a=*b;
	*b=tam;
	printf("\ndia chi a :%d",a);
	printf("\ndia chi b:%d",b);
	printf("\ndia chi &a:%d ",&a);
	printf("\ndia chi &b:%d",&b);
}
// cach de ham hoa doi chay dung 
int main (){
	int m=5;
	int n=6;
	printf(" dia chi m:%d",&m);
	printf("\n dia chi n:%d",&n);
	int *ptr1=&m;// dia chỉ của con trỏ cũng giống như địa chỉ của biến mà con trỏ trỏ tới
	int *ptr2=&n;// địa chỉ của con trỏ cũng giống như địa chỉ của biến mà con trổ trỏ tới 
//	printf("\nDia chi con tro ptr1:%d",ptr1);
//	printf("\nDia chi con tro ptr2:%d",ptr2);
	printf("\nDia chi con tro &ptr1:%d",&ptr1);//day chinh la dia chi ma bien con tro tu sinh ra 
	printf("\nDia chi con tro &ptr2:%d",&ptr2);
	hoanvi(ptr1,ptr2);//ta truyen tham chieu la hai con tro voi dia chỉ cua hai so a và b nên
	//luc nay dia chi ma con trỏ thay doi trong ham chinh la dia chỉ của so a va so b nay 
	printf("\nsau khi goi ham :");
	printf("\nDia chi con tro ptr1:%d",ptr1);
	printf("\nDia chi con tro ptr2:%d",ptr2);
	printf("\nDia chi con tro &ptr1:%d",&ptr1);
	printf("\nDia chi con tro &ptr2:%d",&ptr2);
	printf("\nM=%d",m);
	printf("\nN=%d",n);
	return 0;
//	
//     char a[40]="Thu nhat";
//     char b[50]="Thu hai ";
//     printf("\nDay la khi chua co gi thay doi :\n");
//     printf("%s",a);
//     printf("\n%s",b);
//     char *s1=a;// con trỏ trỏ đén mảng kí tự a
//     char *s2=b;// con trỏ trỏ đến mảng kí tự b
//     printf("\nGia tri cua hai con tro truoc  khi chay ham hoan doi:\n");
//     printf("\n%s",s1);// s1 lúc nay dã bị hoan sang mang b
//     printf("\n%s",s2);// s2 luc nay bi hoan sang mang a
//     swap(s1,s2);
//     printf("\nGia tri cua hai con tro sau khi chay ham hoan doi swap :\n");
//     printf("%s",s1);
//     printf("\n%s",s2);
//     printf("\nGia tri cua a va b khi con tro thay doi :\n");
//     printf("\n%s",a);
//     printf("\n%s",b);
//  
//     return 0;

}
