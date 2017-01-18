/*
  Test 11, complex irreducible control flow.
*/
#include <stdio.h>

static void test(int branch)
{
    int a, b, c, d;
    int k;

    if (branch) {
        goto target;
    }

    a = 1;
    b = 2;
    c = 3;
    d = 4;
    for (k = 0; k < 100; k++) {
        c = a + b;
target:
        d = a - b;
    }
    
    printf("%d %d %d %d %d\n", a, b, c, d, k);
}

int main()
{
    test(0);
    test(1);
    return 0;
} 
