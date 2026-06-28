#include <stdio.h>

void swap(long *p, long *q) {
    long t = *p;
    *p = *q;
    *q = t;
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    long a[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%ld", a + i);
    }
    
    for (int u = 0; u < n - 1; u++) {
        for (int i = 0; i < n - u; i++) {
            if (a[i] > a[i + 1]) {
                swap(a + i, a + i + 1);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%ld", *(a + i));
        
        printf(i != n - 1 ? " " : "\n");
    }
    
    return 0;
}