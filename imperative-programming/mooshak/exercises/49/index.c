#include <stdio.h>

int N, M, Q;

void visit(int x, int y, char grid[N][M], int visited[N][M]) {
  if (x < 0 || M <= x || y < 0 || N <= y)
    return;

  if (visited[y][x])
    return;

  if (grid[y][x] == '#')
    return;

  visited[y][x] = 1;
  // printf("- Visited %d %d\n", y, x);

  int neighbors[] = {y - 1, x, y + 1, x, y, x - 1, y, x + 1};

  for (int p = 0; p < 8; p += 2) {
    visit(neighbors[p + 1], neighbors[p], grid, visited);
  }
}

int countLakes(char grid[N][M]) {
  int visited[N][M];

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      visited[y][x] = 0;
    }
  }

  int count = 0;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
        // printf("Inspecting %d %d\n", y, x);
      if (visited[y][x] || grid[y][x] == '#')
      {
          // printf("--- Already visited %d %d\n\n", y, x);
          continue;}

      visit(x, y, grid, visited);

      count++;
    }
  }

  return count;
}

void bulldozerRow(int row, char grid[N][M]) {
  for (int x = 0; x < M; x++) {
    grid[row][x] = '.';
  }
}

void bulldozerCol(int col, char grid[N][M]) {
  for (int y = 0; y < N; y++) {
    grid[y][col] = '.';
  }
}

void printLake(char grid[N][M]) {
  printf("\nLAKE:\n");

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      printf("%c ", grid[y][x]);
    }

    printf("\n");
  }

  printf("\n");
}

int main() {
  char c;
  int v;

  scanf("%d %d", &N, &M);
  getchar(); // clear buffer

  char grid[N][M];

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      scanf("%c", &c);

      grid[y][x] = c;
    }

    getchar(); // clear buffer
  }

  // printLake(grid);

  printf("%d\n", countLakes(grid));

  scanf("%d", &Q);
  getchar(); // clear buffer

  while (Q--) {
    scanf("%c %d", &c, &v);
    getchar(); // clear buffer

    v--;

    if (c == 'R') {
      bulldozerRow(v, grid);
    } else {
      bulldozerCol(v, grid);
    }

    // printLake(grid);
    
    printf("%d\n", countLakes(grid));
  }

  return 0;
}
