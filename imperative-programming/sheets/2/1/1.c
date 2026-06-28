#include <math.h>
#include <stdio.h>

int main() {
  int n;

  scanf("%d", &n);

  int e = 0;

  while (n / pow(10, e) >= 1) {
    e++;
  }
  
  int sum = 0;
  
  int r = e;
  
  while (0 <= r) {
      int m = floor(n / pow(10, r));
      
      n -= m * pow(10, r);
      
      sum += m;
      r--;
  }

  printf("Num. of digits = %d\n", e);
  printf("Sum of digits = %d\n", sum);
  
  return 0;
}
