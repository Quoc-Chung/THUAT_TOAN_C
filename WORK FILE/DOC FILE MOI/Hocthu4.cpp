#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct Hoten{
 int  id;
 char  ten[50];
 double gpa;
};
void  DocFile(Hoten &ht,char  *tentep){
 FILE *f;
 f=fopen(tentep,"r");
 if(f==NULL){
 	printf("\nKhong the  mo duoc file ");
 	exit(0);
 }	
 fscanf(f,"%d",&ht.id);
 fscanf(f," %[^\n]",ht.ten);
 fscanf(f,"%lf",&ht.gpa);
}
void GhiRa(Hoten &ht){
	printf("%d",ht.id);
	printf("\n%s",ht.ten);
	printf("\n%lf",ht.gpa);
}
int  main(){
	Hoten ht;
	char tentep[50]="Hocthu4.txt";
	DocFile(ht,tentep);
	GhiRa(ht);
	return 0;
}
