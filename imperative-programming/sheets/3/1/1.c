#include <stdbool.h>
#include <stdio.h>

int main() {
  char s;
  int sum = 0;

  while (true) {
    scanf("%c", &s);

    if (s == '\n') {
      printf("The sentence contains %d lowercase letters.\n", sum);
      break;
    }
    
    if ('a' <= s && s <= 'z') {
        sum++;
    }
  }

  return 0;
}
