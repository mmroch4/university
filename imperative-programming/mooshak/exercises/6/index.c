#include <stdio.h>
#include <stdlib.h>

int MAX = 1000;

int main() {
  int n;

  scanf("%d", &n);

  int a[n], b[n];

  int m = MAX;

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (int u = 0; u < n; u++) {
    scanf("%d", &b[u]);
  }

  for (int k = 0; k < n; k++) {
    int diff = abs(a[k] - b[k]);

    if (diff < m) {
      m = diff;
    }
  }
  
  printf("%d\n", m);
}
