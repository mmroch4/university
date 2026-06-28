#include <math.h>
#include <stdio.h>

int main() {
  char c;
  char plate[6];

  int i = 0;

  long num = 0;

  while (scanf("%c", &c)) {
    if (c < 'a' || 'z' < c) {
      break;
    }

    plate[i] = c;
    i++;
  }

  int p = 0;

  for (int u = i - 1; u >= 0; u--) {
    long e = plate[u] - 'a' + 1;

    num += pow(26, p) * e;
    p++;
  }

  printf("%ld\n", num);

  return 0;
}
