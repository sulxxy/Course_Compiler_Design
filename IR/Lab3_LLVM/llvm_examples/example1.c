#include<stdio.h>

void foo(unsigned e) {
 for (unsigned i = 0; i < e; ++i) {
 printf("Hello\n");
 }
}

int main(int argc, char **argv) {
 foo(argc);
 return 0;
}
