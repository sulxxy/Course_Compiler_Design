/*
  Test 3, uninitialized variable in a loop.
*/
#include <stdio.h>

int main()
{
    int k, i;
    
    for (i = 0; i < 50; i++)
    {
        k = k + 1;
    }
    
    printf("%d %d\n", k, i);
    
    return 0;
} 
