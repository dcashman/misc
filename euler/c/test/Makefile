euler_test : main.o euler_test.o euler.o
	gcc -std=c99 main.o euler.o euler_test.o -o euler_test

main.o : main.c ../euler.h euler_test.h
	gcc -std=c99 -c main.c

euler.o : ../euler.c ../euler.h
	gcc -std=c99 -c ../euler.c

euler_test.o : euler_test.c euler_test.h
	gcc -std=c99 -c euler_test.c

.PHONY : clean
clean :
	rm *.o
	rm euler_test