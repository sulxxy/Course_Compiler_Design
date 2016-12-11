bison -vd RTSL.y -o RTSL.yy.c
flex -o RTSL.l.c RTSL.lex
gcc -o Parser.out *.c
./Parser.out < $1
