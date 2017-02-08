/*
 * Test 5
 * Irreducible control flow
 */
#include <stdio.h>

void test(int pred, int pred2) {
    int i = 1;
    int j = 0;
    int k = -1;
    if (pred) {
        i += 2;
        k += i;
        goto label;
    }
    while (j < 10) {
        k = i + 1;
label:
        i = k - 1;
        j++;
    }

    printf("%d %d\n", i, j);
}

int main() {
    test(0, 1);
    
    return 0;
} 
