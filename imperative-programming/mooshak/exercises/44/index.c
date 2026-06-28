#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) (a <= b ? a : b)
#define MAX(a, b) (a >= b ? a : b)

int main() {
    int n, m, x, y, k, v = 1, h = 1;
    
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

    while (k) {
        int a = n, b = m;
        
        if (h == -1) {
            a = 1;
        }

        if (v == -1) {
            b = 1;
        }

        

        int l = MIN(abs(x - a), abs(y - b));

        l = MIN(l, k);

        x += h * l;
        y += v * l;

        if (x == n) {
            h = -1;
        }
        else if (x == 1) {
            h = 1;
        }

        if (y == m) {
            v = -1;
        }
        else if (y == 1) {
            v = 1;
        }
             
        k -= l;
    }

    printf("%d %d\n", x, y);
    
    return 0;
}