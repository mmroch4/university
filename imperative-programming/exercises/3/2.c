#include <limits.h>
#include <stdio.h>

int main() {
  int n;

  scanf("%d", &n);

  if (n <= 0) {
    return 1;
  }
  
  int m = 0;
  int c = 0;

  for (int i = 0; i < n; i++) {
    int v;

    scanf("%d", &v);

    if (v >= 0) {
        c += 1;
    }
    else {
        c = 0;
    }
    
    if (c > m) {
        m = c;
    }
  }

  printf("%d\n", m);

  return 0;
}
