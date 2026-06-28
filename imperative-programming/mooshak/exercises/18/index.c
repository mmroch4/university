#include <stdio.h>

int MAX = 100000;

int main() {
  char word[MAX];

  char c;
  
  int n = 0;
  
  while (scanf("%c", &c) != -1) {
      if (c == '\n' || c == '\0') break;
      word[n] = c;
      n++;
  }
      
  int middle = n / 2;

  int counter = 0;

  for (int i = 0; i < middle; i++) {
    if (word[i] != word[n - i - 1]) {
      counter++;
    }
  }

  if (counter) {
    printf(
        "Oh boy, this needs a fix. You have to change at least %d characters\n",
        counter);
  } else {
    printf("Inspection passed\n");
  }

  return 0;
}
