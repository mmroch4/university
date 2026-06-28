#include <stdio.h>

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        for (int l = 0; l < n - i; l++) {
            printf("_");
        }
        
        for (int r = n - i; r < n; r++) {
            printf("#");
        }
        
        printf("\n");
    }
    
    return 0;
}