#include <stdio.h>

int N, M;

void visit(int x, int y, int visited[N][M], int grid[N][M]) {
    if (x < 0 || M <= x || y < 0 || N <= y) {
        return;
    }

    if (grid[y][x] == '#') return;

    if (visited[y][x]) return;

    visited[y][x] = 1;

    int neighbors[] = {y - 1, x, y + 1, x, y, x - 1, y, x + 1};

    for (int i = 0; i < 8; i += 2) {
        visit(neighbors[i + 1], neighbors[i], visited, grid);
    }
}

int main() {
    char c;
    
    scanf("%d %d", &N, &M);
    getchar(); // clear buffer

    int grid[N][M];
    int visited[N][M];
    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            scanf("%c", &c);

            grid[y][x] = c;
            visited[y][x] = 0;
        }

        getchar(); // clear buffer
    }

    int lakes = 0;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (visited[y][x] || grid[y][x] == '#') {
                continue;
            }
            
            visit(x, y, visited, grid);

            lakes++;
        }
    }

    printf("%d\n", lakes);
}