#include <stdio.h>

float PI = 3.1415927;

int main() {
    float r, h, v;
    
    scanf("%f %f", &r, &h);
    
    v = ((float)1 / 3) * h * PI * r * r;

    printf("The volume of the cone with a base radius of %f and height %f is: %f\n", r, h, v);
    
    
    return 0;
}