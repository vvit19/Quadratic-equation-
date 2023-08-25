#include "tests.h"
#include "solver.h"
#include "utils.h"
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <malloc.h>

bool test_solve_quadratic(UnitTest* test);
void run_test(UnitTest* test, int* counter_tests, int* counter_passed_tests);
void check_test_fail(double x1, double x2, double x1_expected, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected);
bool is_roots_equal(double x1, double x2, double x1_expected, double x2_expected);
bool is_test_correct(double x1, double x1_expected, double x2, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected);
void read_tests(double* array);
int memory_count();

const int LEN = 6; //struct length

int memory_count() 
{
    double* array = (double*) malloc(sizeof(UnitTest));
    FILE* file = fopen("text.txt", "r");
    assert(file && "file not found");

    int counter = 1;

    for (int i = 0; fscanf(file, "%lf", &array[i]) != EOF; i++)
    {
        if ((i + 1) % LEN == 0)
        {
            array = (double*) realloc(array, ++counter * sizeof(UnitTest));
        }
    }

    fclose(file);
    free(array);

    return counter;
}

void read_tests(double* array)
{
    assert(array);
    FILE* file = fopen("text.txt", "r");
    assert(file && "file not found");

    for (int i = 0; fscanf(file, "%lf", &array[i]) != EOF; i++)
        {   }

    fclose(file);
}

void run_all_tests() 
{
    int length = memory_count();
    double* array = (double*) malloc(length * sizeof(UnitTest));
    read_tests(array);
    UnitTest* tests = (UnitTest*) malloc(length * sizeof(UnitTest));
    
    for (int i = 0, ind = -1; i < length; i++)
    {
        tests[i].a = *(++ind + array);
        tests[i].b = *(++ind + array);
        tests[i].c = *(++ind + array);
        tests[i].x1 = *(++ind + array);
        tests[i].x2 = *(++ind + array);
        tests[i].roots = (RootsNum) *(++ind + array);
    }

    const int UNIT_TESTS_NUM = length - 1;

    int counter_tests = 0;
    int passed_tests = 0;

    for (int i = 0; i < UNIT_TESTS_NUM; i++) 
    {
        UnitTest* test = &tests[i];
        run_test(test, &counter_tests, &passed_tests);
    }

    printf("Tests: %d\n"
           "Passed tests: %d\n", 
           counter_tests, passed_tests);
    free(tests);
    free(array);
}

void run_test(UnitTest* test, int* counter_tests, int* counter_passed_tests) 
{
    assert(test);
    assert(counter_tests);
    assert(counter_passed_tests);

    *counter_tests += 1;
    printf("%d) ", *counter_tests);

    bool correct_test = test_solve_quadratic(test);

    if (correct_test) 
    { 
        *counter_passed_tests += 1; 
        printf("All right\n");
    }
}

bool test_solve_quadratic(UnitTest* test) 
{
    double a = test->a;
    double b = test->b;
    double c = test->c;
    double x1_expected = test->x1;
    double x2_expected = test->x2;
    RootsNum roots_expected = test->roots;
    double x1 = 0;
    double x2 = 0;
    RootsNum roots = solve_quadratic(a, b, c, &x1, &x2);

    return is_test_correct(x1, x1_expected, x2, x2_expected, roots, roots_expected);
}

bool is_test_correct(double x1, double x1_expected, double x2, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected)
{
    if (is_roots_equal(x1, x2, x1_expected, x2_expected) && roots == roots_expected)
    {
        return true;
    }
    check_test_fail(x1, x2, x1_expected, x2_expected, roots, roots_expected);
    return false;
}

void check_test_fail(double x1, double x2, double x1_expected, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected)
{
    printf("Test failed\n");
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

bool is_roots_equal(double x1, double x2, double x1_expected, double x2_expected) 
{
    return ((is_equal(x1, x1_expected) && is_equal(x2, x2_expected)) || 
            (is_equal(x2, x1_expected) && is_equal(x1, x2_expected)));
}

