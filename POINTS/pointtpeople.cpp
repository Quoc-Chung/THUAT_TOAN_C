#include <stdio.h>
#include <math.h>
struct connguoi{
	connguoi(int t,float v1,float ccao){
    tuoi=t;	
	 vong_mot=v1;
	 chieucao=ccao;            
	}
	int tuoi;
	float vong_mot;
	float chieucao;
};
// không nên cộng trừ trên địa chỉ sẽ gây nên rất nhiều rủi do 
int main (){
  struct connguoi thao(22,95,1.70);
  struct connguoi thuong(30,86,1.72);
  struct connguoi hoa(20,88,1.78);
  // dia chi cua ba bien struct 
	printf("\nDia chi nha thao :%d",&thao);
	printf("\nDia chi nha thuong:%d",&thuong);
	printf("\nDia chi nha hoa :%d",&hoa);
    
     connguoi bo_nhi=thao;// đây thực chất chỉ la copy toàn bộ dữ liệu của em thảo sang một người khác với biệt danh bồ nhí 
	//thao.tuoi=25;// nó chỉ lam thay đổi tuổi của em thảo thôi còn tuổi của bồ nhí thì vẫn không thay đổi được 
	// muốn thay đổi phải thay đổi địa chỉ nhà thảo trùng với địa chỉ của bồ nhí thì những thay đổi ở nhà của thảo
	// sẽ kéo theo sự thay đổi của nhà bồ nhí.
	thao.tuoi=18;
	connguoi *bo_nhi1=&thao;// bồ nhí lúc này là em thảo rồi 
	printf("\nTuoi cua bo nhi la:%d ",bo_nhi1->tuoi);// truy cập bằng con trỏ nên có dấu mũi tên 
//	printf("\nTuoi cua bo nhi la:%d",(*bo_nhi1).tuoi);// có thể viết như này cũng tương tự 
	connguoi *bo_nhi2 = &thuong;
	// chú ý  phải  khi báo đúng đặc tả của biến đấy .
	printf("\nVong mot em thuong :%.0f",(*bo_nhi2).vong_mot);
	return 0;
}