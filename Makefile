CC=/usr/bin/gcc

clean:
	rm -f *.o ;
	rm -f a.out ;
	rm -f pyc/*.o ;

build:
	${CC} -c -o pyc/string.o pyc/string.c

test:
	${CC} pyc/string.o test.c && \
	./a.out
