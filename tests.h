#ifndef QUADRATIC_H_
#include "quadratic.h"
#define QUADRATIC_H_
#endif

#ifndef TESTS_H_
#define TESTS_H_

struct UnitTest {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    RootsNum roots;
};

bool test_solve_quadratic(double a, double b, double c, double x1_expected, double x2_expected, 
                          RootsNum res_expected);
void run_all_tests();
void run_test(struct UnitTest* test, int* counter_tests, int* counter_passed_tests);
void check_test_fail(double x1, double x2, double x1_expected, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected);
bool are_roots_equal(double x1, double x2, double x1_expected, double x2_expected);
bool is_test_correct(double x1, double x1_expected, double x2, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected);

#endif