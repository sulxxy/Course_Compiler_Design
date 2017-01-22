/*
  Test 6, uninitialized variables in a while loop.
*/
#include <stdio.h>

int main()
{
    int x, y, a, b;
    
    x = a + b;
    y = a * b;
    while (y > a) {
        a = a + 1;
        x = a + b;
    }
    
    printf("%d %d %d %d\n", x, y, a, b);
    
    return 0;
}

