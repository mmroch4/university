// TODO: TO COMPLETE

#include <stdio.h>

#define N 6
#define M 7
#define MAX 100
#define WINNING 4
#define DIRECTIONS_COUNT 8

int isOutOfBounds(int x, int y) { return 0 > x || N <= x || 0 > y || y >= M; }

void updatePosition(int *x, int *y, int direction) {
  switch (direction) {
  case 0:
    *y = *y - 1;
    break;
  case 1:
    *x = *x + 1;
    *y = *y - 1;
    break;
  case 2:
    *x = *x + 1;
    break;
  case 3:
    *x = *x + 1;
    *y = *y + 1;
    break;
  case 4:
    *y = *y + 1;
    break;
  case 5:
    *x = *x - 1;
    *y = *y + 1;
    break;
  case 6:
    *x = *x - 1;
    break;
  case 7:
    *x = *x - 1;
    *y = *y - 1;
    break;
  }
}

int minMovesToWin(int player, int direction, int count, int x, int y,
                  int grid[N][M]) {}

int main() {
  int t;
  char c;

  scanf("%d", &t);
  getchar();

  while (t--) {
    int grid[N][M];

    for (int y = 0; y < N; y++) {
      for (int x = 0; x < M; x++) {
        grid[y][x] = getchar();
      }

      getchar();
    }
  }
  
  return 0;
}
