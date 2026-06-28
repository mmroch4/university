#include <stdio.h>

unsigned long long factorial(int n) {
  if (n <= 0)
    return 1;

  return n * factorial(n - 1);
}

unsigned long long productRange(int a, int b) {
  if (a == b)
    return a;

  return b * productRange(a, b - 1);
}

unsigned long long binom(int n, int k) {
  if (k == 0)
    return 1;

  return productRange(n - k + 1, n) / factorial(k);
}

int main() {
  int n;

  scanf("%d", &n);

  unsigned long long pascal[n];

  int k = n / 2;
  int l = k + (n % 2);

  for (int i = 0; i < l; i++) {
    pascal[i] = binom(n - 1, i);
  }

  int p = 0;

  while (p < k) {
    pascal[n - p - 1] = pascal[p];

    p++;
  }

  for (int u = 0; u < n; u++) {
    printf("%llu", pascal[u]);

    printf(u == n - 1 ? "\n" : " ");
  }
}
