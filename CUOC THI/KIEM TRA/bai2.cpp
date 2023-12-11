#include <stdio.h>
#include<math.h>
#include<stdlib.h>
struct HCN  {
  double dai;
  double rong;
};

double HinhChuNhat(struct HCN H[], int n) {
  double s = 0.0;
  for (int i = 0; i < n; i++) {
    double tmp = H[i].dai * H[i].rong;
    s += tmp;
  }
  double tb = s / n;
  return tb;
}
double max( struct HCN H[], int n) {
  double max = H[0].dai * H[0].rong;
  for (int i = 1; i < n; i++) {
    double tmp = H[i].dai * H[i].rong;
    if (tmp > max) {
      max = tmp;
    }
  }
  return max;
}

int main() {
  int n;
  scanf("%d", &n);
  struct HCN H[n];

  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &H[i].dai, &H[i].rong);
  }

  double tb = HinhChuNhat(H, n);
  double maxx = max(H,n);

  printf("%.3lf\n", tb);
  printf("%.3lf\n", maxx);

  return 0;
}
