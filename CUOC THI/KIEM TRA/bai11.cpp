#include <stdio.h>
#include <stdlib.h>
struct HocSinh {
  int Ma;
  float Diem;
  char Lop;	
};
void doc(struct HocSinh hv[], int n) {
  for (int i = 0; i < n; i++) {
    scanf("%d", &hv[i].Ma);	
    scanf("%f", &hv[i].Diem);
    scanf(" %c", &hv[i].Lop);
  } 
  int dem = 0;
  for (int i = 0; i < n; i++) {
    if (hv[i].Ma % 5 == 0 && (hv[i].Lop == 'B' || hv[i].Lop == 'C')) {
      dem++;
    }
  }
  printf("%d\n", dem);
  for (int i = 0;i< n-1; i++) {
    for (int j = i; j<n; j++) {
      if (hv[i].Diem < hv[j].Diem) {
        struct HocSinh tmp = hv[i];
        hv[i] = hv[j];
        hv[j] = tmp;
      }
    }
  } 
  for (int i = 0;i < 3;i++) {
    printf("%d\n", hv[i].Ma);
  }
}
int main() {
  int n;
  scanf("%d",&n);
  struct HocSinh *hv = (struct HocSinh*) malloc(n*sizeof(struct HocSinh));
  if (hv == NULL) {
    printf("Khong du bo nho\n");
    return 0;
  }
  doc(hv, n);
  free(hv);
  return 0;
}

