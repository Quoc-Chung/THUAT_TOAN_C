#include <stdio.h>
#include <math.h>
typedef struct student{
int masinhvien;
char tensinhvien[40];
int khoa;	
};
int main (){
	// khoi tao doi tuong thuoc kieu student 
	student a;// khai bao bien struct
	scanf ("%d",&a.masinhvien);
	fflush(stdin);// xoa sach bo nho trong ma den 
	printf("%d",a.masinhvien);
	
	// day la kieu char nen khai bao dung get
    gets(a.tensinhvien);
    
	scanf("%d",&a.khoa);
	printf ("%d",a.khoa); 

	
}
