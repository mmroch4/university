#include <stdio.h>

int get_next_index(int current, int *a, int n) {
    int next = (current + 1) % n;
    
    while (!a[next]) {
        next = (next + 1) % n;
    }
    
    return next;
}

int main() {
    int n, p;
    
    scanf("%d", &n);
    
    int a[n];
    
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    
    int removals = 0;
    int k = 0;
    
    while (removals < n - 1) {
        p = get_next_index(k, a, n);
        
        a[p] = 0;
        removals++;
        k = get_next_index(p, a, n);
    }
    
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            printf("%d\n", a[i]);
            break;
        }
    }
    
    return 0;
}