#include<stdio.h>
#include<math.h>
int main() {
  int *a, **b;

  a = new int;
  *a = 5;

  b = new int*;
  *b = a;


  printf("Gia tri cua *a: %d\n", *a);
  printf("Gia tri cua a: %d\n", a);
  printf("Gia tri cua **b: %d\n", **b);
  printf("Gia tri cua *b: %d\n", *b);
  printf("Gia tri cua b: %d\n", b);

  printf("SAU KHI CHO CON TRO B TRO TOI CON TRO A:\n");
  b = &a;
  printf("Gia tri cua *a: %d\n", *a);
  printf("Gia tri cua a: %d\n", a);
  printf("Gia tri cua **b: %d\n", **b);
  printf("Gia tri cua *b: %d\n", *b);
  printf("Gia tri cua b: %d\n", b);

  delete a;
  delete b;

  return 0;
}