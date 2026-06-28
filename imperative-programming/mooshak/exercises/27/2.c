#include <stdio.h>

int N;

void generate(int size, int *t) {
  if (size == 0) {
    for (int i = 0; i < N; i++) {
      printf("%d", *(t + i));
    }
    
    printf("\n");

    return;
  }

  for (int j = 0; j < 2; j++) {
    *(t + N - size) = j;
    generate(size - 1, t);
  }
}

int main() {
  scanf("%d", &N);

  int t[N];

  generate(N, t);

  return 0;
}
