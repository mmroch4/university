#include <stdio.h>

int main() {
    char s;
    int count = 0;
    int w = 0;
            
    while (1) {
        int r;
        r = scanf("%c", &s);
        
        if (r == -1) {
            count += w;
            break;
        }
        
        if (s == ' ' || s == '\t' || s == '\n') {
            count += w;
            w = 0;
        }
        else {
            w = 1;
        }  
    }
    
    printf("The text contains %d words.\n", count);
    
    return 0;
}