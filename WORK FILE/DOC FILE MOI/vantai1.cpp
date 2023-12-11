//Viết chương trình nhập thông tin cho n ô tô vận tải từ tệp oto.txt. Mỗi ô tô là một 
//cấu trúc và được lưu trữ trên 3 dòng của tệp gồm: BKS (Số biển kiểm soát: là một số 
//nguyên), TT (Trọng tải: là một số thực), CTy (Công ty chủ quản: là một ký tự). Cho biết: 
//chỉ có 3 công ty chủ quản là : A. B, C. Yêu cầu: 
//1. Đếm xem có bao nhiêu ô tô của công ty B có BKS chia hết cho 3. 
//2. In ra màn hình 3 ô tô có trọng tại nhỏ nhất. 
//3. Kết quả lưu vào tệp Output.txt bao gồm cả các thông tin về n ô tô vận tải.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct VanTai{
	int bien;
	float trongtai;
	char cty[2];
};
void  DocFile(VanTai **vt,int &n,char *tentep,char *tepkq){
	FILE *f,*f1;
	f=fopen(tentep,"r");
	f1=fopen(tepkq,"w");
	if(f==NULL){
		printf("\nKhong the  mo duoc file;");
		exit(0);
	}
	if(f1==NULL){
		printf("\nKhong the  mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	*vt=(VanTai*) malloc (n*sizeof(VanTai));
	for(int i=0;i<n;i++){
	 fscanf(f,"%d",&((*vt)[i].bien));
	 fscanf(f,"%f",&((*vt)[i].trongtai));
	 fscanf(f," %[^\n]",((*vt)[i].cty));	
	}
	fprintf(f1,"\nThong tin cua n oto la :\n");
	for(int i=0;i<n;i++){
	 fprintf(f1,"\nBien so :%d - Trong Tai %.2f - Cong Ty : %s",(*vt)[i].bien,(*vt)[i].trongtai,(*vt)[i].cty);
	}
	fclose(f);
	fclose(f1);
}
void DemXeCongTyB( VanTai *vt, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(vt[i].cty,"B")==0  && vt[i].bien % 3 == 0) {
            count++;
        }
    }
    printf("So oto cua cong ty B co BKS chia het cho 3 la: %d\n", count);
}

void In3XeTrongTaiNhoNhat(struct VanTai *vt, int n) {
    printf("Ba oto co trong tai nho nhat la:\n");
    for (int i = 0; i < 3; i++) {
        int minIndex = 0;
        float minValue = vt[0].trongtai;
        for (int j = 1; j < n; j++) {
            if (vt[j].trongtai < minValue) {
                minValue = vt[j].trongtai;
                minIndex = j;
            }
        }
        printf("Bien so: %d - Trong Tai: %.2f\n", vt[minIndex].bien, vt[minIndex].trongtai);
        vt[minIndex].trongtai = INFINITY;  // Đánh dấu ô tô đã được in ra
    }
}
int main() {
    int n;
    struct VanTai *vt;
    char tentep[] = "oto.txt";
    char tepkq[] = "Output.txt";
    DocFile(&vt,n, tentep, tepkq);
    DemXeCongTyB(vt, n);
    In3XeTrongTaiNhoNhat(vt, n);
    free(vt);
    return 0;
}
