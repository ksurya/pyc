CC=/usr/bin/gcc

all: clean build test

clean:
	rm -f *.o ;
	rm -f *.out ;
	rm -f pyc/obj/*.o ;

build:
	mkdir -p pyc/obj
	${CC} -c -o pyc/obj/string.o pyc/src/string.c

test:
	${CC} pyc/obj/string.o -o test.o test.c && ./test.o
