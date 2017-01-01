#include <stdio.h>

void fun_a();
int fun_b(int,int);
int fun_c(int,int);

void fun_a(){
    // empty function
}


int fun_b(int a, int b){
    return a * a + b;  
}


int fun_c(int a, int b){
    int r = 0;
    for(int i=0; i<a; i++)
        r += b * i;
    return r;
}


int main(){
    int a = 10;
    int b = 30;

    fun_a();
    int c = fun_b(a, b);
    int d = fun_c(a, b);
    int e = fun_b(a, a);
    int f = fun_b(c,d);

    printf("result is %d\n", f);
    return 0;
}
