/*
  Test 7, uninitialized variables in a while loop.
*/
#include <stdio.h>

int main()
{
    int x, y, a, b;
 
    a = b * b; 
    while (y < a) {        
        x = a + b;
        y = y + b;
    }
    
    printf("%d %d %d %d\n", x, y, a, b);
    
    return 0;
}

