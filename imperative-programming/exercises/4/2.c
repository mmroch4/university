#include <stdio.h>

int main() {
  int or, n;

  scanf("%d %d", &n, &or);

  if (or == 0) {
    for (int i = 1; i <= n; i++) {
      for (int c = 0; c < i; c++) {
        printf("#");
      }

      printf("\n");
    }

    for (int j = n - 1; 0 < j; j--) {
      for (int k = 0; k < j; k++) {
        printf("#");
      }

      printf("\n");
    }
  } else {
    int l, r;
    l = n - 1;
    r = n - 1;

    for (int i = 0; i < n; i++) {
      for (int c = 0; c < 2 * n; c++) {
        if (l <= c && c <= r) {
          printf("#");
        } else {
          printf(" ");
        }
      }

      l -= 1;
      r += 1;

      printf("\n");
    }
  }

  return 0;
}
