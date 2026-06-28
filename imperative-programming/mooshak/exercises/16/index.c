#include <math.h>
#include <stdio.h>

#define THRESHOLD_SIZE 20

unsigned short THRESHOLD[THRESHOLD_SIZE];

unsigned short POSITION = 0;
unsigned short COUNTER = 1;

void clearThreshold() {
  for (int i = 0; i < THRESHOLD_SIZE; i++) {
    THRESHOLD[i] = 0;
  }
}

char matchChar(int value) {
  switch (value) {
  case 23:
    return 'A';
  case 469:
    return 'B';
  case 1885:
    return 'C';
  case 117:
    return 'D';
  case 1:
    return 'E';
  case 349:
    return 'F';
  case 477:
    return 'G';
  case 85:
    return 'H';
  case 5:
    return 'I';
  case 6007:
    return 'J';
  case 471:
    return 'K';
  case 373:
    return 'L';
  case 119:
    return 'M';
  case 29:
    return 'N';
  case 1911:
    return 'O';
  case 1501:
    return 'P';
  case 7639:
    return 'Q';
  case 93:
    return 'R';
  case 21:
    return 'S';
  case 7:
    return 'T';
  case 87:
    return 'U';
  case 343:
    return 'V';
  case 375:
    return 'W';
  case 1879:
    return 'X';
  case 7543:
    return 'Y';
  case 1909:
    return 'Z';
  case 96119:
    return '1';
  case 22391:
    return '2';
  case 5495:
    return '3';
  case 1367:
    return '4';
  case 341:
    return '5';
  case 1877:
    return '6';
  case 7637:
    return '7';
  case 30581:
    return '8';
  case 122333:
    return '9';
  case 489335:
    return '0';
  default:
    return '-';
  }
}

void identifyChar() {
  int sum = 0;

  int i = 0;

  while (THRESHOLD[i] != 0) {
    sum = sum << (THRESHOLD[i] + 1);
    sum += (int)pow(2, THRESHOLD[i]) - 1;

    i++;
  }

  printf("%c", matchChar(sum));
}

void decode(char prev) {
  if (prev == '0') {
    switch (COUNTER) {
    case 1:
      COUNTER = 1;
      break;
    case 3:
      identifyChar();
      clearThreshold();
      COUNTER = 1;
      POSITION = 0;
      break;
    case 7:
      identifyChar();
      printf(" ");
      clearThreshold();
      COUNTER = 1;
      POSITION = 0;
      break;
    }

    return;
  }

  THRESHOLD[POSITION] = COUNTER;
  COUNTER = 1;
  POSITION++;
}

int main() {
  char current, prev;

  scanf("%c", &prev);

  while (scanf("%c", &current)) {
    if (current != '0' && current != '1') {
      break;
    }

    if (current == prev) {
      COUNTER++;
      prev = current;
      continue;
    }

    decode(prev);

    prev = current;
  }

  THRESHOLD[POSITION] = COUNTER;
  identifyChar();

  printf("\n");

  return 0;
}
