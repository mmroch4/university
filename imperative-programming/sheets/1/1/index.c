#include <stdio.h>

int main() {
  int n = 20;
  int sum = 0;
  
  printf("Odd numbers from 1 to %d: ", n);

  for (int i = 1; i <= n; i += 2) {
    sum += i;
      
    printf("%d", i);
    
    if (i != 19) {
        printf(",");        
    } 
  }
  
  printf("\nSum = %d", sum);

  return 0;
}
