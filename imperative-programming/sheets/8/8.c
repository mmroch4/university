#include <assert.h>
void insert(int vec[], int n, int x) {
  for (int i = 0; i < n - 1; i++) {
    assert(vec[i] <= vec[i + 1]);
  }

  int j = n - 1;
  while (j >= 0 && vec[j] > x) {
    vec[j + 1] = vec[j];
    j--;
  }
  vec[j + 1] = x;
  
  for (int i = 0; i < n; i++) {
    assert(vec[i] <= vec[i + 1]);
  } 
}
