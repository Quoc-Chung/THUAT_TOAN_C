//thêm bất kì ,xoa bat ki 
// tim cac so la so nguyen to trong list
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int nguyen_to(int n){
	if(n<2){
		return 0;
	}
	else{
		for (int i=2;i<=sqrt(n);i++){
			if(n%i==0){
				return 0;
			}
		}
	}
	return 1;
}
struct Node {
	int data;
	struct Node *pNext;// tao moi lien ket 
};
// định nghĩa 
typedef struct Node NODE;
// khoi tao list 
struct List {
	NODE *pHead;// con tro node dau
	NODE *pTail;// con tro node cuoi 
};
typedef struct List LIST;
void khoi_tao_list(List &l){
// No List ==> No node
	l.pHead=NULL;
	l.pTail=NULL;
}
// nhập 1 node 
NODE *khoi_tao_node(int x){
	NODE *p;// con trỏ này để quản lí mối liên kết của node nhap
	p=(NODE *) malloc (sizeof(NODE));
	if(p==NULL){
		printf("\nKhong cap phat duoc dia chi node .");
		exit(1);
	}
	p->data=x;
	p->pNext=NULL;// vì mới chỉ có một node được tạo nên chưa có mối liên kết 
	return p; 
}
   // p  p.head  p.tail;
void them_node_vao_dau(LIST &l,NODE *p){
	// check xem node có rỗng không
	if(l.pHead==NULL){
		l.pHead =l.pTail=p;
	}
	else {
		p->pNext=l.pHead;
		l.pHead=p;// cập nhật lại mối liên kết 
	}
}
// l.pHead   l.pTail   p
void them_vao_cuoi(LIST &l,NODE *p){
	// check xem list rỗng không 
	if(l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else {
		l.pTail->pNext=p;
		l.pTail=p;// cập nhật lại mối liên kết 
	}
}
void create_list(LIST &l,int &x,int &n){
	printf("\nhap so luong node :");
	scanf("%d",&n);
	khoi_tao_list(l);
	for (int i=1;i<=n;i++){
		printf("\nNhap node thu %d:",i);
		scanf("%d",&x);
		NODE *p =  khoi_tao_node(x);
		them_vao_cuoi(l,p);
	}
}
void printf_list (LIST &l){
	printf("\nDanh sach gia tri trong list la :\n");
	for (NODE *i=l.pHead;i!=NULL;i=i->pNext){
		printf("%d ",i->data);
	}
}
void max_list(LIST l){
	int max=-12345;
	for(NODE *i=l.pHead;i!=NULL;i=i->pNext){
		if(max<i->data){
			max=i->data;
		}
	}
	printf("\nGia tri max la :%d",max);
}
void swap(int *x,int *y){
	int tam=*x;
	*x=*y;
	*y=tam;
}
void sap_xep_tang_dan(LIST l){
	for (NODE *i=l.pHead;i!=NULL;i=i->pNext){
		for (NODE *j=l.pHead;j!=NULL;j=j->pNext){
			if(i->data<j->data){
				swap(&i->data,&j->data);
			}
		}	
	}
	printf_list(l);
}
void so_nguyen_to_list(LIST &l){
	printf("\nCac so nguyen to trong list :\n");
	for (NODE *i=l.pHead;i!=NULL;i=i->pNext){
		if(nguyen_to(i->data)){
			printf("%d ",i->data);
		}
	}
}
// đêm sự xuất hiện của từng số trong list 
int count[1000001]={0};
void dem(LIST l){
	int a[100];
	int n=0;
	for (NODE *i=l.pHead;i!=NULL;i=i->pNext){
		a[n]=i->data;
		n++;
	}
	// đếm count trong mảng 
	for (int i=0;i<n;i++){
		count[a[i]]++;
	}
	printf("\nSo lan xuat hien cua cac so trong list :\n");
	for (int i=0;i<1000000;i++){
		if(count[i]>0){
			printf("\n%d %d",i,count[i]);
		}
	}
}
void them_bat_ki (LIST &l,NODE *p,NODE *q){
	for (NODE *i=l.pHead;i!=NULL;i=i->pNext){
		// đã tìm thấy node q trước node cần thêm là node p
		if(i->data==q->data){
		//	 node *g đang ở sau node  *q
			NODE *g=i->pNext;
			i->pNext=p;
			p->pNext=g;
		}
	}
}
void xoa_dau(LIST &l){
	// kiểm tra xem list có phải có một phần tử hay không 
	if(l.pHead->pNext==NULL){
		l.pHead=NULL;
	}
	else {
		NODE *p=l.pHead;
	    l.pHead=l.pHead->pNext;
	    free(p);
	}
}
void xoa_cuoi(LIST &l){
	// kiểm tra danh sach rỗng 
	if(l.pHead==NULL){
		return ;
	}
    NODE *q=NULL;// lưu node truoc node cuối
    for (NODE *i=l.pHead;i!=l.pTail;i=i->pNext){
    	q=i;
	}
	if(q==NULL){// danh sách chỉ có một phần tử  
		l.pHead=NULL;
	}
	else {
	    q->pNext=NULL;	
	}
	// giải phóng  
	free(l.pTail);
}
void xoa_sau_node_q(LIST &l,NODE *q){
	// node này dùng để lưu node cần xóa 
	NODE *g;
	// tìm node q
	for (NODE *i=l.pHead;i!=NULL;i=i->pNext){
		if(i->data==q->data){
			g=i->pNext;// g này đang ở phía sau q
			i->pNext=g->pNext;// sau q lúc này là node ở sau g
			free(g);
			return ;
		}
	}
}
void xoa_bat_ki(LIST &l ,int data){
	if(l.pHead->data==data){
		xoa_dau(l);
		return ;
	}
	if(l.pTail->data==data){
		xoa_cuoi(l);
	}
	else {
		for (NODE *i=l.pHead;i!=NULL;i=i->pNext){
			if(i->data==data){
				// khởi tạo node lưu data vừa tìm được 
				NODE *q=khoi_tao_node(i->data);
				xoa_sau_node_q(l,q);
			}
		}
	}
}
void  search_node(LIST &l ,int data){
	int flag=0;
	for (NODE *i=l.pHead;i!=NULL;i=i->pNext){
		if(i->data==data){
			printf("\nTim thay node.");
			flag++;
			break;
		}
	}
	if(flag==0){
		printf("\nKhong tim thay node.");
	}
}
void giai_phong(LIST &l){
	while (l.pHead!=NULL){
		// tạo node lưu node đầu
		NODE *p=l.pHead;
		// chuyển node ddaafu sang node thứ hai
		l.pHead=l.pHead->pNext;
		free(p);
	}
}
int main (){
	int n;
	int x;
	LIST l;
	create_list(l,x,n);
	printf_list(l);
//	max_list(l);

//	sap_xep_tang_dan(l);

//  so_nguyen_to_list(l);

//  dem(l);
    
    // tạo node cần thêm 
//    int x1;
//    printf("\nNode can them:");
//    scanf("%d",&x1);
//    NODE *p=khoi_tao_node(x1);
//    // khôi tao node truoc node can them
//    int x2;
//    printf("\nNode truoc node can them:");
//    scanf("%d",&x2);
//    NODE *q=khoi_tao_node(x2);
//    them_bat_ki(l,p,q);
//    printf_list(l);
    
//    xoa_dau(l);
//    printf_list(l);
    
//     xoa_cuoi(l);
//     printf_list(l);
       
//     int data;
//     printf("\nNhap data can xoa:");
//     scanf("%d",&data);
//     xoa_bat_ki(l,data);
//     printf_list(l);
        
//    int search;
//    printf("\nNhap gia tri tim kiem trong node :");
//    scanf("%d",&search);
//    search_node(l,search); 

//    giai_phong(l);
   
	   return 0;
}


















