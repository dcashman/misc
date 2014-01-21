euler : main.o euler.o
	gcc -std=c99 main.o euler.o -o euler

main.o : main.c euler.h
	gcc -std=c99 -c main.c

euler.o : euler.c euler.h
	gcc -std=c99 -c euler.c

.PHONY : clean
clean :
	rm *.o
	rm euler