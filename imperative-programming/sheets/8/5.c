#include <stdio.h>
#include <assert.h>
int decimal(char str[]) {
    int i = 0;
    
    long r = 0;
    
    int base = 48;
    
    while (str[i] != '\0') {
        assert('0' <= str[i] && str[i] <= '9');
        
        r *= 10;
        r += str[i] - base;
        
        i++;
    }
    
    return r;
}

int main() {
    printf("%d\n", decimal("12345"));
}