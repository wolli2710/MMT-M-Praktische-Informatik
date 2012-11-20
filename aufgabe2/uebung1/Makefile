all: main

main: main.c
	gcc -Wall -g -DCLS=`getconf LEVEL1_DCACHE_LINESIZE` -std=c99 -msse2 -O3 -o main main.c


test: main
	./main

clean:
	rm -f main