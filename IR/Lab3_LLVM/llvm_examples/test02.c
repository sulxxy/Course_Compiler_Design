/*
  Test 2, uninitialized variables with simple branch.
*/
#include <stdio.h>

int main()
{
    int k;
    int t = 30;
    
    if(k > t){
        printf("%d ", k);
    }
    else {
        k = t;    
    }
    
    printf("%d %d\n", k, t);
    
    return 0;
}  
