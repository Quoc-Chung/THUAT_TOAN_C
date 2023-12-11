#include <stdio.h>
#include <math.h>
int main (){
	float x1,y1,x2,y2,x3,y3;
	printf("Nhap diem A:");
	scanf("%f %f",&x1,&y1);
	printf("\nNhap diem B:");
	scanf("%f %f",&x2,&y2);
	printf("\nNhap diem C:");
	scanf("%f %f",&x3,&y3);
	// kiem tra tam giac can 
	float AB=sqrt (pow(x2-x1,2)+pow(y2-y1,2));
	float BC=sqrt (pow(x3-x2,2)+pow(y3-y2,2));
	float AC=sqrt (pow(x3-x1,2)+pow(y3-y1,2));
	if(AB==BC || BC== AC || AB==AC ){
		printf("\nDay la tam giac can");
	}
	else{
		printf("\nDay khong la tam giac can .");
	}
	float p=(AB+BC+AC)/2;
	float s=sqrt (p*(p-AB)*(p-BC)*(p-AC));
	printf("\nDien tich tmam giac la :%.2f",s);
	return 0;
	
}