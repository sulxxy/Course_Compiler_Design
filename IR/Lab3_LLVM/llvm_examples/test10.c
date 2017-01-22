/*
  Test 10, function with arguments.
*/

#include <stdio.h>

static void test(float a, float b)
{
    float c, d;

    if (a < b) {
        c = 1.0;
        d = 2.0;
    }
    
    printf("%f %f\n", c, d);
}

int main()
{
    test(24.0, 42.0);
    test(42.0, 24.0);
    return 0;
} 
