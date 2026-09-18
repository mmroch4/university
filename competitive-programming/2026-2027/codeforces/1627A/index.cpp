#include <stdio.h>

int T, N, M, R, C;
char ch;

int getDistance(int r, int c) {
    int distance = 0;

    if (r != R) {
        distance++;
    }

    if (c != C) {
        distance++;
    }

    return distance;
}

int min(int a, int b) {
    return a <= b ? a : b;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d %d %d", &N, &M, &R, &C);

        R--;
        C--;
        
        scanf("%c", &ch); // read \n

        int distance = 3; // 3 will be converted to -1

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                scanf("%c", &ch); 

                if (ch == 'B') {                    
                    distance = min(distance, getDistance(r, c));
                }
            }

            scanf("%c", &ch); // read \n
        }

        printf("%d\n", distance == 3 ? -1 : distance);
    }
}