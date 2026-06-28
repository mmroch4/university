#include <stdio.h>

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int remainder = i % 2;
        
        for (int c = 0; c < n; c++) {
            char ch = '#';
            
            if ((c + remainder) % 2 == 1) {
                ch = '_';
            }
            
            printf("%c", ch);
        }
        
        printf("\n");
    }
    
    return 0;
}