/* main routine for C versions of project euler problems: 
 *  http://projecteuler.net/
 *  Author: Dan Cashman
 */
#include "euler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * main routine - reads in the project euler problem number, and computes the
 * answer.
 * argv[1] - the problem number of interest.
 * ret - int the answer to the problem
 */
int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Usage: euler problem_number\n");
    }
    /* need to use unsigned to prevent integer overflow */
    unsigned int problem_number = atoi(argv[1]) - 1;
    if (problem_number >= MAX_PROBLEMS) {
        printf("Usage: Only the first %d "
               "project euler problems so far supported!\n", MAX_PROBLEMS);
    } else {
        printf("Answer to problem %d: %d",
                problem_number + 1, euler_funcs[problem_number]());
    }
    return 0;
}
