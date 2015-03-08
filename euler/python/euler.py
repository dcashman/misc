#!/usr/bin/python
#
# euler.py - collection of euler problems written in python.
#

import sys

#
# problem_1: Find the sum of the multiples of 3 and 5, under 1000.
#
#  problem_1_sum_multiples: Find the sum of all numbers under the given number.
#
#  problem_1_3_5: Find sum of multiples of 3 and 5, which are both prime, so
#    only 15 needs to be discounted.  This is more efficient than the general
#    one.
#

def problem_1_sum_multiples(limit=1000, *multiples):
    sum = 0
    for i in range(1, limit):
        is_mult = False
        for j in multiples:
            if i % j == 0:
                is_mult = True
        if is_mult:
            sum += i
    return sum

def problem_1_3_5(limit=1000):
    sum = 0
    for i in range(3, limit, 3):
        sum += i
    for i in range(5, limit, 5):
        sum += i
    for i in range(15, limit, 15):
        sum -= i
    return sum

def problem_1():
    #return problem_1_sum_multiples(1000, 3, 5)
    return problem_1_3_5()

def init_euler_funcs():
    euler_funcs = []
    euler_funcs.append(problem_1)
    return euler_funcs

def main():
    euler_funcs = init_euler_funcs()
    if len(sys.argv) == 2:
        problem_num = int(sys.argv[1])
        if problem_num > len(euler_funcs):
            print "The solution to problem %d has not yet been written, sorry." % (problem_num)
            return
        print euler_funcs[problem_num - 1]()
    else:
        for e in euler_funcs:
            print e()

if __name__ == "__main__":
    main()
