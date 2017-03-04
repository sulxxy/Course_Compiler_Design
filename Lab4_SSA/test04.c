/*
 * Test 4
 * Basic loop control flow
 */
#include <stdio.h>

int main() {
    int i = 1;
    int j = 0;
    while (j < 10) {
        int k = i + 1;
        i = k - 1;
        j++;
    }

    printf("%d %d\n", i, j);
    
    return 0;
} 
