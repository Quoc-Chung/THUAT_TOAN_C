#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct SV{
	char ht[100];
	float sd;
	char t[2];
};
void read(SV **sv,int *n,char *tentep)
{
	FILE*f;
	f=fopen(tentep,"r");
	if(f==NULL)
	{
		printf("loi mo tep");
		exit(0);
	}
	fscanf(f,"%d",n); // ở đây là n thui
	// ở đây thiếu dấu *sv với *SV
	(*sv)=(SV*)malloc(*n*sizeof(SV));
	for(int i=0;i<*n;i++)
	{
		// cho này phải cách đặc tả ra như này " %[^\n]"
		fscanf(f," %[^\n]",(*sv)[i].ht);
		fscanf(f,"%f",&(*sv)[i].sd);
		fscanf(f," %[^\n]",(*sv)[i].t);
	}
}
void print(SV *sv,int n,FILE*f=stdout)
{
	fprintf(f,"\nThong tin cac thi sinh la:\n");
	for(int i=0;i<n;i++)
	{
		fprintf(f,"Ho ten:%s--So diem:%.2f--Truong:%s\n",sv[i].ht,sv[i].sd,sv[i].t);
	}
}
void tong(SV *sv,int n,FILE*f=stdout)
{
	float tong1=0,tong2=0,tong3=0;
	for(int i=0;i<n;i++)
	{
		if(strcmp(sv[i].t,"A"))
		{
			tong1+=sv[i].sd;
		}
		else if(strcmp(sv[i].t,"B"))
		tong2+=sv[i].sd;
		else tong3+=sv[i].sd;
	}
	if(tong1>tong2&&tong1>tong3)
	{
	fprintf(f,"Truong A co tong diem cao nhat:%.2f",tong1);}
	else if(tong2>tong1&&tong2>tong3)
	{
	fprintf(f,"Truong B co tong diem cao nhat:%.2f",tong2);}
	else
	{
	fprintf(f,"Truong C co tong diem cao nhat:%.2f",tong3);}
}
void diem(SV *sv,int n,FILE*f=stdout)
{
	SV tmp;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		if(sv[i].sd <sv[j].sd) // cho  này bị ngược dấu 
		{
			tmp=sv[j];
			sv[j]=sv[i];
			sv[i]=tmp;
		}
	fprintf(f,"\n3 Thi sinh co diem cao nhat la:\n");
	for(int i=(n-1);i>(n-4);i--)
	fprintf(f,"Hoten:%s--Sodiem:%.2f--Truong:%s\n",sv[i].ht,sv[i].sd,sv[i].t);
}
int main()
{
	int n;
	SV *sv;
	char tentep[50]="baihung3.txt";
	FILE*f=fopen("kqbaihung3.txt","w");
	read(&sv,&n,tentep);
	print(sv,n,f);
	tong(sv,n,f);
	diem(sv,n,f);
}
/* file ghi ra  như này:

Thong tin cac thi sinh la:
Ho ten:vo hoang hung --So diem:7.50--Truong:A
Ho ten:tu quoc chung--So diem:9.50--Truong:B
Ho ten:vu minh quyet--So diem:9.50--Truong:B
Ho ten:vu hong nhung--So diem:9.00--Truong:C
Ho ten:vu minh trang--So diem:8.50--Truong:A
Ho ten:nguyen van kiet--So diem:8.00--Truong:C
Truong A co tong diem cao nhat:36.00
3 Thi sinh co diem cao nhat la:
Hoten:tu quoc chung--Sodiem:9.50--Truong:B
Hoten:vu minh quyet--Sodiem:9.50--Truong:B
Hoten:vu hong nhung--Sodiem:9.00--Truong:C
*/