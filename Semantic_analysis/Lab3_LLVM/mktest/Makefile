all: a.out
a.out: main.o func.o
	gcc $^ -o $@
%.o: %.c
	gcc -c $^ -o $@
