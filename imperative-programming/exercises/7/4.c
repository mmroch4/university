#include <stdio.h>

int main() {
    int n, x;
    
    scanf("%d %d", &x, &n);
    
    int s = 1;
    
    for (int i = 0; i < x; i++) {
        s *= n;
    }
    
    printf("%d\n", s);
    
    return 0;
}