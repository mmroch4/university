#include <stdio.h>

#define NAME_MAX_LENGTH 200

char CARLOS_NAME[] = "Carlos";

void CLEAR_BUFFER() {
  while (getchar() != '\n') {
  }
}

int getWordsCount() {
  char ch, prev;

  int count = 0;

  while ((ch = getchar()) != '\n') {
    if (ch == ' ' && prev != ' ') {
      count++;
    }

    prev = ch;
  }

  if (prev != ' ')
    count++;

  return count;
}

void getPlayersNames(int k, char playerNames[k][NAME_MAX_LENGTH]) {
  char ch, prev;
  int i = 0;
  int p = 0;

  while ((ch = getchar()) != '\n') {
    if (ch == ' ' && prev != ' ') {
      playerNames[i][p] = '\0';
      i++;
      p = 0;
      prev = ch;
      continue;
    } else if (ch == ' ' && prev == ' ') {
      prev = ch;
      continue;
    }

    playerNames[i][p] = ch;
    p++;
    prev = ch;
  }

  playerNames[i][p] = '\0';
}

int isCarlos(char name[]) {
  int i = 0;

  while (name[i] != '\0') {
    if (name[i] != CARLOS_NAME[i])
      return 0;

    i++;
  }

  return name[i] == CARLOS_NAME[i];
}

int getNextPlayer(int p, int k, int players[k]) {
    while (!players[p]) {
        p = (p + 1) % k;
    }

    return p;
}

int main() {
  int N;

  scanf("%d", &N);
  CLEAR_BUFFER();

  while (N--) {
    int x = getWordsCount();

    int k;
    scanf("%d ", &k);

    int players[k];

    for (int i = 0; i < k; i++) {
      players[i] = 1;
    }

    char playerNames[k][NAME_MAX_LENGTH];

    getPlayersNames(k, playerNames);

    int r = k;
    int s = 0;

    while (1 < r--) {
      int e = x;
      e--;

      while (e--) {
        s = getNextPlayer((s + 1) % k, k, players);
      }

      players[s] = 0;

      s = getNextPlayer((s + 1) % k, k, players);
    }

    if (isCarlos(playerNames[s])) {
        printf("O Carlos nao se livrou\n");
    }
    else {
        printf("O Carlos livrou-se (coitado do %s!)\n", playerNames[s]);
    }
  }

  return 0;
}
