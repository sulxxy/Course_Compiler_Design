#include <stdio.h>

void fun_a();
int fun_b(int,int);
int fun_c(int,int);

// empty function
void fun_a(){    
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

double fun_d(int a){
    double r = 0;
    for(int i=0; i<a; i++)
        r *= i;
    return r;
}

float fun_e(int a){
    float r = 0;
    for(int i=0; i<a; i++)
        r += i;
    return r;
}

double fun_h(){
   return 0;
}

int fun_i(int a, int b){
  int p; 
  int r; 
  if (a < b) p = 1;
  else p = 2;
  r = p * 2;
  return r;
}


int main(){
    int a = 10;
    int b = 30;
    int k;
    int l;

    fun_a();
    int c = fun_b(a, b);
    int d = fun_c(a, b);
    int e = fun_b(a, a);
    int f = fun_b(c,d);
	
    double ad = fun_d(a) + 100.0;
    float  af = fun_e(a) + 100.f;
    
    double h = fun_h();

    int m = fun_i(a, b);     

    printf("result is %d\n", f);
    printf("k is %d\n", k);
    printf("m is %d\n", m);
    return 0;
}




