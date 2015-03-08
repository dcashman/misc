#!/usr/bin/python
#
# euler_test.py - collection of tests for the code written for the euler
#problems in euler.py
#

import euler
import sys

#
# problem_1 tets: test with limit of 20 to include 15, which could be
# double-counted
#
def problem_1_sum_multiples_test():
    if euler.problem_1_sum_multiples(20, 3, 5) != 78:
        return False
    else:
        return True

def problem_1_3_5_test():
    if euler.problem_1_3_5(20) != 78:
        return False
    else:
        return True

def init_problem_1_tests():
    p1_tests = []
    p1_tests.append(problem_1_sum_multiples_test)
    p1_tests.append(problem_1_3_5_test)
    return p1_tests

def init_euler_tests():
    euler_tests = []
    euler_tests.append(init_problem_1_tests())
    return euler_tests

def run_problem_tests(test_num, tests):
    success = True
    failed_tests = []
    sys.stdout.write("Testing problem %d: " % (test_num))
    for t in tests:
        if not t():
            sys.stdout.write("@")
            failed_tests.append(t.__name__)
            success = False
        else:
            sys.stdout.write(".")
    if success:
        print " PASS"
    else:
        print "" # newline
        for f in failed_tests:
            print "\t%s FAILED" % (f)
    return

def main():
    euler_tests = init_euler_tests()

    if len(sys.argv) == 2:
        test_num = int(sys.argv[1])
        if test_num > len(euler_tests):
            print "The tests for problem %d has not yet been written, sorry." % (test_num)
        else:
            run_problem_tests(test_num, euler_tests[test_num - 1])
        return
    else:

        # run them all!
        test_num = 1
        for e in euler_tests:
            run_problem_tests(test_num, euler_tests[test_num - 1])
            test_num += 1

if __name__ == "__main__":
    main()
