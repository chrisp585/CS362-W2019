CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: testme.c
	gcc -o run -g testme.c $(CFLAGS)
	./run

clean:
	rm -f *o run *.gcov *.gcda *.gcno
