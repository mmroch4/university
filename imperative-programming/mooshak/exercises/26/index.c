#include <stdio.h>

void move(int from, int to) {
    printf("%d -> %d\n", from, to);
}

void hanoi(int discs, int from, int to, int aux) {
    if (discs == 1) {
        move(from, to);    
        return;
    }
    
    hanoi(discs - 1, from, aux, to);
    move(from, to);
    hanoi(discs - 1, aux, to, from);
}

int main() {
    int n ;
    
    scanf("%d", &n);
    hanoi(n, 1, 3, 2);
}