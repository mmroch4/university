#include <stdio.h>

int L, C, I;

int NEIGHBOURS_COUNT = 8;

void setGrid(char grid[L][C]) {
  char cell;

  int p = 0;

  while (scanf("%c", &cell) && p < L * C) {
    if (cell != '.' && cell != 'O')
      continue;

    grid[p / C][p % C] = cell;

    p++;
  }
}

int getNeighboursLiving(char grid[L][C], int r, int c) {
  int counter = 0;

  int neighbours[][2] = {{r - 1, c - 1}, {r - 1, c},    {r - 1, c + 1},
                         {r, c - 1},     {r, c + 1},    {r + 1, c - 1},
                         {r + 1, c},     {r + 1, c + 1}};

  for (int u = 0; u < NEIGHBOURS_COUNT; u++) {
    int y = neighbours[u][0];
    int x = neighbours[u][1];

    if (x < 0 || C <= x || y < 0 || L <= y)
      continue;

    counter += grid[y][x] == 'O';
  }

  return counter;
}

void displayGrid(char grid[L][C]) {
  for (int y = 0; y < L; y++) {
    for (int x = 0; x < C; x++) {
      printf("%c", grid[y][x]);
    }

    printf("\n");
  }
}

char getUpdatedCellValue(int x, int y, char grid[L][C]) {
  int livingNeighbours = getNeighboursLiving(grid, y, x);

  int isAlive = grid[y][x] == 'O';

  if (isAlive) {
    if (livingNeighbours == 0 || livingNeighbours == 1) {
      return '.';
    } else if (livingNeighbours == 2 || livingNeighbours == 3) {
      return 'O';
    }
    else {
        return '.';
    }
  }
  else {
      if (livingNeighbours == 3) {
          return 'O';
      }
      else {
          return '.';
      }
  }
}

void simulateIteration(char grid[L][C]) {
  char temp_grid[L][C];

  for (int y = 0; y < L; y++) {
    for (int x = 0; x < C; x++) {
      temp_grid[y][x] = getUpdatedCellValue(x, y, grid);
    }
  }

  for (int y = 0; y < L; y++) {
    for (int x = 0; x < C; x++) {
      grid[y][x] = temp_grid[y][x];
    }
  }
}

int main() {
  scanf("%d %d %d", &L, &C, &I);

  char grid[L][C];

  setGrid(grid);

  while (I--) {
    simulateIteration(grid);
  }

  displayGrid(grid);

  return 0;
}
