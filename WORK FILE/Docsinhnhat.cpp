#include <stdio.h>
#include <math.h>
struct ngaysinh{
	int ngay;
	int thang;
	int nam;
};
int main(){
	//tao file va mo file mo dung tep ma ta ghi thi moi doc duoc
	FILE *f;
	// doc file  nhi phan 
	f=fopen ("C:\\Users\\Admin\\Documents\\FILE GHI\\Sinhnhat.bin","rb");
    // kiem tra tep
		if(f==NULL){
		printf("File Khong the mo do gap su co .");
		exit(1);		
	}
	struct ngaysinh n;
	// doc  file nhi phan 
	fread(&n,sizeof(struct ngaysinh),1,f);
	printf("%d/%d/%d",n.ngay,n.thang,n.nam);
	fclose(f);
	return 0;
}