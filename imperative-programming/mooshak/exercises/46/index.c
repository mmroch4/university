#include <stdio.h>

#define MAX(a, b) (a >= b ? a : b)

int isOutOfBounds(int x, int y, int r, int c) {
  return 0 > x || c <= x || 0 > y || y >= r;
}

int visit(int x, int y, int r, int c, int grid[r][c], int visited[r][c]) {
  if (isOutOfBounds(x, y, r, c)) return 0;

  if (visited[y][x]) return 0;

  if (grid[y][x] != '#') return 0;
  
  visited[y][x] = 1;
  
  int neighbours[] = {
      x + 1, y, 
      x - 1, y, 
      x, y + 1, 
      x, y - 1,
      x - 1, y - 1,
      x + 1, y - 1,
      x + 1, y + 1,
      x - 1, y + 1
  };

  int count = 1;
  
  for (int i = 0; i < 16; i += 2) {
      count += visit(neighbours[i], neighbours[i + 1], r, c, grid, visited);
  }

  return count;
}

int main() {
  int T, R, C;

  scanf("%d", &T);

  while (T--) {
    scanf("%d %d", &R, &C);

    getchar();

    int grid[R][C];
    int visited[R][C];

    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        grid[y][x] = getchar();
        visited[y][x] = 0;
      }

      getchar();
    }

    int largest = 0;

    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        if (grid[y][x] != '#' || visited[y][x])
          continue;
        
        int v = visit(x, y, R, C, grid, visited);

        largest = MAX(largest, v);
      }
    }

    printf("%d\n", largest);
  }

  return 0;
}
