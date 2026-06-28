#include <stdio.h>

int max(int a, int b) { return a >= b ? a : b; }

int find_pizza(int x, int y, int r, int c, int visited[r][c], int grid[r][c]) {
  if (visited[y][x]) {
    return 0;
  }

  if (grid[y][x] == '#') {
    return 0;
  }

  visited[y][x] = 1;

  if (grid[y][x] == 'P') {
    return 1;
  }

  int p[8] = {y - 1, x, y + 1, x, y, x + 1, y, x - 1};

  for (int i = 0; i < 8; i += 2) {
    int a = p[i];     // y
    int b = p[i + 1]; // x

    if (a < 0 || r <= a || b < 0 || c <= b)
      continue;

    if (find_pizza(b, a, r, c, visited, grid)) {
      return 1;
    }
  }

  return 0;
}

int main() {
  int n, r, c;
  char p;

  scanf("%d", &n);

  while (n--) {
    scanf("%d %d", &r, &c);
    
    getchar();

    int visited[r][c];
    int grid[r][c];

    int start[2];

    for (int i = 0; i < r; i++) {
      int u = 0;

      while (u < c) {
        p = getchar();

        if (p == 'J') {
          start[0] = i;
          start[1] = u;
        }

        grid[i][u] = p;
        visited[i][u] = 0;

        u++;
      }
  
      getchar();
    }

    printf(find_pizza(start[1], start[0], r, c, visited, grid) ? "yes\n" : "no\n");
  }

  return 0;
}
