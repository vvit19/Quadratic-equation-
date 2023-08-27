#include "tests.h"
#include "solver.h"
#include "utils.h"
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>

bool test_solve_quadratic(UnitTest* test);
void run_test(UnitTest* test, int* counter_tests, int* counter_passed_tests);
void where_test_fail(double x1, double x2, double x1_expected, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected);
bool is_roots_equal(double x1, double x2, double x1_expected, double x2_expected);
bool check_test_correct(double x1, double x1_expected, double x2, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected);
bool connect_file_test(UnitTest** tests, FILE* file, int* ntests);
                     
int run_all_tests(FILE* file) 
{
    assert(file);

    UnitTest* tests = nullptr;
    int ntests = 0;
    if (!connect_file_test(&tests, file, &ntests))
    {
        return TESTS_ERROR;
    }

    int counter_tests = 0;
    int passed_tests = 0;

    for (int i = 0; i < ntests; i++) 
    {
        run_test(&tests[i], &counter_tests, &passed_tests);
    }

    printf("Tests: %d\n"
           "Passed tests: %d\n", 
           counter_tests, passed_tests);
           
    free(tests);
    return RUN_TESTS;
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
    }
}

bool test_solve_quadratic(UnitTest* test) 
{
    assert(test);

    double a = test->a;
    double b = test->b;
    double c = test->c;
    double x1_expected = test->x1;
    double x2_expected = test->x2;
    RootsNum roots_expected = test->roots;
    
    double x1 = 0;
    double x2 = 0;
    RootsNum roots = solve_quadratic(a, b, c, &x1, &x2);

    return check_test_correct(x1, x1_expected, x2, x2_expected, roots, roots_expected);
}

bool check_test_correct(double x1, double x1_expected, double x2, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected)
{
    if (is_roots_equal(x1, x2, x1_expected, x2_expected) && (int) roots == (int) roots_expected)
    {
        printf("All right\n");
        return true;
    }

    printf("Test failed\n");
    where_test_fail(x1, x2, x1_expected, x2_expected, roots, roots_expected);
    return false;
}

void where_test_fail(double x1, double x2, double x1_expected, double x2_expected, 
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

bool is_roots_equal(double x1, double x2, double x1_expected, double x2_expected) 
{
    return ((is_equal(x1, x1_expected) && is_equal(x2, x2_expected)) || 
            (is_equal(x2, x1_expected) && is_equal(x1, x2_expected)));
}

bool connect_file_test(UnitTest** tests, FILE* file, int* ntests)
{
    //no assert for tests and ntests because they are nullptr for this time
    assert(file);
    int max_file_size = get_file_size(file);
    *tests = (UnitTest*) calloc(max_file_size, sizeof(UnitTest));
    if (is_nullptr(*tests))
    {
        return false;
    }

    char* buffer = (char*) calloc(max_file_size, sizeof(char));
    if (is_nullptr(buffer))
    {
        free(*tests);
        return false;
    }

    int buffer_size = read_file(file, buffer, max_file_size);
    fclose(file);

    *ntests = calc_nlines(buffer, buffer_size);

    int* line_size = (int*) calloc(*ntests, sizeof(int));
    if (is_nullptr(line_size))
    {
        free(*tests);
        free(buffer);
        return false;
    }
    get_line_size(line_size, buffer_size, buffer);
    
    int shift = 0;
    for (int i = 0; i < *ntests; i++)
    {
        sscanf((buffer + shift), 
              "%lf %lf %lf %lf %lf %d",
              &((*tests + i)->a),
              &((*tests + i)->b),
              &((*tests + i)->c),
              &((*tests + i)->x1),
              &((*tests + i)->x2),
              (int*)&((*tests + i)->roots));

        shift += line_size[i];
    }

    free(buffer);
    free(line_size);
    return true;
}
