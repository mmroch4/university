#include <stdio.h>
#include <math.h>

void printNum(int n, int len) {
    int v[len];
    
    int i = len - 1;
    
    while (i >= 0) {
        v[i] = n % 2;
        
        n = floor((double)n / 2);
        
        i--;
    }
        
    i = 0;
    
    while (i < len) {
        printf("%d", v[i]);
        
        i++;
    }
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < pow(2, (double)n); i++) {
        printNum(i, n);
        printf("\n");
    }
    
    return 0;
}