#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int N = 30;
int M = 60;
int BORDER_LENGTH = 1;
int BALL_RADIUS = 4;
int DIRECTIONS[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
int CURRENT_DIRECTION = 0;

void draw(int grid[N][M]) {
  for (int i = 0; i < N; i++) {
    for (int u = 0; u < M; u++) {
      switch (grid[i][u]) {
      case 0:
        printf("\x1b[48;5;235m ");
        break;
      case 1:
        printf("\x1b[38;5;220m*");
        break;
      case 2:
        char color[2] = "88";

        if (u < 3 || i < 3 || i > N - 3 - 1 || u > M - 3 - 1) {
          color[0] = '2';
          color[1] = '1';
        } else if (u < 5 || i < 5 || i > N - 5 - 1 || u > M - 5 - 1) {
          color[0] = '4';
          color[1] = '5';
        } else if (u < 8 || i < 8 || i > N - 8 - 1 || u > M - 8 - 1) {
          color[0] = '6';
          color[1] = '1';
        }

        printf("\x1b[38;5;%sm@", color);
        break;
      default:
        printf("\x1b[38;5;1m~");
        break;
      }
    }

    printf("\n");
  }
}

void setGrid(int grid[N][M], int v) {
  for (int i = 0; i < N; i++) {
    for (int u = 0; u < M; u++) {
      grid[i][u] = v;
    }
  }
}

void setBorders(int grid[N][M]) {
  for (int i = 0; i < M; i++) {
    grid[0][i] = 1;
    grid[N - 1][i] = 1;
  }

  for (int u = 0; u < N; u++) {
    grid[u][0] = 1;
    grid[u][M - 1] = 1;
  }
}

void drawBallInitialPosition(int r, int c, int grid[N][M], int left) {
  if (grid[r][c] == 1 || left < 0) {
    return;
  }

  grid[r][c] = 2;

  left--;

  drawBallInitialPosition(r - 1, c, grid, left);
  drawBallInitialPosition(r + 1, c, grid, left);
  drawBallInitialPosition(r, c - 1, grid, left);
  drawBallInitialPosition(r, c + 1, grid, left);
}

void setBallInitialPosition(int grid[N][M]) {
  int middle[2] = {N / 2, M / 2};

  drawBallInitialPosition(middle[0], middle[1], grid, BALL_RADIUS);

  grid[middle[0] - BALL_RADIUS][middle[1]] = 0;
  grid[middle[0] + BALL_RADIUS][middle[1]] = 0;
  grid[middle[0]][middle[1] - BALL_RADIUS] = 0;
  grid[middle[0]][middle[1] + BALL_RADIUS] = 0;
}

bool verifyTopCollision(int grid[N][M]) {
  for (int i = 0; i < M; i++) {
    if (grid[1][i] == 2) {
      return true;
    }
  }

  return false;
}

bool verifyBottomCollision(int grid[N][M]) {
  for (int i = 0; i < M; i++) {
    if (grid[N - 2][i] == 2) {
      return true;
    }
  }

  return false;
}

bool verifyRightCollision(int grid[N][M]) {
  for (int i = 0; i < N; i++) {
    if (grid[i][M - 2] == 2) {
      return true;
    }
  }

  return false;
}

bool verifyLeftCollision(int grid[N][M]) {
  for (int i = 0; i < N; i++) {
    if (grid[i][1] == 2) {
      return true;
    }
  }

  return false;
}

bool verifyCollisions(int grid[N][M]) {
  switch (CURRENT_DIRECTION) {
  case 0:
    return verifyBottomCollision(grid) || verifyRightCollision(grid);
    break;
  case 1:
    return verifyTopCollision(grid) || verifyRightCollision(grid);
    break;
  case 2:
    return verifyTopCollision(grid) || verifyLeftCollision(grid);
    break;
  case 3:
    return verifyBottomCollision(grid) || verifyLeftCollision(grid);
    break;
  default:
    return false;
    break;
  }
}

void changeDirection(int grid[N][M]) {
  int options[4] = {1, 1, 1, 1};

  if (verifyTopCollision(grid)) {
    options[1] = 0;
    options[2] = 0;
  } else if (verifyBottomCollision(grid)) {
    options[0] = 0;
    options[3] = 0;
  }

  if (verifyRightCollision(grid)) {
    options[0] = 0;
    options[1] = 0;
  } else if (verifyLeftCollision(grid)) {
    options[2] = 0;
    options[3] = 0;
  }

  int available = 0;
  int toChoose[4] = {0};

  for (int i = 0; i < 4; i++) {
    if (options[i] == 1) {
      toChoose[available] = i;
      available++;
    }
  }

  int chosen = rand() % available;

  CURRENT_DIRECTION = toChoose[chosen];
}

void moveBall(int grid[N][M]) {
  int updatedGrid[N][M];

  setGrid(updatedGrid, 0);
  setBorders(updatedGrid);

  while (verifyCollisions(grid)) {
    changeDirection(grid);
  }

  int VECTOR[2] = {DIRECTIONS[CURRENT_DIRECTION][0],
                   DIRECTIONS[CURRENT_DIRECTION][1]};

  for (int i = 0; i < N; i++) {
    for (int u = 0; u < M; u++) {
      if (grid[i][u] == 2) {
        updatedGrid[i + VECTOR[1]][u + VECTOR[0]] = 2;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int u = 0; u < M; u++) {
      grid[i][u] = updatedGrid[i][u];
    }
  }
}

int main() {
  int grid[N][M];

  srand((unsigned)time(NULL));

  setGrid(grid, 0);
  setBorders(grid);
  setBallInitialPosition(grid);

  while (1) {
    moveBall(grid);

    printf("\x1b[2H");
    draw(grid);

    usleep(100000); // 0.1 seconds
  }
}
