#include <assert.h>
int min(int a, int b) {
    return a <= b ? a : b;
}

int max(int a, int b) {
    return a >= b ? a : b;
}

int minOf3(int a, int b, int c) {
    return min(min(a, b), c);
}

int maxOf3(int a, int b, int c) {
    return max(max(a, b), c);
}

int median(int a, int b, int c) {
    int r;
    
    if (a <= b && b <= c) {
        r = b;
    }
    else if (a <= c && c <= b) {
        r = c;
    }
    else if (b <= a && a <= c) {
        r = a;
    }
    else if (b <= c && c <= a) {
        r = c;
    }
    else if (c <= a && a <= b) {
        r = a;
    }
    else if (c <= b && b <= a) {
        r = b;
    }
    
    assert(minOf3(a, b, c) <= r && r <= maxOf3(a, b, c));
    
    return r;
}
