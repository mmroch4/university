#include <stdio.h>

int main() {
  int n, k;

  scanf("%d %d", &n, &k);

  if (k == 0) {
    int l = n - 1;
    int r = n - 1;

    for (int i = 0; i < n; i++) {
      for (int p = 0; p < 2 * n - 1; p++) {
        if (l <= p && p <= r) {
          printf("#");
        } else {
          printf("_");
        }
      }
      printf("\n");

      l--;
      r++;
    }

  } else {
    int a = 1;
    int i = 1;
    int step = 1;

    while (a < 2 * n) {
      for (int l = 0; l < i; l++) {
        printf("#");
      }

      for (int r = i; r < n; r++) {
        printf("_");
      }

      printf("\n");

      if (i == n) {
        step = -1;
      }

      i += step;
      a++; 
    }
  }

  return 0;
}
