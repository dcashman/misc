/* main routine for C versions of project euler problems: 
 *  http://projecteuler.net/
 *  Author: Dan Cashman
 */
#include "../euler.h"
#include "euler_test.h"
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
    int num_tests = MAX_PROBLEMS;
    int failed_tests = 0;
    for(int i = 0; i < MAX_PROBLEMS; i++) {
        if(!euler_test_funcs[i]()) {
            printf("Test %d failed\n", i);
            failed_tests++;
        }
    }
    printf("Failed %d out of %d tests\n", failed_tests, MAX_PROBLEMS);
    return 0;
}
