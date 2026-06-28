#include <stdio.h>

int search(int *arr, int l, int r, int v) {
    if (r < l) return 0;
    
    int middle = (r + l) / 2;
        
    if (arr[middle] == v) {
        return 1;
    }
    else if (v < arr[middle]) {
        return search(arr, l, middle - 1, v);
    }
    else {
        return search(arr, middle + 1, r, v);
    }
}

int main() {
    int n, m;
    
    scanf("%d", &n);
    
    int a[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    scanf("%d", &m);
    
    int b[m];
    
    int v;
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &v);

        b[i] = search(a, 0, n - 1, v);
    }
    
    for (int i = 0; i < m; i++) {
        printf(b[i] ? "yes" : "no");
        
        if (i != m - 1) {
            printf(" ");
        }
    }
    
    printf("\n");
    
    return 0;
}