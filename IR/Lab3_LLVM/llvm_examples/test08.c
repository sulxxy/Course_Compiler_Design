/*
  Test 8, a more complex control flow.
*/

#include <stdio.h>

int main()
{
    int a, b, c, d, e;
    float f;
    double g;
    
    if(a > 100){
        a = 10;
    }
    else {
        a = 20;
        b = 20;
    }

    e = e*100;    
    d = c*2;

    for (int i = 0; i < a; i++)
    {
        if(i<a){
            g += 1.0;
        }
        else {
            g = 500.0;
        }
    }
    
    printf("%d %d %d %d %d %f %f\n", a, b, c, d, e, f, g);
    
    return 0;
} 
