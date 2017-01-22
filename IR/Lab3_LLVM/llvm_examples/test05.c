/*
  Test 5, uninitialized variable in a while loop.
*/
#include <stdio.h>

int main()
{
    int count;

    while(count<100)
    { 
        count++;
    }    
    
    printf("%d\n", count);
    
    return 0;
} 
