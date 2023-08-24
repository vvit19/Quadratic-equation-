#include "tests.h"
#include "quadratic.h"
#include "solver.h"
#include "utils.h"
#include <cstdio>
#include <cmath>
#include <cassert>

void run_all_tests() 
{
    struct UnitTest tests[] = {
        {0,  0,  0,  0,  0, INF_ROOTS},
        {0,  0,  5,  0,  0, ZERO_ROOTS},
        {0,  3,  0,  0,  0, ONE_ROOT},
        {0,  2, -4,  2,  0, ONE_ROOT},
        {1,  4,  4, -2,  0, ONE_ROOT},
        {1, -5,  6,  3,  2, TWO_ROOTS},
        {1,  1,  1,  0,  0, ZERO_ROOTS},
        {0,  1, -3,  3,  0, ONE_ROOT},
        {1,  5,  0,  0, -5, TWO_ROOTS},
        {1, -4,  3,  3,  1, TWO_ROOTS}
    };

    const int UNIT_TESTS_NUM = (sizeof(tests)) / (sizeof(UnitTest));

    int counter_tests = 0;
    int passed_tests = 0;

    for (int i = 0; i < UNIT_TESTS_NUM; i++) 
    {
        struct UnitTest* test = &tests[i];
        run_test(test, &counter_tests, &passed_tests);
    }

    printf("Tests: %d\n"
           "Passed tests: %d\n", counter_tests, passed_tests);
}

void run_test(struct UnitTest* test, int* counter_tests, int* counter_passed_tests) 
{
    assert(test);
    assert(counter_tests);
    assert(counter_passed_tests);

    *counter_tests += 1;
    printf("%d) ", *counter_tests);

    if (test_solve_quadratic(test->a, test->b, test->c, test->x1, test->x2, test->roots)) 
    { 
        *counter_passed_tests += 1; 
    }
}

bool test_solve_quadratic(double a, double b, double c, double x1_expected,
                          double x2_expected, RootsNum roots_expected) {
    double x1 = 0;
    double x2 = 0;
    RootsNum roots = solve_quadratic(a, b, c, &x1, &x2);

    return is_test_correct(x1, x1_expected, x2, x2_expected, roots, roots_expected);
}

bool is_test_correct(double x1, double x1_expected, double x2, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected)
{
    if (are_roots_equal(x1, x2, x1_expected, x2_expected) && roots == roots_expected)
    {
        printf("All right\n");
        return true;
    }
    printf("wtf\n");
    check_test_fail(x1, x2, x1_expected, x2_expected, roots, roots_expected);
    return false;
}

void check_test_fail(double x1, double x2, double x1_expected, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected)
{
    if (!is_equal(x1, x1_expected))
    {
        printf("x1 = %f != x1_expected = %f\n", x1, x1_expected);
    }

    if (!is_equal(x2, x2_expected))
    {
        printf("x2 = %f != x2_expected = %f\n", x2, x2_expected);
    }

    if (!is_equal(roots, roots_expected))
    {
        printf("Number of roots != Expected number of roots\n");
    }
}

bool are_roots_equal(double x1, double x2, double x1_expected, double x2_expected) 
{
    return ((is_equal(x1, x1_expected) && is_equal(x2, x2_expected)) || 
            (is_equal(x2, x1_expected) && is_equal(x1, x2_expected)));
}
