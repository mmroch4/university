#include <stdio.h>

void draw_line(int i) {
  while (i--) {
    printf("#");
  }

  printf("\n");
}

int main() {
  int n, t, i, j, k;

  scanf("%d", &n);

  while (n--) {
    scanf("%d", &t);

    draw_line(t);

    j = 1;
    i = t - 2;

    while (i > 0 && j < t - 1) {
      for (k = 0; k < t; k++) {
        if (k == i || k == j) {
          printf("#");

        } else {
          printf(".");
        }
      }

      printf("\n");
      
      j++;
      i--;
    }

    draw_line(t);
  }
}
