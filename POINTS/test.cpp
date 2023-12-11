//#include <stdio.h>
//#include <math.h>
//void tang1(int *a){//tang 1 da lam thay doi gia tri 
//    *(a)+=1;
//    printf("\nDia chi bien a trong  ham truyen con tro :%d",&a);
//    printf("\nGia tri cua bien a truyen con tro là :%d",*a);
//}
//void  tang2(int &a){// satisfy
//     a+=1;
//    printf("\nDia chi bien a trong  ham truyen tham chieu :%d",&a);
//    printf("\nGiá trị của bien a trong hàm truyen tham chieu là :%d",a);
//}
// void tang3(int *&a){
//     *a+=1;
//    printf("\nDia chi bien a trong  ham truyen tham chieu ket hop con tro :%d",&a);
//    printf("\nDau a:%d",a);
//    printf("\nGia tri cua *&a la :%d",*&a);
//    printf("\nGia tri cua bien a trong hàm truyen tham chieu ket hop con tro  là :%d",*a);
// }
//int main (){
//    int a=10;
//    printf("\nAdress by a ban dau :%d",&a);
//    printf("\nGia tri cua bien a ban dau :%d",a);
//   // tang1(&a);
//   // tang2(a);
//   int *x=&a;
//   printf("\nDia chi cua bien &x la :%d",&x);
//   tang3(x);
//    printf("\nGia tri cua a luc nay la :%d",a);
//    return 0;
//
//}
#include <stdio.h>
#include <math.h>
void tang3(int *&b){
    *b+=1;
    printf("\n*b=%d",*b);
    printf("\n&b=%d",&b);
    printf("\nb=%d",b);
    printf("\n*&b=%d",*&b);
}
int  main (){
    int a=10;
    printf("\n&a=%d",&a);
    int *x=&a;
    printf("\nGia tri cua moi chu x la :%d",x);
    printf("\n*x=%d",*x);
    printf("\nDia chi cua con tro x la :%d",&x);
    tang3(x);
    printf("\ndia chi a sau khi truyen ham :%d",&a);
    printf("\nDia chi cua con tro x sau khi truyen ham :%d",&x);
    return 0;
}