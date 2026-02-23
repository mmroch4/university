#include <stdio.h>

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int l = 0; l < n - 1 - i; l++) {
      printf("_");
    }

    for (int r = n - 1 - i; r < n; r++) {
      printf("#");
    }

    printf("\n");
  }
  
  return 0;
}
