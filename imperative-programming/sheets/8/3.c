#include <stdio.h>
#include <assert.h>
int mdc(int a, int b) {
  assert(a != 0 && b != 0);

  while (a != b) {
    if (a > b)
      a = a - b;
    else
      b = b - a;
  }

  return a;
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("%d\n", mdc(a, b));
}
