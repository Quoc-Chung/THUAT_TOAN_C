#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// -Hiển thị thông tin các phòng có trong danh sách.
// - Liệt kê các phòng trống trong danh sách.
// -Tính tổng số lượng giường của các phòng có trong danh sách.
// -Sắp xếp các phòng theo giá thuê tăng dần.
void delete_newline(char c[]){
    size_t len=strlen(c);
    if(c[len-1]=='\n'){
      c[len-1]='\0';
    }
}
struct phong{
    char ma_phong[5];
    char ten_phong[30];
    float don_gia_thue;
    int so_luong;
    char tinh_trang[5];
};
typedef struct phong PHONG;
void nhap(PHONG &p){
    printf("\nNhap ma phong:");
    fflush(stdin);
    fgets(p.ma_phong,sizeof(p.ma_phong),stdin);
    printf("\nNhap ten phong:");
    fflush(stdin);
    fgets(p.ten_phong,sizeof(p.ma_phong),stdin);
    printf("Don gia:");scanf("%f",&p.don_gia_thue);
    printf("\nSo luong:");scanf("%d",&p.so_luong);
    printf("\nNhap tinh trang phong :");
    fflush(stdin);
    fgets(p.tinh_trang,sizeof(p.tinh_trang),stdin);
}
struct Node{
  PHONG data;
  struct Node *pNext;
};
typedef struct Node NODE;
struct List {
   NODE *pHead;
   NODE *pTail;
};
typedef struct List LIST;
// khởi tạo list 
void khoi_tao_list(LIST &l){
    // chưa có node nào được tạo 
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE *khoi_tao_mot_node(PHONG ph){
    // tạo con trỏ lưu node khởi tạo 
    NODE *p=(NODE *) malloc (sizeof(NODE));
    if(p==NULL){
        printf("\nKhong cap phat duoc dia chi cho node khoi tao .");
        exit(1);
    }
    p->data=ph;
    p->pNext=NULL;// vì mới có một node được tạo
    return p;
}
// p    phead    ptail
void them_vao_dau(LIST &l,NODE *p){
    // kiem tra danh sach rong 
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }
    else {
      p->pNext=l.pHead;
      l.pHead=p;
    }
}
// l.pHead   node truoc *p l.pTail   p
void them_vao_cuoi(LIST &l,NODE *p){
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }
    else {
         l.pTail->pNext=p;
         l.pTail=p;
    }
}
void nhap_node(LIST &l,int &n){
    printf("\nNhap so node :");
    scanf("%d",&n);
    khoi_tao_list(l);
    for (int i=1;i<=n;i++){
        printf("\nNhap node thu %d:\n",i);
        PHONG ph;
        nhap(ph);
        NODE *p=khoi_tao_mot_node(ph);
        them_vao_cuoi(l,p);
    }
}
// char ma_phong[5];
//     char ten_phong[30];
//     float don_gia_thue;
//     int so_luong;
//     char tinh_trang[5];
void printf_list(LIST &l){
    printf("\n\t\t\tTHONG TIN NODE\n");
    printf("+---------------------------------------------------------------------------------+\n");
    printf("| %-8s | %-30s | %-10s | %-8s | %-10s |\n",
    "Ma phong","Ten phong","Don gia","So luong"," Tinh trang");
    printf("|---------------------------------------------------------------------------------+\n");
    for (NODE *i=l.pHead;i!=NULL;i=i->pNext){
        delete_newline(i->data.ma_phong);
        delete_newline(i->data.ten_phong);
        delete_newline(i->data.tinh_trang);
    printf("| %-8s | %-30s | %-10.0f | %-8d |  %-10s |\n",
    i->data.ma_phong,i->data.ten_phong,i->data.don_gia_thue,i->data.so_luong,i->data.tinh_trang);
    }
    printf("+---------------------------------------------------------------------------------+");
}
int main (){
    int n;
    LIST l;
    nhap_node(l,n);
    printf_list(l);
    return 0;
}
