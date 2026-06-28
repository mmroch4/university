#include <stdio.h>

int FLAG;
int L, C;
int CELLS;
int CURRENT_DIRECTION = 0;
char DIRECTIONS[] = {'E', 'S', 'W', 'N'};
int CURRENT_POSITION[] = {0, 0};
int IS_DRAWING = 0;
int PAINTED_CELLS = 0;

void drawPosition(int x, int y, char grid[L][C], int paintedRows[L],
                  int paintedCols[C]) {
  if (grid[y][x] == '*') {
    return;
  }

  grid[y][x] = '*';
  PAINTED_CELLS++;
  paintedRows[y]++;
  paintedCols[x]++;
}

void bootstrapGrid(char grid[L][C], int paintedRows[L], int paintedCols[C]) {
  for (int y = 0; y < L; y++) {
    for (int x = 0; x < C; x++) {
      grid[y][x] = '.';
    }
  }

  for (int y = 0; y < L; y++) {
    paintedRows[y] = 0;
  }

  for (int x = 0; x < C; x++) {
    paintedCols[x] = 0;
  }

  if (IS_DRAWING) {
    // STARTS DRAWING
    int x = CURRENT_POSITION[0];
    int y = CURRENT_POSITION[1];

    drawPosition(x, y, grid, paintedRows, paintedCols);
  }
}

int validateInstruction(char instruction) {
  // 0 -> valid
  // 1 -> next instruction
  // 2 -> terminate
  if (instruction == 'e') {
    return 2;
  }

  if (instruction == 'U' || instruction == 'D' || instruction == 'L' ||
      instruction == 'R' || instruction == 'F') {
    return 0;
  }

  return 1;
}

void stopDrawing() { IS_DRAWING = 0; }

void startDrawing(char grid[L][C], int paintedRows[L], int paintedCols[C]) {
  IS_DRAWING = 1;

  int x = CURRENT_POSITION[0];
  int y = CURRENT_POSITION[1];

  drawPosition(x, y, grid, paintedRows, paintedCols);
}

void rotateLeft() {
  if (CURRENT_DIRECTION == 0) {
    CURRENT_DIRECTION = 3;
  } else {
    CURRENT_DIRECTION = (CURRENT_DIRECTION - 1) % 4;
  }
}

void rotateRight() { CURRENT_DIRECTION = (CURRENT_DIRECTION + 1) % 4; }

void moveForward(char grid[L][C], int paintedRows[L], int paintedCols[C]) {
  int steps;

  scanf("%d", &steps);

  while (steps--) {
    switch (CURRENT_DIRECTION) {
    case 0:
      if (CURRENT_POSITION[0] + 1 >= C) {
        CURRENT_POSITION[0] = C - 1;
      } else {
        CURRENT_POSITION[0]++;
      }

      break;
    case 1:
      if (CURRENT_POSITION[1] + 1 >= L) {
        CURRENT_POSITION[1] = L - 1;
      } else {
        CURRENT_POSITION[1]++;
      }
      break;
    case 2:
      if (CURRENT_POSITION[0] - 1 < 0) {
        CURRENT_POSITION[0] = 0;
      } else {
        CURRENT_POSITION[0]--;
      }
      break;
    case 3:
      if (CURRENT_POSITION[1] - 1 < 0) {
        CURRENT_POSITION[1] = 0;
      } else {
        CURRENT_POSITION[1]--;
      }
      break;
    }

    if (IS_DRAWING) {
      int x = CURRENT_POSITION[0];
      int y = CURRENT_POSITION[1];

      drawPosition(x, y, grid, paintedRows, paintedCols);
    }
  }
}

void processInstruction(char instruction, char grid[L][C], int paintedRows[L],
                        int paintedCols[C]) {
  switch (instruction) {
  case 'U': {
    // printf("- STOP DRAWING\n");
    stopDrawing();
    break;
  }
  case 'D': {
    // printf("- START DRAWING\n");

    startDrawing(grid, paintedRows, paintedCols);
    break;
  }
  case 'F': {
    // printf("FOWARD: %c\n", DIRECTIONS[CURRENT_DIRECTION]);

    moveForward(grid, paintedRows, paintedCols);
    break;
  }
  case 'L': {
    // printf("ROTATE LEFT: %c -> ", DIRECTIONS[CURRENT_DIRECTION]);
    rotateLeft();
    // printf("%c\n", DIRECTIONS[CURRENT_DIRECTION]);
    break;
  }
  case 'R': {
    // printf("ROTATE RIGHT: %c -> ", DIRECTIONS[CURRENT_DIRECTION]);

    rotateRight();
    // printf("%c\n", DIRECTIONS[CURRENT_DIRECTION]);

    break;
  }
  default: {
    return;
  }
  }
}

void displayGrid(char grid[L][C]) {
  for (int y = 0; y < L; y++) {
    for (int x = 0; x < C; x++) {
      printf("%c", grid[y][x]);

      if (x != C - 1) {

        printf(" ");
      }
    }

    printf("\n");
  }
}

int getUnpaintedRows(int paintedRows[L]) {
  int counter = 0;

  for (int y = 0; y < L; y++) {
    if (!paintedRows[y]) {
      counter++;
    }
  }

  return counter;
}

int getUnpaintedCols(int paintedCols[C]) {
  int counter = 0;

  for (int x = 0; x < C; x++) {
    if (!paintedCols[x]) {
      counter++;
    }
  }

  return counter;
}

void displayInfo(int paintedRows[L], int paintedCols[C]) {
  int paintedCellsPercentage = (PAINTED_CELLS * 100) / CELLS;

  printf("%d %d %d\n", paintedCellsPercentage, getUnpaintedRows(paintedRows),
         getUnpaintedCols(paintedCols));
}

void verifyPattern(char grid[L][C]) {
  int n, m;

  scanf("%d %d", &n, &m);

  char pattern[n][m];

  char cell;
  int p = 0;

  while (scanf("%c", &cell) && p < n * m) {
    if (cell != '.' && cell != '*')
      continue;

    pattern[p / m][p % m] = cell;

    p++;
  }

  for (int y = 0; y <= L - n; y++) {
    for (int x = 0; x <= C - m; x++) {
      int matches = 1;
          
      for (int a = 0; a < n && matches; a++) {          
        for (int b = 0; b < m && matches; b++) {
          if (pattern[a][b] != grid[a + y][b + x]) {
            matches = 0;
            continue;
          }
        }
      }

      if (matches) {
        printf("Sim\n");
        return;
      }
    }
  }

  printf("Nao\n");
  return;
}

int main() {
  scanf("%d", &FLAG);
  scanf("%d %d", &L, &C);

  CELLS = L * C;

  char GRID[L][C];
  int PAINTED_ROWS[L], PAINTED_COLS[C];

  bootstrapGrid(GRID, PAINTED_ROWS, PAINTED_COLS);

  char instruction;

  while (scanf("%c", &instruction)) {
    int code = validateInstruction(instruction);

    if (code == 2) {
      scanf("%c", &instruction);
      scanf("%c", &instruction);
      break;
    } else if (code == 1) {
      continue;
    }

    processInstruction(instruction, GRID, PAINTED_ROWS, PAINTED_COLS);
  }

  switch (FLAG) {
  case 0:
    displayGrid(GRID);
    break;
  case 1:
    displayInfo(PAINTED_ROWS, PAINTED_COLS);
    break;
  case 2:
    verifyPattern(GRID);
    break;
  }

  return 0;
}
