#include<stdio.h>
#include<math.h>
#include<string.h>
struct sv{
 char hoten[50];
 float dtoan,dli,dhoa;
 }sv[100];
 main(){
 //nhap thong tin cau truc
 int i,n;
 do{
 	printf("nhap n: ");scanf("%d",&n);
 }while(n<=0);
 for(i=1;i<=n;i++){
 printf("nhap sinhvien %d: ",i);
 fflush(stdin);gets(sv[i].hoten);
 printf("nhap diemtoan: ");scanf("%f",&sv[i].dtoan);
 printf("nhap diemli: ");scanf("%f",&sv[i].dli);
 printf("nhap diemhoa: ");scanf("%f",&sv[i].dhoa);
 }
 //in thong tin cau truc
 for(i=1;i<=n;i++){
 	printf("ten sinh vien thu %d: %s",i,sv[i].hoten);
 	printf("diem toan: %.2f\ndiem li: %.2f\ndiem hoa: %.2f",sv[i].dtoan,sv[i].dli,sv[i].dhoa);printf("\n");
 }
//in ra danh sach thi sinh bi thi lai neu diem cua 1 trong 3 mon nho hon 5
 for(i=1;i<=n;i++){
 	if(sv[i].dtoan<5 || sv[i].dli<5 || sv[i].dhoa<5){
 		printf("sinh vien thi lai thu %d: %s ",i,sv[i].hoten);
 	}
 	printf("\n");
 }
 }
