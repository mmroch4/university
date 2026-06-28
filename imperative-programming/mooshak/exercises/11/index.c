#include <stdio.h>

int N;

int setupGrid(char grid[N][N + 1]) {
  int isComplete = 1;

  char cell;

  int i = 0;

  // printf("n: %d\n", N);

  while (scanf("%c", &cell) && i < N * N) {
    // printf("i: %d\n", i);
    if (cell != 'X' && cell != 'O' && cell != '.')
      continue;
    // printf("c: %c\n", cell);

    if (cell == '.')
      isComplete = 0;

    grid[i / N][i % N] = cell;

    i++;
  }

  return isComplete;
}

// char verifyColumns(char grid[N][N + 1]) {}

// char verifyRows(char grid[N][N + 1]) {}

// char verifyMainDiagonal(char grid[N][N + 1]) {}

// char verifySecondaryDiagonal(char grid[N][N + 1]) {}

int main() {
  scanf("%d", &N);

  char GRID[N][N + 1];

  int isComplete = setupGrid(GRID);

  // DEBUG GRID
  // for (int i = 0; i < N; i++) {
  //   for (int u = 0; u < N; u++) {
  //     printf("%c", GRID[i][u]);
  //   }
  //   printf("\n");
  // }

  // VERIFY ROWS
  for (int i = 0; i < N; i++) {
    char current = GRID[i][0];
    int has_won = 1;

    for (int u = 1; u < N; u++) {
      if (GRID[i][u] != current) {
        has_won = 0;
        break;
      }
    }

    if (has_won && current != '.') {
      printf("Ganhou o %c\n", current);
      //printf("venceu em linha\n");

      return 0;
    }
  }

  // VERIFY COLS
  for (int u = 0; u < N; u++) {
    char current = GRID[0][u];
    int has_won = 1;

    for (int i = 1; i < N; i++) {
      if (GRID[i][u] != current) {
        has_won = 0;
        break;
      }
    }

    if (has_won && current != '.') {
      printf("Ganhou o %c\n", current);
      //printf("venceu em coluna\n");

      return 0;
    }
  }

  // VERIFY MAIN DIAGONAL
  char current = GRID[0][0];
  int has_won = 1;

  for (int p = 1; p < N; p++) {
    //printf("%d %d %c\n", p, p, GRID[p][p]);
    if (GRID[p][p] != current) {
      has_won = 0;
      break;
    }
  }

  if (has_won && current != '.') {
    printf("Ganhou o %c\n", current);
    //printf("venceu na diagonal principal\n");

    return 0;
  }

  // VERIFY SECONDARY DIAGONAL
  current = GRID[0][N - 1];
  has_won = 1;

  for (int p = 1; p < N; p++) {
    if (GRID[p][N - p - 1] != current) {
      has_won = 0;
      break;
    }
  }

  if (has_won && current != '.') {
    printf("Ganhou o %c\n", current);
    //printf("venceu na diagonal secundária\n");

    return 0;
  }

  printf(!isComplete ? "Jogo incompleto\n" : "Empate\n");

  return 0;
}
