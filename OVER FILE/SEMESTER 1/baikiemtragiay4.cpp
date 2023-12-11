#include <stdio.h>
#include <math.h>
int main (){
	int n,x;
	printf("Nhap so n:");
	scanf("%d",&n);
	int P[100],Q[100];
	int s1,s2;
	int s=0;
	printf("\nNhap gia tri x:");
	scanf("%d",&x);
	// nhap P(x)
	printf("\nNhap he so cua P:\n");
	for (int i=0;i<=n;i++){
	  scanf("%d",&P[i]);
	}
		printf("\nNhap he so cua Q:\n");
	for (int i=0;i<=n;i++){
		scanf("%d",&Q[i]);
	}
	s1=P[0];
	s2=Q[0];
	for (int i=1;i<=n;i++){
		s1+=P[i]*pow(x,i);
		s2+=Q[i]*pow(x,i);
	}
	s+=3*s1-6*s2+5;
	printf("\nGia tri can tim la :%d",s);
}