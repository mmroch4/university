#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    scanf("%d", &n);
    
    int mountains[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &mountains[i]);
    }
    
    int m = abs(mountains[0] - mountains[n - 1]);
    int k = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int diff = abs(mountains[i] - mountains[i + 1]);

        if (diff > m) {
            m = diff;
            k = i + 1;
        }
    }
        
    int trail[n];
    int c = 0;
    
    while (c < n) {
        trail[c] = mountains[k];
        
        k++;
        
        if (k == n) k = 0;
        
        c++;
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d", trail[i]);
        
        if (i != n - 1) {
            printf(" ");
        }
        else {
            printf("\n");
        }
    }
}
