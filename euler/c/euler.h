/* euler.h
 * author: Dan Cashman
 */
#ifndef EULER_H
#define EULER_H
#define MAX_PROBLEMS 2

extern int (*euler_funcs[])();

/*
 * problem1 - finds the sum of all multiples of 3 or 5 below 1000
 */
int problem1();

/*
 * problem2 - find sum of even fibonacci terms whose values do not exceed 4
 * million.
 */
int problem2();

/*
 * problem1_general - Helper function for problem1() below a given number.
 * limit - the number below which to consider multiples of 3 or 5
 * ret - .the sum of all multiples of 3 or 5 below limit
 */
int problem1_general(int limit);

#endif
