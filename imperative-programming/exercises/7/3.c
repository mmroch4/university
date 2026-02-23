#include <math.h>
#include <stdio.h>

void get_factorization(int *PRIMES, int *factorization, int n) {
  int i = 0;
  int count = 0;

  while (1 < n) {
    while (n % PRIMES[i] == 0) {
      n /= PRIMES[i];
      count++;
    }

    if (0 < count) {
      factorization[i] = count;
    }

    i++;
    count = 0;
  }
}

int main() {
  int a, b;

  scanf("%d %d", &a, &b);

  int PRIMES[] = {2,  3,  5,  7, 11,
                  13, 17, 19, 23}; // DEPENDS ON THIS PRIMES LIST
  int PRIMES_LENGTH = 9;
  int FACTORIZATION_A[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int FACTORIZATION_B[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

  get_factorization(PRIMES, FACTORIZATION_A, a);
  get_factorization(PRIMES, FACTORIZATION_B, b);
    
  int mmc = 1;
  
  int m;
  
  for (int i = 0; i < PRIMES_LENGTH; i++) {
      if (FACTORIZATION_A[i] >= FACTORIZATION_B[i]) {
          m = FACTORIZATION_A[i];
      }
      else {
          m = FACTORIZATION_B[i];
      }
            
      if (m != 0) {
          mmc *= pow(PRIMES[i], m);
      }
  }
  
  printf("%d\n", mmc);

  return 0;
}
