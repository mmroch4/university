#include <stdio.h>

void spill_rocks(int *field, int n, int x, int s) {
    field[x] += s;
    
    int l = x - 1;
    int r = x + 1;
    int i = s - 1;
    
    while (0 < i) {
        if (0 <= l) {
            field[l] += i;
            l--;
        }
        
        if (r < n) {
            field[r] += i;
            r++;
        }
        
        i--;
    }
}

int main() {
    int n, m, x, s;
    
    scanf("%d %d", &n, &m);
    
    int field[n];
    
    for (int i = 0; i < n; i++) {
        field[i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &s);
        
        spill_rocks(field, n, --x, s);
    }

    for (int i = 0; i < n; i++) {
        printf("%d", field[i]);
        
        printf(i != n - 1 ? " " : "\n");
    }
}