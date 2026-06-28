#include <stdbool.h>
#include <stdio.h>

bool even(int x) { return x % 2 == 0; }

int min(int x, int y) { return x <= y ? x : y; }

int max(int x, int y) { return x >= y ? x : y; }

int main() {
  int n, i, u;

  scanf("%d", &n);

  int nums[n];

  for (i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
  }

  for (i = 0; i < n - 1; i++) {
    for (u = 0; u < n - 1 - i; u++) {

      int a = nums[u];
      int b = nums[u + 1];
      int c;
      //printf("comparing %d: %d | %d: %d\n", u, a, u + 1, b);

      if (even(a) && even(b)) {
        a = min(nums[u], nums[u + 1]);
        b = max(nums[u], nums[u + 1]);

        // printf("-- aqui a: %d | b: %d\n", a, b);
        // printf("- %d %d -> max: %d  min: %\n", nums[u], nums[u + 1],
        // max(nums[u], nums[u + 1]), min(nums[u], nums[u + 1]));
      } else if (even(a) && !even(b)) {
        c = a;
        a = b;
        b = c;
      } else if (!even(a) && even(b)) {
      } else {
        a = min(nums[u], nums[u + 1]);
        b = max(nums[u], nums[u + 1]);
      }
      
      //printf("--got a: %d | b: %d\n", a, b);

      nums[u] = a;
      nums[u + 1] = b;
    }
  }

  for (i = 0; i < n; i++) {
    printf("%d", nums[i]);

    printf(i != n - 1 ? " " : "\n");
  }

  return 0;
}
