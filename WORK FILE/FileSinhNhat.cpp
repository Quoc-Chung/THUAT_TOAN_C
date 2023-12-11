#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct ngaysinh{
	int ngay;
	int thang;
	int nam;
};
int main(){
	FILE *f;
	f=fopen("C:\\Users\\Admin\\Documents\\FILE GHI\\Sinhnhat.bin","wb");
	if(f==NULL){
		printf("File Khong the mo do gap su co .");
		exit(1);
	}
	struct ngaysinh n;
	n.ngay=18;
	n.thang=10;
	n.nam=2004;
	fwrite(&n,sizeof(struct ngaysinh),1,f);
	fclose(f);
	return 0;
	
}