#include <stdio.h>

int main() {
    float p;
    
    scanf("%f", &p);
    
    if (p <= 1000) {
        p *= 0.95;
    }
    else if (1000 < p && p <= 2500) {
        p *= 0.9;
    }
    else if (2500 < p && p <= 5000) {
        p *= 0.8;
    }
    else {
        p *= 0.6;
    }
    
    printf("%f", p);
    
    return 0;
}