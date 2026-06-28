#include <stdio.h>

int N;

void permutations(int size, int used, int *a) {
    if (size == 0) {
        for (int u = 0; u < N; u++) {
            printf("%d", *(a + u));
            
            printf(u != N - 1 ? " " : "\n");
        }
        
        return;
    }
    
    for (int i = 0; i < N; i++) {
       if (used & (1 << i)) continue;
        
       *(a + N - size) = i + 1;
       
        permutations(size - 1, used | (1 << i), a);
    }
    
}

int main() {    
    scanf("%d", &N);
    
    int a[N];
    
    permutations(N, 0, a);
}