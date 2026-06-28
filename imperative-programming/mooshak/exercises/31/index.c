#include <limits.h>
#include <stdio.h>
#include <math.h>

int N;

long min(long a, long b) {
    return a <= b ? a : b;
}

long get_min_transition(int from, int *transitions, int used) {
    if (used == pow(2, (double)N) - 1) {
        return 0;
    }
    
    long m = LONG_MAX;
    
    for (int i = 0; i < N; i++) {
         if (used & (1 << i)) continue;
         
         m = min(m, *(transitions + from * N + i) + get_min_transition(i, transitions, used | (1 << i)));
    }
    
    return m;
}

int main() {

  scanf("%d", &N);

  int transitions[N][N];
  
  for (int i = 0; i < N * N; i++) {
    scanf("%d", transitions[0] + i);
  }
  
  long m = LONG_MAX;
  
  for (int i = 0; i < N; i++) {
      m = min(m, get_min_transition(i, transitions[0], 1 << i));
  }
  
  printf("%ld\n", m);

  return 0;
}
