#include <stdio.h>

void print_array(int *a, int n) {
    printf("[");

    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        
        if (i != n - 1) {
            printf(",");
        }
    }
    
    printf("]\n");
}

int rotate(int n, int k, int i) {
    if (i + k >= n) {
        return i + k - n;
    }
    else if (i + k < 0) {
        return i + k + n;        
    }
    
    return i + k;
}

void shift(int *a, int *c, int n, int k) {    
    for (int i = 0; i < n; i++) {        
        c[rotate(n, k, i)] = a[i];
    }
}

int main() {
    int n, k;
    
    scanf("%d", &n);
    
    int a[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    
    scanf("%d", &k);
    
    print_array(a, n);
    
    int c[n];
    
    shift(a, c, n, k);
    
    printf("After shift(a,%d,%d):\n", n, k);
    
    print_array(c, n);
    
    return 0;
}