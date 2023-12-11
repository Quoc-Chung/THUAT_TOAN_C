#include <stdio.h>

int main() {
  int n = 8;
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int flag = 1, flag1 = 1,no= 1;
  // Kiểm tra dãy tăng dần và giảm dần
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      flag = 0;
    }
    if (a[i] < a[i + 1]) {
      flag1 = 0;
    }
    if (a[i] != a[i + 1]) {
      no = 0;
    }
  }
  if (no) {
    printf("KHONG BIET");
  } 
  else if (flag) {
    printf("TANG");
  } 
  else if (flag1) {
    printf("GIAM");
  } 
  else {
    printf("KHONG BIET");
  }

  return 0;
}

