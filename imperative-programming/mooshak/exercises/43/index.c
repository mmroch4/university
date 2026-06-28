#include <stdio.h>

#define CLEAN_BUFFER                                                           \
  {                                                                            \
    while (getchar() != '\n') {                                                \
    }                                                                          \
  }

int main() {
  int n, v;
  char op;

  scanf("%d", &n);
  CLEAN_BUFFER;

  char operations[n - 1];
  int values[n];

  int i = 0;
  int a = 0;
  int b = 0;

  while (i < 4 * n - 3) {
    if (i % 4 == 0) {
      scanf("%d", &v);
      values[a] = v;
      a++;
    } else if (i % 4 == 2) {
      scanf("%c", &op);
      operations[b] = op;
      b++;
    } else {
      scanf("%c", &op);
    }

    i++;
  }

  int canAdd[n];

  i = 0;

  while (i < n) {
      canAdd[i] = 1;
      i++;
  }
  
  i = 0;

  while (i < n - 1) {
    if (operations[i] == '*') {
        int r = values[i] * values[i + 1];
        values[i] = r;
        values[i + 1] = r;
        canAdd[i] = 0;
    }

    i++;
  }

  long sum = 0;

  i = 0;

  while (i < n) {
      if (canAdd[i]) {
          sum += values[i];
      }

      i++;
  }

  printf("%ld\n", sum);

  return 0;
}
