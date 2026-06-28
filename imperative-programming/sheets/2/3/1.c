#include <stdio.h>

int main() {
  float l, w, h;

  scanf("%f %f %f", &l, &w, &h);

  printf("LxWxH: %f*%f*%f (cm)", l, w, h);
  
  float v = l * w * h;
  
  printf("Volume: %f (cm^3", v);

  return 0;
}
