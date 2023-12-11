#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct sinh_nhat{
	int ngay;
	int thang;
	int nam;
};
void delete_newline(char c[]){
	size_t len =strlen(c);
	if(c[len-1]=='\n'){
		c[len-1]='\0';
	}
}
typedef struct sinh_nhat NGAYSINH;// định nghĩa lại ngày sinh
// ví dụ nhap chuoi tU 123 &% QuOC Chung@ ==>Tu Quoc Chung
// đã xóa được các kí tự sô và đặc biệt
void nhap_ngay_sinh(NGAYSINH *sn){
	scanf("%d",&sn->ngay);
	scanf("%d",&sn->thang);
	scanf("%d",&sn->nam);
}
void xoa_bo_dac_biet(char c[]){
	// tạo chuỗi mới để lưu trữ các kí tự chỉ có chữ thường 
	char string_new[100];
	int j=0;
	size_t len =strlen(c);
	for (int i=0;i<len;i++){
		if(isalpha(c[i]) || isspace(c[i])){
			string_new[j]=c[i];
			j++;
		}
	}
	string_new[j]='\0';// đánh dấu chuỗi kêt thúc 
	// copy chuỗi chỉ gồm chữ cái và khoang cach vao chuoi ban dau
	strcpy(c,string_new);
}
char *chuan_hoa_ten(char c[]){
	char luu_chuoi_chuan_hoa[40]="";// đầu tiên ta gán giá trị chuỗi về  0
	char a[10][50];// tạo mảng kí tự để lưu chuỗi a:lưu được tối đa 10 phrase, mỗi cụm từ có thể lưu tối đa 50 kí tự 
	int n=0;// số từ của mảng kí tự 
	char *token =strtok (c," ");
	while (token !=NULL){
		strcpy(a[n],strlwr(token));
	//		strlwr(a[n]);
		token=strtok(NULL," ");
		// chuyển kí tự về dạng in thường 
		n++;
	}
	// viết hoa các chữ đầu của tên 
	for (int i=0;i<n;i++){
		a[i][0]=toupper(a[i][0]);
	}
	// thêm các từ vừa được chuẩn hóa vào chuỗi lưu_chuoi_chuan_hoa 
	for (int i=0;i<n;i++){
		strcat(luu_chuoi_chuan_hoa,a[i]);
		strcat(luu_chuoi_chuan_hoa," ");// them khoảng trắng vào chuỗi 
	}
	strcpy(c,luu_chuoi_chuan_hoa);
	return c;
}
void tao_email(char c[],NGAYSINH ns){
	char a[10][50];// tạo mảng kí tự để lưu các cụm từ ,tối đa 10 cụm từ , mõi cụm từ tối đâ 50 chữ cái 
	int n=0;// ban đầu có 10 từ đươc lưu
	char *token =strtok (c," ");
	while (token != NULL){
		strcpy(a[n],token);
		strlwr(a[n]);// viết thường từ vừa được trích xuất 
		token = strtok(NULL," ");
		n++;// tăng so từ lên để còn chỗ lưu trữ từ mới 
	}
	for (int i=0;i<n;i++){
		printf("%s",a[i]);
	}
	printf("@gmail.com.");	
}
// tạo mật khẩu động từ hai chữ dầu tên + số đâu của ngàysinh ,số cuối của thang sinh,namsinh+ho +@
// ví dụ tu quoc chung
// :ch10tu2004@
int sodau(int n){
	int sodaonguoc=0;
	while (n>0){
		sodaonguoc=sodaonguoc*10+n%10;
		n/=10;
	}
	return sodaonguoc%10;
}
int socuoi(int n){
	return n%10;
}
void tao_mat_khau_dong(char c[],NGAYSINH ns){
	char a[10][100];// mảng này có 3 chuỗi ,mỗi chuỗi có tối đa 100 kí tự 
    // tach chuoi ra tung tu 
    char *token = strtok(c," ");
    int n=0; // đây chính là số chuỗi(số từ copy vào mảng kí tự )
    while (token!=NULL){
        strcpy(a[n],token);// copy chuỗi vào từng chuỗi(tung hàng) của mang hai chieu;
        token = strtok(NULL," ");
        n++;
    }
    for (int i=0;i<n;i++){
    	printf("%s ",a[i]);
	}
	int dau_ngay_sinh=0,cuoi_thang_sinh=0;
	if(ns.ngay>=10){
		dau_ngay_sinh=sodau(ns.ngay);
	}
	else if(ns.ngay<10){
		dau_ngay_sinh=ns.ngay;
	}
	if(ns.thang>=10){
		cuoi_thang_sinh=socuoi(ns.thang);
	}
	else if(ns.thang<10){
		cuoi_thang_sinh=ns.thang;
	}
//	ch10tu2004@
//  ten,daungaysinh,cuoithangsinh,ho,namsinh,@
 //   printf("Mat khau:");
//	printf("%s%d%d%s%d@",a[n-1],dau_ngay_sinh,cuoi_thang_sinh,a[0],ns.nam);
	
}
int main (){
	char ten[40];
	NGAYSINH ns;
	fflush(stdin);
	fgets(ten,sizeof(ten),stdin);
	delete_newline(ten);
	nhap_ngay_sinh(&ns);
	xoa_bo_dac_biet(ten);
    chuan_hoa_ten(ten);
    printf("+------------------------------------+\n");
	printf("|%-20s| %-13s |\n","  Ho va ten "," Ngay sinh ");
	printf("+------------------------------------+\n");
	printf("|%-20s| %-3d/%-3d/%-5d |\n",ten,ns.ngay,ns.thang,ns.nam);
	printf("+------------------------------------+\n");
	for (int i=0;i<5;i++){
    printf("\t\t|||\n");
	}
	printf("+-------------------------------+\n");
    printf("|"); tao_email(ten, ns); printf("\t\t|\n");
    printf("+-------------------------------+\n");
    tao_mat_khau_dong(ten,ns);
	return 0;
}