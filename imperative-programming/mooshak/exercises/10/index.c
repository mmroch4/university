#include <stdio.h>

int main() {
    int n, a;
    
    scanf("%d", &n);
    
    int nums[n];
    
    int max = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        
        max = a > max ? a : max;
        
        nums[i] = a;
    }
    
    int used[max + 1];
    
    for (int i = 0; i < max + 1; i++) {
        used[i] = 0;
    }
    
    used[nums[0]] = 1;
    
    printf("%d", nums[0]);
    
    for (int i = 0; i < n; i++) {
        if (used[nums[i]] == 1) continue;
        
        used[nums[i]] = 1;
    
        printf(" %d", nums[i]);
    }
    
    printf("\n");
}