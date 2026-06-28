#include <math.h>
#include <stdio.h>

int main() {
  int currency[] = {20, 10, 5, 1};
  int amount;

  printf("Amount in EUR? ");
  scanf("%d", &amount);

  for (int i = 0; i < 4; i++) {
    int m = floor(amount / currency[i]);

    amount %= currency[i];

    printf("EUR %d %s: %d\n", currency[i], i == 3 ? "coins" : "notes", m);
  }

  return 0;
}
