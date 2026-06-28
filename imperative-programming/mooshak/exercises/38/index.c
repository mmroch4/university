#include <stdio.h>

void merge(int *c, int *a, int n, int *b, int m) {
    int i = 0;
    
    int l = 0;
    int r = 0;
    
    while (l < n || r < m) {
        if (l >= n) {
            c[i] = b[r++];
        }
        else if (r >= m) {
            c[i] = a[l++];
        }
        else {
            if (a[l] <= b[r]) {
                c[i] = a[l++];
            }
            else {
                c[i] = b[r++];
            }
        }
        
        i++;
    }
}

int main() {
    int n, m;
    
    scanf("%d", &n);
    
    int a[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    
    scanf("%d", &m);
    
    int b[m];
    
    for (int i = 0; i < m; i++) {
        scanf("%d", b + i);
    }
    
    int c[n + m];
    
    merge(c, a, n, b, m);
    
    for (int i = 0; i < n + m; i++) {
        printf("%d", c[i]);
        
        printf(i != n + m - 1 ? " " : "\n");
    }
    
    return 0;
}