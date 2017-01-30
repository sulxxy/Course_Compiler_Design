/*
 * Test 2
 * Checks evaluation of different types of expressions
 */
#include <stdio.h>

int main() {
    int i = 2;
    int j = 3;
    float k = 3.14;

    int a = i + j;
    int b = i < j;
    float c = (float) i;
    float d = i * k;
    
    printf("%d %d %f %f\n", a, b, c, d);
    
    return 0;
}  
