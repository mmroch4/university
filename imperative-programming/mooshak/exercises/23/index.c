#include <stdio.h>

int search(int *arr, int l, int r, int v) {
  if (r < l)
    return 0;

  int middle = (r + l) / 2;

  if (arr[middle] <= v) {
    if (l == r) {
      return arr[middle];
    }

    return search(arr, middle + 1, r, v);
  } else {
    if (middle == 0) {
      return 0;
    }

    if (arr[middle - 1] <= v) {
      return arr[middle - 1];
    }

    return search(arr, l, middle - 1, v);
  }
}

int main() {
  int n, m;

  scanf("%d", &n);

  int a[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  scanf("%d", &m);

  int v;

  for (int i = 0; i < m; i++) {
    scanf("%d", &v);

    printf("%d", search(a, 0, n - 1, v));

    if (i != m - 1) {
      printf(" ");
    }
  }

  printf("\n");

  return 0;
}
