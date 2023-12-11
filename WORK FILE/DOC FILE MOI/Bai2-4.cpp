//Bài 2-4 Nhập danh sách n thí sinh tham gia Code sinh viên UTC từ tệp code.inp. Mỗi thí 
//sinh là một bản ghi được lưu trữ trên ba dòng của tệp trên gồm các trường: HT (Họ tên), 
//SDIEM (Điểm số), Lớp. Gia thiết có 3 lớp tham gia là A1, A2, A3. Dòng đầu của tệp là 
//số nguyên lưu trữ số thí sinh, thông tin các thí sinh được lưu trữ trên mỗi 3 dòng tiếp 
//theo. Yêu cầu:
//1. Tính điểm trung bình của mỗi lớp, và lớp nào có tổng điểm lớn nhất. 
//2. Cho biết 3 thí sinh dự thi có điểm thi cao nhất. 
//3. Kết quả lưu vào tệp output.txt bao gồm cả các thông tin về n thí sinh dự thi
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
struct Code{
  char HoTen[50];
  float DiemSo;
  char Lop[3]; // Sửa kích thước thành 3 để chứa chuỗi "A1", "A2", "A3"
};
void DocFile (Code **c,int &n,char *tentep){
	FILE *f;
	f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	*c=(Code*) malloc (n*sizeof(Code));
	for(int i=0;i<n;i++){
		fscanf(f," %[^\n]",(*c)[i].HoTen);
		fscanf(f,"%f",&(*c)[i].DiemSo);
		fscanf(f," %[^\n]",(*c)[i].Lop);
	}
	fclose(f); // Đóng tệp sau khi đọc xong
}
void DiemMoiLop(Code *c,int n,FILE *f=stdout){
	fprintf(f,"\nDiem Trung Binh Cua Moi Lop:");
	int dem1=0, dem2=0, dem3=0; // Khởi tạo biến đếm ban đầu
	float tong1=0, tong2=0, tong3=0;
	for(int i=0;i<n;i++){
		if(strcmp(c[i].Lop,"A1")==0){
			tong1+=c[i].DiemSo;
			dem1++;
		}
		if(strcmp(c[i].Lop,"A2")==0){ // Sửa thành "A2"
			tong2+=c[i].DiemSo;
			dem2++;
		}
		if(strcmp(c[i].Lop,"A3")==0){
			tong3+=c[i].DiemSo;
			dem3++;
		}
	}
	fprintf(f,"\n Diem TB--Lop A1: %.2f--Lop A2: %.2f--Lop A3: %.2f",tong1/dem1,tong2/dem2,tong3/dem3);
	if (tong1/dem1 > tong2/dem2 && tong1/dem1 >tong3/dem3){
		fprintf(f," Lop A1 co diem Tb lon nhat.");
	}
	else if (tong2/dem2 > tong3/dem3 && tong2/dem2 >tong1/dem1){
		fprintf(f," Lop A2 co diem Tb lon nhat.");
	}
	else{
		fprintf(f," Lop A3 co diem Tb lon nhat.");
	}	
}
void DiemCaoNhat(Code *c,int n,FILE *f=stdout){
	for(int i=0;i<n-1;i++){ // Sửa điều kiện dừng vòng lặp
		for (int j=i+1;j<n;j++){ // Sửa điều kiện duyệt phần tử
			if(c[i].DiemSo <c[j].DiemSo){
				Code tmp =c[i];
				c[i]=c[j];
				c[j]=tmp;
			}
		}
	}
	fprintf(f,"\nBa thi sinh co tong diem cao nhat la:\n");
	for(int i=0;i<3;i++){
		fprintf(f,"Ho ten: %s\n",c[i].HoTen);
		fprintf(f,"Diem: %.2f\n",c[i].DiemSo);
		fprintf(f,"Lop: %s\n",c[i].Lop);
	}
}
int main(){
	int n;
	char tentep[40]="Code.txt";
	Code *c;
	DocFile(&c,n,tentep);

	FILE *f=fopen("Ket_Qua_2.4.txt","w");
	DiemMoiLop(c,n,f);
	DiemCaoNhat(c,n,f);

	fclose(f);
	free(c); // Giải phóng vùng nhớ đã cấp phát
}
