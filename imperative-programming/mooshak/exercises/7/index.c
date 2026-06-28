#include <stdio.h>

int main() {
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    int a[n], b[m], c[n + m];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    
    // u -> a[..] | k -> b[..]
    int u = 0, k = 0;
    
    while (u < n || k < m) {
        if (u >= n && k < m) {
            c[u + k] = b[k];
            k++;
            continue;
        }
        
        if (k >= m && u < n) {
            c[u + k] = a[u];
            u++;
            continue;
        }
                
        if (a[u] <= b[k]) {
            c[u + k] = a[u];
            u++;
        }
        else {
            c[u + k] = b[k];
            k++;
        }
    }
    
    for (int i = 0; i < n + m; i++) {
        printf("%d", c[i]);
        
        if (i != n + m - 1) {
            printf(" ");
        }
        else {
            printf("\n");
        }
    }
}