#include <math.h>
#include <stdio.h>

int main() {
  float a, b, c;

  scanf("%f %f %f", &a, &b, &c);

  if (a == 0) {
    printf("No roots!");

    return 1;
  }

  float delta = pow(b, 2) - 4 * a * c;

  if (delta < 0) {
    printf("No roots!");

    return 1;
  }

  float x_1 = (-b + sqrt(delta)) / (2 * a);
  float x_2 = (-b - sqrt(delta)) / (2 * a);

  if (x_1 == x_2) {
    printf("With a double root: x = %f", x_1);

    return 0;
  }

  printf("With two distinct roots: x1 = %f and x2 = %f", x_1, x_2);

  return 0;
}
