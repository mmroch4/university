#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
  int year, days;
  int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  scanf("%d %d", &year, &days);

  bool is_current_leap = year % 4 == 0 && year % 100 != 0;
  
  if (is_current_leap) {
      months[2] = 29;
  }
  
  int i = 0;
  
  while (days > months[i]) {
      days -= months[i];
      
      i++;
  }
  
  i += 1;
  
  printf("%d/%d/%d", days, i, year);
  
  return 0;
}
