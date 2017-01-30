/*
 * Test 1
 * Checks that anything is propagated at all.
 */
#include <stdio.h>

int main() {
    int i = 1;
    int j = i + 1;
    int k = j + 1;
  
    printf("%d %d %d\n", i, j, k);
    
    return 0;
}
