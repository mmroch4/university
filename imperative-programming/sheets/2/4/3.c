#include <stdbool.h>
#include <stdio.h>

int main() {
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);

  if (a <= 0 || b <= 0 || c <= 0) {
    printf("(%d, %d, %d) cannot define a triangle", a, b, c);

    return 1;
  }

  bool satisfy_property = false;

  if (a < b + c) {
    satisfy_property = true;
  }

  if (b < a + c) {
    satisfy_property = true;
  }

  if (c < a + b) {
    satisfy_property = true;
  }

  if (!satisfy_property) {
    printf("(%d, %d, %d) cannot define a triangle", a, b, c);

    return 1;
  }

  int measures[] = {a, b, c};
  int uniques[] = {0, 0, 0};
  int count = 0;

  for (int i = 0; i < 3; i++) {
    bool has = false;

    for (int u = 0; u < 3; u++) {
      if (measures[i] == uniques[u]) {
        has = true;
      }
    }

    if (!has) {
      uniques[i] = measures[i];
      count++;
    }
  }

  if (count == 1) {
    printf("(%d, %d, %d) defines a equilateral triangle", a, b, c);
  } else if (count == 2) {
    printf("(%d, %d, %d) defines a isosceles triangle", a, b, c);
  } else {
    printf("(%d, %d, %d) defines a scalene triangle", a, b, c);
  }

  return 0;
}
