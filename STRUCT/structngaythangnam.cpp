#include <stdio.h>
#include <math.h>
struct Date {
	int day;
	int month;
	int year ;
};
void inputDate(struct  Date &d){// khai bao ra dia chi cua bien struct day đc gi la 
//khai bao tham chieu  tuc la tâ co the nhap gia tri trong ham luon 
	printf("Nhap vao ngay: ");
	scanf("%d", &d.day);
	printf("\nNhap vao thang :");
	scanf("%d",&d.month);
	printf("\nNhap vao nam :");
	scanf("%d", &d.year);
	
}
void printfDate(struct Date d){
	printf("%d/%d/%d",d.day,d.month,d.year);
}
int check(struct Date d){
	if(d.day<0 || d.month<  0 || d.year <0){
		return 0;
	}
	if(d.day>31 || d.month>12 ){
		return 0;
	}
	if(d.month==2 ){
		if(d.month>28){
			return 0;
		}
	}
	if(d.month== 1 || d.month==3 || d.month== 5 || d.month== 7 || d.month== 8 || 
	 d.month ==10 || d.month==12){
	 	if(d.day>31){
		  return 0;
		 }
	}
	if(d.month== 2 || d.month==4 ||d.month== 6 || d.month== 9 || d.month==11){
		if(d.day>30){
			return 0;
		}
	}
	return 1;// nguoc lai cac trương hop tren 
}
int main (){
	struct Date a ;// khai bao mot bien kieu struct 
	inputDate(a);
	printf("\nNgay thang nam vua nhap la :");
	printfDate(a);// chay cac ham voi doi so truyen vao la gia tri ma ta vua khai bao struct 
	if(check(a)==1){
		printf("\n Ngay thang nam hop le ");
	}
	else {
		printf("\n Ngay thang nam khong hop le ");
	}
	return 0;
}
	