#include <stdio.h>

#define NUM_OF_BACTERIAS 10
#define NEUTRAL_CHARACTER ':'
#define MAX_GROUPS 250000

int N, M;

void printGrid(int grid[N][M]) {
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      printf("%c", grid[y][x]);
    }
    printf("\n");
  }
}

int getBacteriaMaxPower(int a, int b, int powers[NUM_OF_BACTERIAS + 1]) {
  return powers[a - '0'] > powers[b - '0'] ? a : b;
}

void simulate(int x, int y, int group, int grid[N][M], int visited[N][M],
              int powers[NUM_OF_BACTERIAS + 1], int groups[MAX_GROUPS]) {
  if (x < 0 || M <= x || y < 0 || N <= y)
    return;

  if (grid[y][x] == '#')
    return;

  if (visited[y][x])
    return;

  groups[group] = getBacteriaMaxPower(grid[y][x], groups[group], powers);

  visited[y][x] = group;

  int neighbors[] = {y - 1, x, y + 1, x, y, x - 1, y, x + 1};

  for (int i = 0; i < 8; i += 2) {
    simulate(neighbors[i + 1], neighbors[i], group, grid, visited, powers, groups);
  }
}

int main() {
  scanf("%d %d", &N, &M);
  getchar(); // clean buffer;

  int grid[N][M];
  int visited[N][M];
  int powers[NUM_OF_BACTERIAS + 1];

  int groups[MAX_GROUPS + 1];

  for (int i = 0; i <= MAX_GROUPS; i++) {
      groups[i] = NEUTRAL_CHARACTER;
  }

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

  int group = 1;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (visited[y][x] || grid[y][x] == '#')
        continue;

      simulate(x, y, group, grid, visited, powers, groups);

      group++;
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (grid[y][x] == '#')
        continue;

      grid[y][x] = groups[visited[y][x]];
    }
  }

  printGrid(grid);

  return 0;
}
