#include <stdio.h>
#include <string.h>

#define GEN_MAX_SIZE 100000

char GEN[GEN_MAX_SIZE];

void read_string(char *s, int max_size) {
  char c;
  int i = 0;

  max_size--;

  while (max_size) {
    c = getchar();

    if (c == EOF || c == '\n' || c == '\0')
      break;

    *(s + i) = c;

    i++;
    max_size--;
  }

  *(s + i) = '\0';
}

void print(char *s) {
  int i = 0;

  while (s[i] != '\0') {
    printf("%c", s[i]);

    i++;
  }

  printf("\n");
}

void simulate() {
  int j = 0;
  int i = 0;

  char new[GEN_MAX_SIZE];

  while (GEN[i] != '\0') {
    if (GEN[i] == 'A') {
      new[j] = 'A';
      new[++j] = 'B';
      j++;
    } else {
      new[j] = 'A';
      j++;
    }

    i++;
  }

  new[j] = '\0';

  strcpy(GEN, new);
}

int main() {
  read_string(GEN, GEN_MAX_SIZE);

  int n;

  scanf("%d", &n);

  print(GEN);

  while (n--) {
    simulate();
    print(GEN);
  }

  return 0;
}
