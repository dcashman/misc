/*
 * euler.c - source file for project euler problem functions.
 * author: Dan Cashman
 */
#include "euler.h"

int (*euler_funcs[MAX_PROBLEMS])() = {
    problem1,
    problem2
};
/* return sum of multiples of 3 and 5 below 1000 */
int problem1() {
    return problem1_general(1000);
}

/*
 * problem1_general - adds up the multiples of 3 and 5 below the given limit.
 * Rather than checking all numbers from 1 -> limit if they are a multiple of 3
 * or 5, fewer instructions would be required to only add up the multiples of 3
 * and 5, and then remove those that were double-counted, namely the multiples
 * of 3 and 5: 15.
 * returns - sum: the sum of all of the indicated multiples.
 */
int problem1_general(int limit) {
    int sum = 0;
    for(int i = 0; i < limit; i += 3) {
        sum += i;
    }
    for(int i = 0; i < limit; i += 5) {
        sum += i;
    }
    for(int i = 0; i < limit; i += 15) {
        sum -= i;
    }
    return sum;
}

/*
 * problem2 - find the sum of the even fibonnoci terms with values up to 4 million
 */
int problem2() {

    /* initialize array with fibonnaci values */
    /* add up the values in a temporary place */
    return 0;
}
