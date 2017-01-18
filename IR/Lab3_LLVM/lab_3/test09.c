/*
  Test 9. Join.
*/

#include <stdio.h>



int init(){
    return 42;
}


int main(){
    int x = 1;
    int y;
    int z;
    int t;
        
    if(x > y){
      y = 5+x;
    }
    else {
      y = init();
      t = init();
    }
    z = y*y;
    
    printf("%d %d %d %d\n", x, y, z, t);
    
    return 0;
}


