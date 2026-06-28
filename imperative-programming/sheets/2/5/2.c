#include <stdio.h>

int main() {
  int n;

  scanf("%d", &n);

  if (n == 1) {
      printf("1 multiplicity 1");
      
      return 0;
  }
  
  int PRIMES[] = {2, 3, 5, 7, 11, 13, 17, 19, 23}; // DEPENDS ON THIS PRIMES LIST

  int i = 0;
  int count = 0;

  while (1 < n) {
    while (n % PRIMES[i] == 0) {
        n /= PRIMES[i];
        count++;
    }
    
    if (0 < count) {
      printf("%d multiplicity %d\n", PRIMES[i], count);
    }
      
    i++;
    count = 0;
  }

  return 0;
}
