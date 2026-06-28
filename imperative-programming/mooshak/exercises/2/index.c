#include <stdio.h>

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int r = 0; r < n; r += 1) {
        for (int c = 0; c < n; c += 1) {
            if ((c + r) % 2 == 0) {
                printf("#");
            }
            else {
                printf("_");
            }
        }
        
        printf("\n");
    }
    
    return 0;
}