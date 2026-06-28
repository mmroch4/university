#include <stdio.h>

#define MAX_INPUT_SIZE 100000
#define CLEAN_BUFFER                                                           \
  {                                                                            \
    while (getchar() != '\n') {                                                \
    }                                                                          \
  }

int main() {
  int n;
  char ch;

  scanf("%d", &n);
  CLEAN_BUFFER;

  while (n--) {
    char stack[MAX_INPUT_SIZE];
    int p = 0;
    int i = 0;

    int code = 0;

    while ((ch = getchar()) != '\n') {
      if (ch == '(' || ch == '[') {
        stack[p] = ch;
        p++;
      } else if (ch == ')' || ch == ']') {
        p--;

        if (p < 0 || (stack[p] == '[' && ch == ')') ||
            (stack[p] == '(' && ch == ']')) {
          code = 1;
          CLEAN_BUFFER;
          break;
        }

        stack[p] = '\0';
      }

      i++;
    }

    if (p != 0 && code != 1) {
      code = 2;
    }

    switch (code) {
    case 0: {
      printf("Expressao bem formada\n");
      break;
    }
    case 1: {
      printf("Erro na posicao %d\n", i);
      break;
    }
    case 2: {
      printf("Ficam parenteses por fechar\n");
      break;
    }
    }
  }

  return 0;
}
