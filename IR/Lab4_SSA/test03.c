/*
 * Test 3
 * Basic control flow
 */
#include <stdio.h>

void test(int pred) {
    int i = 1;
    int j = 3;
    int k, l;
    if (pred) {
        k = i + 1;
        l = i - 1;
    } else {
        k = j - 1;
        l = j + 1;
    }

    printf("%d %d\n", k, l);
}

int main() {
    test(1);
    
    return 0;
} 
