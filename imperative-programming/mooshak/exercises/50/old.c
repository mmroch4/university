#include <stdio.h>

#define NUM_OF_BACTERIAS 10
#define NEUTRAL_CHARACTER ':'
#define MAX_GROUPS 250000

int N, M;

void printGrid(int grid[N][M]) {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {            
            printf("%c ", grid[y][x]);
        }
        printf("\n");
    }
}

int getBacteriaMaxPower(int a, int b, int powers[NUM_OF_BACTERIAS + 1]) {
    return powers[a - '0'] > powers[b - '0'] ? a : b;
}

int simulate(int x, int y, int group, int grid[N][M], int visited[N][M], int powers[NUM_OF_BACTERIAS + 1], int groups[MAX_GROUPS]) {
    if (x < 0 || M <= x || y < 0 || N <= y) return NEUTRAL_CHARACTER;

    if (grid[y][x] == '#') return NEUTRAL_CHARACTER;
    
    if (visited[y][x]) return NEUTRAL_CHARACTER;

    int max = getBacteriaMaxPower(grid[y][x], groups[group], powers);

    visited[y][x] = 1;
    
    int neighbors[] = {y - 1, x, y + 1, x, y, x - 1, y, x + 1};

    for (int i = 0; i < 8; i += 2) {
        int p = simulate(neighbors[i + 1], neighbors[i], max, grid, visited, powers);

        max = getBacteriaMaxPower(max, p, powers);
    }

    grid[y][x] = max;
    
    return max;
}

int main() {
    scanf("%d %d", &N, &M);
    getchar(); // clean buffer;

    int grid[N][M];
    int visited[N][M];
    int powers[NUM_OF_BACTERIAS + 1];

    char c;
    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            scanf("%c", &c);
            
            grid[y][x] = c;
            visited[y][x] = 0;
        }

        getchar(); // clear buffer
    }

    int i = 0;

    while (i < NUM_OF_BACTERIAS) {
        scanf("%d", powers + i);
        
        i++;
    }

    powers[NUM_OF_BACTERIAS] = 0;    

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (visited[y][x] != -1 || grid[y][x] == '#') continue;

            simulate(x, y, grid[y][x], grid, visited, powers);
        }
    }

    printGrid(grid);
    
    return 0;
}