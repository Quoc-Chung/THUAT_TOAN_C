#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhap(float a[],float b[], int &n, int &m)
{
	int i;
	FILE *f;
	f=fopen("BaiQuyet.txt","r");
	printf("Nhap n va m:");
	fscanf(f,"%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		fscanf(f,"%f",&a[i]);
	}
	for(i=0;i<m;i++)
	{
		fscanf(f,"%f",&b[i]);
	}
	printf("\nP(x)=%.1f",a[0]);
	for(i=1;i<n;i++)
	{
		printf("+%.1f*x^%d",a[i],i);
	}
	printf("\nQ(x)=%.1f",b[0]);
	for(i=1;i<m;i++)
	{
		printf("+%.1f*x^%d",b[i],i);
	}
}
float tinh(float a[],float b[],int n,int m)
{
	int i;
	FILE *f;
	float x1,x2,p,q,s;
	printf("\nNhap x1 va x2:");
	scanf("%f%f",&x1,&x2);
	p=a[0];q=b[0];
	for (i=1;i<n;i++)
	{
		p+=a[i]*pow(x1,i);
	}
	for (i=1;i<m;i++)
	{
		q+=a[i]*pow(x2,i);
	}
	s=p/q;
	printf("\n%f",s);
	return s;
}
void hieudthuc(float a[],float b[],float c[],int n, int m)
{
	int i;
	int max=n?m:n>m;
	c[0]=a[0]-b[0];
	printf("\n%.1f",c[0]);
	for (i=1;i<max;i++)
	{
		c[i]=a[i]-b[i];
		printf("+%.1f",c[i]);
	}
}
main()
{
	float *a,*b,*c;
	int i,n,m,lon=n?m:n>m;
	printf("%d %d %d",m,n,lon);
	FILE *f;
	a=(float*)malloc(n*sizeof(float));
	if(a==NULL){
		printf("\nKhong cap phat duoc bo nho .");
		exit(0);
	}
	b=(float*)malloc(m*sizeof(float));
		if(b==NULL){
		printf("\nKhong cap phat duoc bo nho .");
		exit(0);
	}
	c=(float*)malloc(lon*sizeof(float));
		if(b==NULL){
		printf("\nKhong cap phat duoc bo nho .");
		exit(0);
	}
	nhap(a,b,n,m);
	tinh(a,b,n,m);
	hieudthuc(a,b,c,n,m);
	
}
