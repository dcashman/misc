/*
 * euler_test.c - source file for project euler test functions.
 * author: Dan Cashman
 */
#include "../euler.h"
#include "euler_test.h"

int (*euler_test_funcs[MAX_PROBLEMS])() = {
    problem1_test };

int problem1_test() {
    return (problem1_general(10) == 23);
}
